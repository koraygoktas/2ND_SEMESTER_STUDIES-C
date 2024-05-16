#include <stdio.h>
#include <stdlib.h>

*hafıza yapısı*
-Bir değişken tanımlandığında arka planda bilgisayarın hafızasında bir konuma yerleştirilir
-hafıza küçük hücrelerden oluşmuş bir blok gibi düşünülebilir
-bir değişken tanımlandığında bellek bloğundan gerekli miktarda hücre ilgili değişkene aktarılır
-hafızada değişken için ne kadar hücre ayrılacağı değişkenin tipine göre değişir

int Veri Tipi : 4 bytetır

float veri tipinde değişkenler bellekte en az 4 byte veya 32 bit yer tutarlar

float ve double arasındaki fark ise double veri tipinin çift duyarlılıklı ve 8 byte veya 64 bit yer kaplamasıdır

long double 10 byte yer kaplar
char 1 byte yer kaplar



buradan işaretli işaretsiz intler charlara falan bakabilirsin
Kaynak: https://ibrahimbayraktar.net/c-programlama-veri-tipleri.html

-bir değişken kullanıldığında hafızada onun için bir yer rezerv edilir
-örneğin int sayi tanımlaması bellekte uygun bir yerde 4 byte alanın sayi değişkeni için ayrılmasını sağlar
-ardından sayi değişkenine bir sayi atadığımızda (örneğin 5) hafıza ,beşi sayi değişkeni için ayırdığı
alana kaydediyor
-değişken dediğimiz , uygun bir bellek alanının,bir isme rezerve edilip kullanılmasından ibarettir
-yani kısaca bu değişkenler belleğin belirli bir adresinde hücre olarak tutulurlar


*pointer tanımlama*
-bir veri bloğunun bellekte bulunduğu adresi içeren (gösteren) veri tipidir
	veri_tipi*p;
-p değişkeni <veri_tipi> ile belirtilen tipte bir verinin bellekte saklandığı adresi içerir
	int*iptr;
	float*fptr;
-dikkat edilmesi gereken tek nokta;pointerı işaret edeceği değişken tipine uygun olarak tanımlamasıdır
-yani int bir değişkeni float bir pointer ile işaretlemeye çalışmak hatadır
-değişkenler bir değer tutar ,pointerlar ise bir adres tutar 

-bir pointerın var olan bir değişkenin bulunduğu adresi göstermesi için değişkenin adresinin pointera 
atanması gerekir.bunun iççin değişkenin hafızada tutulduğu adresin bilinmesi gerekir.bu da adres 
operatörü(&) ile sağlanır

-  &y---> y değişkeninin adresini verir

#include <stdio.h>

int main()
{
	int y=5;
	int *yptr;//burada adres tuttuk 
	yptr=&y;//aynı adresi tutması için yapılan atamadır
	printf("%d\n",y);
	printf("%d\n",&y);//bu ve alt satırdaki adresi(ikisi de aynı) random tutar 
	printf("%d\n",yptr);
	printf("%d\n",*yptr);//yptr adresindeki değeri döndür demek
	
}

-pointer bir değişkenin adresini gösterir şekilde atandıktan sonra o pointer,ilgili değişkeni işaret eder
-eğer bahsettiğimiz değişkenin sahip oldupu değeri pointer ile göstermek veya değişken değerini 
değiştirmek isterseniz , pointer başına '*' getirerek işleminizi yapabilirsiniz 
-pointer başına '*' getirerek yapacağınız her atama işlemi değişkeni de etkileyecektir 
-yukarıdaki kodun sonuna *yptr=10; dersek y nin yeni değeri 10 olacak çünkü bu &y adresindeki değişken
değerine hitap etmektedir

#include <stdio.h>

int main()
{
	int y=5;
	int k;
	int *yptr;
	yptr=&y;
	printf("%d\n",y);
	printf("%d\n",&y);
	printf("%d\n",yptr);
	printf("%d\n",*yptr);
	k=*yptr;
	*yptr=10;//burada yptr aynı zamanda &y adresindeki değerden bahsettiğimizden y de 10 olacaktır 
	printf("%d\n",k);
	printf("%d\n",*yptr);
	printf("%d\n",y);//yukarıda y nin adresindeki sayının artık 10 olduğunu belirttik
	printf("%d\n",*yptr);
}

5
6684176
6684176
5
5
10
10
10
çıktısını alıyoruz
	
	#include <stdio.h>

int main()
{
	int y,x,z;
	int *ptr;
	printf("y degeri giriniz:");
	scanf("%d",&y);
	printf("x degeri giriniz:");
	scanf("%d",&x);
	ptr=&y;
	z=*ptr;
	printf("z'nin ilk degeri:%d\n",*ptr);
	ptr=&x;
	z=*ptr;
	printf("z'nin 2. degeri:%d",*ptr);
}

-bir pointerın tuttuğu adresi değiştirebiliriz fakat bir değişkenin tutuldupu adres değiştirilemezdir

-DİPNOT=eğer z ye herhangi bir atama yapmadna z yi çağırırsak ya sıfır değerini ya da bir garbage(rastgele) 
değeri döndürecektir

-POİNTERLER BELLEKTE 8 BYTELIK BİR YER KAPLIYOR

#include <stdio.h>

int main()
{
	int y;
	int *poin;
	printf("%d\n",sizeof(y));
	printf("%d\n",sizeof(poin));
}
yazarsak mesela 
4
8
çıktısını verecektir

int main()
{
	int y;
	int *poin;
	printf("%d\n",sizeof(y));
	printf("%d\n",sizeof(*poin));
}
yaparsak
4
4
çıktısını verir
int main()
{
	int y;
	int *poin;
	poin=&y;
	printf("%d\n",sizeof(y));
	printf("%d\n",sizeof(poin));
}
yaparsak yine
4
8
sonucunu verceektir

-EĞER İKİ YILDIZ VAR İSE BUNUN ANLAMI POİNTERI TUTAN POİNTERDIR 
mesela:
	
	*k ve **m var.m , k pointerını tutan pointer olarak tasarlayacağız. bunu şu şekilde gösteririz:
	m=&k; 
