#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the value of n : ");
    int n;
    scanf("%d", &n);

    float **a;
    a = (float **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i)
        a[i] = (float *)calloc(n + 1, sizeof(int));

    printf("Enter the values of the table (x,y):\n");
    for (int i = 0; i < n; ++i)
        scanf("%f%f", &a[i][0], &a[i][1]);

    float x;
    printf("Enter the value of x : ");
    scanf("%f", &x);

    for (int i = 2; i <= n; ++i)
        for (int j = 0; j <= n - i; ++j)
            a[j][i] = a[j + 1][i - 1] - a[j][i - 1];

    float u = (x - a[0][0]) * 1.0 / (a[1][0] - a[0][0]);
    float serie = u;
    int fact = 1;
    float y = a[0][1];

    for (int i = 2; i <= n; i++)
    {
        y += serie * a[0][i] / fact;
        fact *= i;
        serie *= u - i + 1;
    }

    printf("\nf(x) = %.4f\n\n", y);
    return 0;
}