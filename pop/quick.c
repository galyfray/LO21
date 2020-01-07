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
        Population p1,p2;
        p1.start=pop.start;
        p1.end=start;
        p2.start=start->next;
        p2.end=pop.end;
        quick(p1);//réafecter la valeur est inutile car quick() ne déplace pas l'ordre des élément mais leur valeur
        quick(p2);
    }
    return pop;
}
zhi.yan@utbm.fr
nathan.crombez@utbm.fr
