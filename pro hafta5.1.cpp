
#include <stdio.h>
#include <stdlib.h>
void ptr(int *y);

int main()
{
	int x=7;
	ptr(&x);
	printf("%d",x);
	
}

void ptr(int *y)
{
	*y=*y+5;
}




#include <stdio.h>
#include <stdlib.h>

void ptr(int *y);

int main()
{
	int x=7,*isa=&x;
	printf("%d\n",isa);
	ptr(++isa);
	printf("%d",isa);
}//bu şekil olunca 6684180 6684184 6684184 sonucunu veriyor 
// ama isa++ olsaydı o zaman 664180 7 6684184 sonucunu verirdi

void ptr(int *y)
{
	printf("%d\n",*y);
}




#include <stdio.h>
#include <stdlib.h>



int main()
{
	//pointer dizilerinin boyutu 8'dir o yüzden 8*10=80
	//ister int ister double ister float isterse char tipinde olsun pointer dizi ise her türlü boyutu 8
	char *a[10]={"hi","hello","how"};
	printf("%d",sizeof(a));//80
	printf("%d",sizeof(*a));//8
	
}




#include <stdio.h>
#include <stdlib.h>

int fonk(int **m)
{
	int b=10;
	*m=&b;
	printf("%d",**m);
}

int main()
{
	int a=5,*p=&a;
	fonk(&p);
	printf("\n%d",*p);
	printf("\n%d",a);
	return 0;
}



#include <stdio.h>
#include <stdlib.h>

void swap(int *p,int *o,int *m)
{
	int temp;
	temp=*p;
	*p=*o;
	*o=*m;
	*m=temp;
}

int main()
{
	int a=2,b=4,c=6;
	printf("%d%d%d\n",a,b,c);
	swap(&a,&b,&c);
	printf("%d%d%d",a,b,c);
	return 0;
}




#include <stdio.h>
#include <stdlib.h>



int main()
{
	int i;
	int dizi[5];
	//diziler de bir pointer gibi kullanılabilir
	printf("elemanlari giriniz:\n");
	for(i=0;i<5;i++)
	{
		scanf("%d",dizi+i);
	}
	for(i=0;i<5;i++)
	{
		printf("%d\t",*(dizi+i));
	}
	return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int *rastgele()
	{
		static int  randm[10];
		int i;
		srand((unsigned)time(NULL));
		for(i=0;i<10;i++)
		{
			randm[i]=rand();
			printf("%d\t",randm[i]);
		}
		printf("\n");
		return randm;
		
	}

int main()
{
	int *p,i;
	p=rastgele();
	for(i=0;i<10;i++)
	{
		printf("%d\t",*(p+i));
	}
	return 0;
}
*/




#include <stdio.h>
#include <stdlib.h>


void tersten(int *p,int n)
{
	int a=n/2;
	int temp,i=0;
	n-=1;
	for(a;a>0;a--,i++,n--)
	{
		temp=*(p+i);
		*(p+i)=*(p+n);
		*(p+n)=temp;
	}
	
}

int main()
{
	int i;
	int dizi[5]={2,5,1,3,4};
	tersten(dizi,5);
	for(i=0;i<5;i++)
	{
		printf("%d\t",dizi[i]);
	}
	return 0;
}





#include <stdio.h>
#include <stdlib.h>


int main()
{
	int i,j,a,sayac=0;
	char kelime[20];
	printf("kelime giriniz:");
	gets(kelime);
	for(i=65;i<91;i++)
	{
		for(j=0;j<20;j++)
		{
			if(kelime[j]==i)
			{
				sayac+=1;
			}
		}
		if(sayac!=0)
		{
			printf("%c harfinden:%d adet\n",i,sayac);
		}
		sayac=0;
	}
	
	return 0;
}
