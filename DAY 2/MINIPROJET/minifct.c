#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIVRES 100
#define TAILLE_TITRE 50
#define TAILLE_AUTEUR 50

// Structure pour représenter un livre
typedef struct {
    char titre[TAILLE_TITRE];    // Titre du livre
    char auteur[TAILLE_AUTEUR];  // Auteur du livre
    float prix;                  // Prix du livre en MAD
    int quantite;               // Quantité en stock
} Livre;

// Tableau global pour stocker les livres
Livre stock[MAX_LIVRES];
int nombreLivres = 0;

// ============================================================================
// FONCTIONS UTILITAIRES
// ============================================================================

/**
 * Vide le buffer d'entrée pour éviter les problèmes de saisie
 */
void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Saisit et valide un entier positif
 * Retourne l'entier saisi
 */
int saisirEntierPositif(char message[]) {
    char saisie[50];
    int nombre;
    int resultat;
    
    while (1) {
        printf("%s", message);
        fgets(saisie, 50, stdin);
        
        // Vérifie si la saisie est un nombre valide
        resultat = sscanf(saisie, "%d", &nombre);
        if (resultat == 1 && nombre >= 0) {
            return nombre;
        }
        printf("Erreur : Veuillez entrer un nombre entier positif.\n");
    }
}

/**
 * Saisit et valide un prix positif
 * Retourne le prix saisi
 */
float saisirPrixPositif(char message[]) {
    char saisie[50];
    float nombre;
    int resultat;
    
    while (1) {
        printf("%s", message);
        fgets(saisie, 50, stdin);
        
        // Vérifie si la saisie est un prix valide
        resultat = sscanf(saisie, "%f", &nombre);
        if (resultat == 1 && nombre >= 0) {
            return nombre;
        }
        printf("Erreur : Veuillez entrer un prix valide (nombre positif).\n");
    }
}

// ============================================================================
// FONCTIONS DE GESTION DES LIVRES
// ============================================================================

/**
 * Ajoute un nouveau livre au stock
 */
void ajouterLivre() {
    // Vérifie si le stock est plein
    if (nombreLivres >= MAX_LIVRES) {
        printf("Erreur : Le stock est plein! Capacite maximale : %d livres\n", MAX_LIVRES);
        return;
    }
    
    printf("\n--- AJOUT D'UN NOUVEAU LIVRE ---\n");
    
    // Saisie des informations du livre directement dans le tableau
    printf("Titre : ");
    fgets(stock[nombreLivres].titre, TAILLE_TITRE, stdin);
    stock[nombreLivres].titre[strcspn(stock[nombreLivres].titre, "\n")] = '\0';
    
    printf("Auteur : ");
    fgets(stock[nombreLivres].auteur, TAILLE_AUTEUR, stdin);
    stock[nombreLivres].auteur[strcspn(stock[nombreLivres].auteur, "\n")] = '\0';
    
    stock[nombreLivres].prix = saisirPrixPositif("Prix (MAD) : ");
    stock[nombreLivres].quantite = saisirEntierPositif("Quantite : ");
    
    nombreLivres++;
    printf("Livre ajoute avec succes!\n");
}

/**
 * Affiche seulement les quantités de tous les livres
 */
void afficherQuantites() {
    printf("\n--- QUANTITES DES LIVRES EN STOCK ---\n");
    
    if (nombreLivres == 0) {
        printf("Aucun livre dans le stock.\n");
        return;
    }
    
    // Affiche seulement le titre et la quantité de chaque livre
    for (int i = 0; i < nombreLivres; i++) {
        printf("Livre %d: %s - Quantite: %d\n", i + 1, stock[i].titre, stock[i].quantite);
    }
}

/**
 * Affiche tous les livres disponibles dans le stock
 */
void afficherLivres() {
    printf("\n--- LISTE DES LIVRES (%d titres) ---\n", nombreLivres);
    
    if (nombreLivres == 0) {
        printf("Aucun livre dans le stock.\n");
        return;
    }
    
    // Affiche chaque livre du tableau
    for (int i = 0; i < nombreLivres; i++) {
        printf("\nLivre %d:\n", i + 1);
        printf("  Titre: %s\n", stock[i].titre);
        printf("  Auteur: %s\n", stock[i].auteur);
        printf("  Prix: %.2f MAD\n", stock[i].prix);
        printf("  Quantite: %d\n", stock[i].quantite);
    }
}

/**
 * Recherche un livre par son titre dans le stock
 * Retourne l'index du livre trouvé, ou -1 si non trouvé
 */
int rechercherLivre(char titreRecherche[]) {
    for (int i = 0; i < nombreLivres; i++) {
        // Compare les titres (insensible à la casse)
        if (strcasecmp(stock[i].titre, titreRecherche) == 0) {
            return i; // Livre trouvé
        }
    }
    return -1; // Livre non trouvé
}

/**
 * Affiche seulement la quantité d'un livre spécifique
 */
void afficherQuantiteLivre() {
    printf("\n--- AFFICHER QUANTITE D'UN LIVRE ---\n");
    
    char titreRecherche[TAILLE_TITRE];
    printf("Entrez le titre du livre : ");
    fgets(titreRecherche, TAILLE_TITRE, stdin);
    titreRecherche[strcspn(titreRecherche, "\n")] = '\0';
    
    int index = rechercherLivre(titreRecherche);
    
    if (index != -1) {
        printf("Quantite de '%s' : %d exemplaires\n", stock[index].titre, stock[index].quantite);
    } else {
        printf("Livre non trouve dans le stock.\n");
    }
}

/**
 * Interface de recherche d'un livre par titre
 */
void rechercherLivreParTitre() {
    printf("\n--- RECHERCHE D'UN LIVRE ---\n");
    
    char titreRecherche[TAILLE_TITRE];
    printf("Entrez le titre a rechercher : ");
    fgets(titreRecherche, TAILLE_TITRE, stdin);
    titreRecherche[strcspn(titreRecherche, "\n")] = '\0';
    
    int index = rechercherLivre(titreRecherche);
    
    if (index != -1) {
        printf("\nLivre trouve :\n");
        printf("  Titre: %s\n", stock[index].titre);
        printf("  Auteur: %s\n", stock[index].auteur);
        printf("  Prix: %.2f MAD\n", stock[index].prix);
        printf("  Quantite: %d\n", stock[index].quantite);
    } else {
        printf("Livre non trouve dans le stock.\n");
    }
}

/**
 * Met à jour la quantité d'un livre existant
 */
void mettreAJourQuantite() {
    printf("\n--- MISE A JOUR DE LA QUANTITE ---\n");
    
    char titreRecherche[TAILLE_TITRE];
    printf("Entrez le titre du livre : ");
    fgets(titreRecherche, TAILLE_TITRE, stdin);
    titreRecherche[strcspn(titreRecherche, "\n")] = '\0';
    
    int index = rechercherLivre(titreRecherche);
    
    if (index != -1) {
        printf("Quantite actuelle de '%s' : %d\n", stock[index].titre, stock[index].quantite);
        stock[index].quantite = saisirEntierPositif("Nouvelle quantite : ");
        printf("Quantite mise a jour avec succes!\n");
    } else {
        printf("Livre non trouve dans le stock.\n");
    }
}

/**
 * Supprime un livre du stock
 */
void supprimerLivre() {
    printf("\n--- SUPPRESSION D'UN LIVRE ---\n");
    
    char titreRecherche[TAILLE_TITRE];
    printf("Entrez le titre du livre a supprimer : ");
    fgets(titreRecherche, TAILLE_TITRE, stdin);
    titreRecherche[strcspn(titreRecherche, "\n")] = '\0';
    
    int index = rechercherLivre(titreRecherche);
    
    if (index != -1) {
        // Confirmation de suppression
        printf("Etes-vous sur de vouloir supprimer '%s' ? (o/n) : ", stock[index].titre);
        char confirmation;
        scanf(" %c", &confirmation);
        viderBuffer();
        
        if (confirmation == 'o' || confirmation == 'O') {
            // Décalage des éléments pour supprimer le livre
            for (int i = index; i < nombreLivres - 1; i++) {
                // Copie manuelle de chaque champ
                strcpy(stock[i].titre, stock[i+1].titre);
                strcpy(stock[i].auteur, stock[i+1].auteur);
                stock[i].prix = stock[i+1].prix;
                stock[i].quantite = stock[i+1].quantite;
            }
            nombreLivres--;
            printf("Livre supprime avec succes!\n");
        } else {
            printf("Suppression annulee.\n");
        }
    } else {
        printf("Livre non trouve dans le stock.\n");
    }
}

/**
 * Affiche seulement le total des quantités en stock
 */
void afficherTotalQuantite() {
    printf("\n--- QUANTITE TOTALE EN STOCK ---\n");
    
    if (nombreLivres == 0) {
        printf("Le stock est vide.\n");
        return;
    }
    
    int totalQuantite = 0;
    
    // Calcule la quantité totale
    for (int i = 0; i < nombreLivres; i++) {
        totalQuantite += stock[i].quantite;
    }
    
    printf("Quantite totale de livres en stock : %d exemplaires\n", totalQuantite);
    printf("Nombre de titres differents : %d\n", nombreLivres);
}

/**
 * Affiche le menu principal
 */
void afficherMenu() {
    printf("\n=== MENU PRINCIPAL ===\n");
    printf("1. Ajouter un livre au stock\n");
    printf("2. Afficher tous les livres (details complets)\n");
    printf("3. Afficher seulement les quantites de tous les livres\n");
    printf("4. Afficher la quantite d'un livre specifique\n");
    printf("5. Rechercher un livre par titre\n");
    printf("6. Mettre a jour la quantite d'un livre\n");
    printf("7. Supprimer un livre du stock\n");
    printf("8. Afficher la quantite totale en stock\n");
    printf("9. Quitter\n");
    printf("Votre choix : ");
}

// ============================================================================
// FONCTION PRINCIPALE
// ============================================================================

/**
 * Fonction principale du programme
 */
int main() {
    printf("=== GESTIONNAIRE DE LIBRAIRIE ===\n");
    printf("=== VERSION SIMPLIFIEE - AFFICHAGE QUANTITES ===\n");
    
    int choix;
    char saisie[10];
    
    while(1) {
        afficherMenu();
        
        fgets(saisie, 10, stdin);
        
        // Validation de la saisie
        if (sscanf(saisie, "%d", &choix) != 1) {
            printf("Erreur : Veuillez entrer un nombre valide.\n");
            continue;
        }
        
        // Traitement du choix utilisateur
        switch (choix) {
            case 1:
                ajouterLivre();
                break;
                
            case 2:
                afficherLivres();
                break;
                
            case 3:
                afficherQuantites();
                break;
                
            case 4:
                afficherQuantiteLivre();
                break;
                
            case 5:
                rechercherLivreParTitre();
                break;
                
            case 6:
                mettreAJourQuantite();
                break;
                
            case 7:
                supprimerLivre();
                break;
                
            case 8:
                afficherTotalQuantite();
                break;
                
            case 9:
                printf("Merci d'avoir utilise le systeme. Au revoir!\n");
                return 0;
                
            default:
                printf("Erreur : Choix invalide! Veuillez choisir entre 1 et 9.\n");
        }
    }
    
    return 0;
}
