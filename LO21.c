#include "./bits/bits.h"
#include "./pop/pop.h"
#include "./individu/individu.h.h"

int main(){
    int k;
    for(k=0;k<50;k++){
        Individu L = individu_rinit(longIndiv);
        individu_print(L);
        individu_free(L);
    }
    return 0;
}
