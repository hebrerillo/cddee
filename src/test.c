#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "userFunctions.h"

int main(int argc, char** argv)
{
    List l;

    char n[] = "string 0";
    char n2[] = "string 1";

    init(&l, NULL, NULL);

    //insert data
    insert(&l, n, sizeof (n));
    insert(&l, n2, sizeof (n2));
    
    ListIterator it = buildIterator(&l);
    ListElement *current;
    while((current = next(&it)) != NULL)
    {
        printf("Data = %s\n",(char*)current->data);
    }
    
    destroyList(&l);
    
    return (EXIT_SUCCESS);
}
