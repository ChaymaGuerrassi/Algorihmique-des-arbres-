//
// union-find.c

#include "union-find.h"
#define M 50

void Initialisation(int peres[][2]){
    /* Fonction qui initialise le tableau peres avec N ensembles d'un élement chacun. */
    
    int i;
    for (i=0; i<N; i++) {
        peres[i][PERE] = i;
        peres[i][RANG] = 1;
    }
}

int TrouveNaif(int peres[][2], int x) {
    /* Fonction qui permet de trouver le représentant d'un élément x donné en Argument. */
    
    if (peres[x][PERE] == x)
        return x;

    cherchePere++;
    return TrouveNaif(peres, peres[x][PERE]);

}

void FusionNaive(int peres[N][2], int x, int y) {
    /* Fonction qui fusionne les ensembles contenant x et y.*/

    int representant_x, representant_y;

    representant_x = TrouveNaif(peres, x);
    representant_y = TrouveNaif(peres, y);

    if (representant_x != representant_y)
        peres[representant_y][PERE] = representant_x;
    /*
        OU
        peres[representant_x][PERE] = representant_y;
    */
}


int TrouveCompresse(int peres[N][2], int x) {

    if (peres[x][PERE] != x)

        cherchePere++;
        peres[x][PERE] = TrouveCompresse(peres,peres[x][PERE]);

    return peres[x][PERE];

}

void FusionRang(int peres[][2], int x, int y) {
    
    int representant_x, representant_y;

    representant_x = TrouveNaif(peres, x);
    representant_y = TrouveNaif(peres, y);

    if (representant_x != representant_y){
        
        /* Rang de x supérieur à rang de y */
        if (peres[representant_x][RANG] > peres[representant_y][RANG]){
            peres[representant_y][PERE] = representant_x;
            peres[representant_x][RANG] += peres[representant_y][RANG];
            
        }
        /* Rang de y supérieur à rang de x */
        if (peres[representant_y][RANG] > peres[representant_x][RANG]){
            peres[representant_x][PERE] = representant_y;
            peres[representant_y][RANG] += peres[representant_x][RANG];
        }
        /* Rang de x égal au rang de y */
        if (peres[representant_y][RANG] == peres[representant_x][RANG]){
            peres[representant_y][PERE] = representant_x;
            peres[representant_x][RANG] += peres[representant_y][RANG];
        }
        
    }
        
}

int main(void) {
    
    int peres[N][2];
    int i,j = 0;
    int nombre_aleatoire;
    srand(time(NULL));
    
    
    Initialisation(peres);
    
    
    /* Affiche un couple (indice, rang) */
    printf("éléments : \n");
    for(i = 0; i < N; i++){
        printf("(%d,", peres[i][PERE]);
        printf(" %d)", peres[i][RANG]);
        printf("\n");
    }
    
    

    return 0;
}
