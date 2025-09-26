#include <stdio.h>

int main() {
    int n, i, x;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);

    int tab[n];
    printf("Entrez %d entiers tri�s (ordre croissant) :\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
    }

    printf("Entrez l��l�ment � rechercher : ");
    scanf("%d", &x);

    int debut = 0, fin = n - 1, milieu, trouve = 0;

    while (debut <= fin) {
        milieu = (debut + fin) / 2;

        if (tab[milieu] == x) {
            printf("�l�ment %d trouv� � la position %d (indice %d)\n", x, milieu + 1, milieu);
            trouve = 1;
            break;
        }
        else if (tab[milieu] < x) {
            debut = milieu + 1; // chercher � droite
        }
        else {
            fin = milieu - 1;   // chercher � gauche
        }
    }

    if (!trouve) {
        printf("�l�ment %d non trouv� dans le tableau.\n", x);
    }

    return 0;
}

