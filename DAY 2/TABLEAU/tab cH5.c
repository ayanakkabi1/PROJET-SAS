#include<stdio.h>
int main(){
	int N,i,MIN;
	int tab[N];
	printf("donner la taille du tableau:");
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		printf("donner tab[%d]:",i);
		scanf("%d",&tab[i]);
		MIN=tab[0];
		if(tab[i]<MIN){
			MIN=tab[i];
		}
		
	}
		printf("MIN=%d\n",MIN);
	return 0;
}
