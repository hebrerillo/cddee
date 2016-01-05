#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "userFunctions.h"


int main(int argc, char** argv)
{  
    List l,l2;
    
    
    const int n[] = {1,2,3};
    const int n2[] = {10,11,12};
    
    //init lists
    init(&l, destroySimpleList,printListInt);
    init(&l2, destroySimpleList,printListInt);
    
    
    //insert data
    insert(&l,n,sizeof(n));
    insert(&l2,n2,sizeof(n2));
    
    if(concat(&l,&l2))
        printList(&l);
    
    return (EXIT_SUCCESS);
}
