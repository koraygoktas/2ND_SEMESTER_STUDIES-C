*ENUM=
-deðiþkenin alabileceði deðerlerin belli (sabit) olduðu durumlarda programý daha okunabilir hale getirmek için
kullanýlýr
-enumlar sabitler gibidir
-enumlar sabit olarak ayarlanýr
-deðerler sýfýrdan baþlar birer birer artar 
-benzersiz sabit isimlerine ihtiyaç vardýr
-biz enum ile kendi veri tipimizi oluþturabiliriz
-örenðin yeni bir boolean tipi oluþturabiliriz
-bu boolean tipinde 0 false 1 true olabilir


#include <stdio.h>
int main()
{
	enum maincolors{//burada harflendirme yapýlmadýðý için red 0 yellow 1 blue 2 olur
		red,
		yellow,
		blue
	};
	enum maincolors pixel;//burada enum maincolors bir veri tipi pixel ise deðiþken gibidir
	pixel = blue;
	if(pixel==red)
		printf("red pixel");
	else if(pixel==blue)
		printf("blue pixel");
	else
		printf("yellow pixel");
	return 0;
}


#include <stdio.h>


enum week{
	mon=1,tue,wed,thr,fri,sat,sun//mon=1 yapmazsak monu 0 olarak alýr
	//mona 3 wede 8 falan diye numaralandýrabilirdik de
};
int main()
{
	enum week day;
	day =tue;
	printf("%d",day);
	return 0;
}
//2 çýktýsýný alýrsýn


#include <stdio.h>


enum week{
	mon=1,tue,wed=5,thr,fri=10,sat,sun
};
int main()
{
	
	printf("%d\t%d\t%d\t%d\t%d",mon,tue,wed,thr,fri);
	return 0;
}
//1,2,5,6,10 deðerlerini döndürür

-her deðiþkenin tanýmlamasýnda enum yazmamanýn iki yolu vardýr:
	-deðiþkeni enum tanýmlamasý ile yazmak
	-typedef ile kullanmak
	
enum week{
	mon,tue,wed,thr,fri,sat,sun
}day;//þeklinde day deðiþkenimizi direkt olarak belirttik

-----------------------------------
ya da 

typedef int tamsayý;
tamsayý n;//þeklinde yapabiliriz



#include <stdio.h>

int main()
{
	enum boolean{
		false=0,true=1
	};
	typedef enum boolean bool;
	bool istrue;
	istrue=true;
	if(istrue==true)
	printf("selam");
	else
	printf("no");
	return 0;
}


-eðer enum global olarak tanýmlanýrsa bir fonka parametre olarak gönderilebilir

#include <stdio.h>

enum month_list{
	ocak=1,subat,mart,nisan,mayis,haziran,temmuz,agustos,eylul,ekim,kasim,aralik
};

typedef enum month_list months;
void writemonths(months);
int main()
{
	months thismonth=aralik;
	printf("month %d is ",thismonth);
	writemonths(thismonth);
	return 0;
}
void writemonths(months nameofmonth)
{
	switch(nameofmonth){
		case ocak: printf("ocak");break;
		case subat: printf("subat");break;
		case mart: printf("mart");break;
		case nisan: printf("nisan");break;
		case mayis: printf("mayis");break;
		case haziran: printf("haziran");break;
		case temmuz: printf("temmuz");break;
		case agustos: printf("agustos");break;
		case eylul: printf("eylul");break;
		case ekim: printf("ekim");break;
		case kasim: printf("kasim");break;
		case aralik: printf("aralik");break;
		
	}
}




*YAPILAR=
-farklý tipte deðiþkenleri tek bir yapý altýnda gruplamka için kullanýlýrlar 
-yapýlar nesne yönelimli programlama için önemlidir



#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct {
		int day;
		int month;
		int year;
	}birth_day;
	printf("enter your birth day\n");
	printf("enter it in dd/mm/yy format\n");
	scanf("%d%d%d",&birth_day.day,
					 &birth_day.month,
					 &birth_day.year);
	printf("your birth day :");
	printf("%d/%d/%d\n",birth_day.day,
					 	birth_day.month,
					 	birth_day.year);
	return 0;
}




#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct {
		int day;
		int month;
		int year;
	}you,yoursister,yourbro;
	//üstte you yoursister yourbro demezsem altýnda þöyle belit
	printf("enter your birth day\n");
	printf("enter it in dd/mm/yy format\n");
	scanf("%d%d%d",&you.day,
					 &you.month,
					 &you.year);
	printf("enter your sisters birth day\n");
	printf("enter it in dd/mm/yy format\n");
	scanf("%d%d%d",&yoursister.day,
					 &yoursister.month,
					 &yoursister.year);
	printf("enter your bros birth day\n");
	printf("enter it in dd/mm/yy format\n");
	scanf("%d%d%d",&yourbro.day,
					 &yourbro.month,
					 &yourbro.year);	
	return 0;
}
//üstte you=yoursister diyerek yoursisterýn verileirni you ya katarýr aktarabiliriz

-iç içe struct yapýsý da oluþturulabilir

struct{
	....
	y
	....
	struct{
		...
		x
		...
	}deðiþken1;
}deðiþken2;

-üstte x için deðiþken2.deðiþken1.x deriz 
-y için ise direkt deðiþken2.y deriz