#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ANIMAUX 200
#define MAX_NOM 50
#define MAX_ESPECE 30
#define MAX_HABITAT 30
struct Animal{
	int id;
    char nom[MAX_NOM];
    char espece[MAX_ESPECE];
    int age;
    char habitat[MAX_HABITAT];
    float poids;
};
struct Animal Animaux[MAX_ANIMAUX]={{1,"Simba","Lion",5,"Savane",190.5},{2,"Nala","Lion",4,"Savane",175},{3,"ShereKhan","Tigre",8,"Jungle",220.3},{4,"Baloo","Ours",12,"Forêt",310},
{5,"Raja","Éléphant",15,"Savane",540.7},{6,"Marty","Zèbre",6,"Savane",300.2},{7,"Gloria","Hippopotame",10,"Rivière",450},{8,"Alex","Lion",7,"Savane",200},
{9,"Julien","Lémurien",3,"Jungle",12.5},{10,"Melman","Girafe",9,"Savane",390.8},{11,"Timon","Suricate",2,"Désert",1.2},{12,"Pumbaa","Phacochère",5,"Savane",120},
{13,"Scar","Lion",11,"Savane",210.4},{14,"Kaa","Serpent",6,"Jungle",45},{15,"Iko","Perroquet",4,"Jungle",2.1},{16,"Dumbo","Éléphant",3,"Savane",320},
{17,"Kiki","Chien sauvage",7,"Savane",25},{18,"Donatello","Tortue",40,"Rivière",90.5},{19,"Polly","Oiseau",5,"Jungle",1.5},{20,"Kong","Gorille",13,"Jungle",180}
};


// Variables globales
int nbAnimaux = 20;
int dernierId = 20;
int i;

// Vider le buffer d'entrée
void viderBuffer() {
    while (getchar() != '\n');
}

// Vérifier si un nom est valide (que des lettres, espaces et tirets)
int estNomValide(char nom[]) {
	int i;
    int longueur = strlen(nom);
    if (longueur == 0) return 0;
   
    for (i = 0; i < longueur; i++) {
        if (!isalpha(nom[i]) && nom[i] != ' ' && nom[i] != '-') {
            return 0;
        }
    }
    return 1;
}

// Vérifier si un nom existe déjà dans le zoo
int nomExisteDeja(char nom[]) {
	int i;
	for (i = 0; i < nbAnimaux; i++) {
        if (strcmp(Animaux[i].nom, nom) == 0) {
            return 1;
        }
    }
    return 0;
}

// Saisie sécurisée d'un nom
void saisirNom(char nom[]) {
    int nomValide = 0;
   
    while (!nomValide) {
        printf("Nom de l'animal : ");
        scanf("%s", nom);
        viderBuffer();
       
        if (!estNomValide(nom)) {
            printf("Erreur : Le nom ne doit contenir que des lettres, espaces et tirets.\n");
            printf("Veuillez réessayer.\n");
        } else if (nomExisteDeja(nom)) {
            printf("Erreur : Un animal avec ce nom existe déjà dans le zoo.\n");
            printf("Veuillez choisir un autre nom.\n");
        } else {
            nomValide = 1;
        }
    }
}

// Saisie sécurisée d'une espèce
void saisirEspece(char espece[]) {
    printf("veulliez donner l'Espèce (lion, tigre, girafe, elephant, etc.) : ");
    scanf("%s", Animaux[nbAnimaux].espece);
}

// Saisie sécurisée d'un habitat
void saisirHabitat(char habitat[]) {
    printf("veulliez donner l'Habitat (savane, jungle, desert, aquatique, etc.) : ");
    scanf("%s", Animaux[nbAnimaux].habitat);
}

// Saisie sécurisée d'un âge
int saisirAge() {
    int age;
    printf("veulliez donner l'age (en années) : ");
    scanf("%d",&Animaux[nbAnimaux].age);
    return age;
}

// Saisie sécurisée d'un poids
float saisirPoids() {
    float poids;
    printf("veulliez donner le Poids (en kg) : ");
    scanf("%f",&Animaux[nbAnimaux].poids);
    return poids;
}

// Afficher un animal
void afficherAnimals() {
	for (i = 0; i < nbAnimaux ; i++)
    printf("ID: %d      | Nom: %s          | Espèce: %s    | Âge: %d ans | Habitat: %s | Poids: %.2f kg\n",
           Animaux[i].id, Animaux[i].nom, Animaux[i].espece, Animaux[i].age, Animaux[i].habitat, Animaux[i].poids);
}

// Trouver un animal par son ID
int trouverAnimalParId(int id) {
	int i;
    for (i = 0; i < nbAnimaux; i++) {
        if (Animaux[i].id == id) {
            return i;
        }
    }
    return -1;
}
void triParAge(struct Animal animaux[], int nbAnimaux) {
    int i, j;
    
    for (i = 0; i < nbAnimaux - 1; i++) {
        for (j = 0; j < nbAnimaux - i - 1; j++) {
            if (animaux[j].age > animaux[j+1].age) {
                // Échange des structures complètes sans pointeurs
                struct Animal temp = animaux[j];
                animaux[j] = animaux[j+1];
                animaux[j+1] = temp;
            }
        }
    }
        
       	
}

// Afficher le menu principal
void afficherMenu() {
        printf("\n+-----------------------+\n");
        printf("¦      MENU PRINCIPALE    ¦\n");
        printf("+-------------------------¦\n");
        printf("¦ 1. Ajouter              ¦\n");
        printf("¦ 2. Afficher les animaux ¦\n");
        printf("¦ 3. Modifier un animal   ¦\n");
        printf("¦ 4. Supprimer un animal  ¦\n");
        printf("¦ 5. Rechercher un animal ¦\n");
        printf("¦ 6. Statistiques         ¦\n");
        printf("¦ 0. Quitter              ¦\n");
        printf("+-------------------------+\n");
}

// Ajouter un seul animal
void ajouterAnimal() {
    if (nbAnimaux >= MAX_ANIMAUX) {
        printf("Erreur : Capacité maximale atteinte (%d animaux)\n", MAX_ANIMAUX);
        return;
    }
   
    printf("\n=== AJOUT D'UN ANIMAL ===\n");
   
    // Saisie sécurisée du nom
    saisirNom( Animaux[nbAnimaux].nom);
   
    // Saisie de l'espèce
    saisirEspece( Animaux[nbAnimaux].espece);
   
    // Saisie de l'âge
     saisirAge();
   
    // Saisie de l'habitat
    saisirHabitat( Animaux[nbAnimaux].habitat);
   
    // Saisie du poids
    saisirPoids();
    nbAnimaux++;
   
    printf("Animal ajouté avec succès ! ID: %d\n", Animaux[nbAnimaux].id);
}

// Ajouter plusieurs animaux
void ajouterPlusieursAnimaux() {
    int nombre,i;
    printf("\n=== AJOUT MULTIPLE D'ANIMAUX ===\n");
    printf("Combien d'animaux voulez-vous ajouter ? ");
    scanf("%d", &nombre);
    viderBuffer();
   
    if (nbAnimaux + nombre > MAX_ANIMAUX) {
        printf("Erreur : Impossible d'ajouter %d animaux. Capacité restante : %d\n",
               nombre, MAX_ANIMAUX - nbAnimaux);
        return;
    }
   
    for ( i = 0; i < nombre; i++) {
        printf("\n--- Animal %d/%d ---\n", i + 1, nombre);
        ajouterAnimal();
    }
   
    printf("\n%d animaux ajoutés avec succès !\n", nombre);
}

// Afficher tous les animaux
void afficherAnimaux() {
	int i;
    printf("\n=== LISTE DES ANIMAUX (%d animaux) ===\n", nbAnimaux);
   
    if (nbAnimaux == 0) {
        printf("Aucun animal dans le zoo.\n");
        return;
    }
   
    for ( i = 0; i < nbAnimaux; i++) {
        printf("%d", i + 1);
        afficherAnimal(Animaux[i]);
    }
}

// Modifier un animal
void modifierAnimal() {
    if (nbAnimaux == 0) {
        printf("Aucun animal à modifier.\n");
        return;
    }
   
    int id,i;
    printf("\n=== MODIFICATION D'UN ANIMAL ===\n");
    printf("ID de l'animal à modifier : ");
    scanf("%d", &id);
    viderBuffer();
   
    int index = trouverAnimalParId(id);
    if (index == -1) {
        printf("Animal avec ID %d non trouvé.\n", id);
        return;
    }
   
    printf("Animal trouvé : ");
    afficherAnimal(Animaux[index]);
   
    printf("\nNouvelles informations :\n");
   
    // Saisie du nouveau nom avec vérification
    printf("Nouveau nom [%s] : ", Animaux[index].nom);
    char nouveauNom[MAX_NOM];
    scanf("%s", nouveauNom);
    viderBuffer();
   
    if (strlen(nouveauNom) > 0) {
        if (estNomValide(nouveauNom)) {
            // Vérifier si le nouveau nom n'existe pas déjà (sauf pour l'animal actuel)
            int nomDejaUtilise = 0;
            for ( i = 0; i < nbAnimaux; i++) {
                if (i != index && strcmp(Animaux[i].nom, nouveauNom) == 0) {
                    nomDejaUtilise = 1;
                    break;
                }
            }
           
            if (!nomDejaUtilise) {
                strcpy(Animaux[index].nom, nouveauNom);
            } else {
                printf("Erreur : Ce nom est déjà utilisé par un autre animal.\n");
            }
        } else {
            printf("Erreur : Nom invalide. Utilisez seulement des lettres, espaces et tirets.\n");
        }
    }
   
    // Saisie de la nouvelle espèce
    printf("Nouvelle espèce [%s] : ", Animaux[index].espece);
    char nouvelleEspece[MAX_ESPECE];
    scanf("%s", nouvelleEspece);
    viderBuffer();
    if (strlen(nouvelleEspece) > 0) {
        strcpy(Animaux[index].espece, nouvelleEspece);
    }
   
    // Saisie du nouvel âge
    printf("Nouvel âge [%d] : ", Animaux[index].age);
    int nouvelAge;
    if (scanf("%d", &nouvelAge) == 1) {
        Animaux[index].age = nouvelAge;
    }
    viderBuffer();
   
    // Saisie du nouvel habitat
    printf("Nouvel habitat [%s] : ", Animaux[index].habitat);
    char nouvelHabitat[MAX_HABITAT];
    scanf("%s", nouvelHabitat);
    viderBuffer();
    if (strlen(nouvelHabitat) > 0) {
        strcpy(Animaux[index].habitat, nouvelHabitat);
    }
   
    // Saisie du nouveau poids
    printf("Nouveau poids %.2f : ",Animaux[index].poids);
    float nouveauPoids;
    if (scanf("%f", &nouveauPoids) == 1) {
        Animaux[index].poids = nouveauPoids;
    }
    viderBuffer();
   
    printf("Animal modifié avec succès !\n");
}

// Supprimer un animal
void supprimerAnimal() {
    if (nbAnimaux == 0) {
        printf("Aucun animal à supprimer.\n");
        return;
    }
   
    int id;
    printf("\n=== SUPPRESSION D'UN ANIMAL ===\n");
    printf("ID de l'animal à supprimer : ");
    scanf("%d", &id);
    viderBuffer();
   
    int index = trouverAnimalParId(id);
    if (index == -1) {
        printf("Animal avec ID %d non trouvé.\n", id);
        return;
    }
   
    printf("Animal à supprimer : ");
    afficherAnimal(Animaux[index]);
   
    char confirmation;
    printf("Êtes-vous sûr de vouloir supprimer cet animal ? (o/n) : ");
    scanf(" %c", &confirmation);
    viderBuffer();
   
    if (confirmation == 'o' || confirmation == 'O') {
        // Décalage des éléments pour supprimer l'animal
        for (i = index; i < nbAnimaux - 1; i++) {
            Animaux[i] = Animaux[i + 1];
        }
        nbAnimaux--;
        printf("Animal supprimé avec succès !\n");
    } else {
        printf("Suppression annulée.\n");
    }
}

// Afficher les statistiques
void afficherStatistiques() {
    printf("\n=== STATISTIQUES DU ZOO ===\n");
    printf("Nombre total d'animaux : %d\n", nbAnimaux);
   
    if (nbAnimaux == 0) {
        return;
    }
   
    // Statistiques par espèce
    printf("\n--- Répartition par espèce ---\n");
    char especes[MAX_ANIMAUX][MAX_ESPECE];
    int countEspeces[MAX_ANIMAUX] = {0};
    int nbEspeces = 0,i,j;
   
    for ( i = 0; i < nbAnimaux; i++) {
        int trouve = 0;
        for ( j = 0; j < nbEspeces; j++) {
            if (strcmp(Animaux[i].espece, especes[j]) == 0) {
                countEspeces[j]++;
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            strcpy(especes[nbEspeces],Animaux[i].espece);
            countEspeces[nbEspeces] = 1;
            nbEspeces++;
        }
    }
   
    for ( i = 0; i < nbEspeces; i++) {
        printf("- %s : %d animal(s)\n", especes[i], countEspeces[i]);
    }
   
    // Statistiques par habitat
    printf("\n--- Répartition par habitat ---\n");
    char habitats[MAX_ANIMAUX][MAX_HABITAT];
    int countHabitats[MAX_ANIMAUX] = {0};
    int nbHabitats = 0;
    for (i=0; i < nbAnimaux; i++) {
        int trouve = 0;
        for ( j = 0; j < nbHabitats; j++) {
            if (strcmp(Animaux[i].habitat, habitats[j]) == 0) {
                countHabitats[j]++;
                trouve = 1;
                break;
            }
        }
        if (!trouve) {
            strcpy(habitats[nbHabitats], Animaux[i].habitat);
            countHabitats[nbHabitats] = 1;
            nbHabitats++;
        }
    }
   
    for (i=0; i < nbHabitats; i++) {
        printf("- %s : %d animal(s)\n", habitats[i], countHabitats[i]);
    }
   
    // Âge moyen et poids moyen
    float ageMoyen = 0, poidsMoyen = 0;
    int ageMin = Animaux[0].age, ageMax = Animaux[0].age;
    float poidsMin = Animaux[0].poids, poidsMax = Animaux[0].poids;
   
    for (i=0; i < nbAnimaux; i++) {
        ageMoyen += Animaux[i].age;
        poidsMoyen += Animaux[i].poids;
       
        if (Animaux[i].age < ageMin) ageMin = Animaux[i].age;
        if (Animaux[i].age > ageMax) ageMax = Animaux[i].age;
        if (Animaux[i].poids < poidsMin) poidsMin = Animaux[i].poids;
        if (Animaux[i].poids > poidsMax) poidsMax = Animaux[i].poids;
    }
   
    ageMoyen /= nbAnimaux;
    poidsMoyen /= nbAnimaux;
   
    printf("\n--- Statistiques générales ---\n");
    printf("Âge moyen : %.1f ans\n", ageMoyen);
    printf("Âge min/max : %d - %d ans\n", ageMin, ageMax);
    printf("Poids moyen : %.2f kg\n", poidsMoyen);
    printf("Poids min/max : %.2f - %.2f kg\n", poidsMin, poidsMax);
}

// FONCTION MAIN À LA FIN
int main() 
{
    int choix;
   
    printf("=== GESTIONNAIRE DU ZOO ===\n");
   
    do {
        afficherMenu();
        printf("Votre choix : ");
        scanf("%d", &choix);
        viderBuffer();
       
        switch(choix) 
		{
            case 1:
            	 printf("\n                            +-------------------------+\n");
                 printf("                            |      MENU d'ajout       |\n");
                 printf("                            +-------------------------|\n");
                 printf("                            | 1. Ajouter un animal    |\n");
                 printf("                            | 2. Ajouter des  animaux |\n");
                 printf("                            | 7. Quitter              |\n");
                 printf("                            +-------------------------+\n");
                 printf("Veuiller donner le choix : ");
                 scanf("%d",&choix);
                 do
				 {
					 if(choix==1)
					 {
	                   ajouterAnimal();
	                   break;
	                  }
	                 else if(choix==2)
					 {
	                      ajouterPlusieursAnimaux();
	                      break;
	                  }
	                 else
	                 afficherMenu();
                 }while(choix<=2);
                 break;
            case 2:
            	 printf("\n                            +-------------------------------------------------+\n");
                 printf("                            |                   MENU STATISTIQUES              |\n");
                 printf("                            +--------------------------------------------------|\n");
                 printf("                            | 1. Afficher sans tri                  .          |\n");
                 printf("                            | 2. Afficher trier avec nom                       |\n");
                 printf("                            | 3. Afficher trier par age(du petit au plus grand)|\n");
                 printf("                            | 6. Quitter                                       |\n");
                 printf("                            +--------------------------------------------------+\n");
                 printf("Veuiller donner le choix : ");
                 scanf("%d",&choix);
                 if(choix==1)
				 {
                     afficherAnimaux();
                 }
                 else if(choix==2) 
				 {
                  triParAge(Animaux,nbAnimaux);
                  afficherAnimals();
                  } 
				 else 	
                   break;
            case 3:
                 modifierAnimal();
                break;
            case 4:
                supprimerAnimal();
                break;
            case 5:
                 printf("\n                            +--------------------------------------------+\n");
                 printf("                            |                   MENU STATISTIQUES          |\n");
                 printf("                            +----------------------------------------------|\n");
                 printf("                            | 1. Nombre total d'animaux dans le zoo.       |\n");
                 printf("                            | 2. Âge moyen des animaux                     |\n");
                 printf("                            | 3. Plus vieux et plus jeune animal          |\n");
                 printf("                            | 5. Afficher les espèces les plus représentées|\n");
                 printf("                            | 6. Quitter                                   |\n");
                 printf("                            +----------------------------------------------+\n");
                 printf("Veuiller donner le choix : ");
                 scanf("%d",&choix);
                afficherStatistiques();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide ! Veuillez réessayer.\n");
       
        printf("\n");
    }
    } while(choix != 0);
    return 0;   
}
