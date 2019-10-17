
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
    srand(time(0));
    return bits_init((Bit)rand()%2);
}

BitsList bitslist_ajoutert(BitsList L,Bits* B){
    B->next=L;
    return B;
}

BitsList bitslist_rinit(int lenth){
    int i;
    BitsList L=NULL;
    for (i=0;i<lenth;i++){
        L=BitsList_ajoutert(L,bits_rinit());
    }
    return L;
}

int bitslist_toint(BitsList liste){
    int pow = 1;
    int value = 0;
    Bits* elem = liste;
    while (elem != NULL){ 
        value = value + pow*elem->value;
        pow = pow*2;
        elem = elem->next;
    }
    return value;
}

BitsList crossBreed(BitsList L1,BitsList L2 ,float pCroise){
    BitsList L3 = NULL;
    srand(time(0));
    if (L1!=NULL && L2!=NULL){
       if ((rand()%100)/100.0>pCroise) {
            L3=bits_init(L1->value);
       }else{
            L3=bits_init(L2->value);
       }
       
    }
    Bits * B3=L3;
    while(L1!=NULL && L2!=NULL){
        if ((rand()%100)/100.0>pCroise) {
            B3->next=bits_init(L1->value);
        }else{
            B3->next=bits_init(L2->value);
        }
        L1=L1->next;
        L2=L2->next;
        B3=B3->next;
    }
    return L3;
}

float quality(int Value,float A,float B,int lenth){
    int i,P=1;
    for(i=1;i<=lenth;i++){
        P=2*P;
    }
    float X=(x/P)*(B-A)+A;
    return (-X)*X;
}
