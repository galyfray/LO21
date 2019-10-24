
#include "bits.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>


Bits* bits_init(Bit bit){//créer un bit initialiser avec la valeur donnée en argument
    Bits* B=(Bits*)malloc(sizeof(Bits));
    B->value = bit;
    B->next = NULL;
    return B;
}

Bits* bits_rinit(){//créer un bits initialiser aléatoirement sans suivant
    static Bit first =0;
    if (first==0){ //permet de ne pas réinitialiser les nombre aléatoire a chaque appel évite d'avoir que des bitslist avec que des 1 ou que des 0
        srand(time(NULL));
        first=1;
    }
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
        L=bitslist_ajoutert(L,bits_rinit());
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

float quality(float Value,float A,float B,int lenth){
    int i,P=1;
    for(i=1;i<=lenth;i++){
        P=2*P;
    }
    float X=(Value/P)*(B-A)+A;
    return (-X)*X;
}

void bitslist_free(BitsList BL){
    Bits* next;
    while(BL != NULL){
        next=BL->next;
        free(BL);
        BL=next;
    }
}

void bitslist_print(BitsList BL){
    int V=bitslist_toint(BL);
    float Q=quality(V,-1,1,longIndiv);
    printf("#============#\n#Value: %i\n#Quality: %.4f\n#BitList:",V,Q);
    while (BL!=NULL){
        printf("%d",BL->value);
        BL=BL->next;
    }
    printf("\n#============#\n");
}
