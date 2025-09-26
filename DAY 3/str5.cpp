#include<stdio.h>
struct livre{
	char titre[50];
	char auteur[50];
	int annee;
};
int sais(int annee){
	struct livre L1;
	printf("donner le titre:");
	scanf("%s",L1.titre);
	printf("donner l'auteur:");
	scanf("%s",L1.auteur);
	printf("donner l'annee:");
	scanf("%d",&L1.annee);
	printf("LE TITRE EST %s \n l'auteur est %s\n l'annee est %d\n",L1.titre,L1.auteur,L1.annee);
	return annee;
}
int main(){
	int annee;
	sais(annee);
}
