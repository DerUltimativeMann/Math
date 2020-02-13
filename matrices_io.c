#include "matrices_io.h"

int loadMatrix(matrix *mat, FILE *fp)
{
    int i, j, iFlag = 1;

    iFlag *= fread(&mat->n, sizeof(int), 1, fp);
    iFlag *= fread(&mat->m, sizeof(int), 1, fp);

    initMatrix(mat, mat->n, mat->m);

    for(i=0; i<mat->n; i++)
    {
        for(j=0; j<mat->m; j++)
        {
            iFlag *= fread(&mat->val[i][j], sizeof(double), 1, fp);
        }
    }
    return iFlag;
}


int saveMatrix(matrix *mat, FILE *fp)
{
    int i, j, iFlag = 1;

    iFlag *= fwrite(&mat->n, sizeof(int), 1, fp);
    iFlag *= fwrite(&mat->m, sizeof(int), 1, fp);

    for(i=0; i<mat->n; i++)
    {
        for(j=0; j<mat->m; j++)
        {
            iFlag *= fwrite(&mat->val[i][j], sizeof(double), 1, fp);
        }
    }
    return iFlag;
}
