N SAYISINA KADAR YAZDIRAN REKÜSRSİF

#include <stdio.h>
#include <stdlib.h>
//birden n sayisina kadar tüm değerleri yazdıran rekürsif fonk 
int f(int n)
{
	if(n==0)
	{
		return 0;
	}
	f(n-1);
	printf("%d\n",n);
	
}
int main()
{
	int sayi =5;
	f(sayi);
	return 0;

}


N SAYISINA KADAR TOPLAYAN REKÜRSİF FONK

#include <stdio.h>

int toplam(int sayi)
{
	if(sayi==1)
	{
		return sayi;
	}
	else
	{
		return (sayi+toplam(sayi-1));
	}
}

int main()
{
	int a=5;
	printf("sum of numbers one to five=%d",toplam(a));
	return 0;
}


REKÜRSİF ÇARPIM TABLOSU

	#include <stdio.h>

int tablo(int x)
{
	int i;
	if(x<=5)
	{
		for(i=1;i<6;i++)
		{
			printf("%-3d",x*i);
		}
		printf("\n");
		return tablo(x+1);
	}
	else return 1;
}

int main(void)
{
	int x=1;
	tablo(x);
	return 0;
}


N SAYISINA KADAR FAKTÖRİYEL ALAN REKÜRSİF

	#include <stdio.h>

long faktor(long sayi)
{
	if(sayi<=1)
	return 1;
	
	else
	return (sayi*faktor(sayi-1));
}


int main()
{
	
	int i;
	for(i=0;i<=10;i++)
	{
		printf("%d!=%d\n",i,faktor(i));
	}
	
	return 0;
}
	
	
	EBOB BULMA REKÜRSİF İLE
	
#include <stdio.h>
#include <stdlib.h>


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


DİZİNİN ELEMANLARINI REKÜRSİF İLE TOPLAMA

#include <stdio.h>
#include <stdlib.h>
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

DİZİNİN EN BÜYÜK ELEMANINI BULDURAN PROGRAM REKÜRSİF İLE

#include <stdio.h>
#include <stslib.h>
int func(int a[],int n)
{
	int x;
	if(n==1)
	{
		return a[0];
	}
	else 
	{
		x=func(a,n-1);
	}
	if(x>a[n-1])
	{
		return x;
	}
	else
	{
		return a[n-1];
	}
}

int main()
{
	int arr[]={12,33,2,67,2};
	printf("%d",func(arr,5));
	getchar();
	return 0;
}



REKÜRSİF İLE DİZİNİN ELEMANLARININ TOPLAMI

#include <stdio.h>
#include <stslib.h>
int func(int dizi[],int n);

int main()
{
	int n=5;
	int dizi[5]={3,7,3,2,1};
	int toplam=func(dizi,n-1);
	printf("toplam=%d",toplam);
	
	
	return 0;
}

int func(int dizi[],int n)
{
	if(n==0)
	{
		return dizi[0];
	}
	return (dizi[n]+func(dizi,n-1));
}



POİNTER ÇALIŞMASI

#include <stdio.h>

int main()
{
   double *m,**k,array[5]={10.3,4.2,2.7,9.0,6.1};
   m=array;//diziyi tuttu başlangıç değerleri falan her şey aynı
   printf("%.lf\n",*(m+1));//4.2 çıktı
   *(m+3)+= 3.5;//9.0+3.5=12.5 oldu artık 3.indis dizi için de geçerli pointer için de sonuçta ikisinin adresi aynı
   m+=2;//m'nin başlangıç değerini artık 0. inditteki 10.3 değil de 2.indisteki 2.7 yaptık yani m nin 0. indisi artık 2.7
   printf("%.lf\n",*(m+1));//12.5 çıktı
   m=&array[3];//m için baş indisi dizinin 3. indisi yaptık yani m şu an array[3]'te oranın adresini tutuyor
   k=&m;//k ise m'nin tuttuğu adresi tutuyor
   printf("%.lf\n",*(*(k)-1));//bu ifade aslında şöyle de ayzılabilir= *(m-1) çünkü k adresinde tutulan değer m dir.
   printf("%p\n",*k);//m bellek adresini döndürecektir 012FFA78 olsun değeri
   m=m-1;//m'nin adresini double olduğu için 1*8 kadar azalttık ve m şu an dizinin 2. indisinde orayı tutuyor. 
   printf("%p",m);//012FFA70 döner
   //**k, m nin içindeki değeri döndürür. *k ise m yi döndürür yani adresi
   //oluşturulan k farklı bir blok üzerinde tutuluyor ve değeri m oluyor
   //istersen m ve k yı yani adresleri çağır,göreceksin ki arasında bir bağlantı yok
    return 0;
}



POİNTER MANTIĞI

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


int main()
{
 int x=5,*ptrx,int y=6;
 ptrx=&x;
 (ptrx+1)=&y
 printf("ptrx nin adresi =%d\n",ptrx);//6684180
 *++ptrx;
 printf("ptrx nin degeri =%d\n",*ptrx);//6684184
 printf("ptrx nin adresi =%d\n",ptrx);//6684184
 *ptrx++;
 printf("ptrx nin degeri =%d\n",*ptrx);//0
 printf("ptrx nin adresi =%d\n",ptrx);//6684188
 printf("%d",x);//5
    return 0;
}

POİNTER DİZİ MANTIĞI

#include <stdio.h>

int main()
{
int elm,*ptr;
int month[12];
ptr=month;//month[0]'ın adresini ptr'ye ata
elm=ptr[3];//elm=month[3]
ptr=month+3;//ptr month [3] adresini göstersin alttakiyle aynı
ptr=&month[3];//ptr month [3] adresini göstersin
elm=(ptr+2)[2];//elm=ptr[4] === month[7]
elm=*(month+3);
ptr=month;//month[0]'ın adresini ptr'ye ata
elm=*(ptr+2);//elm = month[2]
elm=*(month+1);//elm = month[1]
}




POİNTER DİZİ MANTIĞI

#include <stdio.h>

int main()
{
	int d[10],j;
	int *ptr;
	for(j=0;j<10;j++)
		d[j]=j;
	
	ptr=d;
	 for(j=0;j<10;j++)
	 {
	 	printf("\n%d",*ptr);
	 	ptr++;//yani burada ilk olarak bi kere arttırılmasıyla d[1] gösterdiğini söylüyor daha sonra d[2] öylece her arttırıldığında bu şekilde gidiyor 
	 }
	 //ptr artık dizinin başını göstermez
	printf("\n%d",*(ptr-1));
	ptr=d;
	for(j=0;j<10;j++)
		printf("\n%d",*(ptr+j));
	//ptr hala dizinin başını gösterir
	printf("\n%d",*ptr);
	
	return 0;
}



DİZİ TUTAN POİNTER MANTIĞI


#include <stdio.h>

int main()
{
int i,j;
char * ilkbahar[3]={"mart","nisan","mayis"};
char * yaz[3]={"haziran","temmuz","agustos"};
char * sonbahar[3]={"eylul","ekim","kasim"};
char * kis[3]={"aralik","ocak","subat"};

char ** table[4];// char pointer (string) tutan dizileri tutan dizi 
table[0]=ilkbahar;
table[1]=yaz;
table[2]=sonbahar;
table[3]=kis;

for(i=0;i<4;i++)
{
	for(j=0;j<3;j++)
	{
		printf("%s\n",table[i][j]);
	}
}

	return 0;
}


DİZİDEKİ DEĞERLERİ DEĞİŞTİRMEYE YARAYAN FONKLU POİNTER

#include <stdio.h>
#include <stdlib.h>
void fonk(int *a)
 {
 	*a=4;
 }

int main()
{
	int a=2;
	int *p;
	p=&a;
	printf("%d",a);
	fonk(p);
	printf("\n%d",a);

	return 0;
}



DİZİDEKİ DEĞERLERİ DEĞİŞTİRMEYE YARAYAN FONKLU POİNTER

#include <stdio.h>
#include <stdlib.h>
void fonk(int *a,int n)
 {
 	int i;
 	for(i=0;i<n;i++)
 	{
 		*(a+i)+=1;
	}
 }

int main()
{
	int i,dizi[5]={1,2,3,4,5},n=5,*p;
	for(i=0;i<n;i++)
	{
		printf("%d\n",dizi[i]);
	}
	p=dizi;
	fonk(p,n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",dizi[i]);
	}
	return 0;
}



DEĞİŞKENİ FONK İÇERİSİNDE POİNTER İLE DEĞİŞTİRME

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





POİNTER BİLGİSİ

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


DİZİ POİNTER MANTIĞI

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


RASTGELE SAYI SEÇTİRMELİ DİZİ POİNTER SORUSU

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


POİNTER İLE DİZİYİ TERSTEN YAZDIRMA


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


KELİME İÇİNDE HANGİ HARFTEN KAÇ TANE OLDUĞUNU BULMA

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


MALLOC KULLANIMI

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>



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




POİNTERI FONK ADRESİNE EŞİTLEME

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



POİNTERI VOİD OLARAK TANIMLAMA

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



POİNTER DİZİ MANTIĞI İSTENİLEN TUŞA BASILANA KADAR ŞU KARAKTERİ YAZDIR SORUSU

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



ÜSTTEKİ SORU TARZININ REALLOCLUSU VE BOŞUNA BELLEKTE YER KAPLAMAMIŞ HALİ

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


POİNTER İLE TUTULAN DEĞERLERİ FONKA GÖNDERİP YER DEĞİŞTİRME

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void swap(int*,int*);
int main()
{
	int a,b;
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

POİNTER MANTIĞI

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



POİNTER İLE DİZİNİN EN BÜYÜK ELEMANINI BULAN PROGRAM

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



CUMLEDEKİ KELİMELERİ SIRASINA GORE TERSTEN YAZDIRAN PROGRAM

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



REALLOC İLE DİZİYE YENİ ELEMANLAR EKLEME


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


DİZİLERİ POİNTER İLE BİRLEŞTİRME SORUSU


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>



int main()
{
	int a,b;
	printf("ilk diziniz kac elemanli olacak?\n=");
	scanf("%d",&a);
	printf("ikinci diziniz kac elemanli olacak?\n=");
	scanf("%d",&b);
	int i;
	int *dizi1,*dizi2;
	dizi1=(int*)malloc(a*sizeof(int));
	dizi2=(int*)malloc(b*sizeof(int));
	printf("1. dizinin elemanlarini giriniz:");
	for(i=0;i<a;i++)
	{
		scanf("%d",&dizi1[i]);
	}
	printf("2. dizinin elemanlarini giriniz:");
	for(i=0;i<b;i++)
	{
		scanf("%d",&dizi2[i]);
	}
	dizi1=(int*)realloc(dizi1,(a+b)*sizeof(int));
	int k=0;
	for(i=a;i<a+b;i++)
	{
		dizi1[i]=dizi2[k];
		k++;
	}
	for(i=0;i<a+b;i++)
	{
		printf("yeni dizinin %d. elemani = %d\n",i,dizi1[i]);
	}
	
	free(dizi1);
	free(dizi2);
	
	return 0;
	
}


POİNTER İLE DİZİNİN EN BUYUK VE EN KUCUK ELEMANLARINI BULMAK

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


void enler(int*,int,int*,int*);
int main()
{
	int enb,enk;
	int *dizi;
	int n;
	
	printf("diziniz kac elemanli olacak?\t=");
	scanf("%d",&n);
	int i;
	dizi=(int*)malloc(n*sizeof(int));
	printf("dizinin elemanlarini giriniz:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&dizi[i]);
	}
	enler(dizi,n,&enb,&enk);
	printf("dizinin en buyuk sayisi=%d\ndizinin en kucuk sayisi=%d",enb,enk);
	
	return 0;
	
}
	void enler(int *array,int n,int *enb,int *enk)
	{
		int i;
		*enb=array[0];
		*enk=array[0];
		for(i=1;i<n;i++)
		{
			if(array[i]<*enk)
			*enk=array[i];
			if(array[i]>*enb)
			*enb=array[i];
		}
	}
	
	
	
	REKÜRSİF İLE DİZİDEKİ EN BÜYÜK VE EN KÜÇÜK SAYILARI BULMA
	
	#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>



int array(int*,int);
int fonk(int*,int);
int main()
{
	int dizi[5]={4,2,8,1,6};
	int enb,enk;
	int n=5;
	enb=array(dizi,n);	
	enk=fonk(dizi,n);
	printf("dizinin en kucuk elemani=%d\nen buyuk elemani ise=%d",enk,enb);
	return 0;
}

int array(int *ptr,int n)
{
	int enb;
	if(n==1)
		return ptr[0];
	
	else
	{
		enb=array(ptr,n-1);
	}
	if(enb>ptr[n-1])
		return enb;
	else
		return ptr[n-1];
}
int fonk(int *ptr,int n)
{
	int enk;
	if(n==1)
		return ptr[0];
	else
		enk=fonk(ptr,n-1);
	
	if(enk<ptr[n-1])
		return enk;
	else
		return ptr[n-1];
}


RANDOM SAYI ALMA

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
	
	
	
	DİNAMİK BELLEK İLE POİNTER BOYUTUNU GENİŞLETME
	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	printf("dizi boyutu giirniz:");
	scanf("%d",&n);
	char *ptr;
	ptr=(char*)malloc(n*sizeof(char));
	int i;
	printf("dizi elemanlarini giriniz:");
	for(i=0;i<n;i++)
	{
		scanf(" %c",(ptr+i));
	}
	ptr=(char*)realloc(ptr,(n+2)*sizeof(char));
	printf("simdi ek karakterleri giriniz:");
	for(i;i<n+2;i++)
	{
		scanf(" %c",(ptr+i));
	}
	for(i=0;i<n+2;i++)
	{
		printf("%c",*(ptr+i));
	}
	
	free(ptr);
	
	
	return 0;
}


POİNTER BİR KELİMEYİ BELLEK BOYUTUNU ARTTIRIP SIĞDIĞI KADAR ARDI SIRA YAZMAK

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int i,n;
	char *isim;
	printf("adiniz kac harften olusmaktadir?\t:");
	scanf("%d",&n);

	isim=(char*)malloc((n+1)*sizeof(char));

	printf("isminizin karakterlerini girer misiniz?\t:");
	for(i=0;i<n;i++)
	{
		scanf(" %c",(isim+i));
	}
	unsigned int ogrno=2210238019;
	int toplam=0;
	while(ogrno!=0)
	{
		toplam+=ogrno%10;
		ogrno/=10;
	}
	isim = (char*)realloc(isim, (n + toplam+1) * sizeof(char));

	for(i=0;i<toplam;i++)
	{
		isim[i+n]=isim[i];
	}
	for(i=0;i<toplam+n;i++)
	{
		printf("%c",isim[i]);
	}
	
	
	return 0;
}




DİNAMİK BELLEK İLE POİNTER BOYUTUNU GENİŞLETME

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n;
	printf("dizi boyutu giirniz:");
	scanf("%d",&n);
	char *ptr;
	ptr=(char*)malloc(n*sizeof(char));
	int i;
	printf("dizi elemanlarini giriniz:");
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		scanf("%c",(ptr+i));
	}
	ptr=(char*)realloc(ptr,(n+2)*sizeof(char));
	printf("simdi ek karakterleri giriniz:");
	for(i;i<n+2;i++)
	{
		fflush(stdin);
		scanf("%c",(ptr+i));
	}
	for(i=0;i<n+2;i++)
	{
		printf("%c",*(ptr+i));
	}
	
	return 0;
}
