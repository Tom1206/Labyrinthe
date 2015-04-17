main : main.o grille.o joueur.o
	gcc -o main main.o grille.o joueur.o -lncurses

grille.o : grille.c grille.h
	gcc -c grille.c

joueur.o : joueur.c joueur.h
	gcc -c joueur.c

main.o : main.c grille.h joueur.h
	gcc -c main.c
