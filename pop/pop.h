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

Population pop_init(int);

Elem* elem_init();

void elem_vinit(Elem*);

Population quick(Population);/*trie la population puis renvoie la version triée, ne bouge que les valeurs donc la réafectation est optionnelle*/

void tronc(Population, int, int);

void pop_del(Population);

Population pop_breed(Population, int, int);

#endif
