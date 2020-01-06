#ifndef POP_CUSTOM_HEADER
#define POP_CUSTOM_HEADER
#include "../individu/individu.h"

typedef struct elem{
    float qual;
    Individu individus;
    struct elem* next;
    struct elem* prev;
} Elem;

typedef struct population {
    Elem* start;
    Elem* end;
} Population;

Population pop_init(int); // créé une lsite d'individu que l'on a stocké dans cet objet

Elem* elem_init(); //créer un élement vide

void elem_vinit(Elem*); // initialise les valeurs d'un élement

Population quick(Population);/*trie la population puis renvoie la version triée, ne bouge que les valeurs donc la réafectation est optionnelle*/

void tronc(Population, int, int); // gère la selection des individu

void pop_del(Population); // permet de supprimer le contenu d'une population

Population pop_breed(Population, int, int); // croise une population afin d'en faire une seconde

#endif
