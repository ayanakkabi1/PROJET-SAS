#include<stdio.h>
int main(){
	int N,i,A;
	printf("donner la taille :");
	scanf("%d",&N);
	int tab[N];
	for(i=0;i<N;i++){
		printf("donner tab[%d] :",i);
		scanf("%d",&tab[i]);
	}
	printf("donner la valeur a rechercher:");
	scanf("%d",&A);
	for(i=0;i<N;i++){
		if(tab[i]==A){
			printf("present");
			break;
		}	
}
    if(i==N){
    	printf("NON");
	}
return 0;
}
