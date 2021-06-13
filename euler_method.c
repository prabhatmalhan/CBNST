#include<stdio.h>

float f(float x,float y)
{
    return -y;
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
        y+=h*f(x,y);
        x+=h;
    }
    printf("f(%f) = %f\n",x,y);
    return 0;
}