#include <stdio.h>

int main() {
    int base, exposant;
    long resultat = 1;  // utiliser long pour éviter les débordements rapides

    // Lecture des données
    printf("Entrez la base (positive) : ");
    scanf("%d", &base);

    printf("Entrez l’exposant (non négatif) : ");
    scanf("%d", &exposant);

    int i = 0;
    while (i < exposant) {
        resultat = resultat * base;
        i++;
    }

    printf("%d puissance %d = %ld\n", base, exposant, resultat);

    return 0;
}

