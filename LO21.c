#include "./bits/bits.h"

int main(){
    int k;
    for(k=0;k<50;k++){
        BitsList L = bitslist_rinit(longIndiv);
        bitslist_print(L);
        bitslist_free(L);
    }
    return 0;
}
