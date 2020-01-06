
#include "pop.h"
#include <stdio.h>
#include <stdlib.h>

Population pop_init (int taillePOP){
	Population Pop;
	Elem* Eprev=elem_init();
	Elem* E;
	Pop.start = Eprev;
	elem_vinit(Eprev);
	for(int i=0;i<(taillePOP-1);i++){ // ce for initialise chaque élements de la population initiale
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
	Elem* Ecpy=Pop.start; // Il s'agit de l'element que l'on va copier
	Elem* Emob=Pop.start; // il s'agit du curseur mobile qui va parcourir tout la liste
	for(int i=0;i<tSelect;i++){  // Nous commençons par placer le curseur Emob après la selection d'element à copier
		Emob=Emob->next;
	}
	int t=tSelect, c=0;
	while(Emob!=NULL && t<taillePOP){ // nous allons donc copier les premiers element de la liste jusqu'à la la fin de la liste
		while(Emob!=NULL && c<tSelect){ // cette ligne permet de s'assurer que la tête de copie reste dans sa partie de la liste afin de d'éviter en cas de problème de copie que la t^te se mette à copier des valeurs erronée
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
	while (Element->next!=NULL){  // on supprime chaque element 1 à 1
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
	Elem* elem1, elem2,E; // l'on créer donc deux element de lecture, elem1 et eleme2 et un autre element nous permetans de batir element par element la nouvelle population
	elem1=pope.start;
	elem2=pope.start;
	
	int rg1, rg2,i,p=0 ;
	
	while (p<taillePOP){
		
		rg1=(random()%taillePOP);
		rg2=rg1;
		while(rg1==rg2){  //on s'assure que le rang des element de base soient different afin de ne pas croiser deux individus identiques
			rg2=(random()%taillePOP);
		}
		
		for(i=0;i<rg1;i++){ // on place le premier element de lecture à son rang
			elem1=elem1->next;
		}
		
		for(i=0;i<rg2;i++){ // on place le second element de lecture à son rang
			elem2=elem2->next;
		}		
		Eprev->individus= individu_copycat(elem1->individus); //on copie le premier element de lecture dans l'element en cour de creation
		individu_breed(Eprev->individus,elem2->individus,pcroise); // on croise l'element en cours de creation contenant une copie d'elem1 avec elem2
		Eprev->qual=quality(individu_toint(Eprev->individus),A,B,longIndiv); // on calcule la qualité du nouvel element
		if(p!=taillePOP-1){ // on s'assure de ne pas créer une nouvelle population trop importante.
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
