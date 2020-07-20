#include<stdio.h>
#include<malloc.h>

int main()
{
    int n,x;
	int *a;
    FILE *f;
    printf("Moi nhap n: ");
    scanf("%d",&n);
    a = (int*)malloc(n*sizeof(int));
    //Nhap mang A:
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",(a+i));
    }
	
	f = fopen("ABC2020.txt","wt");
    //Xuat vao file:
    printf("\nMang da nhap la: \n");
	for(int i=0 ; i<n ; i++)
	{
        printf("\t%d",*(a+i));
		fprintf(f,"\t%d",*(a+i));
	}
    fprintf(f,"\n");
    //Sap xep mang giam dan, ghi vao tep:
    printf("\nMang da sap xep la: \n");
    int tg;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(*(a+i)<*(a+j))
            {
                tg=*(a+i);
                *(a+i)=*(a+j);
                *(a+j)=tg;
            }
        }
    }
    for(int i=0 ; i<n ; i++)
	{
        printf("\t%d",*(a+i));
        fprintf(f,"\t%d",*(a+i));
	}
    fclose(f);
    //Xoa phan tu bang x:
    printf("\nMoi nhap x: ");
    scanf("%d",&x);
    for (int i = 0; i < n; i++)
    {
        if(*(a+i)==x)
        {
            for (int j = i; j < n; j++)
            {
                *(a+j)=*(a+j+1);
            }
            n--;
        }
    }
    printf("\nDay sau khi xoa la: \n");
    for (int i = 0; i < n; i++)
    {
        printf("\t%d",*(a+i));
    }
    //Kiem tra day so co hop le khong:
    int kt1=0,kt2=0;
    for (int i = 0; i < n; i++)
    {
        if(*(a+i)<0)
        {
            printf("\nDay so khong hop le!");
            return 0;
            break;
        }
        else kt1++;
        if(*(a+i) %2 == 0 && *(a+i+1) %2 ==0) kt2++;
        if(kt2==2)
        {
            printf("\nDay so khong hop le!");
            return 0;
            break;
        }
    }
    if (kt1 == n && kt2<3)
    {
        printf("\nDay hop le!");
    }
    return 0;
}