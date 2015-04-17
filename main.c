#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "joueur.h"

int main()
{
    joueur * j = alloue_joueur();
    grille * g = creer_grille(j);
    while(42)
    {
        afficher_grille(g, j);
        deplacement(g, j);
    }
    suppr_joueur(j);
    suppr_grille(g);
    return 0;
}
