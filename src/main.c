// Create by natword //
#include <stdio.h>
#include "gestionlivre.h"

int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("Erreur d'argument de la ligne de commande \n");
        return -1;
    }
    printf("BIENVENU DANS CETTE INTERFACE DE GESTION DES LIVRES DANS UNE BIBLIOTHEQUES \n");
    char continuer = 1;
    hashTable ht = loadFile(argv[1]);

    while (continuer != 0) {
        int choix;
        printf("0 - Quitter\n ");
        printf("1 - Regarder les livres dans la bibliotheque \n");
        printf("2 - ajouter un livre dans la bibliotheque \n");
        printf("3 - Supprimer un livre dans la bibliotheque \n");
        printf("4 - Rechercher un livre dans la bibliotheque \n");

        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficherBibliotheque(ht);
                printf("\n");
                break;

            case 2:
                livre newBook = newLivre();
                int position = hashCode(newBook.nom[0]);
                insererLivre(&ht.elt[position], newBook);
                printf("Livre ajoute \n");
                break;

            case 3:
                char *supp = calloc(50, sizeof(char));
                printf("Saisir le livre a supprimer de la bibliotheque :");
                scanf("%s", supp);
                supprimerLivre(&ht, supp);
                free(supp);
                break;

            case 4:
                char *rech = calloc(100, sizeof(char));
                printf("Saisir le livre a recherche : ");
                scanf("%s", rech);
                rechercherElement(rech, ht);
                free(rech);
                break;

            case 0:
                continuer = 0;
                break;

        }
    }

    freeBibliotheque(&ht);
    // le fichier creee va s'apparaitre dans le dossier cmake-build-debug
    modifierBibliotheque("bibliothequemodified.txt", ht);
    return 0;
}

