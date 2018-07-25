#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int main ()
{
   int x = 0;
   int y = 0;
   int z = 0;
   int i = 0;
   int alea = 0;
   int temporaire;
   int grilleR[9][9];
   int k = 0 ;
   int casevide = 0;
   int zone1 = 0;
   int zone2 = 0;
   int verification;
   int grille[9][9] = {
                    	{1,2,3,4,5,6,7,8,9},
                    	{4,5,6,7,8,9,1,2,3},
                    	{7,8,9,1,2,3,4,5,6},
                    	{2,3,1,5,6,4,8,9,7},
                    	{5,6,4,8,9,7,2,3,1},
                    	{8,9,7,2,3,1,5,6,4},
                    	{3,1,2,6,4,5,9,7,8},
                    	{6,4,5,9,7,8,3,1,2},
                    	{9,7,8,3,1,2,6,4,5},
                	};


//Niveau de difficulté
   printf("Saisir le niveau de difficulte \n\n");
   printf("Entrez :\n\n -2 pour facile\n -5 pour moyen\n -7 pour difficile\n -9 pour SUDOKU MASTER\n\n");

   k = getche()-48;



// Melange de la grille
   srand(time(NULL));

   while (x < 9)
   {
      if (x < 3)
         alea = (rand() % (3));
      else if (x >= 3 && x < 6)
         alea = (rand() % (3)) + 3;
      else
         alea = (rand() % (3)) + 6;
    	// par ligne
      y = 0;
      while (y < 9)
      {
         temporaire = grille[x][y];
         grille[x][y] = grille[alea][y];
         grille[alea][y] = temporaire;
         y++;
      }
    	// par colonne
      y = 0;
      while (y < 9)
      {
         temporaire = grille[y][x];
         grille[y][x] = grille[y][alea];
         grille[y][alea] = temporaire;
         y++;
      }
      x++;
   }
	// Remplacement de la grille
   i = 0;
   while (i < 9)
   {
    	// inversion par ligne
      x = 0;
      alea = (rand() % (9)) + 1;
      while (x < 9)
      {
         y = 0;
         z = 1;
         while (y < 9)
         {
            if (grille[x][y] == z)
               grille[x][y] = alea;
            else if (grille[x][y] == alea)
               grille[x][y] = z;
            y++;
         }
         z++;
         x++;
      }
    	// inversion par colonne
      x = 0;
      alea = (rand() % (9)) + 1;
      while (x < 9)
      {
         y = 0;
         z = 1;
         while (y < 9)
         {
            if (grille[y][x] == z)
               grille[y][x] = alea;
            else if (grille[y][x] == alea)
               grille[y][x] = z;
            y++;
         }
         z++;
         x++;
      }
      i++;
   }
   for (x = 0; x < 9 ; x++ )
   {
      for (y = 0 ; y < 9 ; y++)
      {
         grilleR[x][y]=grille[x][y];
      }
   }

	// Remplissage des 0
   for (y = 0; y < 3 ; y++ )
   {
      zone1=0;
      for (x = 0 ; x < 3 ; x++)
      {
         for (casevide = 0 ; casevide < k ; casevide++)
         {
            grille[rand()%3+zone1][rand()%3+zone2]=0;
         }
         zone1=zone1+3;
      }
      zone2=zone2+3;
   }


   printf("\n ------------|-----------|------------\n");
   for (x = 0; x < 9 ; x++ )
   {
      for (y = 0 ; y < 9 ; y++)
      {
         printf(" | %d",grille[x][y]);
      }
      printf(" |");
      printf("\n ------------|-----------|------------\n");
   }

   printf("\nVeux tu voir la solution ? Si oui, il suffit d'appuyer sur une lettre\n\n");
   verification = getch();
   printf("\nLa solution est :\n");

   if (verification = 1){
      printf("\n ------------|-----------|------------\n");
      for (x = 0; x < 9 ; x++ )
      {
         for (y = 0 ; y < 9 ; y++)
         {
            printf(" | %d",grilleR[0+x][0+y]);
         }
         printf(" |");
         printf("\n ------------|-----------|------------\n");
      }
   }
   printf("\nMerci d'avoir joué!\n\n");
   verification = getch();
}






