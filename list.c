#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void init(List *l, void (*destroyList)(void *data))
{
    l->size = 0;
    l->head = l->end = NULL;
    l->destroy = destroyList;
}

int main(int argc, char** argv)
{
    List l;
    init(&l,NULL);
    
    return (EXIT_SUCCESS);
}

