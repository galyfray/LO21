
#include "..\bit\bits.h"
#include "..\individu\individu.h"

typedef struct elem{
    float qual;
    Individu individus
    struct elem* next;
    struct elem* prev;
} Elem;

typedef struct population {
    Elem* start;
    Elem* end;
} Population;

Population pop_init ();

Elem* elem_init();

Elem* elem_rinit(Elem*);



