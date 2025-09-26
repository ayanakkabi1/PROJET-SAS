#include<stdio.h>
struct ETU{
	char prenom[30];
	char nom[30];
	int notes[30];
};
int main(){
	int i=1,n;
	struct ETU E1[30];
	printf("entrer le nbr d'etudiant a ajouter ");
	scanf("%d",&n);
	while(n < 30){
   	printf("donner le prenom de l'etudiant %d:",i);
   	scanf("%s",E1[i].prenom);
   	printf("donner le nom de l'etudiant %d:",i);
   	scanf("%s",E1[i].nom);
   	printf("donner la notes de l'etudian%d:",i);
   	scanf("%d",&E1[i].notes);
	i++;	 
	}
	for (int i = 0;i<n; i++){
	printf(" prenom=%s \n nom=%s \n notes=%d \n",E1[i].prenom,E1[i].nom,E1[i].notes);
}
	return 0;
}
