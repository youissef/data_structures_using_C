#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int sommet;
    int taille;
    int pile[30];
} myPile;

int estpleinne(myPile p) {
    return p.sommet == p.taille;
}

int PileVide(myPile p) {
    return p.sommet == 0;
}

void empiler(myPile* p, int v) {
    p->pile[p->sommet] = v;
    p->sommet++;
}

int depiler(myPile* p) {
    p->sommet--;
    return p->pile[p->sommet];
}

int main() {
    myPile P1, P2;
    int n;
    
    printf("Enter la taille max de pile P1: ");
    scanf("%d", &P1.taille);
    
    P1.sommet = 0; // Initialize stack top
    
    while (!estpleinne(P1)) {
        printf("Donner une valeur : ");
        scanf("%d", &n);
        empiler(&P1, n);
    }
    
    printf("\nP1 Contents:\n");
    while (!PileVide(P1)) {
        printf("%d ", depiler(&P1));
    }
    
    return 0;
}
