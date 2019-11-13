#include "./bits/bits.h"
#include "./pop/pop.h"
#include "./individu/individu.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Population p=pop_init(16);
    Elem * E=p.start;
    int i;
    /*int T[4]={3,1,2,4};
    
    for(i=0;i<4;i++){
        E->qual=T[i];
        E=E->next;
    }
    E=p.start;*/
    i=1;
    while (E != NULL){
        printf("%02i:%0.4f|0x%lx\n",i,E->qual,(unsigned long int)E);
        i++;
        E=E->next;
    }
    
    //printf("end:%0.4f|0x%lx\n",p.end->qual,(unsigned long int)p.end);
    printf("#=======================#\n");
    p=quick(p);
    E=p.start;
    i=1;
    while (E != NULL){
        printf("%02i:%0.4f|0x%lx\n",i,E->qual,(unsigned long int)E);
        i++;
        E=E->next;
    }
    return 0;
}
