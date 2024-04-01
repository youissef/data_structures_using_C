#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct prior
{
    int valeur;
    int prioritaire;
    struct prior *next;
} prioritaire;
typedef struct
{
    prioritaire *sommet;
} Pile;
void initialiser(Pile *pile)
{
    pile->sommet = NULL;
}
void ajouter(Pile *pile){
    int valeur;
    prioritaire* newprior = (prioritaire*)malloc(sizeof(prioritaire));
    newprior->valeur = valeur;
    newprior->prioritaire = prioritaire;
}
void retirer(){}
