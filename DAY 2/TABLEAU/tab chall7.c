#include<stdio.h>
int main(){
	int N,i,M;
	int tab[N];
	printf("donner la taille du tableau:");
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		printf("donner tab[%d]:",i);
		scanf("%d/n",&tab[i]);
		}
	M=tab[0];
	for(i=0;i<N;i++){
	if(M<tab[i]){
		    M=tab[i+1];
			tab[i]=tab[i+1];
		}	
    }
    for(i=0;i<N;i++){
    	printf("tab[%d]=%d\n",i,tab[i]);
    }
	return 0;
}
