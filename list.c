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

void printList(const List *l)
{
    ListElement *aux = l->head;
    while(aux!=NULL)
    {
        printf("%s",(char*)aux->data);
        aux = aux->next;
    }
}

int main(int argc, char** argv)
{
    List l;
    init(&l,NULL);
    printList(&l);
    return (EXIT_SUCCESS);
}

