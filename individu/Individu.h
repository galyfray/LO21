#ifndef BITS_CUSTOM_HEADER
#define BITS_CUSTOM_HEADER

#include "../bits/bits.h"

#define longIndiv 8

typedef Bits* Individu;

Individu Individu_ajoutert(Individu,Bits*); /*ajout un Bits en tête a une Individu*/

Individu Individu_rinit(int); /*initialise une liste n Bits ayant pour valeur aléatoirement 0 ou 1*/

int Individu_toint(Individu);

Individu crossBreed(Individu,Individu,float);

float quality(float,float,float,int);

void Individu_free(Individu);

void Individu_print(Individu);

#endif