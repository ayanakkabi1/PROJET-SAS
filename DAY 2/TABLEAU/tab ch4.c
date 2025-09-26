#include<stdio.h>
int main(){
	int N,i,MAX=0;
	int tab[N];
	printf("donner la taille du tableau:");
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		printf("donner tab[%d]:",i);
		scanf("%d",&tab[i]);
		if(MAX<tab[i]){
			MAX=tab[i];
		}
		
	}
		printf("max=%d\n",MAX);
	return 0;
}
