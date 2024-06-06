#include <stdio.h>
#include <math.h>
#include <complex.h>

#define ARRAY_LEN(x) (sizeof(x) / sizeof((x)[0]))
#define PI 3.14159265359

double complex in[4] = {1, 2 - I, -I, -1 + 2*I};
// double complex in[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
double complex out[10] = {};

double complex* dft(double complex *in,  double complex *out, size_t N) {

    for (size_t k = 0; k < N; k++)
    {
        out[k] = 0;
        for (size_t n = 0; n < N; n++)
        {
            double complex x = 2 * PI * k * n / N;
            out[k] += in[n] * cexp(-I * x);
        }
    }
    return out;
}



int main()
{
    size_t N = ARRAY_LEN(in);
    double complex* a = dft(in, out, N);
    for (size_t k = 0; k < N; k++)
    {
        printf("X[%ld] = %.1f %+.1fi\n", k, creal(a[k]), cimag(a[k]));
    }
}