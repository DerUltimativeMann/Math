#include <stdlib.h>

#ifdef DEBUG
#include <stdio.h>
#endif

#include "matrices.h"


void initMatrix(matrix *mat, int n, int m)
{
    if(mat)
    {
        int x,y;
        mat->n = n; /* Rows */
        mat->m = m; /* Columns */

        if((mat->val = (double**)malloc(sizeof(double*) * n)))
        {
            int i;

            for(i=0; i < n; i++)
            {
                if(!(mat->val[i] = (double*)malloc(sizeof(double) * m)))
                {
                    #ifdef DEBUG
                    printf("ERR - memory allocation failed!\n");
                    #endif
                    return;
                }
            }
        }
        else
        {
            #ifdef DEBUG
            printf("ERR - memory allocation failed!\n");
            #endif
            return;
        }

        for(y=0; y < n; y++)
        {
            for(x=0; x < m; x++)
            {
                mat->val[y][x] = 0;
            }
        }
    }
}


void deleteMatrix(matrix *mat)
{
    if(mat)
    {
        int i;
        for(i=0; i < mat->n; i++)
            free(mat->val[i]);
        free(mat->val);
        mat->n = 0;
        mat->m = 0;
    }
}


void setMatrixElement(matrix *mat, int n, int m, double val)
{
    mat->val[n][m] = val;
}


int matrixMult(matrix *input_mat1, matrix *input_mat2, matrix *output_mat)
{
    int i, j;

    if(input_mat1->m != input_mat2->n )
    {
        #ifdef DEBUG
        printf("ERR - incompatible matrices for matrix-multiplication\n");
        #endif
        return MATRIXMATH_MATRIXPRODUCT_ERROR;
    }
    else
    {
        initMatrix(output_mat, input_mat1->n, input_mat2->m);
        for(i=0; i < output_mat->n; i++)
        {
            for(j=0; j < output_mat->m; j++)
            {
                int x;
                for(x=0; x < input_mat1->m; x++)
                {
                    output_mat->val[i][j] += input_mat1->val[i][x] * input_mat2->val[x][j];
                }
            }
        }
    }
    return MATRIXMATH_OK;
}


int matrixFunc(matrix *mat, double (*fktp)(double))
{
    int i, j;
    for(i=0; i < mat->n; i++)
    {
        for(j=0; j < mat->m; j++)
        {
            mat->val[i][j] = (*fktp)(mat->val[i][j]);
        }
    }

    return MATRIXMATH_OK;
}
