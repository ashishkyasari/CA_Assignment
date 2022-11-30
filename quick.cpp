#include<stdio.h>
#define M 10

void input(int *a)
{
    int i=0;
    printf("\nArray Data\n");
    while(i<M)
    {
        scanf("%d",(a+i));
        i++;
    }
}

void display(int *a, int flag)
{
    int i=0;
    if(flag==0)
        printf("\nBefore sorting\n");
    else
        printf("\nAfter Sorting\n");
    while(i<M)
    {
        printf("%d ",*(a+i));
        i++;
    }
}

void Swap(int *p, int *q)
{
    int r=*p;
    *p=*q;
    *q=r;
}

void pivote(int *a,int l, int r)
{
    if(*(a+l)>*(a+r))
    {
        Swap(a+l,a+r);
    }
}

int partition(int *a, int l, int r)
{
    int i=l,j=r,k;
    pivote(a,l,r);
    k=*(a+l);
    do
    {
        do ++i;while(*(a+i)<k);
        do --j;while(*(a+j)>k);
        if(i<j)
            Swap(a+i,a+j);
    } while (i<j);
    Swap(a+j,a+l);
    return j;   
}

void quick(int *a, int l,int r)
{
    int j;
    if(l<r)
    {
        j=partition(a,l,r);
        quick(a,l,j-1);
        quick(a,j+1,r);
    }
}

int main()
{
    int x[M];
    input(x);
    display(x,0);
    quick(x,0,M-1);
    display(x,1);

    return 0;
}