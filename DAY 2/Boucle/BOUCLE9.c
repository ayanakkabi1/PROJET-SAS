#include <stdio.h>

int main() {
    int base, exposant;
    long resultat = 1;  // utiliser long pour �viter les d�bordements rapides

    // Lecture des donn�es
    printf("Entrez la base (positive) : ");
    scanf("%d", &base);

    printf("Entrez l�exposant (non n�gatif) : ");
    scanf("%d", &exposant);

    int i = 0;
    while (i < exposant) {
        resultat = resultat * base;
        i++;
    }

    printf("%d puissance %d = %ld\n", base, exposant, resultat);

    return 0;
}

