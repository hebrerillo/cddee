#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main(int argc, char** argv)
{
    List l;
    init(&l, NULL);
    
    
    const int n1[] = {1,2,3,4};
    const int n2[] = {5,6,7,8,9};
    const int n3[] = {15,16,17,18,19};
    const int n4[] = {415,416,417,418,419};
    
    insert(&l,n1,sizeof(n1));
    insert(&l,n2,sizeof(n2));
    insert(&l,n3,sizeof(n3));
    insert(&l,n4,sizeof(n4));
    printList(&l);
    removeNext(&l,l.head->next->next->next,NULL);

    
    printList(&l);
    return (EXIT_SUCCESS);
}
