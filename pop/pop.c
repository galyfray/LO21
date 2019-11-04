
#include "pop.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

Population pop_init (Elem* Epre, Elem* Eder){// plutot un truc qui contruis une pop de taille n
	//Population* Pop=(Population*)malloc(sizeof(Population);
	Population Pop;
	Pop->start = Epre;
	Pop->end = Eder;
	return (Pop);
}

Elem* elem_init() { //nan mais non billy non 
	Elem* E=(Elem*)malloc(sizeof(Elem));
	E->next = NULL;
	E->prev = NULL;
	E->individus = Individu_rinit(8);
	//E->qual = 
	return (E*);
}

Elem* elem_rinit(Elem* Eprev) { //c'est pas un poil du foutage de gueule ? nan mais vraiment ?
	Elem* E=(Elem*)malloc(sizeof(Elem));
	E->next = NULL:
	E->prev = Eprev
	E->individus = Individu_rinit(longIndiv);
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