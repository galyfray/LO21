#include <stdlib.h>
#include <time.h>

long int random(void){//renvoie un entier aléatoire en initialisant le rand qu'une seule fois sinon il y as des problème lors de sont utilisation dans un lapse de temps cour
    static int init=1;
    if (init){
        init=0;
        srand(time(0));
    }
    return rand();
}
