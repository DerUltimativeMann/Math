#ifndef _MATRICES_IO_H
#define _MATRICES_IO_H

#include <stdio.h>
#include "matrices.h"

int loadMatrix(matrix*, FILE*);
int saveMatrix(matrix*, FILE*);

#endif
