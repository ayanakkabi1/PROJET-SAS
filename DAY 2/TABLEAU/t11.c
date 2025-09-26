#include<stdio.h>
int main(){
int N,i,A,B;
	printf("donner la taille du tableau:");
	scanf("%d",&N);
	int tab[N];
	
	for(i=0;i<N;i++){
		printf("donner tab[%d]:",i);
		scanf("%d/n",&tab[i]);
		}
	printf("donner la valeur a remplacer:");
	scanf("%d",&A);
	printf("donner la nouvelle valeur:");
	scanf("%d",&B);
	for(i=0;i<N;i++){
	if(tab[i]==A){
		    tab[i]=B;
		}	
    }
    printf("nouveau tableau\n");
    for(i=0;i<N;i++){
    	 printf("%d\n",tab[i]);
	}
	return 0;
}
