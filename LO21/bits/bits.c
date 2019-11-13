#include "bits.h"

#include <time.h>
#include <stdlib.h>


Bits* bits_init(Bit bit){//créer un bit initialiser avec la valeur donnée en argument
    Bits* B=(Bits*)malloc(sizeof(Bits));
    B->value = bit;
    B->next = NULL;
    return B;
}

Bits* bits_rinit(){//créer un bits initialiser aléatoirement sans suivant
    static Bit first =0;
    if (first==0){ //permet de ne pas réinitialiser les nombre aléatoire a chaque appel évite d'avoir que des individu avec que des 1 ou que des 0
        srand(time(NULL));
        first=1;
    }
    return bits_init((Bit)rand()%2);
}

