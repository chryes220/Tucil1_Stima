#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>

typedef struct eltype {
    char letter;
    int color_code;
} eltype;

/* COLOR CODE
0 - default color
1 - red
2 - green
3 - yellow
4 - blue  
5 - purple 
6 - cyan */

typedef struct matrix {
    eltype buffer[50][50];
    int nRow;
    int nCol;
} matrix;

#define elmt(M,i,j) (M).buffer[i][j].letter
#define color(M,i,j) (M).buffer[i][j].color_code
#define row(M) (M).nRow
#define col(M) (M).nCol

void copy_matrix (matrix m1, matrix *m2);
void print_matrix (matrix m);

#endif