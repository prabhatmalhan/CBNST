#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    float arr[n][n + 1];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n + 1; ++j)
            scanf("%f", &arr[i][j]);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                if (arr[i][i] == 0)
                {
                    for (int k = i + 1; k < n; ++k)
                    {
                        if (arr[k][i] != 0)
                        {
                            for (int l = 0; l < n + 1; ++l)
                                arr[i][l] += arr[k][l];
                            break;
                        }
                    }
                }

                float temp = arr[j][i] / arr[i][i];
                for (int k = 0; k < n + 1; ++k)
                    arr[j][k] = arr[j][k] - arr[i][k] * temp;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
            printf("%f\t", arr[i][j]);
        printf("\n");
    }
    return 0;
}