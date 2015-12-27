#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int insert(List *l, const void *data)
{
    ListElement *n = NULL;
    if ((n = (ListElement *) malloc(sizeof (ListElement))) == NULL)
    {
        return -1;
    }
    n->data = (void*) data;
    n->next = NULL;
    
    if (l->head == NULL)
    {
        l->head = n;
        l->end = l->head;
    }
    else
    {
        n->next = l->head;
        l->head = n;
    }
    return 1;
}



void init(List *l, void (*destroyList)(void *data))
{
    l->size = 0;
    l->head = l->end = NULL;
    l->destroy = destroyList;
}

void printList(const List *l)
{
    ListElement *aux = l->head;
    while (aux != NULL)
    {
        printf("%s ", (char*) aux->data);
        aux = aux->next;
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    List l;
    init(&l, NULL);
    insert(&l, "olakase");
    insert(&l, "olakase2");
    

    printList(&l);
    return (EXIT_SUCCESS);
}

