#include <stdio.h>
#include <stdlib.h>

int TailleDuTableau() {
  int size;
  scanf("%d", &size);
  printf("La Taille des tableau de jeux est : %d \n", size);
  return size;
}

int NombreDeBateaux() {
  unsigned int boat;
  scanf("%d", &boat);
  printf("Le nombre de bateau :  %d \n", boat);
  return boat;
}

void TestNombreDeBateauxA(unsigned int expectedBoats, unsigned int boatA){
  if(expectedBoats != boatA){
    printf("FIN DE PARTIE : PAS ASSEZ DE BATEAUX \n");
  }
}
void TestNombreDeBateauxB(unsigned int expectedBoats, unsigned int boatB){
  if(expectedBoats != boatB){
    printf("FIN DE PARTIE : PAS ASSEZ DE BATEAUX \n");
  }
}
unsigned int compteBateauxA(unsigned int size, unsigned AliceTb[size][size]){
  unsigned int boatA = 0;
  for(int i = 0; i <size ; i++){
    for(int j = 0; j <size; j++){
      scanf("%u",&AliceTb[i][j]);
      if(AliceTb[i][j]==1){
        boatA++;
      }
    }
  }
  return boatA;
}
unsigned int compteBateauxB(unsigned int size, unsigned BernardTb[size][size]){
  unsigned int boatB = 0;
  for(int i = 0; i <size ; i++){
    for(int j = 0; j <size; j++){
      scanf("%u",&BernardTb[i][j]);
      if(BernardTb[i][j]==1){
        boatB++;
      }
      }
    }
  return boatB;
}
void plateauAlice(unsigned int size,unsigned AliceTb[size][size]){
  for(int i = 0; i < size ; i++){
    for(int j = 0; j < size ; j++){
    scanf("%u", &AliceTb[i][j]);
}
}
}
void plateauBernard(unsigned int size,unsigned BernardTb[size][size]){
  for(int i = 0; i < size ; i++){
    for(int j = 0; j < size ; j++){
    scanf("%u", &BernardTb[i][j]);
}
}
}
void Separator(){
    char caracteres[2];
    scanf("%s",caracteres);
}

int compteCoupsAlice(int tour){
  unsigned int compteCoupsA = 0;
  if(tour == 0){
    compteCoupsA = 1;
  }
  return compteCoupsA;
}


int toucheBateauAlice(int size, unsigned AliceTb[size][size], int coordX, int coordY){
  int nbBoatTouchA = 0;
  if(AliceTb[coordX][coordY] == 1){
    AliceTb[coordX][coordY] = 0;
    nbBoatTouchA = 1;
}
  return nbBoatTouchA;
}

int toucheBateauBernard(int size ,unsigned BernardTb[size][size], int coordX, int coordY){
  int nbBoatTouchB = 0;
  if(BernardTb[coordX][coordY] == 1){
    BernardTb[coordX][coordY] = 0;
    nbBoatTouchB = 1;
}
  return nbBoatTouchB;
}

int compteCoupsBernard(int tour){
  unsigned int compteCoupsB = 0;
  if(tour == 1){
    compteCoupsB = 1;
  }
  return compteCoupsB;
}

void coupsManquant(int compteCoupsA,int compteCoupsB){
 int coups;
 coups = compteCoupsA + compteCoupsB;
 if(compteCoupsA != compteCoupsB){
   printf("COUP MANQUANT : PARTIE INCOMPLETE \n");
   printf("Nombre de coups ALice: %d\n", compteCoupsA);
   printf("Nombre de coups Bernard: %d\n", compteCoupsB);
 }

 printf("Nombre de coups : %d \n", coups);

}

int coupsInterdit(int size, signed int coordX, signed int coordY){
 int coupInterdit = 0; // = 0 Pas de coup interdit

 if(coordX >= size || coordY >= size){
   coupInterdit = 1;
   printf("COUP INTERDIT : PARTIE FINIE \n");
 }

 return coupInterdit;
}

void lireCoups(int size,unsigned int AliceTb[size][size],unsigned int BernardTb[size][size]){
  unsigned int compteCoupsB = 0;
  unsigned int compteCoupsA = 0;

  unsigned int nbBoatTouchA = 0;
  unsigned int nbBoatTouchB = 0;


  int partieFin = 0; //La partie n'est pas fini

  int tour = 0; // = 0 Tour d'ALice = 1 Tour de Bernard

  int coupInterdit = 0;

  while(partieFin == 0)
  {
    signed int coordX;
    signed int coordY;

    scanf("%d %d",&coordX,&coordY);

    if(coordX < 0 || coordY < 0){
      partieFin = 1;
    }else{
      compteCoupsA = compteCoupsA + compteCoupsAlice(tour);
      compteCoupsB = compteCoupsB + compteCoupsBernard(tour);

      if(tour == 0){
        nbBoatTouchB = nbBoatTouchB + toucheBateauBernard(size,BernardTb,coordX,coordY);
        tour = 1;
      }
      else {
        nbBoatTouchA = nbBoatTouchA + toucheBateauAlice(size,AliceTb,coordX,coordY);
        tour = 0;
      }

      coupInterdit = coupsInterdit(size, coordX, coordY);
      if(coupInterdit == 1){
        partieFin = 1;
      }

    }

  }
  coupsManquant(compteCoupsA,compteCoupsB);

}
  void winner(int size,int )



int main()
{
  int size = TailleDuTableau();
  unsigned int expectedBoats = NombreDeBateaux();
  unsigned int AliceTb[size][size];
  unsigned int BernardTb[size][size];
  Separator();
  Separator();
  plateauAlice(size,AliceTb);
  unsigned int boatA = compteBateauxA(size,AliceTb);
  TestNombreDeBateauxA(expectedBoats, boatA);
  Separator();
  Separator();
  plateauBernard(size,BernardTb);
  unsigned int boatB = compteBateauxB(size,BernardTb);
  TestNombreDeBateauxB(expectedBoats, boatB);
  Separator();
  Separator();
  Separator();
  lireCoups(size,AliceTb,BernardTb);
  return 0;
}
