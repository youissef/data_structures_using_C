#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure de nœud
typedef struct Liste_Chainee
{
    char nom[20];
    char prenom[20];
    float note;
    struct Liste_Chainee *suivant;
} LSC;

// les  variables globales
LSC *Debut = NULL;
LSC *lsup = NULL; 
LSC *linf = NULL;  

//nouveau nœud
LSC *Nouveau_Noeud(char nom[20], char prenom[20], float note)
{
    LSC *nv = (LSC *)malloc(sizeof(LSC));
    if (nv != NULL)
    {
        strcpy(nv->nom, nom);
        strcpy(nv->prenom, prenom);
        nv->note = note;
        nv->suivant = NULL;
    }
    return nv;
}

// insérer un nœud au début 
void inserer_debut(char nom[20], char prenom[20], float note)
{
    LSC *nv = Nouveau_Noeud(nom, prenom, note);
    if (nv != NULL)
    {
        nv->suivant = Debut;
        Debut = nv;
    }
}

// insérer un nœud à la fin 
void inserer_fin(char nom[20], char prenom[20], float note)
{
    LSC *aide, *nv = Nouveau_Noeud(nom, prenom, note);
    aide = Debut;
    if (nv != NULL)
    {
        if (Debut == NULL)
        {
            Debut = nv;
        }
        else
        {
            while (aide->suivant != NULL)
            {
                aide = aide->suivant;
            }
            aide->suivant = nv;
        }
    }
}

// libérer la mémoire
void liberer_memoire()
{
    LSC *temp;
    while (Debut != NULL)
    {
        temp = Debut;
        Debut = Debut->suivant;
        free(temp);
    }
    lsup = NULL;
    linf = NULL;
}

// diviser la classe en deux groupes 
void diviser_classe()
{
    LSC *aide1, *x;
    aide1 = Debut;
    while (aide1 != NULL)
    {
        x = Nouveau_Noeud(aide1->nom, aide1->prenom, aide1->note);
        if (x != NULL)
        {
            if (aide1->note >= 10)
            {
                if (lsup == NULL)
                    lsup = x;
            }
            else
            {
                if (linf == NULL)
                    linf = x;
            }
        }
        aide1 = aide1->suivant;
    }
}

// afficher les étudiants de chaque groupe 
void afficher_groupes_iteratif(LSC *liste)
{
    LSC *temp = liste;
    while (temp != NULL)
    {
        printf("%s %s %.2f\n", temp->nom, temp->prenom, temp->note);
        temp = temp->suivant;
    }
}

// trier les étudiants par note
void trier(LSC *L)
{
    LSC *i, *j, *min;
    float aux1;
    char aux2[20];
    for (i = L; i->suivant != NULL; i = i->suivant)
    {
        min = i;
        for (j = i->suivant; j != NULL; j = j->suivant)
        {
            if (j->note < min->note)
                min = j;
        }
        // Échanger les données des nœuds si nécessaire
        if (min != i)
        {
            aux1 = i->note;
            i->note = min->note;
            min->note = aux1;
            strcpy(aux2, i->nom);
            strcpy(i->nom, min->nom);
            strcpy(min->nom, aux2);
            strcpy(aux2, i->prenom);
            strcpy(i->prenom, min->prenom);
            strcpy(min->prenom, aux2);
        }
    }
}

int main()
{
    // pour tester
    inserer_debut("youssef","hachimi",16);
    inserer_debut("yahya","mohib",14);
    inserer_debut("hamza","mouanid",18);
    inserer_debut("ayoub","lchehb",8);
    
    // Affichage de la liste initiale
    printf("Liste initiale :\n");
    afficher_groupes_iteratif(Debut);
    printf("\n");

    // Division de la classe en deux groupes
    diviser_classe();

    // Affichage des deux groupes
    printf("Liste des etudiants admis :\n");
    afficher_groupes_iteratif(lsup);
    printf("\n");

    printf("Liste des etudiants non admis :\n");
    afficher_groupes_iteratif(linf);
    printf("\n");

    // Trier les étudiants admis par ordre de mérite (note)
    trier(lsup);

    // Affichage de la liste des étudiants admis triée
    printf("Liste des etudiants admis triee par ordre de merite :\n");
    afficher_groupes_iteratif(lsup);
    printf("\n");

    // Libération de la mémoire utilisée par la liste chaînée
    liberer_memoire();

    return 0;
}
