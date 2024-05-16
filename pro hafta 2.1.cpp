#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
int main()
{
	
	register int i;
	char name[100];
	printf("enter a string:");
	gets(name);
	printf("the reverse of string: ");
	for(i=strlen(name)-1;i>=0;i--)
	{
		printf("%c",name[i]);
	}	
	
	return 0;
}
*/
//register değişken tipinin autodan farkı daha hızlı ulaşılabiliyor olmasıdır

/*
int g;

void func1();
void func2();
void func3();

int main()
{
	printf("enter the value of g:");
	scanf("%d",&g);
	func1();
	func2();
	func3();
	printf("teh value of g is:%d",g);
	return 0;
	
}

void func1()
{
	printf("the value of g is %d\n",g+3);
}


void func2()
{
	printf("the value of g is %d\n",g+22);
}


void func3()
{
	printf("the value of g is %d\n",g+40);
}
*/

/*
int bulebob(int,int,int);

int main()
{
	int a,b;
	printf("enter two numbers:");
	scanf("%d%d",&a,&b);
	int buyuk,kucuk;
	if(a>=b){
		buyuk=a;
		kucuk=b;
	}
	else
	{
		kucuk=a;
		buyuk=b;
	}
	int kucuk1=kucuk;
	int ebob=bulebob(buyuk,kucuk,kucuk1);
	printf("%d ile %d ebobu =%d",a,b,ebob);
}

int bulebob(int buyuk,int kucuk,int kucuk1)
{

	if(buyuk%kucuk!=0||kucuk1%kucuk!=0)
	{
		return bulebob(buyuk,kucuk-1,kucuk1);
	}
	else
	return kucuk;
}

*/


/*
int ebobul(int ,int);
int main()
{
	int n1,n2,ebob;
	printf("iki sayi gir:");
	scanf("%d%d",&n1,&n2);
	
	ebob=ebobul(n1,n2);
	printf("%d ile %d ebobu=%d",n1,n2,ebob);
	
	return 0;
	
	
}

int ebobul(int x,int y)
{
	while(x!=y)
	{
		if(x>y)
		{
			return ebobul(x-y,y);
		}
		else
			return ebobul(x,y-x);
	}
	return x;
}

*/

/*

int sum(int);

int main()
{
	int summ,n;
	printf("enter a number:");
	scanf("%d",&n);
	
	summ=sum(n);
	printf(" sum of the numbers 1 to n is:%d",summ);
	
	return 0;
}

int sum(int num)
{
	if(num>0)
	{
		return (num+sum(num-1));
	}
	else 
	return 0;
}

*/


/*
int toplam(int str[],int x,int y);

int main()
{
	int n;
	printf("diziniz kac elemanli olacaktir?: ");
	scanf("%d",&n);
	int a=n;
	int dizi[n];
	for(n-1;n-1>=0;n--)
	{
		printf("dizinin %d. elemanini giriniz:",n-1);
		scanf("%d",&dizi[n-1]);
	}
	int top=0;
	top=toplam(dizi,a-1,top);
	printf("dizinin elemanlarinin toplami = %d",top);
	
}

int toplam(int str[],int x,int y)
{
	if(x<0)
	{
		return y;
	}
	y+=str[x];
	return toplam(str,x-1,y);
	
}

*/


