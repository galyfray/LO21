 #include "pop.h"
 
 Population quick(Population pop){
    Elem* end = pop.end, start=pop.start,swp=pop.start,nxt=NULL;
    if (start != NULL && start != end) {
        if (swp->qual > end->qual){
            swp=swp->next;
        }
        while (swp != end){
            
            if (swp->qual > end->qual){
                nxt=swp->next;
                swp->prev->next=nxt;
                nxt->prev=swp->prev;
                swp->prev=start;
                swp->next=start->next;
                start->next=swp;
                start=swp;
                swp=nxt;
            }
        }
        end->pre->next=end->next;
        if end->next != NULL {
            end->next->prev=nxt;
        }
        end->prev=start;
        end->next=start->next;
        start->next=end;
        Population A,B:
        A.start=pop.start;
        A.end=end;
        B.start=end->next;
        B.end=pop.end;
        A=quick(A);
        B=quick(B);
        pop.start=A.start;
        pop.end=B.end;
    }
    return pop;
 
 }
