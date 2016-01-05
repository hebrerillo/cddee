#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "userFunctions.h"


int main(int argc, char** argv)
{  
    List l,l2;
    List l3;//list of lists
    
    const int n[] = {1,2,3};
    const int n2[] = {10,11,12};
    
    //init lists
    init(&l, destroySimpleList,printListString);
    init(&l2, destroySimpleList,printListInt);
    init(&l3, destroyComplexList,printComplexList);
    
    //insert data
    buildFromFile(&l,"phonenumbers.txt");
    insert(&l2,n,sizeof(n));
    insert(&l2,n2,sizeof(n2));
    
    insert(&l3,&l,sizeof(l));
    insert(&l3,&l2,sizeof(l2));
    
    //printList(&l);
    //printList(&l2);
    printList(&l3);
    
    return (EXIT_SUCCESS);
}
