#include<stdio.h>

int main()
{
int n,k;
printf("enter a no of rows:");
scanf("%d",&n);
int a;
for(int i=1;i<=n;i++)
{
  for(k=1;k<=n-i;k++)
     {
      printf(" ");
      }
    if(i%2!=0) a=1;
    else a=0;
    for(int j=1;j<=i;j++)
    {
    printf(" %d",a);
    if(a==0) a=1;
    else a=0;
    }
    printf("\n");
    }
    
    
    return 0;
}