#ifndef GESTIONLIVRE_H
#define GESTIONLIVRE_H
#include <stdio.h>
#include <stdlib.h>
#define HASHSIZE 26
typedef struct {
    char nom[100];
    char genre[50];
    char auteur[100];
    int annee;
}livre;

typedef struct listLivre {
    livre data;
    struct listLivre *next;
}listLivre;

typedef struct {
    char key;
    listLivre *head;
}hashNode;

typedef struct {
    hashNode elt[HASHSIZE];
}hashTable;


livre newLivre() ;
int hashCode(char key) ;
void insererLivre(hashNode *biblio, livre newLivre) ;
hashTable initialiserHashTable();
hashTable loadFile (char *fileName);
void afficherBibliotheque (hashTable ht);
void supprimerLivre (hashTable *ht, char *name);

void rechercherElement(char *elt, hashTable ht);

void modifierBibliotheque (char *filename, hashTable ht);
void freeBibliotheque(hashTable *ht);



#endif //GESTIONLIVRE_H
