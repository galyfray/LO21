#ifndef INDIVIDU_CUSTOM_HEADER
#define INDIVIDU_CUSTOM_HEADER

#include "../bits/bits.h"
#include "random.h"

#define longIndiv 8
#define A -1
#define B 1

typedef Bits* Individu;

Individu individu_ajoutert(Individu,Bits*); /*ajout un Bits en tête a une Individu*/

Individu individu_rinit(int); /*initialise une liste n Bits ayant pour valeur aléatoirement 0 ou 1*/

int individu_toint(Individu);

Individu individu_copycat(Individu); /*créer une copie d'un individu (c'est comme ça que l'on fait les bébés chinois)*/

Individu individu_breed(Individu,Individu,int);/*remplace les bits de l'individu 1 par ceux de l'individu 2 avec une chance de pcroise% */

float quality(int,float,float,int);

void individu_free(Individu);

void individu_print(Individu);

#endif
