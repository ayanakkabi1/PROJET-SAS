#include <stdio.h>

int main() {
    int lignes,i,k,j;
    printf("Entrez le nombre de lignes de la pyramide : ");
    scanf("%d", &lignes);

    int nb = 1; // on commence par 1 étoile (même si ce n’est pas premier)

    for ( i = 1; i <= lignes; i++) {
        // Si ce n’est pas la première ligne, trouver le prochain nombre premier
        if (i > 1) {
            nb++;
            int premier = 0;
            while (!premier) {
                int estPremier = 1;
                for (k = 2; k * k <= nb; k++) {
                    if (nb % k == 0) {
                        estPremier = 0;
                        break;
                    }
                }
                if (nb >= 2 && estPremier) {
                    premier = 1;
                } else {
                    nb++;
                }
            }
        }

        // Afficher les espaces pour centrer
        for ( j = 0; j < lignes - i; j++) {
            printf(" ");
        }

        // Afficher les étoiles
        for ( j = 0; j < nb; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

