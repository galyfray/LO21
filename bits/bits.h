#ifndef BITS_CUSTOM_HEADER
#define BITS_CUSTOM_HEADER

typedef unsigned char Bit;

/* Structure représentant une liste chainée de bit */
typedef struct bits{
    Bit value;
    struct bits* next;
} Bits;

Bits* bits_init(Bit); /*créer un Bits avec comme valeur bit sans suivant*/

Bits* bits_rinit(void); /*créer un Bits avec comme valeur aléatoirement 0 ou 1 sans suivant*/

#endif
