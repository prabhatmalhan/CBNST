#include<stdio.h>

float f(float x,float y)
{
    return x+y;
}

int main()
{
    float x0,y0,xn,h;
    printf("Enter x0 : ");
    scanf("%f",&x0);
    printf("Enter y0 : ");
    scanf("%f",&y0);
    printf("Enter xn : ");
    scanf("%f",&xn);
    printf("Enter h : ");
    scanf("%f",&h);
    float x=x0,y=y0;
    while(x<xn)
    {
        float k1,k2,k3,k4;
        k1=h*f(x,y);
        k2=h*f(x+h/2,y+k1/2);
        k3=h*f(x+h/2,y+k2/2);
        k4=h*f(x+h,y+k3);
        y+=(k1+2*k2+2*k3+k4)/6;
        x+=h;
    }
    printf("f(%f) = %f\n",x,y);
    return 0;
}