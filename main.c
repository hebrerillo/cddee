#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main(int argc, char** argv)
{
    List l,l2;
    init(&l, NULL);
    init(&l2, NULL);
    
    const int n1[] = {1,2,3,4};
    const int n2[] = {5,6,7,8,9};
    
    insert(&l,n1,sizeof(n1));
    insert(&l,n2,sizeof(n2));
    copyList(&l2,&l);
    *((int*)(l2.head->data)) = 90;//altering l2 does not affect l
    printList(&l2);
    printList(&l);
    return (EXIT_SUCCESS);
}
