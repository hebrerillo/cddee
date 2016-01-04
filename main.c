#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


/**
 * Destroy a list with single data associated
 * @param data
 */
void destroySimpleList(void *data)
{
    ListElement *element = (ListElement*)data;
    free(element->data);
    free(element);
}


int main(int argc, char** argv)
{  
    List l;
    init(&l, destroySimpleList);
    buildFromFile(&l,"phonenumbers.txt");
    destroyList(&l);
    printListString(&l);
    return (EXIT_SUCCESS);
}
