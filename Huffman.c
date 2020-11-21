#include "Huffman.h"



void trie(Noeud tab[]) {
    int i,j,memo,trier;

    assert(tab != NULL);

    for (i=NBLETTRES-1; i>=1; i--){
        trier = 1;
        for (j=0; j<i; j++) {
            if (tab[j+1].occur < tab[j].occur) {
                memo = tab[j+1].occur;
                tab[j+1].occur = tab[j].occur;
                tab[j].occur = memo;
                trier = 0;
            }
        if (trier)
            return;
        }
    }
}


int compteLettres(FILE *in, Noeud tab[]) {

    int caractereActuel;
    char ascii;
    int i;
    int trier;
    int nb_lettre = 0;
    assert(tab != NULL);
    assert(in != NULL);

    for (i=0; i<NBLETTRES; i++) {
        tab[i].lettre = '';
        tab[i].occur = 0;
        tab[i].fg = 0;
        tab[i].fd = 0;
    }

    do {
        caractereActuel = fgetc(in);
        tab[caractereActuel].occur++;
        char ascii = (char)caractereActuel;
        if (tab[caractereActuel].lettre == '')
            tab[caractereActuel].lettre = ascii;
            nb_lettre++;

    } while(caractereActuel != EOF);

    trie(tab);

    return nb_lettre;

}

int plusPetit(Noeud tab[], int *prem_feuille, int *prem_noeud, int noeud_libre) {
    int plus_petit = 0;

    if(*prem_feuille < NBLETTRES && *prem_noeud < noeud_libre) {
        if(tab[*prem_feuille].occur < tab[*prem_noeud].occur) {
            plus_petit = *prem_feuille;
            *prem_feuille += 1;
        }
        else {
            plus_petit = *prem_noeud;
            *prem_noeud += 1;
        }
    }

    else if(*prem_feuille == NBLETTRES  ) {
        
        plus_petit = *prem_noeud;
        *prem_noeud += 1;
        return plus_petit;
    }

    else {
        plus_petit = *prem_feuille;
        *prem_feuille += 1;
        return plus_petit;
    }

    return plus_petit;
}


int construitArbre(Noeud tab[], int taille) {
    int i;
    int
    for (i = 0; i < NBLETTRES; i++)
        if (tab[i].occur == 1)
            

    while(noeud_libre<NBLETTRE+1){
        
        premierNoeud = plus_petit(tab, &prem_feuille, &prem_noeud, noeud_libre);
        secondNoeud = plus_petit(tab, &prem_feuille, &prem_noeud, noeud_libre);
        tab[noeud_libre].occur = tab[premierNoeud].occur + tab[secondNoeud].occur;
        tab[noeud_libre].fg = premierNoeud;
        tab[noeud_libre].fd = secondNoeud;
        noeud_libre++;
    }

    return noeud_libre - 1;
}



