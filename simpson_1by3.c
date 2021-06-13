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
    int trigger=1;
    for(float i=a+h ; i<b ; i+=h)
    {
        sum+=(3+trigger)*f(i);
        trigger=-trigger;
    }
    printf("ans:%f",h*sum/3);
    return 0;
}
