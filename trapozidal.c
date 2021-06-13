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
    for(float i=a+h ; i<b ; i+=h)
        sum+=2*f(i);
    printf("ans:%f",h*sum/2);
    return 0;
}
