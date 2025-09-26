#include<stdio.h>
int main(){
	int N,i;
	int Tab[N];
	printf("donner la taille du tableau:");
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		printf("donner tab[%d]:",i);
		scanf("%d",&Tab[i]);
	}
	for(i=0;i<N;i++){
		printf("%d\n",Tab[i]);
	}
}
