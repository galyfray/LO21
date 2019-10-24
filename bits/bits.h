#ifndef BITS_CUSTOM_HEADER
#define BITS_CUSTOM_HEADER

#define longIndiv 8

typedef unsigned char Bit;

/* Structure représentant une liste chainée de bit */
typedef struct bits{
    Bit value;
    struct bits* next;
} Bits;

typedef Bits* BitsList;

Bits* bits_init(Bit); /*créer un Bits avec comme valeur bit sans suivant*/

Bits* bits_rinit(void); /*créer un Bits avec comme valeur aléatoirement 0 ou 1 sans suivant*/

BitsList bitslist_ajoutert(BitsList,Bits*); /*ajout un Bits en tête a une BitsList*/

BitsList bitslist_rinit(int); /*initialise une liste n Bits ayant pour valeur aléatoirement 0 ou 1*/

int bitslist_toint(BitsList);

BitsList crossBreed(BitsList,BitsList,float);

float quality(float,float,float,int);

void bitslist_free(BitsList);

void bitslist_print(BitsList);

#endif
