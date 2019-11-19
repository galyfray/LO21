
#include "pop.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define A -1
#define B 1

Population pop_init (int taillePOP){
	Population Pop;
	Elem* Eprev=elem_init();
	Elem* E;
	Pop.start = Eprev;
	elem_vinit(Eprev);
	for(int i=0;i<(taillePOP-1);i++){
		E=elem_init();
		elem_vinit(E);
		Eprev->next=E;
		E->prev=Eprev;
		Eprev=E;
	}
	Pop.end = E;
	return (Pop);
}

Elem* elem_init() {
	Elem* E=(Elem*)malloc(sizeof(Elem));
	E->next = NULL;
	E->prev = NULL;
	return (E);
}

void elem_vinit(Elem* E){
	E->individus = individu_rinit(longIndiv);
	E->qual = quality(individu_toint(E->individus),A,B,longIndiv);
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

Population pop_breed(Population pops, int taillePOP,int pcroise){
	
	Population pope;
	Elem* Eprev=elem_init;
	pope.start=Eprev;
	Elem* elem1, *elem2,*E;
	elem1=pops.start;
	elem2=pops.start;
	
	int rg1, rg2,i ;
	
	srand(time(0));
	
	for(int p=0;p<taillePOP;p++){
		
		rg1=(rand()%taillePOP);
		rg2=rg1;
		while(rg1==rg2){
			rg2=(rand()%taillePOP);
		}
		
		for(i=0;i<=rg1;i++){
			elem1=elem1->next;
		}
		
		for(i=0;i<=rg1;i++){
			elem2=elem2->next;
		}
		
		Eprev->individus= individu_copycat(elem1->individu);
		individu_breed(Eprev->individus,elem2,pcroise);
		Eprev->qual=quality(individu_toint(Elem->individus),A,B,longIndiv);
		E=elem_init();
		Eprev->next=E;
		E->prev=Eprev;
		Eprev=E;
		
		elem1=pops.start;
		elem2=pops.start;
	}
	
	pope.end=E;
	//pop_del(pops);
	return (pope);
}
