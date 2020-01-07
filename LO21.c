#include "./bits/bits.h"
#include "./pop/pop.h"
#include "./individu/individu.h"
#include <stdlib.h>
#include <stdio.h>


int main(){
    int ngen=20,select=28;
	Population pp;
    Population p=pop_init(taillepop);
	for(int n=0;n<ngen;n++){
		pp=pop_breed(p,taillepop,pcroise);
		pp=quick(pp);
		tronc(pp,select,taillepop);
		pop_del(p);
		p=pp;
	}

	printf("Meilleur individu de la population avec %i individu, %i generation, %i meilleurs individus selectionne et un breed a %i de croisement a :\n -une valeur de :%li\n -une qualite de %.6f\n",taillepop,ngen,select,pcroise,individu_toint(p.start->individus),p.start->qual);
 	
    return 0;
}

