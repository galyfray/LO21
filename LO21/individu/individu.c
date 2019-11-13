#include "individu.h"
#include "../bits/bits.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

Individu individu_ajoutert(Individu L,Bits* B){
    B->next=L;
    return B;
}

Individu individu_rinit(int length){
    int i;
    Individu L=NULL;
    for (i=0;i<length;i++){
        L=individu_ajoutert(L,bits_rinit());
    }
    return L;
}

int individu_toint(Individu liste){
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

Individu crossBreed(Individu L1,Individu L2 ,float pCroise){
    Individu L3 = NULL;
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

float quality(int Value,float A,float B,int length){
    int i,P=1;
    for(i=1;i<=length;i++){
        P=2*P;
    }
    float X=((float)Value/P)*(B-A)+A;
    return (-X)*X;
}

void individu_free(Individu BL){
    Bits* next;
    while(BL != NULL){
        next=BL->next;
        free(BL);
        BL=next;
    }
}

void individu_print(Individu BL){
    int V=individu_toint(BL);
    float Q=quality(V,-1,1,longIndiv);
    printf("#============#\n#Value: %i\n#Quality: %.4f\n#BitList:",V,Q);
    while (BL!=NULL){
        printf("%d",BL->value);
        BL=BL->next;
    }
    printf("\n#============#\n");
}
