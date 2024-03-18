#include "pim.cpp"

using namespace std;
// Level 1
// x stands for different data types(S D C Z)
// xSWAP: y <=> x, dimension: y[n * 1], x[n * 1]
void iSWAP(int n, int **x, int **y){
    int *t;
	t = *x;
	*x = *y;
	*y = t;
}
void sSWAP(int n, float **x, float **y){
    float *t;
	t = *x;
	*x = *y;
	*y = t;
}

// xSCAL: x = alpha * x, dimension: x[n * 1]
void iSCAL(int n, int alpha, int *x){
    int *y;
    iGEMV(n, 1, x, &alpha, y);
    x = y;
}
void sSCAL(int n, float alpha, float *x){
    float *y;
    sGEMV(n, 1, x, &alpha, y);
    x = y;
}

// xAXPY: y = alpha * x + y, dimension: x[n * 1], y[n * 1]
void iAXPY(int n, int alpha, int *x, int *y){
    iSCAL(n, alpha, x);
    iXPY(n, x, y);
}
void sAXPY(int n, float alpha, float *x, float *y){
    sSCAL(n, alpha, x);
    sXPY(n, x, y);
}

// xDOT: return x^T * y, dimension: x[n * 1], y[n * 1]
int iDOT(int n, int *x, int *y){
    int *res;
    iGEMV(1, n, x, y, res);
    return *res;
}
int sDOT(int n, float *x, float *y){
    float *res;
    sGEMV(1, n, x, y, res);
    return *res;
}

// xROT: Givens Rotation
// iROT is useless
void sROT(int n, float *x, float *y, float C, float S){
    for (int i = 0; i < n; i++){
        float t = C * x[i] + S * y[i];
        y[i] = C * y[i] - S * x[i];
        x[i] = t;
    }
}