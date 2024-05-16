#include <stdio.h>
/*
int main()
{
    int a, b, c;
    char *p = 0;
    int *q = 0;
    double *m = 0;
	printf("%p\t%p\t%p\n",p,q,m);
    p += 3;//char veri tipi 1 byte olduğundan 1*3ten 3 artmış olacak
    q += 2;
    m += 1;

    printf("%p\t%p\t%p", p, q, m);

    return 0;
    
    /*Kodda *p = 0 ifadesi, p pointerının işaret ettiği bellek adresindeki değeri sıfıra eşitler. Ancak, p pointerı
	 herhangi bir bellek adresine sahip değil, yani bir null pointer.
     Null pointer, herhangi bir bellek adresine sahip olmayan bir pointerdır ve bu nedenle işaret ettiği
	 bellek adresindeki değeri değiştiremezsiniz.*/
	 /* İlk olarak, a, b ve c isimli üç tane tamsayı değişkeni tanımlanıyor.
p, q ve m isimli üç tane pointer değişkeni tanımlanıyor. Başlangıçta bu pointerlar NULL değerine eşitleniyor.
p += 3 ifadesi, p pointerını bellekteki 3. karaktere (ya da bayta) ilerletir. Burada p bir karakter pointerı olduğundan, bellekteki her bir karakter için bir bayt yer ayrıldığını unutmamak gerekir.
q += 2 ifadesi, q pointerını bellekteki 2. integer (tam sayı) değerine ilerletir. Burada q bir integer pointerı olduğundan, bellekteki her bir integer için 4 bayt yer ayrıldığını unutmamak gerekir.
m += 2 ifadesi, m pointerını bellekteki 2. double (ondalık sayı) değerine ilerletir. Burada m bir double pointerı olduğundan, bellekteki her bir double için 8 bayt yer ayrıldığını unutmamak gerekir.
Son olarak, printf fonksiyonu kullanılarak, p, q ve m pointerlarının bellekteki konumları yazdırılır. %p format belirleyicisi, bir pointerın bellek adresini yazdırmak için kullanılır.
*/
/*
}*/



/*
int main()
{
//diziler kendi başlangıç adreslerini saklı tutarlar ve başlangıç adresleri sıfırıncı indistir
int array[4]={3,5,1,2};
int *p=array+2;//burada 0+2den *p, arrayın 2.indisteki değeri başlangıç adresi olarak tutar yani 2. indisi.Dolayısıyla *p nin değeri 1 dir
printf("%d%d",p[-2],array[*p]);
//p[-2] p ye göre sıfırıncı indisten iki indis geriye gidip -2. indisi yazdırır yani p nin başlangıç adresi olan sıfırıncı indisten geriye gidince arrayın sıfırıncı indisine gelmiş oluruz o da 3 tür
//array[*p] diyerek kastı array[1] yani 3 tür
}

*/


#include <stdio.h>

int main()
{
   double *m,**k,array[5]={10.3,4.2,2.7,9.0,6.1};
   m=array;//diziyi tuttu başlangı. değerleri falan her şey aynı
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
*/
