#include "individu.h"
#include "../bits/bits.h"

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

Individu individu_ajoutert(Individu L,Bits* bit){
    bit->next=L;
    return bit;
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

float quality(int Value,float p1,float p2,int length){
    int i,P=1;
    for(i=1;i<=length;i++){
        P=2*P;
    }
    float X=((float)Value/P)*(p2-p1)+p1;
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
    Individu N = NULL,Stock=NULL;
    Bits* p=I;
    if (p){
        N=bits_init(p->value);
        Stock=N;
        p=p->next;
    }
    while (p){
        N->next=bits_init(p->value);
        N=N->next;
        p=p->next;
    }
    return Stock;
}

Individu individu_breed(Individu Breeded,Individu Breeder,int pcroise){
    srand(time(0));
    Individu B1=Breeded,B2=Breeder;
    while (B1 && B2){
        if (rand()%100<=pcroise){
            (B1->value)=(B2->value);
        }
        B1=(B1->next);
        B2=(B2->next);
    }
    return Breeded;
}
