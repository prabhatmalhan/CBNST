/*
PROBLEM STATEMENT :- Solve for the unknown variables using Gauss-Elemination method.

                        x+y-z=-2
                        2x-y+z=5
                      -x+2y+2z=1

*/

//SOLUTION

#include <stdio.h>
int main()
{
    //Number of unknown variables
    int n;
    scanf("%d", &n);
    float arr[n][n + 1];

    //getting the input
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n + 1; j++)
            scanf("%f", &arr[i][j]);

    //converting to upper triangular form
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = j + 1; i < n; i++)
        {

            //to prevent the error of division by 0
            if (arr[j][j] == 0)
            {
                for (int x = i; x < n; x++)
                {

                    //adding the next row to present
                    if (arr[x][j] != 0)
                    {
                        for (int y = 0; y < n + 1; y++)
                            arr[j][y] += arr[x][y];
                        break;
                    }
                }
            }

            //subtracting the column values
            float temp = arr[i][j] / arr[j][j];
            for (int k = 0; k < n + 1; k++)
                arr[i][k] = arr[i][k] - temp * arr[j][k];
        }
    }

    //reverse-tracking the array for solutions
    float roots[n];
    for (int i = n - 1; i >= 0; i--)
    {
        float sum = 0;
        for (int j = n - 1; j > i; j--)
            sum += arr[i][j] * roots[j];
        roots[i] = (arr[i][n] - sum) / arr[i][i];
    }

    //printing roots
    printf("\nRoots: ");
    for (int i = 0; i < n; i++)
        printf("%.2f ", roots[i]);

    return 0;
}