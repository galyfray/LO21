
#include "..\bit\bits.h"
#include "..\individu\individu.h"
#include "pop.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

Population pop_init (Elem* Epre, Elem* Eder){
	Population* Pop=(Population*malloc(sizeof(Population));
	Pop->start = Epre;
	Pop->end = Eder;
	return (Pop*);
}

Elem* elem_init() {
	Elem* E=(Elem*)malloc(sizeof(Elem));
	E->next = NULL;
	E->prev = NULL;
	E->individus = Individu_rinit(8);
	//E->qual = 
	return (E*);
}

Elem* elem_init(Elem* Eprev) {
	Elem* E=(Elem*)malloc(sizeof(Elem));
	E->next = NULL:
	E->prev = Eprev
	E->individus = Individu_rinit(8);
	//E->qual =
	Eprev->next=E;
	return (E*);
}

/*
mettre en mémoire adresse En
créer En+1
donner En.next adresse En+1
Donner En+1.prev adresse En
*/