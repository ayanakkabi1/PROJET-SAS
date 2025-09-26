#include <stdio.h>

#define MAX_LIVRES 100
#define TAILLE_TITRE 50
#define TAILLE_AUTEUR 50

int main() {
    char titres[MAX_LIVRES][TAILLE_TITRE];
    char auteurs[MAX_LIVRES][TAILLE_AUTEUR];
    float prix[MAX_LIVRES];
    int quantites[MAX_LIVRES];
    int nombreLivres = 0;
    int choix, i, j, k;
    char titreRecherche[TAILLE_TITRE];
    int trouve;
    int nouvelleQuantite;
    int totalStock;
    
    printf("===  LIBRAIRIE ===\n");
    
    while(1) {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Ajouter un livre au stock\n");
        printf("2. Afficher tous les livres disponibles\n");
        printf("3. Rechercher un livre par titre\n");
        printf("4. Mettre a jour la quantite d'un livre\n");
        printf("5. Supprimer un livre du stock\n");
        printf("6. Afficher le nombre total de livres en stock\n");
        printf("7. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        getchar();
        switch (choix) {
            case 1:
                if (nombreLivres >= MAX_LIVRES) {
                    printf("Erreur : Le stock est plein!\n");
                    break;
                }
                
                printf("\n--- AJOUT D'UN NOUVEAU LIVRE ---\n");
                
                printf("Titre : ");
                scanf(" %[^\n]", titres[nombreLivres]);
                getchar();
                printf("Auteur : ");
                scanf(" %[^\n]",auteurs[nombreLivres]);
                getchar();
                printf("Prix : ");
                scanf("%f", &prix[nombreLivres]);
                getchar();
                printf("Quantite : ");
                scanf("%d", &quantites[nombreLivres]);
                getchar();
                nombreLivres++;
                printf("Livre ajoute avec succes!\n");
                break;
                
            case 2: 
                printf("\n--- LISTE DES LIVRES ---\n");
                
                if (nombreLivres == 0) {
                    printf("Aucun livre dans le stock.\n");
                    break;
                }
                
                for (i = 0; i < nombreLivres; i++) {
                    printf("\nLivre %d:\n", i + 1);
                    printf("  Titre: %s \n", titres[i]);
                    printf("  Auteur:%s \n", auteurs[i]);
                    printf("  Prix: %.2f MAD \n", prix[i]);
                    printf("  Quantite: %d \n", quantites[i]);
                }
                break;
                
            case 3: 
                printf("\n--- RECHERCHE D'UN LIVRE ---\n");
                printf("Entrez le titre a rechercher : ");
                scanf(" %[^\n]", titreRecherche);
                
                trouve = 0;
                for (i = 0; i < nombreLivres; i++) {
                    j = 0;
                    int egal = 1;
                    while (titres[i][j] != '\0' && titreRecherche[j] != '\0') {
                        if (titres[i][j] != titreRecherche[j]) {
                            egal = 0;
                            break;
                        }
                        j++;
                    }
                    if (egal && titres[i][j] == '\0' && titreRecherche[j] == '\0') {
                        printf("\nLivre trouve :\n");
                        printf("  Titre: %s\n", titres[i]);
                        printf("  Auteur: %s\n", auteurs[i]);
                        printf("  Prix: %.2f MAD\n", prix[i]);
                        printf("  Quantite: %d\n", quantites[i]);
                        trouve = 1;
                        break;
                    }
                }
                
                if (trouve == 0) {
                    printf("Livre non trouve dans le stock.\n");
                }
                break;
                
            case 4: 
                printf("\n--- MISE A JOUR DE LA QUANTITE ---\n");
                printf("Entrez le titre du livre : ");
                scanf("%[^\n]", titreRecherche);
                
                trouve = 0;
                for (i = 0; i < nombreLivres; i++) {
                    j = 0;
                    int egal = 1;
                    while (titres[i][j] != '\0' && titreRecherche[j] != '\0') {
                        if (titres[i][j] != titreRecherche[j]) {
                            egal = 0;
                            break;
                        }
                        j++;
                    }
                    if (egal && titres[i][j] == '\0' && titreRecherche[j] == '\0') {
                        printf("Quantite actuelle : %d\n", quantites[i]);
                        printf("Nouvelle quantite : ");
                        scanf("%d", &nouvelleQuantite);
                        
                        if (nouvelleQuantite >= 0) {
                            quantites[i] = nouvelleQuantite;
                            printf("Quantite mise a jour avec succes!\n");
                        } else {
                            printf("Erreur : La quantite doit etre positive!\n");
                        }
                        trouve = 1;
                        break;
                    }
                }
                
                if (trouve == 0) {
                    printf("Livre non trouve dans le stock.\n");
                }
                break;
                
            case 5: 
                printf("\n--- SUPPRESSION D'UN LIVRE ---\n");
                printf("Entrez le titre du livre a supprimer : ");
                scanf(" %[^\n]", titreRecherche);
                
                trouve = 0;
                for (i = 0; i < nombreLivres; i++) {
                    j = 0;
                    int egal = 1;
                    while (titres[i][j] != '\0' && titreRecherche[j] != '\0') {
                        if (titres[i][j] != titreRecherche[j]) {
                            egal = 0;
                            break;
                        }
                        j++;
                    }
                    if (egal && titres[i][j] == '\0' && titreRecherche[j] == '\0') {
                        trouve = 1;
                        for (j = i; j < nombreLivres - 1; j++) {
                            k = 0;
                            while (titres[j + 1][k] != '\0') {
                                titres[j][k] = titres[j + 1][k];
                                k++;
                            }
                            titres[j][k] = '\0';
                            k = 0;
                            while (auteurs[j + 1][k] != '\0') {
                                auteurs[j][k] = auteurs[j + 1][k];
                                k++;
                            }
                            auteurs[j][k] = '\0';
                            
                            prix[j] = prix[j + 1];
                            quantites[j] = quantites[j + 1];
                        }
                        nombreLivres--;
                        printf("Livre supprime avec succes!\n");
                        break;
                    }
                }
                
                if (trouve == 0) {
                    printf("Livre non trouve dans le stock.\n");
                }
                break;
                
            case 6: 
                printf("\n--- TOTAL DU STOCK ---\n");
                totalStock = 0;
                
                for (i = 0; i < nombreLivres; i++) {
                    totalStock += quantites[i];
                }
                
                printf("Nombre total de livres en stock : %d\n", totalStock);
                printf("Nombre de titres differents : %d\n", nombreLivres);
                 break;
                
            case 7: 
                printf("Merci d'avoir utilise le systeme. Au revoir!\n");
                return 0;
                
            default:
                printf("Erreur : Choix invalide! Veuillez choisir entre 1 et 7.\n");
        }
    }
    
    return 0;
}
