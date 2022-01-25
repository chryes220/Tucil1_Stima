#include "matrix.h"

void copy_matrix (matrix m1, matrix *m2) {
    int i, j;
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 50; j++) {
            elmt(*m2,i,j) = elmt(m1,i,j);
            color(*m2,i,j) = color(m1,i,j);
        }
    }
    row(*m2) = row(m1);
    col(*m2) = col(m1);
}

void print_matrix (matrix m) {
    int i;
    int j;
    for (i = 0; i < row(m); i++) {
        for (j = 0; j < col(m); j++) {
            if (color(m,i,j) == 1) {
                printf("\033[0;31m");
            }
            else if (color(m,i,j) == 2) {
                printf("\033[0;32m");
            }
            else if (color(m,i,j) == 3) {
                printf("\033[0;33m");
            }
            else if (color(m,i,j) == 4) {
                printf("\033[0;34m");
            }
            else if (color(m,i,j) == 5) {
                printf("\033[0;35m");
            }
            else if (color(m,i,j) == 6) {
                printf("\033[0;36m");
            }
            printf("%c ", elmt(m,i,j));
            printf("\033[0m");
        }
        printf("\n");
    }
}