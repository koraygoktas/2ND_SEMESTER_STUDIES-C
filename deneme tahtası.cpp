#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	struct dogum{
		int day;
		int month;
		int year;
	};
	
	struct bilgiler{
		char name[20];
		int length;
		struct dogum tarih;
	};
	struct bilgiler kisi[3]={"ali",170,{12,03,1999},
							 "veli",190,{11,11,1997},
							 "koray",180,{02,04,2004}	
	};
	
	for(i=0;i<3;i++)
	{
		printf("kayit no=%d\n",i+1);
		printf("name=%s\n",kisi[i].name);
		printf("boyu=%d\n",kisi[i].length);
		printf("tarih=%d/%d/%d",kisi[i].tarih.day,
							    kisi[i].tarih.month,
								kisi[i].tarih.year);
		printf("\n\n");
	}
	return 0;
}
