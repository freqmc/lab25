#define _USE_MATH_DEFINES 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

int rand10(int mmax);
double rand_double(double dmin, double dmax);
int* rand10_arr(int n, int mmax);
double* rand_double_arr(int n, double dmin, double dmax);

int main() {
    int mmax, n;
    double dmin, dmax;
    int* ptr_arr_1;
    double* ptr_arr_2;
    srand(time(NULL));
    system("chcp 1251");
    printf("¬ведите максимальное число дл€ генерации случайного целого числа:\n");
    scanf("%d", &mmax);
    getchar();
    printf("%d\n", rand10(mmax));
    printf("¬ведите минимальное и максимальное число дл€ генерации случайного вещественного числа:\n");
    scanf("%lf %lf", &dmin, &dmax);
    getchar();
    printf("%lf\n", rand_double(dmin, dmax));
    printf("¬ведите кол-во элементов в массиве:\n");
    scanf("%d", &n);
    getchar();
    printf("¬ведите максимальное число дл€ генерации случайного целого числа:\n");
    scanf("%d", &mmax);
    getchar();
    ptr_arr_1 = rand10_arr(n, mmax);
    for (int i = 0; i < n; i++) {
        printf("%d\n", ptr_arr_1[i]);
    }
    printf("¬ведите кол-во элементов в массиве\n");
    scanf("%d", &n);
    getchar();
    printf("¬ведите минимальное и максимальное число дл€ генерации случайного вещественного числа:\n");
    scanf("%lf %lf", &dmin, &dmax);
    getchar();
    ptr_arr_2 = rand_double_arr(n, dmin, dmax);
    ptr_arr_1 = rand10_arr(n, mmax);
    for (int i = 0; i < n; i++) {
        printf("%lf\n", ptr_arr_2[i]);
    }
}

int rand10(int mmax) {
	return 0 + rand() % mmax;
}

int* rand10_arr(int n, int mmax) {
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = rand10(mmax); 
    }
    return arr;
}

double rand_double(double dmin, double dmax) {
	return dmin + 1.f * (dmax - dmin) * rand() / RAND_MAX;
}

double* rand_double_arr(int n, double dmin, double dmax) {
    double* arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        arr[i] = rand_double(dmin, dmax);
    }
    return arr;
}
