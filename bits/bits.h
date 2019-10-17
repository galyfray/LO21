#ifndef BITS_CUSTOM_HEADER
#define BITS_CUSTOM_HEADER

#define longIndiv 8;

typedef unsigned char Bit;

/* Structure représentant une liste chainée de bit */
typedef struct bits{
    Bit value;
    struct bits* next;
} Bits;

typedef Bits* BitsList;

Bits* bits_init(Bit);

Bits* bits_rinit(void);

BitsList bitslist_ajoutert(BitsList,Bits*);

BitsList bitslist_rinit(int);

int bitslist_toint(BitsList);

BitsList crossBreed(BitsList,BitsList,float);

float quality(int,float,float,int;

#endif
