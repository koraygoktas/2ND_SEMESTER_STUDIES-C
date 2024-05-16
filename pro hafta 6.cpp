-calloc fonku ile malloc fonku arasındaki fark:mallocta tüm elemanlarınıza yer ayrılırken callocta
garbage değerler arındırılır ona göre bir yer ayrımı olur 

#include <stdio.h>
#include <stdlib.h>


int main()
{
	int *dizi;//dinamik bir dizi oluşturmak için pointerlardan yararlandık
	int eleman_sayisi,i;
	printf("eleman sayisini giriniz:");
	scanf("%d",&eleman_sayisi);
	dizi=(int*)malloc(eleman_sayisi*sizeof(int));//dizimizi istediğimiz boyutta oluşturuyoruz
	//dizi =(int*)calloc(eleman_sayisi,sizeof(int)) şeklinde de olabilirdi
	for(i=0;i<eleman_sayisi;i++)
	{
		printf("adres=%d\tdeger=%d\n",&dizi[i],dizi[i]);
	}
	free(dizi);//hafızadan temizleme
	
	//dizideki elemanları belirlemediğimize göre ya 0 döndürecek ya da garbage değer
	return 0;
}



*FONKSİYON POİNTERLAR*

-pointerlar bir fonkun tutulduğu adresi görüntüleyebilir
-normal pointer gibi fonksiyonun adresini içeren değişken tanıı yapılmalıdır
int (*fptr)(int ,int);
-bu tanımda fptr değişkeni iki tane int tipinde parametre alan ve geriye int tipinde değer döndüren 
bir fonkun adresini içerir
int *fptr (int,int);
-bu tanımda ise iki tane int tipinde parametre alan ve geriye int pointer döndüren bir fonksiyon 
tanımlanmıştır



#include <stdio.h>
#include <stdlib.h>

int kare(int);
int kup(int);


int main()
{
	int (*islem)(int);//bir int değer alıp geriye int değer döndüren fonkun adresi
	int i;
	char c;
	printf("1-kare alani\n2-kup hacmi\n");
	c=getchar();
	printf("bir sayi giriniz");
	scanf("%d",&i);
	if(c=='1')
	{
		islem = kare ;//kare fonkunun adresi islem değişkenine kopyalanır
	}
	else
	{
		islem =kup;//kup fonkunun adresi islem değişkenine kopyalanır
	}
	printf("sonuc=%d",islem(i));
	
	while(getchar()!='\n')
	{
	};
	getchar();
	return 0;
}

int kare(int s)
{
	return s*s;
}
int kup(int s)
{
	return s*s*s;
}


*VOİD POİNTERLAR*
-pointerlar void olara tanımlanabilir
-bu şekilde tanımlanan pointerların gösterdiği adresteki değere erişmek için veri tipi belirtilmelidir



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	void *a;
	a=(char*)malloc(6);
	strcpy((char*)a,"12345");
	printf("%s\n",a);
	free(a);//adresi serbest bıraktık
	a=(double*)malloc(sizeof(double));
	//değere erişirken değişken tipi belirt
	*(double*)a=3.234;
	printf("%f\n",*(double*)a);
	getchar();	
	
	return 0;
	
}






#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
	char giris[50];
	char *p;
	int i=0,k;
	p=giris;
	while(1)
	{
		*(p+i)=getch();
		if(*(p+i)==13)//13= enter tuşunun ascii kodu
		{
			break;
		}
		putchar('*');
		
		i++;
	}
	printf("\n");
	for(k=0;k<i;k++)
	{
		printf("adres[%d]: %d\t",k,p+k);
		putchar(*(p+k));
		printf("\n");
	}
	
	
	return 0;
	
}







#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
	char *p;
	int i=0,k;
	p=(char*)malloc(sizeof(char));
	while(1)
	{
		*(p+i)=getch();
		if(*(p+i)==13)
		{
			break;
		}
		putchar('*');
		i++;
		p=(char*)realloc(p,(i+1)*sizeof(char));//p pointerının tutmuş olduğu yeri (i+1)*1 kadar genişlet
		//ve burada malloc veya calloc kullansaydı sıfırdan yer ayırırdı alanını genişletmek istiyoruz sadece
		// bi de malloc kullansaydık dizi ardışık gitmeyecekti karışacaktı
		//realloc:mesela 3 elemanlı dizi için bakıyor 100 boş 101 boş ama 102 dolu o zaman boş adres arıyor
		//bu 3 eleman için ardışık olacak şekilde gidiyor oraya koyuyor üçünü
	}
	putchar('\n');
	for(k=0;k<i;k++)
	{
		putchar(*(p+k));
		printf("\n");
	}
	return 0;
	
}




#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void swap(int*,int*);
int main()
{
	int a,b,*k,*p;
	printf("a ve b degiskenlerinin degerlerini giriniz:");
	scanf("%d%d",&a,&b);
	swap(&a,&b);
	printf("a'nin degeri=%d\nb'nin degeri=%d",a,b);
	return 0;	
}
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}




#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void rectangle(int,int,int*,int*);
int main()
{
	int kisa,uzun,alan,cevre;
	printf("sirasiyle kisa ve uzun kenari giriniz:");
	scanf("%d%d",&kisa,&uzun);
	rectangle(kisa,uzun,&alan,&cevre);
	printf("kisa kenar=%d\nuzun kenar=%d\nalan=%d\ncevre=%d",kisa,uzun,alan,cevre);
	return 0;	
}
void rectangle(int m,int n,int *area,int *perimeter)
{
	*area=m*n;
	*perimeter=2*(m+n);
}





#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int uzunluk(char*);

int main()
{
	char kelime[100];
	printf("kelimenizi giriniz:");
	gets(kelime);
	printf("kelimenizin uzunlugu=%d",uzunluk(kelime));
	return 0;
}

int uzunluk(char *ptr)
{
	int i=0;
	while(ptr[i]!='\0')//*ptr diyip altta p yi bir arttırabilirdik yanii++ ya gerek kalmazdı
	{
		//++p;
		i++;
	}
	return i;
}