#include<stdio.h>
#include<math.h>

void nhap(float &x, int &n)
{
    printf("Moi nhap y : ");
    scanf("%f",&x);
    printf("Moi nhap m : ");
    scanf("%d",&n);
}

float canbacn(float x, int n)
{
    float a; 
    a = pow(x,1.0/n);
    return a;
}

float tinhP(float x, int n)
{
    float p,a=1,t=1,h=0;
    int m=0;
    if(x>=0&&n>=0)
    {
        for (int i = 1; i <= n; i++)
        {
            a=a*x;
            t=t*x;
            m=n*i;
            h=h-(float)t/m;
        }
        return p = 2000*a + h;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            a=a*x;
        }
        return p = 2000 + sqrt(a);
    }
    
}

int main()
{
    float y,cbn,p;
    int m;
    nhap(y,m);
    cbn=canbacn(y,m);
    printf("\nCan bac m cua y la: %.4f",cbn);
    p=tinhP(y,m);
    printf("\nP(y,m) = %.4f",p);
    return 0;
}