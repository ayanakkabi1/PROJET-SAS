#include <stdio.h>

struct livre{
    char titre[50];
    char auteur[50];
    int nombre;
};


int main()
{  int nbr,i;
   struct livre livres[40] = {{"Les Miserable", "x", 40}, {"Les Miserable", "x", 40}, 
                             {"Les Miserable", "x", 40}, {"Les Miserable", "x", 40}};
   printf("entrer le nombre de livres que tu veux entrer:");
   scanf("%d",&nbr);
   for(i=4;i<nbr+4;i++){
   	printf("donner le Titre du livre %d:",i+1);
   	scanf("%s",livres[i].titre);
   	printf("donner l'auteur du livre %d:",i+1);
   	scanf("%s",livres[i].auteur);
   	printf("donner le prix du livre %d:",i+1);
   	scanf("%d",&livres[i].nombre);
   }
   
   for (int i = 0;i<nbr+4; i++){
       printf("Le titre d'element %d est: %s\n l'auteur du livre %d est :%s \n le PRIX  de livre %d est:%d\n\n ", i + 1, livres[i].titre,i+1,livres[i].auteur,i+1,livres[i].nombre);
   }
    return 0;
}
