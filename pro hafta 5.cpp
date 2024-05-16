*POİNTER TUTAN POİNTER*
-pointer da bir değişkendir ve onu da işaret edecek bir pointer yapısı kullanılabilir
-pointer değişkenini işaret edecek bir pointer tanımlıyorsnaız başına ** getirmemiz gerekir
-buradaki * sayısı değişebilir.mesela pointeri işaret eden bir pointerı işaret ediyorsnaız *** koyarsınız

*POİNTER ARİTMETİĞİ*
-işaretçi değişkenler üzeirnde toplama ve çıkarma işlemleri geçerlidir.ancak eklenip çıkarılacak sayılar
tamsayı olmadılır
-işaretçi değişkenin değeri bir arttırıldığı zaman bir sonraki bloğu işaret eder
-işaretçi değişkenin alcağı yeni değer işaretçi değişkenin ne tip bir veri bloğunu işaret ettiğine bağlıdır

int i,*iptr;
iptr=&i;//iptr örneğin 1000 nolu adresi gösteriyorsa 
iptr+=2;//bu işlemden sonra iptr yeni değeri 1008(iptr+2*4)'dir
çünkü int tipi hafızada 4 bayt yer kaplıyor




#include <stdio.h>

int main()
{
 int x,*ptrx;
 double y,*ptry;
 ptrx=&x;
 printf("ptrx nin adresi =%d\n",ptrx);
 ptrx++;
 printf("ptrx nin adresi =%d\n",ptrx);
 ptry=&y;
 printf("ptr nin adresi =%d\n",ptry);
 ptry++;
 printf("ptr nin adresi =%d\n",ptry);
    return 0;
}
yazdığımızda 

ptrx nin adresi =6684172
ptrx nin adresi =6684176
ptr nin adresi =6684160
ptr nin adresi =6684168

çıktısını veriyor

int x; olması  koşuluyla
ptrx=&x; burada ptrx örneğin 1000 nolu adresi gösteriyorsa 
ptrx++; ptrx'in 1004 nolu adresi göstermesini sağlar



#include <stdio.h>

int main()
{
 int x=5,*ptrx;
 ptrx=&x;
 printf("ptrx nin adresi =%d\n",ptrx);//6684180
 *ptrx++;
 printf("ptrx nin degeri =%d\n",*ptrx);//6684184
 printf("ptrx nin adresi =%d\n",ptrx);//6684184
 printf("%d",x);//5
    return 0;
}

 burada *ptrx++ ile önce ptrx'in adresini bir arttırdık sonra o adresteki değeri adresin kendisi yaptık
 EĞER (*ptrx) YAPMIŞ OLSAYDIK SONUÇLAR BAMBAŞKA OLURDU.(*ptrx)++ yapsaydık aderste bir değişiklik olmadan
 adresteki değeri bir arttırmış olacaktık.
 
 *ptrx+=1 de bir sıkıntı yok yani düşündüğün gibi adresi değiştirmeden sadece adresteki değeri değiştiriyor
 
 
 
 *DİZİLER İLE POİNTERLAR ARASINDAKİ İLİŞKİ*
 -bir dizi adı sabit bir pointer gibi düşünülebilir
 -Pointerlar değişkenleri gösterebildikleri gibi dizleri de gösterebilirler
 int dizi[6];
 int *ptr;
 -dizi ve pointerı eşitlemek için dizi adı kullanılabilir.çünkü dizi adı aslında o dizinin ilk 
 elemanının adresidir.
 ptr=dizi;//artık ptr[0] ve dizi[0] eşittir
 -aynı işlemi ptr=&dizi[0] ile de yapabiliriz
 
 -pointerlalrı dinamik bellek şeklinde kullanıp ihtiyacımız sonlandığı zaman belleği işletim sistemine iade 
 edebiliyoruz fakat diziler bir kere oluşturulduğu zaman program sonlanıncaya kadar devam etmekte veya
 yaratıldığı blok içerisinde yaşamaya devam etmekte kalıyor
 
 
 #include <stdio.h>

int main()
{
 int dizi[5]={3,8,2,6,9};
 int *point;
 point=&dizi[0];
 printf("%d",*(dizi+4));// point[4] veya *(point+4) ile de gösterebilirdik

    return 0;
}



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

BU ÜSTTEKİ SORU ÇEŞİDİNDE MUTLAKA GELİRMİŞ


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



-diziler pointer içerebilir
-pointer tutan diziler sayesinde birden fazla diziye erişim sağlanabilir
-pointer tutan diziye dizilerin başlangıç adreslerini atamak yeterlidir
-pointer tutan dizi üzerindeki değişiklik diziyi orijinal diziyi etkiler



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


*FONKSİYONU DEĞER YA DA REFERANS İLE ÇAĞIRMA*call by value or call by reference 
-bir fonksiyona göderilen parametrenin normalde değeri değişmez.fonksiyon içerisinde yapılan işlemlerin
hiçbiri argüman değişkeni etkilemez
-sadece değişken değerinin aktarıldığı ve argümanın etkilenmediği bu duruma "call by value" veya 
"pass by value " adı verilir.
-bir fonksiyondan birden fazla değer döndürülmesi veya fonksiyonun içerisinde yapacağımız değişikliklerin
parametre değişkene yansıması gereken durumlar olabilir
-işte bu tür durumlarda "call by reference" veya "pass by reference" olarak isimlendirilen yöntem 
uygulanır
-argüman değer olarak aktarılmaz argüman olan değişkenin adres bilgisi fonka aktarılır.bu sayede 
fonksiyon içerisinde yapacağımız her türlü değişiklik argüman değişkene yansır 

#include <stdio.h>
#include <stdlib.h>
void fonk(int a)
 {
 	a=4;
 }

int main()
{
	int a=2;
	printf("%d",a);
	fonk(a);
	printf("\n%d",a);

	return 0;
}
yaparsak ikinci olarak a yı yazdırmak isteidğimizde bize 2 yerine 4 sonucunu vermiyecektir o yüzden kodu
alttaki gibi pointer kullanarak yazmamız gerekir 


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
bu çıktıda ise ;
2
4
alırız


#include <stdio.h>
#include <stdlib.h>
void fonk(int dizi[],int n)
 {
 	int i;
 	for(i=0;i<n;i++)
 	{
 		dizi[i]++;
	 }
 }

int main()
{
	int i,dizi[5]={1,2,3,4,5},n=5;
	//burada dizi üzerinde yapılan değişiklikler main fonksdaki diziyi de etkilemektedir
	for(i=0;i<n;i++)
	{
		printf("%d\n",dizi[i]);
	}
	fonk(dizi,n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",dizi[i]);
	}
	return 0;
}
yukarıdaki program fonksiyona referans ile çağırmaya örnektir



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
1
2
3
4
5
2
3
4
5
6 çıktısını verecektir

-eğer yazdığınız fonksiyon birden fazla değer döndürmek zorundaysa,referanf yoluyla aktarım zorunlu
hale geliyor
-çünkü return ifadesşyle sadece tek bir değer döndürebiliriz
-önreğin bir bölme işleminde bölüm ve kalanı yazdıracak bir fonk yazdırsacağımızı düşünelim 
-bu durumda bölen ve bölünen fonka gönderilecek argümanlar olurken kalan ve bölüm geriye dönmelidir
-return ifadesi geriye tek bir değer vereceğinden ikinci değeri döndürebilmek için referans yöntemi
kullanmamız gerekmektedir


#include <stdio.h>
#include <stdlib.h>
int bolme(int x,int y,int *a)
 {
 	*a=x%y;
 	return x/y;//bura bölümü ifade eder
 }

int main()
{
	int bolunen,bolen,kalan,bolum;
	bolunen=13;
	bolen=6;
	bolum=bolme(bolunen,bolen,&kalan);
	printf("bolum =%d,kalan =%d",bolum,kalan);
	return 0;
}



*DİNAMİK BELLEK YÖNETİMİ*(önemli)
-bir program çalıştırıldığında işletim sistemi programın çalışması için bir alan ayırır(stack ve heap)
-stack(yığın),fonklar ve onların yerel değişkenlerinin tutulduğu alandır.yani veriler üst üste yığılır
-heap(öbek),program için ayrılan ve çalışma zamanında hafıza alanı açmak için kullanılan boş alandır
-yığın ve öbek belleğin mantıksal parçalarıdır
-yığın LİFO(last in first out) mantığında çalışır.bir kutu olarak düşündüğünüzde kutuya koyduğunuz 
kitaplar üst üste eklenirken son koyduğunuz kitaba ilk erişirsiniz 
-heap ise program için ayrılmış olan ve programcının sorumluluğunda kullanılan bellek bölümüdür.
-yığında bilgi kaybolmaz ama eğer öbekte bilginin bulunduğu kutunun adresini kaybederseniz bilginize erişemezsiniz
-yığın içerisinde değer tipi değişkenleri,işaretçi değişkenleri ve kod adreslerini saklar 
-yığın daha hzılıdır.çalışma mantığı basittir ve elemanlar sıralı biçimde yerleştirilmiştir
-yığını dinamik olarak kullanamayız yani istediğimiz gibi geri devredemeyiz ama heapi dinamik olarak kullanabiliriz
-işaretçiler tarafından gösterilen bellek alanları ise öbek alanında saklanır 
-öbek daha yavaştır.öbekteki nesneye erişmek için karmaşık arama işlemi uygulanmalıdır
-ancka yığın dinamik bri yapıya sahiptir

-şimdiye kadar yazdığımız programlarda dizilerin boyutu önceden belliydi .
-ancka dizi eleman sayısı sabit olmayan ve önceden kestiremediğimiz bir durum varsa ve biz ne olur ne olmaz
dizi eleman sayısı olark bütük bir sayı atarsak bu sefer de hafızayı boş yere işgal etmiş olacağız 
-ÇÖZÜM= dinamik bellek yönetimi kullanmaktır 

-dinamik bellek yönetiminde  program akışında ihtiyaç duyulan bellek miktarı belirlenir 
-d,namik bellek yönetimi için malloc(),calloc() ve realloc() olmak üzere 3 fonk kullanılır 
-her üç fonksiyon da stdlib kütüphanesinde bulunur.bu yüzden fonklardan herhangi birini kullanacağınız
zaman programın başına #include <stdlib.h> koymamamız gerekmektedir 


*MALLOC FONKU*
-bir değişken için hafızadan bir blok yer ayrılmaıs için kullanılır 
-eğer hafızada yeterli alan yoksa fonksiyon null döndürür
int *ptr;
ptr=(int*)malloc(n*sizeof(int));

(int*)= pointer için int tipinde bir alan açıyoruz
n*sizeof(int)=n ile int veri tipinin byte değerini çarpıyoruz yani n*4 oluyor
malloc= sayesinde hafızadan yeterli yer tutabiliyoruz fazlasını kullanmıyor belleği doldurmuyoruz

*CALLOC FONKU*
-Calloc fonku da hafıza bloğu almak için kullanılabilir
-eğer hafızada yeterli alan yoksa fonk null döndürür
-malloc fonkdan farklı olarak argüman listesi değişmektedir
char*ptr;
ptr=(char*)calloc(10,sizeof(char));

mallocta n*sizeof(x) diyorken burada direkt olarak çarpmadan 10,sizeof(x) demiş

*REALLOC FONKU*
-Hafızadan ayrılan bir alanı yeniden boyutlandırmak için kullanılır
-tekrar ayarlanacak hafıza alanının başlangıcını işaret edecek bir pointer ve yeni boyut bilgisini 
parametre olarak alır 

void *realloc(void *ptr,size_t size);
şeklinde kullanımı vardır

-realloc fonku daha önce tahsis edilen bloğun hemen altında sürekliliği bozmayacak şekilde tahsisat yapar 
-eğer daha önce tahsis edilen bloğun hemen altında yeterli alan yoksa bellekte bloğun tamamı için yer arar
-yeterli hafıza alanı bulursa bloğun tamamını hafızada o bölgeye taşır.eskisini siler . yeterli alan
bulamaz ise null döndürür
-taşıyacağı yere bloğun tamamını taşır sığdığı kadarını bırakıp kalanını taşıma mevzusu yok yani
-eğer realloc fonku yeterli alan bulamayıp bloğu başka yere taşırsa bu durumda geri dönüş değerini 
aynı işaretçiye atamak gerekir.
-çünkü bu durumda bloğun başlangıç adresi değişmektedir

char *ptr;
ptr=(char*)calloc(10,sizeof(char));
ptr=realloc(ptr,20*sizeof(char));

biz burada eleman sayısını 10 dan 20 ye çıkardık

*FREE FONK*
-gelişmiş programlama dilleirnde(java,#c...) kuallanılmayan nesnelerin temizlenmesi otomatik olarak çöp toplayıcılarla
(garbage collector ) yapılmaktadır.
-ne yazık ki c programlama dili için bir çöp toplayııcı yoktur ve iyi programcıyla kötü programcı burada
kendini belli eder 
-büyük boyutta ve kapsamlı bir program söz konusuysa efektif bellek yönetiminin ne kadar önemli
olduğunu daha iyi anlarsınız 
-gereksiz tüketilen bellekten kaçınmak gerekmektedir.
-malloc ve calloc fonkları ile hafızadan ayrılan alanın tekrar heap alanına serbest bırakılması 
için kullanılır 

int *ptr;
ptr= (int*)malloc(n*sizeof(int));
free(ptr);

---------------------

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i,*ptr,n,sum=0;
	printf("eleman sayisini giriniz:");
	scanf("%d",&n);
	
	ptr=(int*)malloc(n*sizeof(int));
	if(ptr==NULL)
	{
		printf("bellekte yeterli hafiza yok");
	}
	else
	{
		printf("dizinin elemanlarini giriniz:\n");
		for(i=0;i<n;i++)
		{
			scanf("%d",ptr+i);
			sum+=*(ptr+i);
		}
		printf("girdiginiz sayilarin toplami:%d",sum);
	}
	return 0;
}
 

  ----------------------------------------
  
  
  #include <stdio.h>
#include <stdlib.h>

int *dizileri_birlestir(int[],int,int[],int);

int main()
{
	int i;
	int liste1[5]={6,7,8,9,10};
	int liste2[7]={1,2,3,4,5,6,7};
	int *ptr;//sonucu dondurmasi icin pointer tanimladik
	ptr=dizileri_birlestir(liste1,5,liste2,7);//ptr isimli pointerı bir dizi olarak düşünebiliriz
	for(i=0;i<12;i++)
	{
		printf("%d\n",ptr[i]);
	}
	return 0;
}

int *dizileri_birlestir(int dizi1[],int boyut1,int dizi2[],int boyut2)
{
	int *sonuc=(int*)calloc(boyut1+boyut2, sizeof(int));
	int i,k;
	
	for(i=0;i<boyut1;i++)
	{
		sonuc[i]=dizi1[i];
	}
	
	for(k=0;k<boyut2;k++,i++)
	{
		sonuc[i]=dizi2[k];
	}
	return sonuc;
}

  
