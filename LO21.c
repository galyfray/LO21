#include "./bits/bits.h"
#include "./pop/pop.h"
#include "./individu/individu.h"
#include <stdlib.h>
#include <stdio.h>

void pop_display(Population);

int main(){
    int ngen=5;
	Population pp;
    Population p=pop_init(16);
	pop_display(p);
	printf("\nPop cree\n\n");
	for(int n=1;n<=ngen;n++){
		pp=pop_breed(p,16,50);
		pop_display(pp);
		printf("\nPop croisee gen %i\n\n",n);
		pp=quick(pp);
		pop_display(pp);
		printf("\nPop triee gen %i\n\n",n);
		tronc(pp,4,16);
		pop_display(pp);
		printf("\nPop tronque gen %i\n\n",n);
		
		pop_del(p);
		
		p=pp;
	}
    return 0;
}


void pop_display(Population p){
	Elem *E=p.start;
	int i = 1;
	while(E!=NULL){
		printf("#Individu : %i\n",i);
		individu_print(E->individus);
		E=E->next;
		i++;
	}
}
