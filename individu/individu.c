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

Individu individu_copycat(Individu I){
    Individu N = NULL;//manque la récup du pointeur de début de nouvelle liste
    Bits* p=I;
    if (p){
        N=bits_init(p->value);
        p=p->next;
    }
    while (p){
        N->next=bits_init(p->value);
        N=N->next;
        p=p->next;
    }
    return N;
}

Individu individu_breed(Individu Breeded,Individu Breeder,int pcroise){
    srand(time(0));
    Individu B=Breeded,B2=Breeder;
    while (B && B2){
        if (rand()%100<=pcroise){
            (B->value)=(B2->value);
        }
        B=(B->next);
        B2=(B2->next);
    }
    return Breeded;
}
