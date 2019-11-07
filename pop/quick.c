 #include "pop.h"
 #include <stdlib.h>
 
void extract(Elem* E){//extrait un Elem d'une population tout en conservant l'intégriter de la pop charge a l'utilisateur de mettre a jour les borne start et end de sa pop au besoin
    if (E->next){
        E->next->prev=E->prev;
    }
    if (E->prev){
        E->prev->next=E->next;
    }
    E->next=NULL;
    E->prev=NULL;
}
 
void insert_inbtwn(Elem* prev,Elem* next, Elem* Elm){ //place Elm entre prev et next
    Elm->next=next;
    Elm->prev=prev;
    if (prev ){
        prev->next=Elm;
    }
    if (next ){
        next->prev=Elm;
    }
    
}

Population quick(Population pop){
    Elem *start = pop.start,*end=pop.end,*swp=pop.start, *tmp=NULL;
    if (start != end && start !=NULL) {
        while (start->qual<end->qual){
            tmp=start->next;
            extract(start);
            insert_inbtwn(end,end->next,start);
            end=start;
            start=tmp;
            swp=tmp;
            pop.start=start;
            pop.end=end;
        }
        while (swp != end) {
            tmp=swp->next;
            if (swp->qual>end->qual){
                if (swp != start){
                    extract(swp);
                    insert_inbtwn(start,start->next,swp);
                    start=swp;
                }
            }
            swp=tmp;
        }
        Population A,B;
        extract(end);
        insert_inbtwn(start,start->next,end);
        A.end=start;
        A.start=start;
        
        B.end=swp;
        
        B.start=A.end->next;
        
        while (A.start->prev){
            A.start=A.start->prev;
        }
        while (B.end->next){
            B.end=B.end->next;
        }
        
        
        B.start->prev=NULL;
        A.end->next=NULL;
        
        A=quick(A);
        B=quick(B);
        
        pop.start=A.start;
        A.end->next=B.start;
        B.start->prev=A.end;
        pop.end=B.end;
    }
    return pop;
}


