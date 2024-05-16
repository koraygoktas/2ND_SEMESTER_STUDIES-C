#include <stdio.h>

/*
int func(int a[],int n)
{
	int x;
	if(n==1)
	{
		return a[0];
	}
	else 
	{
		x=func(a,n-1);
	}
	if(x>a[n-1])
	{
		return x;
	}
	else
	{
		return a[n-1];
	}
}

int main()
{
	int arr[]={12,33,2,67,2};
	printf("%d",func(arr,5));
	getchar();
	return 0;
}

*/

/*

int func1(int x,int y)
{
	if(x==0)
	{
		return y;
	}
	else 
		return func1(x-1,x+y); 
		
}

void func2(int n)
{
	int i=0;
	if(n>1)
	{
		func2(n-1);
		printf("\n");
		
	}
	for(i=0;i<n;i++)
	{
		printf("*");
		
	}
}

int main()
{
	int a=5,b=2,c;
	c=func1(a,b);
	printf("valude of the c number is:%d\n",c);
	func2(5);
	getchar();
	return 0;
}

*/


int func(int dizi[],int n);

int main()
{
	int n=5;
	int dizi[5]={3,7,3,2,1};
	int toplam=func(dizi,n-1);
	printf("toplam=%d",toplam);
	
	
	return 0;
}

int func(int dizi[],int n)
{
	if(n==0)
	{
		return dizi[0];
	}
	return (dizi[n]+func(dizi,n-1));
}