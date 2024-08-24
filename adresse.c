#include <stdio.h>
void login(FILE *file,char *chaine);
void passwd(FILE *file,char *chaine);
int main(){
    FILE *file=NULL;
    char chaine[100];
    login(file,chaine);
    passwd(file,chaine);

    return 0;
}
void login(FILE *file,char *chaine)
{
    file=fopen("login" , "a+");
    printf("entrez votre login:");
    scanf("%s" , chaine);

    fprintf(file,"%s", chaine);
    

    if(file == NULL)
    {
        printf("erreur d'ouverture");
    }
    
}
void passwd(FILE *file,char *chaine)
{
    file=fopen("passwd" , "a+");
    printf("entrez votre password:");
    scanf("%s" , chaine);

    fprintf(file,"%s", chaine);


    if(file == NULL)
    {
        printf("erreur d'ouverture");
    }

}