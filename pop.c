
#include "pop.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define A -1
#define B 1

Population pop_init (int taillePOP){// plutot un truc qui contruis une pop de taille n
	Population Pop;
	Elem* Eprev=elem_init();
	Elem* E;
	Pop.start = Eprev;
	for(int i=0;i<(taillePOP-1);i++){
		E=elem_init();
		Eprev->next=E;
		E->prev=Eprev;
		Eprev=E;
	}
	Pop.end = E;
	return (Pop);
}

Elem* elem_init() { //nan mais non billy non 
	Elem* E=(Elem*)malloc(sizeof(Elem));
	E->next = NULL;
	E->prev = NULL;
	E->individus = individu_rinit(longIndiv);
	E->qual = quality(individu_toint(E->individus),A,B,longIndiv);
	return (E);
}

void tronc(Population Pop, int tSelect, int taillePOP) {
	Elem* Ecpy=Pop.start;
	Elem* Emob=Pop.start;
	for(int i=0;i<=tSelect;i++){
		Emob=Emob->next;
	}
	int t=tSelect, c=0;
	while(Emob->next!=NULL && t<taillePOP){
		while(Emob->next!=NULL && c<tSelect){
			c++;
			t++;
			Emob->individus=Ecpy->individus;
			Emob->qual=Ecpy->qual;
			Emob=Emob->next;
			Ecpy=Ecpy->next;
		}
		Emob=Emob->next;
		Ecpy=Pop.start;
		c=0;
	}
}

void pop_del(Population pop){
	Elem* Elem=pop.start;
	Elem* Elemnext;
	while (elem!=NULL){
		Elemnext=Elem->next;
		individu_free(Elem->individus);
		free(Elem);
		Elem=Elemnext;
	}
	free(pop);
}