#include "grille.h"

grille * alloue_grille(int n, int m)
{
    grille * g = (grille *) malloc(sizeof(grille));
    g -> n = n;
    g -> m = m;
    g -> content = (int **) malloc(g -> m * sizeof(int *));
    for (int i = 0; i < g -> m; i++)
        g -> content[i] = (int *) malloc(g -> n * sizeof(int));
    return g;
}

grille * creer_grille(joueur * j)
{
    FILE* fichier = NULL;
    fichier = fopen("grille.txt", "r");
    if (fichier != NULL)
    {
        int n, m;
        fscanf(fichier,"%d %d", &n, &m);
        fgetc(fichier);
        grille * g = alloue_grille(m, n);

        fscanf(fichier, "%d %d", &j -> x, &j -> y);
        fgetc(fichier);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                fscanf(fichier,"%d",&g -> content[i][j]);
            }
            fgetc(fichier);
        }
        fclose(fichier);
        return g;
    }
    else {
        printf("Impossible d'ouvrir le fichier grille.txt");
        exit (1);
    }
}

void suppr_grille(grille * g)
{
    for (int i = 0; i < g -> m; i++) {
        free (g -> content[i]);
    }
    free(g -> content);
    free(g);
}

char afficher_element(int e)
{
    switch (e) {
        case 0 :
            return '#';
            break;
        case 1 :
            return ' ';
            break;
        default :
            return ' ';
            break;
    }
}

void afficher_grille(grille * g, joueur * j)
{
    initscr();
    printw(" ");
    for (int k = 0; k < g -> m; k++)
        printw("-");
    printw("\n");
    for (int i = 1; i < g -> n + 1; i++)
    {
        for (int j = 1; j < g -> m + 1; j++)
        {
            if (j == 1)
                printw("|");
            mvprintw(i, j, "%c", afficher_element(g -> content[i-1][j-1]));
            if (j + 1 == g -> m + 1)
                printw("|");
            if (j == g -> m)
                printw("\n");
        }
    }
    printw(" ");
    for (int k = 0; k < g -> m; k++)
        printw("-");
    printw("\n");
    mvprintw(j -> y + 1, j -> x + 1, "Y");
    refresh();
}

void deplacement(grille * g, joueur * j)
{
    int t = getch();
    // z=122 q=113 s=115 d=100
    switch (t) {
        case 122 :
            if ((g -> content[j -> y - 1][j -> x] != 0) && (j -> y > 0))
                (j -> y) --;
            break;
        case 115 :
            if (g -> content[j -> y + 1][j -> x] != 0)
                (j -> y) ++;
            break;
        case 113 :
            if (g -> content[j -> y ][j -> x - 1] != 0)
                (j -> x) --;
            break;
        case 100 :
            if (g -> content[j -> y ][j -> x + 1] != 0)
                (j -> x) ++;
            break;
    }
}
