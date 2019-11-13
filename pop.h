#ifndef __POP_HEADER__
#define __POP_HEADER__
#include "../bits/bits.h"
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

Population quick(Population);//trie tout Billy TOUT

void tronc(Population, int, int);

void pop_del(Population);

#endif