
#include <stdio.h>
#include <stdlib.h>

typedef struct noeud{
    
    int valeur;/* étiquette du nœud */
    struct noeud *fg;/* adresse du fils gauche */
    struct noeud *fd;/* adresse du fils droit */

} CelluleM, *Arbre;



Arbre alloueNoeud(int val){
    
    Arbre tree;
    tree = (CelluleM *) malloc(sizeof(CelluleM));
    
    if (tree != NULL){
        
        tree->valeur = val;
        tree->fg = NULL;
        tree->fd = NULL;
        return tree;
    }
    
    else
        return NULL;
}

Arbre Recherche(Arbre a, int n){
/*Fonction qui renvoie le noeud d'étiquette minimum.*/
    
    if (a == NULL || a->valeur == n)
        return a;
    
    if (n < a->valeur)
        return Recherche(a->fg, n);
    
    return Recherche(a->fd, n);
    
}

int ajout(Arbre *a, int n){
/*Fonction qui renvoie 1 lors de l'ajout d'un noeud d'étiquette n à l'arbre a et 0 sinon.*/
    
    Arbre arbre = *a;
    
    if (Recherche(arbre, n)==NULL){
        
        if (arbre == NULL){
            
            arbre = alloueNoeud(n);
            return 1;
        }
        
        else if (n <= arbre->valeur)
            
            return ajout(&arbre->fg, n);
        
        return ajout(&arbre->fd, n);
    }
    
    return 0;
}

Arbre extraitMin(Arbre *a){
/*Fonction qui renvoie le noeud d'étiquette minimum.*/
    
    Arbre tmp;
    Arbre arbre = *a;
    
    if (arbre == NULL)
        return arbre;
    
    if (arbre->fg == NULL){
        tmp = arbre;
        arbre = arbre->fd;
        return tmp;
    }
    
    return extraitMin(&arbre->fg);
}

Arbre extraitMax(Arbre *a){
/*Fonction qui renvoie le noeud d'étiquette maximum.*/

    Arbre tmp;
    Arbre arbre = *a;
    
    if (arbre == NULL)
        return arbre;
    
    if (arbre->fd == NULL){
        tmp = arbre;
        arbre = arbre->fg;
        return tmp;
    }
    
    return extraitMax(&arbre->fd);
}


Arbre extrait(Arbre *a, int n){
/*Fonction qui renvoie le noeud d'étiquette n.*/

    Arbre arbre = *a;
    
    if (arbre->valeur == n || arbre == NULL)
        return arbre;
    
    if (n < arbre->valeur)
        return extrait(&arbre->fg, n);
    
    return extrait(&arbre->fd, n);
}


int VerificationABR(Arbre racine){
    /* Fonction qui applique la deuxième règle du cours pour déterminer si un arbre binaire est de recherche, elle retourne 1, ou non, elle retourne 0.*/
    
    
    if ( racine == NULL)
        return 1;
    
    if (racine->fg != NULL && racine->valeur <= racine->fg->valeur)
        return 0;
    
    if (racine->fd != NULL && racine->valeur > racine->fd->valeur)
        return 0;
    
    return VerificationABR(racine->fg) && VerificationABR(racine->fd);
}


void ParcoursInfixe(Arbre a){
    
    int i = 0;
    
    if (a != NULL){
        
        ParcoursInfixe(a->fg);
        i = a->valeur;
        printf("%d \n", i);
        ParcoursInfixe(a->fd);
        
    }
}


int main(int argc, const char * argv[]) {
    
    Arbre a = alloueNoeud(5);
    
    a->fg = alloueNoeud(1);
    a->fg->fg = alloueNoeud(11);
    a->fg->fd = alloueNoeud(11);
    a->fd = alloueNoeud(21);
    a->fd->fd = alloueNoeud(42);
    a->fd->fd->fd = alloueNoeud(15);

    Arbre recherche = Recherche(a, 15);
    printf("Recherche :");
    ParcoursInfixe(recherche);
    
    Arbre min = extraitMin(&a);
    printf("Minimum : ");
    ParcoursInfixe(min);
    
    Arbre max = extraitMax(&a);
    printf("Maximum : ");
    ParcoursInfixe(max);
    
    printf("ABR : %d \n", VerificationABR(a));

    return 0;
}
