/*
PROBLEM STATEMENT :- Solve the following equation using Regula Falsi method.

                        cos(x) - 3x = -1

*/

//SOLUTION

#include<stdio.h>
#include <math.h>

float f(float x) // defination of f(X)
{
    return cos(x)-3*x+1;
}

int main()
{
    float a,b;
    //getting input from user
    while(1)
    {
        printf("Enter the guessed interval : ");
        scanf("%f%f",&a,&b);

        float x=f(a),y=f(b);
        
        //invalid if f(a)*f(b) is positive
        if(x*y>0)
        {
            printf("Do you want to try again (y/n) : ");
            char ch;
            fflush(stdin);
            scanf("%c",&ch);
            if(ch=='n')
                return 0;
            else
                continue;
        }
        
        //if one of the inputs is the answer
        else if(x*y==0)
        {
            if(x==0)
                printf("%f is root",x);
            else
                printf("%f is root",y);
            return 0;
        }
        else
        {
            //proceed to process
            break;
        }
    }
    
    //getting the info required for further processing
    printf("Enter the no. of iterations : ");
    int n;
    scanf("%d",&n);
    printf("Enter the acceptable error : ");
    float e;
    scanf("%f",&e);
    float c=(a*f(b)-b*f(a))/(f(b)-f(a));
    printf("Value of c,i = %f,1\n",c);
    
    //processing begins
        for(int i=1 ; i<n ; ++i)
    {
        float temp=c;

        //updation of value of b
        if(f(a)*f(c)<0)
            b=c;
        
        //updation of value of a
        else if(f(a)*f(c)>0)
            a=c;
        
        //if c is the root
        else
        {
            printf("%f is root found at iteration %d\n",c,i);
            return 0;
        }

        //new value of c being calculated
        c=(a*f(b)-b*f(a))/(f(b)-f(a));
        
        printf("Value of c,i = %f,%d\n",c,i+1);
        
        //if the root is found
        if(fabs(c-temp)<=e)
        {
            printf("%f is root found at iteration %d\n",temp,i);
            return 0;
        }
    }

    //if no root is found
    printf("Insufficient Iterations");
    return 0;
}
