C PROGRAMLARININ BELLEK DÜZENİ VE REKÜRSİF (ÖZYİNELEMELİ) FOKNLAR


SAKLAMA SINIFI/saklama yeri/başlangıç değeri/kapsam/yaşam döngüsü/
--------------/
auto----------/stack segment/anlamsız veri(garbage)/block/bloğu bitene kadar
extern--------/data segment/sıfır/global/programın başından sonuna kadar
static--------/data segment/sıfır/block/programın başından sonuna kadar
register------/cpu yazmaçları/anlamsız veri(garbage)/bloğu bitene kadar

*C PROGRAMLARININ BELLEK DÜZENİ*
1.METİN SEGMENTİ=progrmaın derlenmiş ikili sayı sistemindeki kodları içerir
2.İLK DEĞER VERİLMİŞ VERİ SEGMENTİ=ilk değer atanmış global ve statik değişkenleri içerir
3.İLK DEĞER VERİLMEMİŞ VERİ SEGMENTİ=ilk değer atanmamış global ve statik değişkenleri içerir
4.YIĞIN SEGMENTİ(STACK)=fonkların lokal değişkenleri ,fonklara geçirilen parametreler ve fonk dönüş adresi
5.ÖBEK SEGMENTİ(HEAP)=malloc() ve relloc() fonklaır ile ayrılır,free() fonkları ile boşaltılır


metin segment=derlenen programın makine kodunu tutar
-bir programın bir nesne dosyasındaki veya bellekteki yürütülebilir komutları içeren bölümlerinden biridir

yığın (stack) segment=bir fonk çağırlıdığında kaydedilen bilgilerle birlikte otomatik değişkenlerin saklandığı yerdir
-bir fonk her çağırıldığında geri dönülecek yerin adresi ve arayanın ortamı ile ilgili bazı makine kayıtları gibi
bazı bilgiler yığında saklanır
-yeni çağırılan fonk daha sonra otomatik ve geçici değişkenleri için yığında yer alır.Bu özellik rekürsif fonkların
çalışmasını sağlar

öbek (heap) segment=dinamik bellek ayırma işleminin genellikle gerçekleştiği bölümdür
-öbek alan malloc,realloc ve free tarafından yönetilir


*GENİŞ PROGRAMLAR OLUŞTURMA*

-büyük programlar genelde farklı klasörlerde bulunan .h uzantılı header dosyaları ve .c uzantılı dosyalardan oluşur
-preprocessor programı #include <"dosya adı"> direktifini aldığında bu dosyayı aynı klasörde veya sistemde
tanımlı yerlerde arar 
-bulunmaz ise hata mesajı verilir derleme durdurulur.
- .h uzantılı dosyalarda #include ,#define direktifleri,struct yapıları ,fonk prototipleri bulunabilir



*ÖZYİNELEME (REKÜRSİF) FONKLAR*
-kendi kendini çağıran fonklardır
-eğer fonk temel durum ile çağırılırsa bir sonuç döndürür
-eğer fonk daha karmaşık bir problem ile çağırılırsa,fonk problemi iki temel parçaya böler:
	1.fonkun işi nasıl yapacağını bildiği kısım
	2.fonkun işi nasıl yapacağını bilmediği kısım:
		-2.kısım orijinal fonka benzemelidir
		-fonkun bilmediği kısmı çözebilmek için kendisinin bir kopyasını çalıştırır
-sonunda temel durum çözülür




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


-fonk bitince çağırıldığı fonka gidiyor taaa en son maine gelip sonlanana kadar


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

üstteki örnekte döngü tablosu şudur:
	
	çağıran fonk/çağrılan fonk/dönen değer
	------------------------------------------------
	main		/	toplam(5)	/	(5+toplam(4))
	toplam(5)	/	toplam(4)	/	(4+toplam(3))
	toplam(4)	/	toplam(3)	/	(3+toplam(2))
	toplam(3)	/	toplam(2)	/	(2+toplam(1))
	toplam(2)	/	toplam(1)	/			1
	
	sonda return sayi ile toplam(1)=1 olarak bulduk ve bunu oraya gelene kadarki fonk sonuçlarının yerlerine koyup 
	sonucu bulabiliriz
	
	
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


döngü tablosu şu şekildedir:
	
	
	çağrılan fonk/fonkun çağrıldığı yer/dönen değer
	------------------------------------------------
	tablo(1)	/	main		/	1
	tablo(2)	/	tablo(1)	/	1
	tablo(3)	/	tablo(2)	/	1
	tablo(4)	/	tablo(3)	/	1
	tablo(5)	/	tablo(4)	/	1
	tablo(6)	/	tablo(5)	/	1
	
	sonda fonksiyon geriye döndü ve ilk istenen değer yani tablo(1) de 1 dönüp sonlanmıştır
	
	
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
	
	
	
	0 dan 11 e kadra sayilarin faktoriyellerini bulan program
	
	
	
	
	



