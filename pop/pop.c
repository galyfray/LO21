
#include "pop.h"
#include <stdio.h>
#include <stdlib.h>

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
	for(int i=0;i<tSelect;i++){
		Emob=Emob->next;
	}
	int t=tSelect, c=0;
	while(Emob!=NULL && t<taillePOP){
		while(Emob!=NULL && c<tSelect){
			c++;
			t++;
			Emob->individus=individu_copycat(Ecpy->individus);
			Emob->qual=Ecpy->qual;
			Emob=Emob->next;
			Ecpy=Ecpy->next;
		}
		Ecpy=Pop.start;
		c=0;
	}
}

void pop_del(Population pop){
	Elem* Element=pop.start;
	Elem* Elemnext;
	while (Element->next!=NULL){
		Elemnext=Element->next;
		individu_free(Element->individus);
		free(Element);
		Element=Elemnext;
	}
	individu_free(Element->individus);
	free(Element);
	pop.start=NULL;
	pop.end=NULL;
}

Population pop_breed(Population pope, int taillePOP,int pcroise){
	
	Population pops;
	Elem* Eprev=elem_init();
	pops.start=Eprev;
	Elem* elem1, elem2,E;
	elem1=pope.start;
	elem2=pope.start;
	
	int rg1, rg2,i,p=0 ;
	
	while (p<taillePOP){
		
		rg1=(random()%taillePOP);
		rg2=rg1;
		while(rg1==rg2){
			rg2=(random()%taillePOP);
		}
		
		for(i=0;i<rg1;i++){
			elem1=elem1->next;
		}
		
		for(i=0;i<rg2;i++){
			elem2=elem2->next;
		}		
		Eprev->individus= individu_copycat(elem1->individus);
		individu_breed(Eprev->individus,elem2->individus,pcroise);
		Eprev->qual=quality(individu_toint(Eprev->individus),A,B,longIndiv);
		if(p!=taillePOP-1){
			E=elem_init();
			Eprev->next=E;
			E->prev=Eprev;
			Eprev=E;
		}
		elem1=pope.start;
		elem2=pope.start;
		p++;
	}
	
	pops.end=E;
	return (pops);
}
