#include<stdio.h>


/*
void fun(int x)
{
	if(x>0)
	{
		fun(--x);
		printf("%d\t",x);
		fun(--x);
		
	}
}



int main()
{
	int a =4;
	fun(a);
	return 0;
}

*/

/*

int bin(int num)
{
	if(num==0)
	{
		return 0;
	}
	else
	{
		return num%2 + 10*bin(num/2);
	}
}

int main()
{
	int num=10;
	printf("sayinin binary karsiligi=%d",bin(num));
	return 0;
}

*/


/*
#include <string.h>

void fonk(char dizi[], int x)
{
    if (dizi[x] == dizi[strlen(dizi) - 1 - x])
    {
        if (x != 0)
            fonk(dizi, --x);
        else
            printf("Girilen kelime palindromdur.");
    }
    else
    {
        printf("Kelimeniz palindrom degildir.");
    }
}

int main()
{
    char kelime[20];
    printf("Kelime giriniz: ");
    fgets(kelime, 20, stdin);
    kelime[strcspn(kelime, "\n")] = '\0'; // fgets() sonrası gelen newline karakterini temizle(boş)
    int n = strlen(kelime);
    fonk(kelime, n - 1);
    return 0;
}

*/

/*

int pal(int num);
int ters(int num);

int main()
{
	int num;
	printf("bir sayi giriniz:");
	scanf("%d",&num);
	if(pal(num)==1)
	{
		printf("girilen sayi palindromdur");
	}
	else
	{
		printf("girilen sayi palindrom degildir");
	}
	return 0;
}

int pal(int num)
{
	if(num==ters(num))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int ters(int num)
{
	int rem;
	static int sum=0;
	
	if(num!=0)
	{
		rem =num%10;
		sum=sum*10+rem;
		ters(num/10);
		
	}
	
	else
	{
			return sum;
	}
}

*/

#include <string.h>
#include <math.h>

int ort(int dizi[],int n);
int main()
{
	int dizi[]={2,1,3,5,4};
	int n=5;
	double ortalama=ort(dizi,n-1)/n;
	printf("dizinin elemanlarinin ortalamasi=%.2lf",ortalama);
	return 0;
}

int ort(int dizi[],int n)
{
	
	if(n>=0)
	{
		return dizi[n]+ort(dizi,n-1);
	}
	else
	{
		return 0;
	}
}
