#include<stdio.h>
struct personne{
	char prenom[10];
	char nom[10];
	int age;
};
int main(){
	struct personne p1={"AMINE","BENNANI",25};
	printf("NOM =%s \n prenom=%s \n age=%d \n",p1.nom,p1.prenom,p1.age);
	return 0;
}
