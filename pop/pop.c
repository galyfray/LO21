
#include "pop.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

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
	E->individus = Individu_rinit(longIndiv);
	E->qual = quality(Individu_toint(E->individus),A,B,longIndiv);
	return (E);
}
