#include <stdio.h>
#include <stdlib.h>
int topla(int x){
	if(x==1){
		return 1;
	}
	else{
		return x+topla(x-1);
	}
}

int main()
{
	int sayi;
	printf("bir sayi giriniz:");
	scanf("%d",&sayi);
	printf("%d sayisina kadar olan sayıların toplamı:%d",sayi,topla(sayi)-sayi);
	
	return 0;
}
