#ifndef __COMPTAGE__
#define __COMPTAGE__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define  NBLETTRES 256
#define  NBNOEUDS (NBLETTRES * 2 + 1)


typedef  struct {
    unsigned char lettre;
    int occur;
    int fg;
    int fd;
} Noeud;


typedef  struct {
    int  taille;
    char *code;
} Code;


/*trie par nombre d’occurrences croissant les lettres apparaissant dans in et les place dans tab. 
Renvoyer le nombre de lettres différentes présentes dans in.*/
int compteLettres(FILE *in, Noeud tab[]);
/*Trie le tab par ordre croissant d'occurance.*/
void trie(Noeud tab[]);


#endif