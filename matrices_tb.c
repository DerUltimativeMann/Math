#include <stdio.h>
#include <math.h>
#include "matrices.h"
#include "matrices_io.h"

void printMat(matrix *mat)
{
    if(mat)
    {
        int i, j;
        for(i=0; i < mat->n; i++)
        {
            for(j=0; j < mat->m; j++)
            {
                printf("\t%.5lf", mat->val[i][j]);
            }
            putchar('\n');
        }

    }
    else
    {
        printf("No Matrix given.\n");
    }
}

double times2(double val)
{
    return val*2;
}

double sigmoid(double val)
{
    return 1.0 / (1.0 + exp(-val));
}

int main()
{
    matrix mat;
    FILE *fp = NULL;

    #ifdef SAVE
    matrix mat_in1, mat_in2;
    int i, j;

    initMatrix(&mat_in1, 5, 3);
    initMatrix(&mat_in2, 3, 4);

    /* Set input matrix 1 */
    for(i=0; i < mat_in1.n; i++)
    {
        for(j=0; j < mat_in1.m; j++)
        {
            setMatrixElement(&mat_in1, i, j, 0.1*(i+j));
        }
    }

    /* Set input matrix 2 */
    for(i=0; i < mat_in2.n; i++)
    {
        for(j=0; j < mat_in2.m; j++)
        {
            setMatrixElement(&mat_in2, i, j, 0.1*(i+j));
        }
    }

    /* Multiply matrices */
    matrixMult(&mat_in1, &mat_in2, &mat);

    printf("Matrix Testbench\n\n");
    printMat(&mat_in1);
    putchar('\n');
    printMat(&mat_in2);
    putchar('\n');
    printMat(&mat);
    putchar('\n');

    printf("Sigmoid\n\n");
    matrixFunc(&mat, sigmoid);
    printMat(&mat);
    putchar('\n');

    fp = fopen("mat.dat", "wb");
    printf("Saved matrix: %d\n\n", saveMatrix(&mat, fp));

    deleteMatrix(&mat_in1);
    deleteMatrix(&mat_in2);
    #endif /* SAVE */

    #ifdef LOAD
    fp = fopen("mat.dat", "rb");
    printf("Loaded matrix: %d\n\n", loadMatrix(&mat, fp));
    printMat(&mat);
    putchar('\n');
    #endif /* LOAD */

    fclose(fp);
    deleteMatrix(&mat);

    printf("Done...\n");

    return 0;
}
