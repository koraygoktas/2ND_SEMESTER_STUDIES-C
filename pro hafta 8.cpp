*SIRALAMA

-bir grup veriyi artan veya azalan şekilde sıralama
en popüler sıralama algoritmaları-->
	-insertion sort(araya ekleme sıralaması)
	-selection sort(seçim sıralaması)
	-bubble sort(kabarcık sıralaması)
	-quick sort(hızlı sıralama)
	
seçim sıralaması=
-eğer bir eleman olması gereken yerde ise bulunduğu sıra drğiştirilmez
-yarı yarıya sıralanmış bir grup veri olması durumunda eleman yeri değişimi azdır
-listedeki ilk elemanı al ve bunu listedeki en küçük elemanın yeri ile değiştir.bu işlemi son elemana
kadar tekrar et 




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sirala(int *dizi,int n)
{
	int i,j;
	int temp;
	for(i=0;i<n-1;i++)//büyükten küçüğe sıralama
	{
		for(j=i+1;j<n;j++)
		{			
			if(dizi[i]<dizi[j])
			{
				temp=dizi[i];
				dizi[i]=dizi[j];
				dizi[j]=temp;
			}
			
		}
			
	
	}
}


int main()
{
  	int str1[30]={4,2,7,9,5,6,1,4,3,8};
  	sirala(str1,10);
  	for(int i=0;i<10;i++)
  	{
  		printf("%d\t",str1[i]);
	  }
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main()
{
  	int dizi[5]={4,2,6,1,3} ;    
  	int i,temp;
  	for(i=0;i<4;i++)
  	{
  		if(dizi[i]>dizi[i+1])
  		{
  			temp=dizi[i];
  			dizi[i]=dizi[i+1];
  			dizi[i+1]=temp;
		  }
	  }
	  for(i=0;i<5;i++)
	  {
	  	printf("%d\t",dizi[i]);
	  }
  	
    return 0;
}



*arama=

-bir dizi içerisinde belirli bir elemanı bulma işlemine arama denir
-iki tür arama tekniği vardır-->
	-doğrusal arama
	-ikili arama 
	
	
	
DOĞRUSAL ARAMA=

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
