#include "inc1.cpp"

using namespace std;

#define PIMNoTrans 111
#define PIMTrans 112
#define PIMConjTrans 113
#define PIMConjNoTrans 114

// xGEMV: y = alpha Ax + beta y, dimension: A[m * n] x[n * 1] y[m * 1]
void iGEMV(char TRANS, int m, int n, int ALPHA, int *A, int *x, int BETA, int *y){
    if (TRANS == 'T' or TRANS == 't') A = iTRANS(m, n, A);
    int *a = (int*)malloc(m * sizeof(int));
    iGEMV(m, n, A, x, a);
    iSCAL(n, BETA, y);
    iAXPY(n, ALPHA, a, y);
}
void sGEMV(char TRANS, float m, float n, float ALPHA, float *A, float *x, float BETA, float *y){
    if (TRANS == 'T' or TRANS == 't') A = sTRANS(m, n, A);
    float *a = (float*)malloc(m * sizeof(float));
    sGEMV(m, n, A, x, a);
    sSCAL(n, BETA, y);
    sAXPY(n, ALPHA, a, y);
}

// xGBMV: y = alpha Ax + beta y, A: Matrix-Band dimension: A[m * n] x[n * 1] y[m * 1]
// A[i, j]=Band[i - j + LU + 1, j]
void iGBMV(char TRANS, int m, int n, int KL, int KU, int ALPHA, int *A, int *x, int BETA, int *y){
    int *T = (int*)malloc(m * n * sizeof(int));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if ((0 <= i - j + KU) && (i - j + KU <= KU + KL)) T[i * n + j] = A[(i - j + KU) * n + j];
            else T[i * n + j] = 0;
    iGEMV(TRANS, m, n, ALPHA, T, x, BETA, y);
}
void sGBMV(char TRANS, int m, int n, int KL, int KU, float ALPHA, float *A, float *x, float BETA, float *y){
    float *T = (float*)malloc(m * n * sizeof(float));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++){
            if ((0 <= i - j + KU) && (i - j + KU <= KU + KL)) T[i * n + j] = A[(i - j + KU) * n + j];
            else T[i * n + j] = 0;
    sGEMV(TRANS, m, n, ALPHA, T, x, BETA, y);
}

