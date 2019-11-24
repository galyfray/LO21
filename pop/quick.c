 #include "pop.h"
 #include <stdlib.h>
 
Population quick(Population pop){
    Elem *start=pop.start,*end=pop.end,*swp=pop.start,tmp;
    if(start != end && start){ // vérifie les cas triviaux liste vide et liste de 1 élément
        while(swp != end){ //tant que l'itérative est différente du pivot on peut travailler
            if (swp->qual>end->qual){
                tmp.qual=swp->qual;
                tmp.individus = swp->individus;
                swp->qual=start->qual;
                swp->individus=start->individus;
                start->qual=tmp.qual;
                start->individus=tmp.individus;
                start=start->next;
            }
            swp=swp->next;
        }
        if (start != end){//la condition n'est fausse que si la liste est déja trier par rapport au pivot
            tmp.qual=end->qual;
            tmp.individus=end->individus;
            end->qual=start->qual;
            end->individus=start->individus;
            start->qual=tmp.qual;
            start->individus=tmp.individus;
        } else {
            start = start->prev; 
        }
        Population A,B;
        A.start=pop.start;
        A.end=start;
        B.start=start->next;
        B.end=pop.end;
        quick(A);//réafecter la valeur est inutile car quick() ne déplace pas l'ordre des élément mais leur valeur
        quick(B);
    }
    return pop;
}

