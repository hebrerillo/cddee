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
    init(&l, destroySimpleList);
    init(&l2, destroySimpleList);
    init(&l3, destroyComplexList);
    
    //insert data
    buildFromFile(&l,"phonenumbers.txt");
    insert(&l2,n,sizeof(n));
    insert(&l2,n2,sizeof(n2));
    
    insert(&l3,&l,sizeof(l));
    insert(&l3,&l2,sizeof(l2));
    
    destroyList(&l3);
    
    return (EXIT_SUCCESS);
}
