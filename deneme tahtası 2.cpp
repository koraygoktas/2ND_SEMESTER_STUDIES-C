#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arama(int *str,int aranan,int index)
{
	int i;
	for(i=0;i<index;i++)
	{
		if(str[i]==aranan)
		{
			return i;
			break;
		}
	}
}


int main()
{
  	int dizi[5]={4,2,6,1,3} ;    
  	int aranan;
  	int n=5;
  	printf("aradiginiz sayiyi giriniz:");
  	scanf("%d",&aranan);
  	printf("aradiginiz sayi %d. indistedir.",arama(dizi,aranan,n));
    return 0;
}
