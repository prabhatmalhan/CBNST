#include<stdio.h>

float f(float x)
{
    return 1/(1+x*x);
}

int main()
{
    float a,b;
    int n;
    printf("Enter lower limit : ");
    scanf("%f",&a);
    printf("Enter upper limit : ");
    scanf("%f",&b);
    printf("Enter no. of sub-intervals : ");
    scanf("%d",&n);
    float h=(b-a)/n;
    float sum=f(a)+f(b);
    int j=1;
    for(float i=a+h ; i<b ; i+=h,j++)
    {
        int multiplier;
        if(j%3==0)
            multiplier=2;
        else
            multiplier=3;
        sum+=multiplier*f(i);
    }
    printf("ans:%f",3*h*sum/8);
    return 0;
}
