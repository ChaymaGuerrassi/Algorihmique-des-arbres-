//
//  union-find.h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define PERE 0
#define RANG 1
#define N 5
static unsigned int cherchePere = 0;


void Initialisation(int peres[N][2]);
int TrouveNaif(int peres[N][2], int x);
void FusionNaive(int peres[N][2], int x, int y);
int TrouveCompresse(int peres[N][2], int x);
void FusionRang(int peres[N][2], int x, int y);

