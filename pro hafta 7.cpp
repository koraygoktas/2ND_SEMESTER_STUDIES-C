*STRİNG

=null karaket ile biten karakter dizisidir
örnek=char str[8];
-en çok 8 karakter albailen bir dizi oluşturur
-eğer str dizisi string olarak kullanılacak ise en fazla 7 karakter alabilir ve sonu null karakter ile
bitmek zorundadır

-string ifadelerle işlemler yapabilmek için include <string.h> kütüphanesini eklememiz gerekmektedir
-bazı önemli fonklar
	=strcpy(char *str1,const char str2);//str2 yi str1 e kopyallıyor, eğer str1 de farklı bir şey varsa 
	//o değer kaybolup str2 nin değerini alıyor
	=strlen(const char *str);//stringin uzunluğunu ölçüyor fakat null hariç
	=strcat(char *str1,const char *str2);//ikinci stringi birinci stringe ekliyor
	=strcmp(const char *str1,const char *str2);// stringleri ascii kodlarına göre karşılaştırıyor
	
	
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kopyalama(char *str1, const char *str2)
{
    while (*str2 != '\0')
    {
        *str1++ = *str2++;
    }
    *str1 = '\0';
}

int main()
{
    char str1[20] = "koray";
    char str2[20] = "goktas";
    
    kopyalama(str1, str2);
    printf("dizinin yeni hali = %s\n", str1);
    
    return 0;
}







#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char str1[20] = "koray";
    char str2[20] = "goktas";
    
    strcpy(str1,str2);
    printf("dizinin yeni hali = %s\n", str1);
    
    return 0;
}






#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void length(char *string)
{
	int len=0;
	while(*string++)//stirng null görene kadar
		len++;
	printf("the length of the string is %d",len);	
}

int main()
{
  	char str1[20]="koray goktas";
  	length(str1);
    return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *yapistirma(char *str1,const char *str2)
{
	char *p=str1;
	while(*p)
		p++;
	while(*str2)
		*p++=*str2++;
	*p='\0';
	return str1;
}
int main()
{
  	char str1[60]="koray goktas ";
 	char str2[60]="software engineer";
 	
	printf("dizinin yeni hali=%s",yapistirma(str1,str2));
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
  	char str1[60];
 	char str2[60];
 	strcpy(str1,"istanbul... ");
 	strcpy(str2,"bekle beni");
 	strcat(str1,str2);
 	printf("the new version of the string is=%s",str1);

    return 0;
}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char compare(const char *str1,const char *str2)
{
	while(*str1&&*str2&&*str1==*str2)
	{
		str1++;
		str2++;
	}
	return *str1 - *str2;
}


int main()
{
  	char str1[60]="koray";
 	char str2[60]="korak";
	printf("karakterlerin ascii kodundaki farki=%d",compare(str1,str2));
    return 0;
}

