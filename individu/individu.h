#ifndef INDIVIDU_CUSTOM_HEADER
#define INDIVIDU_CUSTOM_HEADER

#include "../bits/bits.h"

#define longIndiv 8

typedef Bits* Individu;

Individu individu_ajoutert(Individu,Bits*); /*ajout un Bits en tête a une Individu*/

Individu individu_rinit(int); /*initialise une liste n Bits ayant pour valeur aléatoirement 0 ou 1*/

int individu_toint(Individu);

Individu crossBreed(Individu,Individu,float);

float quality(int,float,float,int);

void individu_free(Individu);

void individu_print(Individu);

#endif
