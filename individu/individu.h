#ifndef INDIVIDU_CUSTOM_HEADER
#define INDIVIDU_CUSTOM_HEADER

#include "../bits/bits.h"
#include "random.h"
#include <math.h>

#define longIndiv 32
#define A -1*M_PI
#define B M_PI

typedef Bits* Individu;

Individu individu_ajoutert(Individu,Bits*); /*ajout un Bits en tête a un Individu*/

Individu individu_rinit(int); /*initialise une liste n Bits ayant pour valeur aléatoirement 0 ou 1*/

long int individu_toint(Individu); /*calcule la valeur d'un individu en transformant ça chaîne de bits un en scalaire en base 10*/

Individu individu_copycat(Individu); /*créer une copie de l'individu envoyer en paramètre, la copie est l'individu renvoyer par la fonction*/

Individu individu_breed(Individu,Individu,int); /*remplace les bits de l'individu 1 par ceux de l'individu 2 avec une chance de pcroise%, renvoie l'individu 1 après transformation*/

float quality(int,float,float,int); /*calcule la qualité d'un individu a partir de sa valeur, deux réel A et B (donné dans l'ennoncer) et la taille de l'individu */

void individu_free(Individu); /* Libère l'espace prise par un individu et tout les bits qui le compose*/

void individu_print(Individu); /*Imprime un individu uniquement pour debug la liste de bits composant l'individu sont écris a l'enver*/

#endif
