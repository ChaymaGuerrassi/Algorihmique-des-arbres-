//
//  main.c
//  TP7-Tas
//

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int estTas(int tab[], int taille){
    assert(taille != 0);
    int i;
    int parent;
    

    for (i = 1; i < taille; i++){
        parent = (i-1)/2;
        if (tab[i] < tab[parent])
            return 0;
    }
    
    return 1;
}

void affiche_tas(int tab[], int taille){
    assert(taille != 0);
    
    int i;
    if (estTas(tab, taille)){
        for (i = 0; i < taille; i++)
            printf("-----");
        
        printf("\n");
        
        for (i = 0; i < taille; i++)
            printf("| %d ", tab[i]);
        
        printf("|");
        printf("\n");
        for (i = 0; i < taille; i++)
            printf("-----");
        
        
        printf("\n");
        
    }
}

int enumPermutation(int tab[], int premier, int n){
    assert(n != 0);
    int i;
    int cpt_permutation;
    
    cpt_permutation = 0;
    
    if (premier > n)
        return 1;
    
    if (premier <= n){
        /* Parcours pour placer premier à la première case vide*/
        for(i = 0; i < n; i++){
            if (tab[i] == 0){
                tab[i] = premier;
                cpt_permutation += enumPermutation(tab, premier+1, n);
                tab[i] = 0;
            }
        }
    }
    
    if (estTas(tab, n))
        affiche_tas(tab, n);
    
    return cpt_permutation;
    
}

int enumTasNaif(int tab[], int premier, int n){
    assert(n != 0);
    int i;
    int cpt_tas;
    
    cpt_tas = 0;
    
    if (premier > n){
        if (estTas(tab, n)){
            affiche_tas(tab, n);
            return 1;
        }
    }
    
    if (premier <= n){
        /* Parcours pour placer premier à la première case vide*/
        for(i = 0; i < n; i++){
            if (tab[i] == 0){
                tab[i] = premier;
                cpt_tas += enumTasNaif(tab, premier+1, n);
                
                tab[i] = 0;
            }
        }
    }
    
    return cpt_tas;
}

int main(int argc, const char * argv[]) {

    int tab[5] = {0, 0, 0, 0, 0};

//    printf("Nombre de permutation : %d", enumPermutation(tab, 1, 5));
    printf("Nombre de tas : %d \n", enumTasNaif(tab, 1, 5));
    
    return 0;
}
