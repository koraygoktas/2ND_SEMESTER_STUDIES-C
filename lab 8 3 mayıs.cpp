#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	struct ogrenci{
		char isim[20];
		char soyisim[20];
		float vizenot;
		float finalnot;
		
	};
	
	struct ogrenci *ptr;
	ptr=(struct ogrenci*)malloc(2*sizeof(struct ogrenci));
	
	
	printf("ogrenci bilgilerini giriniz:\n");
	int i;
	for(i=0;i<2;i++)
	{
		printf("%d. ogrencinin ismini giirniz:",i+1);
		scanf("%s",(ptr+i)->isim);
		printf("%d. ogrencinin soyismini giirniz:",i+1);
		scanf("%s",(ptr+i)->soyisim);
		printf("%d. ogrencinin vize notunu giirniz:",i+1);
		scanf("%f",&(ptr+i)->vizenot);
		printf("%d. ogrencinin final notunuz giirniz:",i+1);
		scanf("%f",&(ptr+i)->finalnot);
	}
	
	int gano;
	for(i=0;i<2;i++)
	{
		gano=((ptr+i)->vizenot*40/100)+((ptr+i)->finalnot*60/100);
		printf("%s'in ortalamasi : %d\n",(ptr+i)->isim,gano);
	}
	int j;
	struct ogrenci temp;
	for(j=0;j<2;j++)
	{
		for(i=0;i<1-j;i++)
		{
			if(strcmp((ptr+i)->isim,(ptr+i+1)->isim)>0)
			{
				strcpy(temp.isim,(ptr+i)->isim);
				strcpy((ptr+i)->isim,(ptr+i+1)->isim);
				strcpy((ptr+i+1)->isim,temp.isim);
			}
		}
	}
	printf("siralandiktan sonra isimler:\n");
	for(i=0;i<2;i++)
	{
		printf("%d. ogrenci:%s\t",i+1,(ptr+i)->isim);
	}
	
}