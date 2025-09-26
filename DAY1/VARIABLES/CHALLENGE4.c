#include<stdio.h>
int main(){
	float V;
	printf("donner la vitesse en kilometres par heure (km/h) :");
	scanf("%f",&V);
	V =V*0.27778;
	printf("La vitesse en mètres par seconde (m/s) est : %.2f", V);
	return 0;
}
