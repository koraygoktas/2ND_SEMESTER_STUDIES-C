görülecek konular-->
-reküfsif fonklar
-işaretçiler(pointerlar)(değer yolula çağırma,referans yoluyla çağırma,dinamik bellek yöntemi)
-struct,enum ve typdef tanımlamaları
-tek bağlı doğrusal listeler
-sıralama ve arama algoritması
-string ve matematikselfonklar
-sıralı ve rastgele erişimli dosyalar

*NESNE FAALİYET ALANLARI*
-faaliyet alanı(scope)=bir nesnenin tanınabildiği program aralığı

--nesne faaliyet alanı ,program içerisinde tanımlandığı yer ile ilgili

1-blok faaliyet alanı(block scope)=yalnızca bir blok içerisinde tanınma
2-fonk faa. al.(function scope)= yalnızca bir fonk içeriisnde tanınma
3-dosya faa.al.(file scope)=tüm dosya içinde yani fonkların tümünde tanınma

--değişkenler faaliyet alanlarına göre 3 kısımda incelenir:
	-yerel değişkenler
	-global değ.
	-parametre değ.

NOT:iki değişkenin aynı faaliyet alanı grubuna ait oluyor olması(blok ,fonk veya dosya)fonk alanlarının tamamen
aynı olduğu anlamına gelmez.

-YEREL DEĞİŞKENLER=yerel değişkenler blok faaliyet alanına uyar . sadece tanımlandıkları blok içerisinde geçerlidirler

{
	int a;
	{
		int b;
	}
}

b değişkeninin faaliyet alanı hemen üstündeki ve altındaki süslü parantezlerin içidir.a nınki de a nın hemen
üstündeki ve altındaki süslü parantezlerin içidir.mesela b nin tanımlı olduğu parantezin dışında b ile ilgili bir 
işlem yapmaya kalkışırsak derleyici hata verir çünkü biz b yi sadece o blok içersinde tanımlamışız.
ama mesela a için b nin tanımlandığı iç blok içersinde de işlem yapabiliriz bir problem olmaz


--farklı faaliyet alanına sahip aynı isimli değişkenler kullanılabilir

{
	int a=10
	{
		int a=20;
	}
	printf("%d",a);
}
dediğimizde bize 10 çıktısını verecektir
--derleyici bu değişkenleri fakrlı adreslerde tutar

-GLOBAL DEĞİŞKENLER=bütün blokların dışında tanımlanmış değişkenlerdir
-global değişkenler dosya faaliyet alanı kuralına uyar
-global değişkene ilk değer verilebilir
-aynı isimli global ve yerel değişkenin tanınabilir olduğu blokta ancak yerel değişkene erişilebilir

-kütüphaneler-
int a=3;
int main(){
	printf("%d",a);
}
dediğimizde 3 çıkar. a burada global değişkendir her yerde kullanabiliriz.eğer değer atanmazsa default değer
olarak sıfır döndürecektir

-kütüphaneler-
int a=5;

void fonk1(void)
{
	printf("%d\t",a);
}
int main()
{
	int a;
	a=10;
	fonk1();
	printf("%d",a);
}
yaparsan çıktı olarak 5	10 döndürecektir bunun sebebi ise main fonkun içinde global olarak atadığımız a değişkeninden
farklı bir a değişkeni atadık bundan kaynaklı main içinde atanan a ile işlem yaptı ama üstte oluşturduğumuz fonk1'e 
gidince global a ile işlem yaptı çünkü fonk1'in içinde herhangi bir a değişkeni atamadık

-PARAMETRE DEĞİŞKENLERİ=fonksiyon paramtereleridir
-fonk faaliyet alanı kurallarına uyarlar
-sadece paramteresi oldukları fonk içerisinde geçerlidirler

#include <stdio.h>
#include <stdlib.h>

int a=5;

void fonk1(int a/*bura paramtere değişkenidir ve altta atanan a burada tanımlanan parametre değişkenidir*/)
{
	a=20;
	printf("%d\t",a);
}
int main()
{
	printf("%d\t",a);
	fonk1(a);
	printf("%d",a);
}

5	20	5 çıktısını verir

*NESNE ÖMRÜ*=nesnelerin faaliyet gösterdiği zaman aralığını tanımlar
-nesneler dinamik ve statik ömürlü olmak üzere ikiye ayrılır
-STATİK ÖMÜRLÜ NESNE:
	-program bitene kadar faaliyet gösterir
	-hafızada DATA SEGMENT kısmında tutulurlar
	- 1-global değişkenler 2-stringler 3-statik yerel değişkenler

DİNAMİK ÖMÜRLÜ NESNE:
	-progremın belirli bölümünde belirli zaman aralığında faaliyet gösterip yok olurlar
	- 1-yerel değişkenler 2-paramtere değişkenleri 3-dinamik bellek fonkları ile oluşturulan nesneler
	-yerel değikenler ve paramtere değişkenleri STACK SEGMENT  bölgesinde tutulurlar
	
	
	
-örenğin,yerel değişkenler tanımlandıklalrı blok çalışıtğında tanımlanır blok bitince yok olular
-yani çalışma süresi bloğun çalışma süresi kadardır
-statik ömürlü değişkene ilk değer verilmezse değeri 0 olur
-dinamik ömürlü değişkene ilk değer atanmazsa hafızada değişken için ayrılan bölgede o anda bulunan değer atanır
-örneğin,global değişkene ilk değer atnamaz ise değeri 0,yerel değişkene ilk değer atanmaz ise değeri kestirilemez 
yani random bir sayı belirler o değişken için ve o değer kalır değiştirilmediği müddetçe(garbage değer)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,c,b=4;
	c=a+b;
	printf("%d\t",c);
	printf("%d",a);
}
mesela bunu çalıştırdığımda a için bellek kafasına göre 16 değerini verdi ve çıktı 20	16 şeklinde geldi

*YER VE TÜR BELİRLEYİCİLER*
-örn,yerel değişkenler tanımlandıkları blok çalıştığında tanımlanır blok bitince yok olurlar
-C'de nesnelerin ikincil özellikleri belirleyiciler ile tanımlanır
-Belirleyiciler:1-yer belirleyici 2-tür belirleyici
-4 tane yer belirleyici vardır(saklama sınıfları):
	1-auto
	2-register
	3-static
	4-extern(dış)
	
-2 tane tür belirleyici vardır:
	1-const
	2-volatile

-genel değişken tanımlama biçimi:
	[yer belirleyici] [tür belirleyici] [tür] nesne;
	yer belirleyici tür belirleyici ve tür herahngi bri sırayla verilebilir
	
	auto const int a=10;(tavsiye edilen)
	const auto int a=10;
	int const auto a=10;
	
	
*SAKLAMA SINIFI*
-C'de her değişken ve fonkun iki niteliği vardır:
	tip ve depolama sınıfı
-4 depolama sınıfı auto extern register static olarak verilir
-nesne kedni bloğu içinde oluşturulur ve yok edilir
*auto:fonk içinde bildirilen değişkenler varsayılan olarak otomatiktir.bu değişkenler fonk kapsamında kullanılabilir:
	auto double x,y;
stack bölgesinde tutulurlar. global değişkenler ve parametre değişkenleri auto özelliği alamaz

*extern:bloklar ve fonklar arasındaki bilgi aktarımını sğalamanın yollarından biri harici değişkenelri kullanmaktır
-bir işlevin dışında bir değişken bildirildiğinde,depolama birimi kendisine kalıcı olarak atanır ve depolama sınıfı
extern olur.
-C derleyiicisi başka bir modülde tanımlı fonku otomatik olarak extern kabul eder.fonklar için extern kullanımı
gereksizidir.
-extern ile tanımlanan değişkene ilk değer verilmezse derleyici tarafından hafızada yer ayırlmaz
-extern,a bloğunda kullanılan bir değişkeni değeriyle birlikte b bloğunda kullanmamıza yarayan bir saklama sınıfı

#include <stdio.h>
#include <stdlib.h>
extern int a=1,b=3,c=5;
int f(void);
int main(void)
{
	printf("%d\t",f());
	printf("%d\t%d\t%d",a,b,c);
}
int f(void)
{
	auto int b,c;
	a=b=c=4;
	return(a+b+c);
}
12	4	3	5 çıktısını verir

#include <stdio.h>
#include <stdlib.h>
int a=1,b=4,c=5;
int f(void);
int main(void)
{
	printf("%d\n",f());
	printf("%d\t%d\t%d",a,b,c);
}
int f(void)
{
	int b,c;
	b=c=a;
	return(a+b+c);
}
3	1	4	5 çıktısını verir

*register=derleyiciye ilişkilendirme değişkenlerinin yüksek hızlı bellek kayıtlarında saklanması gerektiğini söyler
-değişkeninn bellekte değil de CPU'nun yazmaçlarında tutulacağını belirtir 
-dğeişkenlerin yazmaçta tutulması programın hızlanmasını sağlar 
-belleğe erişim ,yazmaçlara erişimden daha yavaştır çünkü belleklere erişim için belli bir makine zamanı gerekir
-yazmaçlar sınırlı sayıdadır

*static=fonklar içinde tanımlanan yerel değişkenlerdir
-fonk sonlandıktan sonra değişken değeri saklanır
-static belirleyiciye sahip değişkenler programın çalışması boyunca bellekten kaybolmazlar.autonun zıttıdır.
-sadece tanımlandıkları fonklarda geçerlidirler 