#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//PARTIE 1

char** creer_grille(int n){
   char** grille=(char**)malloc((n)*sizeof(char*));
   int i,j;
   for(i=0;i<n;i++){
      grille[i]=(char*) malloc((n)*sizeof(char));
      for(j=0;j<n;j++)
      {
         grille[i][j]='.';
      }
   }
   return grille;
}

void afficher_grille(char** M, int n){
   int i, j;

   for(i=0;i<n;i++){
      for(j=0;j<n;j++){
         printf("%c ", M[i][j]);
      }
      printf("\n");
   }
}

//PARTIE 2
int coup_gagnant(char** M, int n, int ci, int cj){
   int ligne=1, colonne=1, diagonale1=1, diagonale2=1;
   int i;
   char val=M[ci][cj];

   for(i=0;i<n;i++){
      ligne = ligne && (val==M[ci][i]);
      colonne = colonne && (val==M[i][cj]);
      diagonale1 = diagonale1 && (val==M[i][i]);
      diagonale2 = diagonale2 && (val==M[i][n-1-i]);

   }

   return ligne || colonne || diagonale1 || diagonale2;
}


int jouer(char** M, int n, int ci, int cj, char symbol){

   if((ci || cj)>n){
      return -1;
   }
   else{
      M[ci][cj]=symbol;
   }

   return coup_gagnant(M, n, ci , cj);
}

int main(){
   int taille=0, drapeau=0, joueur=1, coup_restant;
   int ci=0, cj=0;
   char** Matrice;
   char symbol='X';

   printf("Quelle taille de grille ?\n");
   scanf("%d", &taille);

   coup_restant=taille*taille;


   Matrice=creer_grille(taille);

   while(drapeau==0 && coup_restant>0){

      afficher_grille(Matrice,taille);
      printf("Joueur %d (%c) doit jouer, entrez ligne et colonne\n", joueur, symbol);
      scanf("%d %d", &ci, &cj);

      drapeau=jouer(Matrice, taille, ci, cj, symbol);

      if(drapeau != -1){
         joueur= joueur%2+1;
         if(joueur==2)
            symbol ='O';
         else
            symbol ='X';
         coup_restant--;
      }
      else{
         printf("Erreur\n");
      }
   }

   afficher_grille(Matrice,taille);
   if(drapeau==1){
      printf("Joueur %d a gagné\n", joueur%2+1);
   }
   else
   {
      printf("Egalité: pas de vainqueur.\n");
   }
   return 0;

}
