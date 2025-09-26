#include<stdio.h>
int main(){
	float T;
	printf("donner la temperature en celsieus: ");
	scanf("%f",&T);
	T=T + 273.15;
	printf("la temperature en kelvin est: %.2f",T);
	return 0;
}
