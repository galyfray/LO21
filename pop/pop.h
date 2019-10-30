
#include "LO21\bit\bits.h"

/* Structure représentant une liste chainée d'individu */
typedef struct BitsList{
    int qual;
    struct BitsList* next;
	struct BitsList* prev;
} Population;

typedef BitsList* Individu