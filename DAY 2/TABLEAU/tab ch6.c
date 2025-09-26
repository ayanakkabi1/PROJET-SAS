#include<stdio.h>
int main(){
	int N,i;
	float F;
	int tab[N];
	float tabF[N];
	printf("donner la taille du tableau:");
	scanf("%d",&N);
	
	for(i=0;i<N;i++){
		printf("donner tab[%d]:\n",i);
		scanf("%d",&tab[i]);
    };
    printf("donner le facteur:");
	scanf("%.2f",&F);
	for(i=0;i<N;i++){
	    tabF[i]	= F * tab[i];
    }
    printf("NOUVEAU TABLEAU :\n");
    for(i=0;i<N;i++){
		printf("tabF[%d]= %.2f\n",i,tabF[i]);
    } 
    return 0;
}
		
