#include <stdio.h>lg
#include <stdlib.h>

//Constante de TAILLE x, x doit etre un nombre impaire pour que le carre magique puisse fonctionner
#define TAILLE 7

//CREATION DE LA STRUCTURE position pour le deplacement en x et en y dans le tableau
typedef struct t_Position
{
	int x;
	int y;
}t_Position;

// PROTOTYPES
void intitailisation (int tableau[TAILLE][TAILLE], t_Position position);
void verification (int tableau[TAILLE][TAILLE], t_Position position);
void affichage (int tableau[TAILLE][TAILLE]);

int main ()
{
    //VARIABLES
    int a,b =0;
	int tableau[TAILLE][TAILLE];
	t_Position position;  //Variable position de type (de structure) t_Position

    //PROCEDURE INITIALISATION
    intitailisation (tableau, position);

    //Placement du curseur a la position du 1 (centre du tableau en y et centre du tableau -1 en x)
	position.x = TAILLE/2 -1;
	position.y = TAILLE/2;

    //PROCEDURE VERIFICATION
    verification (tableau,position);

    //PROCEDURE AFFICHAGE
    affichage (tableau);

	return 0;
}

// Cette Procedure initialise le tableau en le remplissant de 0.
//Les paramettres sont le tableau et la position
void intitailisation (int tableau[TAILLE][TAILLE], t_Position position)
{
	//SET TABLEAU A 0 A L'AIDE D'UNE DOUBLE BOUCLE
	for (int a=0;a<TAILLE;a++){
		for (int b=0;b<TAILLE;b++){
			tableau[a][b]=0;
        }
    }
}
//Cette Procedure verifie l'etat des cellules (occupé par un nombre, hors du tableau (dans le doute j'ai protégé les 4 cotés du tableau)) et remplie le tableau grace a la boucle while
//Les paramettres sont le tableau et la position
void verification (int tableau[TAILLE][TAILLE], t_Position position)
{
    //VARIABLES
    //Création d'un pointeur *pt qui pointe vers la position
    t_Position *pt = &position;
	int valeur =1;

	//BOUCLE DE REMPLISSAGE
    	while (valeur <= TAILLE * TAILLE) // TAILLE * TAILLE car le nombre de valeur a insérer est égale au carré du coté (TAILLE)
	{
		if (pt->x <0) //si le curseur sort par le haut, il retourne en bas
			pt->x = TAILLE - 1; // -1 car TAILLE = 5 donc 0-5 donne 6 lignes

		if (pt->x >=TAILLE) // si le curseur sort par le bas, il retourne en haut ( >= car TAILLE = 5, donc de 0->5 donne 6 lignes)
			pt->x = 0;

		if (pt->y < 0) //si le curseur sort par la gauche, il retourne à droite
			pt->y = TAILLE - 1;

		if (pt->y >=TAILLE) // si le curseur sort par la gauche il retourne a droite
		pt->y = 0;

        // si la cellule est occupé par un nombre autre que 0, le curseur se deplace
		if (tableau[position.x][position.y] != 0)
		{
			pt->x = (pt->x -1);
			pt->y -= 1;
		}
		// Si tout est normal, pas de hors cadre, pas de chiffre present, alors on fait le mouvement normal
		else
		{
			tableau[pt->x][pt->y] = valeur;
			pt->x--; pt->y++; valeur++;
		}
	}
}
//cette procedure permet d'afficher le tableau precedement rempli
//On utilisera comme paramettre le tableau
void affichage (int tableau[TAILLE][TAILLE])
{
    int a,b =0;
        // DOUBLE BOUCLE D'AFFICHAGE
    	for (a =0; a<=TAILLE-1; a++)
	{
		for (b=0; b<=TAILLE-2; b++)
		{
			printf("%i    ", tableau[a][b]);
		}
		printf("%i\n", tableau[a][b]);
	}

}
