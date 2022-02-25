#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(){


int N =10;
static char mots [10][10]= {"ELEMENT","BONJOUR", "BELLE", "MECHANT","ETUDIANT", "BRAVO","TELECOM", "REUSSITE","INGENIEUR", "GENIE" };
int coups , j,i , score =0 ;
char lettre ;
bool test_trouve ;
printf ("*********** Bienvenue dans le jeu mots secrets ! ***********\n");
printf(" Vous avez 10 mot a trouver\n \n");
char mot_trouve [20];
for (j =0; j<N; j++){
coups = 3;

printf ("vous avez  %d coups d'essai\n\n", coups);
	for (i =0; i<strlen(mots[j]); i++){
	mot_trouve [i]= '_';
  }
mot_trouve [strlen(mots[j])]='\0';
printf(" CHERCHER MOT : %d \n", j+1);
do {
	test_trouve=false ;
	
	printf("proposez une lettre : \n");
	scanf(" %c",&lettre );
	
	if(lettre>= 'a' && lettre<= 'z') {
        lettre = lettre -32;
      }
    
	for (i= 0; i<strlen(mots[j]); i++){
		if (lettre== mots[j][i]){
			test_trouve =true;
			mot_trouve[i]=lettre;
		}
	}
	if (test_trouve==false){
		coups = coups-1;
		printf("Erreur \n");
		printf("################################### \n");
	}
	if (coups>0){
    	if (strcmp (mot_trouve,mots[j])!=0){
    		if (coups<3){
	           printf("il vous reste %d coups a jouer \n", coups);
	       }
         	printf("%s\n", mot_trouve); 	
     }
   }
	if (strcmp (mot_trouve,mots[j])==0){
		printf("%s\n", mot_trouve); 	
		printf("FELICITATION !\n");
		printf("################################### \n ");
		score ++;
		if (j+1==N){
				printf ("            FIN DE JEUX             \n");
			printf("******************************************\n");
		    printf("*                                        *\n");
		    printf("*                                        *\n");
		    printf("*     votre score est : %d / %d           *\n",score, N);
            printf("*                                        *\n");
            printf("*                                        *\n");
			printf("******************************************\n");;	
		}	
	}
	if (coups == 0){
		if(j<2){
			printf("OUPS... ");
		printf("Vous avez encore %d mot a trouver  \n", N-(j+1));
		}else{
			printf ("            FIN DE JEUX             \n");
			printf("******************************************\n");
		    printf("*                                        *\n");
		    printf("*                                        *\n");
		    printf("*     votre score est : %d / %d           *\n",score, N);
            printf("*                                        *\n");
            printf("*                                        *\n");
			printf("******************************************\n");
		}
	}


}while (coups>0 && strcmp (mot_trouve,mots[j]) !=0);


} 
return 0;
}


