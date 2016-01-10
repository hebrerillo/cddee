#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "userFunctions.h"

int main(int argc, char** argv)
{
    List l, l2,l3;

    int n[] = {1, 2, 3};
    int n2[] = {10, 11, 12};
    

    //init lists
    init(&l, NULL, NULL);
//    init(&l2, NULL, printListInt);


    //insert data
    insert(&l, n, sizeof (n));
    insert(&l, n2, sizeof (n2));
    
    destroyList(&l);
//    destroyList(&l2);
    
    return (EXIT_SUCCESS);
}
