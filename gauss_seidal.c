#include <stdio.h>
#include <math.h>

int main()
{
    printf("Enter the number of variables : ");
    int n;
    scanf("%d", &n);
    printf("Enter the equation coefficients :\n");
    float a[n][n + 1], sii = 0, sij = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n + 1; ++j)
        {
            scanf("%f", &a[i][j]);
            if (i == j)
                sii += a[i][j];
            else
                sij += a[i][j];
        }
    }

    if(sii<sij)
    {
        printf("Incorrect input");
        return 0;
    }
    
    printf("Enter initial values of unknown : ");
    float xk[n];
    for (int i = 0; i < n; ++i)
        scanf("%f", &xk[i]);

    printf("Enter acceptable error : ");
    float e;
    scanf("%f",&e);
    printf("\n");
    while(1)
    {
        float xk1[n];
        for (int i = 0; i < n; ++i)
        {
            float s = 0;
            for (int j = 0; j < i; ++j)
                s += a[i][j] * xk1[j];
            for (int j = i + 1; j < n; ++j)
                s += a[i][j] * xk[j];
            xk1[i] = (a[i][n] - s) / a[i][i];
        }

        for(int i=0 ; i<n ; ++i)
            printf("%f\t",xk1[i]);
        printf("\n");

        for(int i=0 ; i<n ; ++i)
        {
            if(fabs(xk[i]-xk1[i])<=e)
            {
                printf("\n");
                for(int i=0 ; i<n ; ++i)
                    printf("x%d = %d\n",i+1,(int)round(xk1[i]));
                return 0;
            }
        }

        for(int i=0 ; i<n ; ++i)
            xk[i]=xk1[i];
    }
    return 0;
}