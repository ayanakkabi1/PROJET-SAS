#include<stdio.h>
#include<string.h>
int main(){
    char nom[50];
    char prenom[50];
    char mail[50];
    int age;
    char sex;
    printf("entrez votre nom:");
    scanf("%s",nom);
    printf("entrez votre prenom:");
    scanf("%s",prenom);
    printf("entrez votre adresse email:");
    scanf("%s",mail);
    printf("entrez votre age:");
    scanf("%d", &age);
    printf("entrez votre sex:");
    scanf(" %c", &sex);
    printf("Nom: %s \n",nom);
    printf("Prénom: %s \n",prenom);
    printf("Age: %d \n",age);
    printf("sexe: %c \n",sex);
    printf("Adresse email: %s \n",mail);
     return 0;
}




