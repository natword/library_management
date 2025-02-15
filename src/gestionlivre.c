#include "gestionlivre.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
/*
 * TACHE :  fonction qui permet de creer un nouveau livre
 *
 *
 */
livre newLivre() {
    livre l;
    printf("Saisir le nom du livre : ");
    scanf("%s",l.nom);
    printf("Saisir l'auteur du livre: ");
    scanf("%s",l.auteur);
    printf("Saisir la annee: ");
    scanf("%d",&l.annee);
    printf("Saisir la genre du livre: ");
    scanf("%s",l.genre);
    return l;
}

// Fonction qui me permet d'obtenir l'indice de l'element a inserer dans le tableau de hashage
int hashCode(char key) {
    key = tolower(key);
    return (key - 'a');
}

// Fonction qui permet d'inserer un element dans le tableau de hashage
void insererLivre(hashNode *biblio, livre newLivre) {
    int position = hashCode(newLivre.nom[0]);
    listLivre *newL = malloc(sizeof(listLivre));
    if (newL == NULL) {
        printf("Erreur d'allocation de la memoire \n");
        exit(1);
    }
    newL->data = newLivre;
    newL -> next = biblio->head;
    biblio->head = newL;


}

// Fonction qui permet d'initialiser un hashtable

hashTable initialiserHashTable() {
    hashTable ht;
    for (int i = 0; i < HASHSIZE; i++) {
        ht.elt[i].key = 'a' + i;
        ht.elt[i].head = NULL;
    }
    return ht;
}

/*
 *  Le fichier sera sous la forme
 *
 *  nom_livre1 nom_auteur genre anneedepublication
 *  nom_livre2 nom_auteur genre anneedepublication
 *  nom_livre3 nom_auteur genre anneedepublication
 */
hashTable loadFile (char *fileName) {
    hashTable ht = initialiserHashTable();
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Erreur d'open file \n");
        exit(1);
    }
    livre newLivre;
    while (fscanf(file, "%99s %99s %99s %i", &newLivre.nom, &newLivre.auteur, &newLivre.genre, &newLivre.annee) == 4) {
        int position = hashCode(newLivre.nom[0]);
        insererLivre(&ht.elt[position], newLivre);
    }
    afficherBibliotheque(ht);
    printf("\n");
    fclose(file);
    return ht;
}

// Procedure qui permet d'afficher les elements d'une bibliotheque
void afficherBibliotheque (hashTable ht) {
    printf("Nom du Livre     Auteur    Genre    Annee \n");
    for (int i = 0; i < HASHSIZE; i++) {
        listLivre *aux = ht.elt[i].head;
        while (aux != NULL) {
            printf("%s ", aux->data.nom);
            printf("%s ", aux->data.auteur);
            printf("%s ", aux->data.genre);
            printf("%i ", aux->data.annee);
            printf("\n");
            aux = aux->next;
        }

    }
}


// Procedure qui permet de supprimer un livre dans la biliotheque
void supprimerLivre (hashTable *ht, char *name) {
    int position = hashCode(name[0]);
    listLivre *aux = ht->elt[position].head;
    if (aux == NULL) {
        printf("element non existant \n");
        return;
    }
    // Si le premier element da la liste est l'element a suppriemer alors
    if (strcmp(name, aux->data.nom) == 0) {
        listLivre *temp = ht->elt[position].head;
        ht->elt[position].head = ht->elt[position].head->next;
        printf("Livre supprimer ! \n");
        free(temp);
    }

    else {
        while (aux->next != NULL && strcmp(name, aux->next->data.nom) != 0) {
            aux = aux->next;
        }
        if (aux->next != NULL) {
            listLivre *temp = aux->next;
            aux->next = temp->next;
            printf("Livre supprimer ! \n");
            free(temp);
        }
        else {
            printf("Element non existant \n");
        }
    }
}

// Procedure qui permet de rechercher un elment dans la bibliotheque et de l'afficher
void rechercherElement(char *elt, hashTable ht) {
    int position = hashCode(elt[0]);
    listLivre *aux = ht.elt[position].head;
    while (aux != NULL && strcmp(elt, aux->data.nom) != 0) {
        aux = aux->next;
    }
    if (aux != NULL) {
        printf("%s %s %s %i \n", aux->data.nom, aux->data.auteur, aux->data.genre, aux->data.annee);
    }
    else {
        printf("Element non existant \n");
    }
}

void modifierBibliotheque (char *filename, hashTable ht) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erreur d'open file \n");
        exit(1);
    }
    for (int i = 0; i < HASHSIZE; i++) {
        listLivre *aux = ht.elt[i].head;
        while (aux != NULL) {
            fprintf(file, "%s %s %s %i\n", aux->data.nom, aux->data.auteur, aux->data.genre, aux->data.annee);
            aux = aux->next;
        }
    }
    fclose(file);
}

void freeBibliotheque(hashTable *ht) {
    for (int i =0 ; i < HASHSIZE; ++i) {
        listLivre *aux = ht->elt[i].head;
        while (aux != NULL) {
            listLivre *temp = aux;
            aux = aux->next;
            free(temp);
        }
    }
}


