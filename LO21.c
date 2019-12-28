#include "./bits/bits.h"
#include "./pop/pop.h"
#include "./individu/individu.h"
#include <stdlib.h>
#include <stdio.h>

void pop_display(Population);
void pop_out(FILE*,Population);

int main(){
    FILE* f=fopen("output.txt","a");//permet de pas supprimé les anciens output
    int ngen=20,select=28,taillepop=32,pcroise=50;
	Population pp;
    Population p=pop_init(taillepop);
	for(int n=0;n<ngen;n++){
		fprintf(f,"génération %i\n",n);
		pop_out(f,p);
		//pop_display(p);
		pp=pop_breed(p,taillepop,pcroise);
		pp=quick(pp);
		tronc(pp,select,taillepop);
		pop_del(p);
		p=pp;
		
	}
	fprintf(f,"Meilleur individu de la population avec %i individu, %i génération, %i meilleurs individus séléctionné et un breed à %i de croisement à :\n -une valeur de :%li\n -une qualité de %.6f\n",taillepop,ngen,select,pcroise,individu_toint(p.start->individus),p.start->qual);
 	
    return 0;
}

void pop_out(FILE* f,Population p){
    Elem* E=p.start;
    int i=1;
    while(E){//si E==Null alors la boucle se coupe car Null==0 soit false
        fprintf(f,"#Individu :%i\n#\n##Valeur: %li\n##Qualité:%.6f\n#\n",i,individu_toint(E->individus),E->qual);
        i++;
        E=E->next;
    }
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
