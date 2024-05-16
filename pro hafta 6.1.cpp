#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int *ptr=(int*)malloc(5*sizeof(int));
	for(i=0;i<5;i++)
	{							// 0  1  2  3  4					
		*(ptr+i)=i;             //[0][1][2][3][4]
	}
	printf("%d\n",ptr);
	printf("%d\n",*ptr++);//0//önce değer yaz sonra blok noyu arttır yani ptr bir sonraki bloğu işaret etsin
	printf("%d\n",ptr);
	printf("%d\n",(*ptr)++);//1//önce değeri yaz sonra değeri bir arttır.Bu satırdan sonra *ptr=2 dir
	printf("%d\n",ptr);
	printf("%d\n",*ptr);//2
	printf("%d\n",ptr);
	printf("%d\n",*++ptr);//2//önce bloğu arttır sonra vardığın bloğun içerisindeki değeri yaz
	printf("%d\n",ptr);
	printf("%d\n",++*ptr);//3//önce bulunduğun bloktaki değeri arttır sonra yaz
	printf("%d\n",ptr);
	return 0;
}





#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
	int boyut;
	printf("dizinin boyutunu giriniz:");
	scanf("%d",&boyut);
	int i;
	int *arr=(int*)malloc(boyut*sizeof(int));
	printf("dizinin elemanlarini giriniz:\n");
	
	for(i=0;i<boyut;i++)
	{
		scanf("%d",&arr[i]);
	}
	int max=arr[0];//*arr
	for(i=1;i<boyut;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	printf("dizinin en buyuk sayisi = %d",max);
	free(arr);//diziyi bellekten çıkardık 
	return 0;
}





#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char kelime[100];
	printf("kelimenizi giriniz:");
	gets(kelime);
	int i,uzunluk=strlen(kelime);
	char *ptr;
	ptr=&kelime[uzunluk-1];
	printf("kelimenizin tersi=");
	for(i=uzunluk-1;i>=0;i--)
	{
		printf("%c",*ptr);
		ptr--;
	}
	return 0;
}






#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char cumle[100];
	printf("cumle giriniz:");
	gets(cumle);
	int length=strlen(cumle);
	int i;
	for(i=length-1;i>=0;i--)    
	{
		if(cumle[i]==' ')
		{
			cumle[i]='\0';
			printf("%s ",&(cumle[i])+1);
		}
	}
	printf("%s",cumle);
	
	return 0;
}





#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int *ptr;
	int eleman;
	printf("eleman sayisini giriniz:");
	scanf("%d",&eleman);
	ptr=(int*)malloc(sizeof(int)*eleman);
	printf("dizinin elemanlarini giriniz:\n");
	int i;
	for(i=0;i<eleman;i++)
	{
		scanf("%d",&ptr[i]);
	}
	int eleman2;
	printf("kac eleman eklemek istiyorsunuz?");
	scanf("%d",&eleman2);
	int sonuc=eleman+eleman2;
	ptr=(int*)realloc(ptr,sonuc*sizeof(int));
	for(;i<sonuc;i++)
	{
		scanf("%d",&ptr[i]);
	}
	for(i=0;i<sonuc;i++)
	{
		printf("%d\n",ptr[i]);
	}
	return 0;
}