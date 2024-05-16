*ENUM=
-de�i�kenin alabilece�i de�erlerin belli (sabit) oldu�u durumlarda program� daha okunabilir hale getirmek i�in
kullan�l�r
-enumlar sabitler gibidir
-enumlar sabit olarak ayarlan�r
-de�erler s�f�rdan ba�lar birer birer artar 
-benzersiz sabit isimlerine ihtiya� vard�r
-biz enum ile kendi veri tipimizi olu�turabiliriz
-�ren�in yeni bir boolean tipi olu�turabiliriz
-bu boolean tipinde 0 false 1 true olabilir


#include <stdio.h>
int main()
{
	enum maincolors{//burada harflendirme yap�lmad��� i�in red 0 yellow 1 blue 2 olur
		red,
		yellow,
		blue
	};
	enum maincolors pixel;//burada enum maincolors bir veri tipi pixel ise de�i�ken gibidir
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
	mon=1,tue,wed,thr,fri,sat,sun//mon=1 yapmazsak monu 0 olarak al�r
	//mona 3 wede 8 falan diye numaraland�rabilirdik de
};
int main()
{
	enum week day;
	day =tue;
	printf("%d",day);
	return 0;
}
//2 ��kt�s�n� al�rs�n


#include <stdio.h>


enum week{
	mon=1,tue,wed=5,thr,fri=10,sat,sun
};
int main()
{
	
	printf("%d\t%d\t%d\t%d\t%d",mon,tue,wed,thr,fri);
	return 0;
}
//1,2,5,6,10 de�erlerini d�nd�r�r

-her de�i�kenin tan�mlamas�nda enum yazmaman�n iki yolu vard�r:
	-de�i�keni enum tan�mlamas� ile yazmak
	-typedef ile kullanmak
	
enum week{
	mon,tue,wed,thr,fri,sat,sun
}day;//�eklinde day de�i�kenimizi direkt olarak belirttik

-----------------------------------
ya da 

typedef int tamsay�;
tamsay� n;//�eklinde yapabiliriz



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


-e�er enum global olarak tan�mlan�rsa bir fonka parametre olarak g�nderilebilir

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
-farkl� tipte de�i�kenleri tek bir yap� alt�nda gruplamka i�in kullan�l�rlar 
-yap�lar nesne y�nelimli programlama i�in �nemlidir



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
	//�stte you yoursister yourbro demezsem alt�nda ��yle belit
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
//�stte you=yoursister diyerek yoursister�n verileirni you ya katar�r aktarabiliriz

-i� i�e struct yap�s� da olu�turulabilir

struct{
	....
	y
	....
	struct{
		...
		x
		...
	}de�i�ken1;
}de�i�ken2;

-�stte x i�in de�i�ken2.de�i�ken1.x deriz 
-y i�in ise direkt de�i�ken2.y deriz