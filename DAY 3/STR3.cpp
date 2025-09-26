#include<stdio.h>
struct AIRE{
	float largeur;
	float longueur;
};
float aire(float largeur,float longueur){
	return largeur * longueur;
}
int main(){
	float largeur,longueur;
	struct AIRE A1;
	printf("veuiller entrer la largueur :\n");
	scanf("%f", &A1.largeur);
	printf("veuillez entrer la longueur :\n");
	scanf("%f", &A1.longueur);
	printf("l''aire est : %.2f",aire(A1.largeur,A1.longueur));
	
	return 0;
}

