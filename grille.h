#ifndef GRILLE
#define GRILLE

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "joueur.h"

typedef struct
{
    int m;
    int n;
    int **content;
} grille;

grille * alloue_grille(int n, int m);

grille * creer_grille(joueur * j);

void suppr_grille(grille * g);

char afficher_element(int e);

void afficher_grille(grille * g, joueur * j);

void deplacement(grille * g, joueur * j);

#endif /* end of include guard: GRILLE */
