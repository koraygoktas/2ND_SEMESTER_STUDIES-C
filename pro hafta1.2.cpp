#include <stdio.h>
#include <stdlib.h>
/*
int x=5;

int main()
{
	//int x=45; yazmış olsaydık sonda printf("x=%d",x) girdisine x=45 çıktısı verirdi
	{
		int x=10,y=12;
		{
			printf("x=%d y=%d\n",x,y);
			{
				int y=40;
				x++;
				y++;
				printf("x=%d y=%d\n",x,y);
			}
			printf("x=%d y=%d\n",x,y);
		}
		
	}
	printf("x=%d",x);
	return 0;
}
*/



void fonk(void);
void sta_fonk(void);

int main()
{
	fonk();
	sta_fonk();
	
	printf("\n");
	
	fonk();
	sta_fonk();
}

void fonk()
{
	int id =1;
	printf("id=%d\t",id);
	id+=21;
	printf("id=%d\n",id);
}

void sta_fonk()
{
	//static yer belirtecinde değer sıfırlanmaz son olarak nasıl kaldıysa öyle kalır yani 22 den devam eder
	static int id=1;
	printf("id=%d\t",id);
	id+=21;
	printf("id=%d\n",id);
}

-----------------------
int main()
{
	int i=5;
	for(i;i>0;i--)
	{
		static int j=5;
		
		printf("%d\t",j--);
	}
	
	return 0;
}
*/

