#include <stdio.h>
int main()
{
    //Number of unknown variables
    int n;
    scanf("%d", &n);
    float arr[n][n + 1];
    
    //getting the input
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n + 1; ++j)
            scanf("%f", &arr[i][j]);
    
    //converting to diadonal matrix form
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j)
            {
                //to prevent the error of division by 0
                if (arr[i][i] == 0)
                {
                    for (int k = i + 1; k < n; ++k)
                    {
                        //adding the next row to present
                        if (arr[k][i] != 0)
                        {
                            for (int l = 0; l < n + 1; ++l)
                                arr[i][l] += arr[k][l];
                            break;
                        }
                    }
                }

                //subtracting the column values
                float temp = arr[j][i] / arr[i][i];
                for (int k = 0; k < n + 1; ++k)
                    arr[j][k] = arr[j][k] - arr[i][k] * temp;
            }
        }
    }

    //reverse-tracking the array for solutions
    float roots[n];
    for(int i=0 ; i<n ; ++i)
        roots[i]=arr[i][n]/arr[i][i];

    //printing roots
    printf("\nRoots: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", roots[i]);

    return 0;
}