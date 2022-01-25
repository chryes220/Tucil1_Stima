#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <string.h>
#include "boolean.h"
#include "matrix.h"
#include "wordlist.h"

void read_file (char *file_name, matrix *m, wordList *wl) {
    // membaca file
    char dir[] = "./test/";
    char ch;
    boolean read_grid;
    int i, j, k;
    char wrd[20];

    strncat(dir, file_name, 20);
    FILE *fp = fopen(dir, "r");

    if (fp == NULL) {
        printf("Fail to read the file!\n");
        row(*m) = 0;
        col(*m) = 0;
    }
    else {
        ch = fgetc(fp);
        read_grid = true;

        i = 0;
        j = 0;

        for (k = 0; k < 20; k++) {
            wrd[k] = '\0';
        }
        k = 0;

        while (ch != EOF) {

            if (read_grid) {
                if (j == 0 && ch == '\n') {
                    read_grid = false; // found a blank line
                }
                else if (ch == '\n') {
                    // go to the next row
                    i++;
                    row(*m) = i;
                    j = 0;
                }
                else {
                    if ((int) ch != 32) {
                        elmt(*m,i,j) = ch;
                        color(*m,i,j) = 0;
                        j++;
                        col(*m) = j;
                    }
                }
            }

            else {
                if (ch == '\n') {
                    enqueue(wl, wrd);
                    for (k = 0; k < 20; k++) {
                        wrd[k] = '\0';
                    }
                    k = 0;
                }
                else {
                    wrd[k] = ch;
                    k++;
                }
            }
            ch = fgetc(fp);
        }
        enqueue(wl, wrd);
        fclose(fp);
    }
}

boolean check_N (wordList w, int k, matrix m, int i, int j) {
    // memeriksa ke arah utara
    if (k == length(w)) {
        return true;
    }
    else if (i == -1 || word(w)[k] != elmt(m,i,j)) {
        return false;
    }
    else {
        return (check_N(w, k+1, m, i-1, j));
    }
}

boolean check_S (wordList w, int k, matrix m, int i, int j) {
    // memeriksa ke arah selatan
    if (k == length(w)) {
        return true;
    }
    else if (i == row(m) || word(w)[k] != elmt(m,i,j)) {
        return false;
    }
    else {
        return (check_S(w, k+1, m, i+1, j));
    }
}

boolean check_W (wordList w, int k, matrix m, int i, int j) {
    // memeriksa ke arah barat
    if (k == length(w)) {
        return true;
    }
    else if (j == -1 || word(w)[k] != elmt(m,i,j)) {
        return false;
    }
    else {
        return (check_W(w, k+1, m, i, j-1));
    }
}

boolean check_E (wordList w, int k, matrix m, int i, int j) {
    // memeriksa ke arah timur
    if (k == length(w)) {
        return true;
    }
    else if (j == col(m) || word(w)[k] != elmt(m,i,j)) {
        return false;
    }
    else {
        return (check_E(w, k+1, m, i, j+1));
    }
}

boolean check_NE (wordList w, int k, matrix m, int i, int j) {
    // memeriksa ke arah timur laut
    if (k == length(w)) {
        return true;
    }
    else if (i == -1 ||j == col(m) || word(w)[k] != elmt(m,i,j)) {
        return false;
    }
    else {
        return (check_NE(w, k+1, m, i-1, j+1));
    }
}

boolean check_SE (wordList w, int k, matrix m, int i, int j) {
    // memeriksa ke arah tenggara
    if (k == length(w)) {
        return true;
    }
    else if (i == row(m) || j == col(m) || word(w)[k] != elmt(m,i,j)) {
        return false;
    }
    else {
        return (check_SE(w, k+1, m, i+1, j+1));
    }
}

boolean check_SW (wordList w, int k, matrix m, int i, int j) {
    // memeriksa ke arah barat daya
    if (k == length(w)) {
        return true;
    }
    else if (i == row(m) || j == -1 || word(w)[k] != elmt(m,i,j)) {
        return false;
    }
    else {
        return (check_SW(w, k+1, m, i+1, j-1));
    }
}

boolean check_NW (wordList w, int k, matrix m, int i, int j) {
    // memeriksa ke arah barat laut
    if (k == length(w)) {
        return true;
    }
    else if (i == -1 || j == -1 || word(w)[k] != elmt(m,i,j)) {
        return false;
    }
    else {
        return (check_NW(w, k+1, m, i-1, j-1));
    }
}

void ans_matrix (wordList w, int i, int j, matrix *m_ans, char dir) {
    // mengupdate matriks yang berisi kumpulan jawaban dengan memberi warna pada kata yang telah ditemukan
    int x, y, l;
    int rand_color;

    rand_color = (rand() % 6) + 1;

    x = i;
    y = j;
    l = 0;

    if (dir == 'N') { //north
        while (l < length(w)) {
            if (color(*m_ans, x, y) == rand_color) {
                rand_color = (rand() % 6) + 1;
                l = 0;
                x = i;
                y = j;
            }
            else {
                color(*m_ans, x, y) = rand_color;
                l++;
                x--;
            }
        }
    }
    else if (dir == 'S') { //south
        while (l < length(w)) {
            if (color(*m_ans, x, y) == rand_color) {
                rand_color = (rand() % 6) + 1;
                l = 0;
                x = i;
                y = j;
            }
            else {
                color(*m_ans, x, y) = rand_color;
                l++;
                x++;
            }
        }
    }
    else if (dir == 'E') { //east
        while (l < length(w)) {
            if (color(*m_ans, x, y) == rand_color) {
                rand_color = (rand() % 6) + 1;
                l = 0;
                x = i;
                y = j;
            }
            else {
                color(*m_ans, x, y) = rand_color;
                l++;
                y++;
            }
        }
    }
    else if (dir == 'W') { //west
        while (l < length(w)) {
            if (color(*m_ans, x, y) == rand_color) {
                rand_color = (rand() % 6) + 1;
                l = 0;
                x = i;
                y = j;
            }
            else {
                color(*m_ans, x, y) = rand_color;
                l++;
                y--;
            }
        }
    }
    else if (dir == 'U') { //northeast
        while (l < length(w)) {
            if (color(*m_ans, x, y) == rand_color) {
                rand_color = (rand() % 6) + 1;
                l = 0;
                x = i;
                y = j;
            }
            else {
                color(*m_ans, x, y) = rand_color;
                l++;
                x--;
                y++;
            }
        }
    }
    else if (dir == 'M') { //southeast
        while (l < length(w)) {
            if (color(*m_ans, x, y) == rand_color) {
                rand_color = (rand() % 6) + 1;
                l = 0;
                x = i;
                y = j;
            }
            else {
                color(*m_ans, x, y) = rand_color;
                l++;
                x++;
                y++;
            }
        }
    }
    else if (dir == 'B') { //southwest
        while (l < length(w)) {
            if (color(*m_ans, x, y) == rand_color) {
                rand_color = (rand() % 6) + 1;
                l = 0;
                x = i;
                y = j;
            }
            else {
                color(*m_ans, x, y) = rand_color;
                l++;
                x++;
                y--;
            }
        }
    }
    else if (dir == 'T') { //northwest
        while (l < length(w)) {
            if (color(*m_ans, x, y) == rand_color) {
                rand_color = (rand() % 6) + 1;
                l = 0;
                x = i;
                y = j;
            }
            else {
                color(*m_ans, x, y) = rand_color;
                l++;
                x--;
                y--;
            }
        }
    }
}

int main () {
    matrix m, m_ans;
    wordList l, l_notfound, l_found;
    char filename[20];
    int i, j, k, g, o;
    boolean found;
    struct timespec begin, end;
    float searchtime;

    // membaca file
    printf("Enter file name : ");
    scanf("%s", &filename);
    read_file(filename, &m, &l);

    if (row(m) != 0 || col(m) != 0) {

        copy_matrix(m, &m_ans); // membuat matriks jawaban

        printf("matrix size is : %dx%d\n\n", row(m), col(m));

        while (l != NULL) {
            // begin the brute force for each word in the list
            found = false;
            i = 0;
            j = 0;

            // begin time count
            clock_gettime(CLOCK_MONOTONIC, &begin);

            while (!found && i < row(m)) {
                if (j == col(m)) {
                    // ke baris berikutnya
                    i++;
                    j = 0;
                }
                else if (check_N(first(l), 0, m, i, j)) {
                    ans_matrix(first(l), i, j, &m_ans, 'N');
                    found = true;
                }
                else if (check_S(first(l), 0, m, i, j)) {
                    ans_matrix(first(l), i, j, &m_ans, 'S');
                    found = true;
                }
                else if (check_E(first(l), 0, m, i, j)) {
                    ans_matrix(first(l), i, j, &m_ans, 'E');
                    found = true;
                }
                else if (check_W(first(l), 0, m, i, j)) {
                    ans_matrix(first(l), i, j, &m_ans, 'W');
                    found = true;
                }
                else if (check_NE(first(l), 0, m, i, j)) {
                    ans_matrix(first(l), i, j, &m_ans, 'U');
                    found = true;
                }
                else if (check_SE(first(l), 0, m, i, j)) {
                    ans_matrix(first(l), i, j, &m_ans, 'M');
                    found = true;
                }
                else if (check_SW(first(l), 0, m, i, j)) {
                    ans_matrix(first(l), i, j, &m_ans, 'B');
                    found = true;
                }
                else if (check_NW(first(l), 0, m, i, j)) {
                    ans_matrix(first(l), i, j, &m_ans, 'T');
                    found = true;
                }
                else {
                    // ke kolom berikutnya
                    j++;
                }
            }
            if (found) {
                // stop time count
                clock_gettime(CLOCK_MONOTONIC, &end);
                searchtime = (end.tv_nsec - begin.tv_nsec) / 1000000000.0 + (end.tv_sec  - begin.tv_sec);
        
                printf("word ");
                for (g = 0; g < length(first(l)); g++) {
                    printf("%c", word(first(l))[g]);
                }
                printf(" found in %f seconds\n", searchtime);
                dequeue(&l, &l_found);
            }
            else {
                dequeue(&l, &l_notfound);
            }
        }
        printf("\n");
        print_matrix(m_ans);
        printf("\n");
        if (l_notfound != NULL) {
            printf("These are the words which cannot be found :\n");
            print_wordList(l_notfound);
        }
        printf("\n");
        printf("Fin\n");
    }
    return 0;
}