#ifndef INDIVIDU_HEADER
#define INDIVIDU_HEADER

#define longIndiv 8;

typedef unsigned char Bit;

/* Structure représentant une liste chainée de bit */
typedef struct bits{
    Bit value;
    struct bits* next;
} Bits;

typedef *Bits BitsList;
/* structure reprénsentant un individus */

typedef struct individu {
    Bits* bitChain;
} Individu;


#endif
