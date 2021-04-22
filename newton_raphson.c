/*
PROBLEM STATEMENT :- Solve the following equation using Newton Raphson method.

                        x³ - x = 1

*/

//SOLUTION

#include<stdio.h>
#include <math.h>

float f(float x) // defination of f(x)
{
    return pow(x,3)-x-1;
}

float df(float x) // defination of f'(x)
{
    return 3*pow(x,2)-1;
}

int main()
{
    //getting input from user
    printf("Enter the initial guess : ");
    float c;
    scanf("%f",&c);
     printf("Enter the no. of iterations : ");
    int n;
    scanf("%d",&n);
    printf("Enter the acceptable error : ");
    float e;
    scanf("%f",&e);
    
    //processing begins
    for(int i=0 ; i<n ; ++i)
    {
        //new value of d being calculated
        float d=c-f(c)/df(c);        
        printf("Value of c,i = %f,%d\n",d,i+1);

        //if the root is found
        if(fabs(d-c)<=e)
        {
            printf("%f is root found at iteration %d\n",d,i+1);
            return 0;
        }

        //updation of value of c
        c=d;
    }

    //if no root is found
    printf("Insufficient Iterations");
    return 0;
}