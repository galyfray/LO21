
#include "..\bit\bits.h"
#include "..\individu\individu.h"

/* Structure représentant une liste chainée d'individu */
typedef struct BitsList{
    float qual;
	Individu Indiv
    struct BitsList* next;
	struct BitsList* prev;
} Population;

typedef BitsList* Individu