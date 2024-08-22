#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

void getip();
int valid(char* A);
int main()
{
	getip();
	return 0;
}

void getip()
{
	
	char* ip=NULL;
	ip=malloc(MAX*sizeof(char));
	if(ip==NULL)
	{
		printf("erreur allocation");
		exit(1);
	}
	get:
	printf("\nles addresses ip doivent respecter le format a.b.c.d ou a,b,c,d sont des entiers compris entre 0 et 255\n\n");
	printf("ip:");
	scanf("%s", ip);
	if(!valid(ip))
	{
		goto get;
	}
}

int valid(char* A)
{
	int buff,class;
	char* buffer;
	int count_point=0;
	for(int i=0 ; i<strlen(A) ; i++)
	{
		if(A[i]=='.')
		{
			count_point++;
		}
		else
		{
			if(!strchr("0123456789",A[i]))
			{
				printf("erreur de syntaxe\n");
				return 0;
			}
		}
	}
	if(count_point!=3)
	{
		printf("erreur de syntaxe\n");
		return 0;
	}

	buffer=strtok(A,".");
	class=atoi(buffer);
	while(buffer!=NULL)
	{
		int buff;
		buff=atoi(buffer);
		if(buff>255||buff<0)
		{
			printf("addresse ip non valide sur %d\n",buff);
			return 0;
		}
		buffer=strtok(NULL,".");
	}
	printf("l'adresse ip est de classe:");
	if(class<=128)
	{
		printf("A");
	}
	else if(class<=192)
	{
		printf("B");
	}
	else if(class<=224)
	{
		printf("C");
	}
	else
	{
		printf("D");
	}
	return 1;
}
