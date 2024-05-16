#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void sort(char **kelime,int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n-1-i;j++)
	 		if(strcmp(kelime[j],kelime[j+1])>0)
	 		{
	 			char *temp;
	 			temp=(char*)calloc(10,sizeof(char));
	 			strcpy(temp,kelime[j]);
	 			strcpy(kelime[j],kelime[j+1]);
	 			strcpy(kelime[j+1],temp);
			 }
}



int main()
{
	char **kelime;
	int n,i;
	printf("kac kelime gireceksiniz?:");
	scanf("%d",&n);
	kelime=(char**)calloc(n,sizeof(char*));
	for(i=0;i<n;i++)
	{
		kelime[i]=(char*)calloc(10,sizeof(char));
		scanf("%s",kelime[i]);
		
	}
	sort(kelime,n);
	
	printf("sort edildikten sonraki hali \n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",kelime[i]);
	}
	
	return 0;
}