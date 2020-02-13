#ifndef _MATRICES_H
#define _MATRICES_H

/* FUNCTION RETURN VALUES */
#define MATRIXMATH_OK                       1
#define MATRIXMATH_MATRIXPRODUCT_ERROR      -1

typedef struct
{
    int n,m;
    double **val;
}matrix;

/* Matrix handling */
void initMatrix(matrix*, int, int);                 /* initialize a n,m-matrix. All elements are 0. */
void deleteMatrix(matrix*);                         /* delete all Matrix elements */
void setMatrixElement(matrix*, int, int, double);   /* set the Matrix Element at the given row,column. */

/* Matrix operations */
int matrixMult(matrix*, matrix*, matrix*);          /* Input_mat1* Input_mat2 = Output_mat */
int matrixFunc(matrix*, double (*fktp)(double));    /* use a mathematical function on all matrix elements */
int matrixTrans(matrix*, matrix*);                  /* Transposes the first matrix into the second */

#endif
