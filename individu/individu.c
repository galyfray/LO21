#include "individu.h"
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
        L=individu_ajoutert(L,bits_rinit());//créer un bits aléatoirement et l'joute en tete directement
    }
    return L;
}

int individu_toint(Individu liste){
    int pow = 1;//représente 2^n, c'est plus efficace que d'utilisé pow
    int value = 0;
    Bits* elem = liste;
    while (elem != NULL){ //on part du principe que la liste chainé organise les bits par ordre de puissance croissante
        value = value + pow*elem->value;
        pow = pow*2;
        elem = elem->next;
    }
    return value;
}

float quality(int Value,float p1,float p2,int length){
    int i,P=1;
    for(i=1;i<=length;i++){ //calcule de P^n parmet de ne pas se retrouver avec les erreurs de pow du au passage de float a int 
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

void individu_print(Individu BL){//uniquement pour du debug
    int V=individu_toint(BL);
    float Q=quality(V,-1,1,longIndiv);
    printf("#============#\n#Pointeur: %08lx\n#Value: %i\n#Quality: %.4f\n#BitList:",(long unsigned int)BL,V,Q);
    while (BL!=NULL){//imprime les bits a l'enver
        printf("%d",BL->value);
        BL=BL->next;
    }
    printf("\n#============#\n");
}

Individu individu_copycat(Individu I){
    Individu N = NULL,Stock=NULL;
    Bits* p=I;
    if (p){//si I n'est pas vide
        N=bits_init(p->value);
        Stock=N;//on stock le premier element de la liste
        p=p->next;
    }
    while (p){//on ajoute tout les element de la list I en queue de la liste Stock
        N->next=bits_init(p->value); //initialise les bits avec une valeur mais sans suivant donc la liste est corectement construite a chaque itération
        N=N->next;
        p=p->next;
    }
    return Stock;
}

Individu individu_breed(Individu Breeded,Individu Breeder,int pcroise){
    Individu B1=Breeded,B2=Breeder;
    while (B1 && B2){
        if (random()%100<=pcroise){//teste pour voir si l'on modifie la valeur de B1 ou non
            (B1->value)=(B2->value);
        }
        B1=(B1->next);
        B2=(B2->next);
    }
    return Breeded;
}
