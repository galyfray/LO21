#include "./bits/bits.h"
#include "./pop/pop.h"
#include "./individu/individu.h"
#include <stdlib.h>
#include <stdio.h>

void pop_display(Population);

int main(){
    Individus indiv=individu_rinit(longIndiv),indiv2;
    indiv2=copycat(indiv);
    
    /*
	Population pp;
    Population p=pop_init(16);
	pop_display(p);
    printf("\nPop cree\n\n");
	p=quick(p);
	pop_display(p);
    printf("\nPop triee\n\n");
	tronc(p,4,16);
	pop_display(p);
    printf("\nPop tronque\n\n");
	pp=pop_breed(p,16,50);
	pop_display(pp);
    printf("\nPop croisee\n\n");*/
    return 0;
}


void pop_display(Population p){
	Elem *E=p.start;
	while(E!=NULL){
		individu_print(E->individus);
		E=E->next;
	}
}
