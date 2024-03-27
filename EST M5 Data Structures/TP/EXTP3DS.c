#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noeud
{
    int valeur;
    struct noeud *suivant;
} Noeud;

typedef struct
{
    Noeud *Debut;
    Noeud *Fin;
} File;

// initialisation
void initialiser(File *File)
{
    File->Debut = NULL;
    File->Fin = NULL;
}
// verfier
int FileVide(File *file)
{
    return (file->Debut == NULL);
}
// add element
void enfiler(File *file, int valeur)
{
    Noeud *nouveauNoeud = (Noeud *)malloc(sizeof(Noeud));
    if (nouveauNoeud == NULL)
    {
        printf("erreur :Impossible d'allouer de la memoire\n ");
        exit(EXIT_FAILURE);
    }
    nouveauNoeud->valeur = valeur;
    nouveauNoeud->suivant = NULL;

    if (fileVide(file))
    {
        file->Debut = nouveauNoeud;
        file->Fin = nouveauNoeud;
    }
    else
    {
        file->Fin->suivant = nouveauNoeud;
        file->Fin = nouveauNoeud;
    }
}
// Supprimer et retourner l'element en tete de file
int defiler(File *file)
{
    if (FileVide(file))
    {
        printf("Erreur : la file est vide. \n");
        exit(EXIT_FAILURE);
    }
    Noeud *noeudSupprime = file->Debut;
    int valeur = noeudSupprime->valeur;
    file->Debut = file->Debut->suivant;
    free(noeudSupprime);
    return valeur;
}
void defilerEnfiler(File *f1, File *f2)
{
    int element = defiler(f1);
    enfiler(f2, element);
}
int comparer(File *file1, File *file2)
{
    if (!FileVide(file1) && !FileVide(file2))
    {
        return (file1->Debut->valeur >= file2->Debut->valeur) ? 1 : 0;
    }
    else
    {
        printf("Erreur : une des files est est.\n");
        exit(EXIT_FAILURE);
    }
}
void trier (File *f1,File *f2,File *f3){
    while (!fileVide(f1)){
        int max_element = INT_MIN;
        while (!fileVide(f1)){
            int element = defiler(f1);
            if (element > max_element){
                max_element = element ;
            } 
            enfiler(f3,element);       
        }
        while(!fileVide(f3)){
        int element = defiler(f3);
        if(element != max_element){
            enfiler(f1, element);
        }
        else{
            enfiler(f2, element);
        }
        }
    }
}


// main function
int main(){
    File f1,f2,f3;
    initialiser(&f1);
    initialiser(&f2);
    initialiser(&f3);
    // add element:
    enfiler(&f1,5);
    enfiler(&f1,4);
    enfiler(&f1,9);
    enfiler(&f1,8);
    enfiler(&f1,3);
    // trier f1
    trier(&f1,&f2,&f3);
    int max_element = INT_MIN;
    while(!FileVide(&f2)){
        int element = defiler(&f2);
        printf("%d",element);
        if(element > max_element){
            max_element = element;
        }
    }
    printf("\n");
    // afficher le plus grand element
    printf("le plus grand element est:");
    if(max_element != INT_MIN){
        printf("%d\n",max_element);
    }
    else{
        printf("la file est vide.\n");
    }

}












// void FileVide(LSC *file)
// {
//     file->start = -1;
//     file->end = -1;
// }
// void Enfiler(LSC *file,int element){

// }
// prototype

// void FileVide();
// void Enfiler();
// void Defiler();
// void DefilerEnfiler();
// void Comparer();
//
