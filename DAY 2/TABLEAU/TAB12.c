#include<stdio.h>

int main(){
    int N,i;

    printf("Entrez le nombre des elements: ");
    scanf("%d", &N);

    int tab[N];

    for(i=0; i<N; i++){
        printf("Entrez le %d element: ", i);
        scanf("%d", &tab[i]);
    }

    for(i=0;i<N;i++){
        if(tab[i]%2==0){
            printf("%d ", tab[i]);
        }
    }
return 0;
}

