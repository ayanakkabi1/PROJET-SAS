#include<stdio.h>
int main(){
	int N,i,S=0;
	int tab[N];
	printf("donner la taille du tableau:");
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		printf("donner tab[%d]:",i);
		scanf("%d",&tab[i]);
		S= S + tab[i];
	}
	printf("la somme =%d\n",S);
	return 0;
}
