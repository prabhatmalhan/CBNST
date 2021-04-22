#include<stdio.h>

float NumeratorProduct(float a[][2],int n,float x)
{
    float product=1;
    for(int i=0 ; i<n ; ++i)
        product*=x-a[i][0];
    return product;
}

float DenominatorProduct(float a[][2],int n,float x,int j)
{
    float product=1;
    for(int i=0 ; i<n ; ++i)
        if(i!=j)
            product*=a[j][0]-a[i][0];
    return product;
}

int main()
{
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    float arr[n][2];
    printf("Enter the values of table:\n");
    for(int i=0 ; i<n ; ++i)
        scanf("%f%f",&arr[i][0],&arr[i][1]);
    printf("Enter the value of x :");
    float x;
    scanf("%f",&x);
    float y=0;
    float np=NumeratorProduct(arr,n,x);
    for(int i=0 ; i<n ; ++i)
        y+=np/(x-arr[i][0])/DenominatorProduct(arr,n,x,i)*arr[i][1];
    printf("y(x) = %.4f",y);
    return 0;
}