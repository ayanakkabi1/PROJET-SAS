#include <stdio.h>

int main() {
    int n,j,i;
    printf("Entrez un entier n : ");
    scanf("%d", &n);

    printf("Nombres premiers de 1 à %d :\n", n);

    for ( i = 2; i <= n; i++) {
        int estPremier = 1; // on suppose que i est premier

        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                estPremier = 0;
                break;
            }
        }

        if (estPremier) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}

