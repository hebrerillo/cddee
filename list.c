#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int insert(List *l, const void *data,int size)
{
    ListElement *n = NULL;
    if ((n = (ListElement *) malloc(sizeof (ListElement))) == NULL)
    {
        return -1;
    }
    n->data = (void *)malloc(size);
    memcpy(n->data,data,size);
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
    l->size++;
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
    printf("Size of list = %d\n",l->size);
}


int insertAfter(List *l, ListElement *element, const void *data,int size)
{
    ListElement *n = NULL;
    if(element == NULL)
    {
        return insert(l,data,size);
    }
    else
    {
        
        if ((n = (ListElement *) malloc(sizeof (ListElement))) == NULL)
        {
            return -1;
        }
        n->data = (void *)malloc(size);
        memcpy(n->data,data,size);
        n->next = NULL;
        
        if(element == l->end)
        {
            l->end->next = n;
            l->end = n;
        }
        else
        {
            n->next = element->next;
            element->next = n;
        }
        return 1;
    }
}


int main(int argc, char** argv)
{
    
    List l;
    init(&l, NULL);
    const char item1[] = "item1";
    const char item2[] = "item2";
    
    insert(&l,item1,sizeof(item1));
    insert(&l,item2,sizeof(item2));
    printList(&l);
    return (EXIT_SUCCESS);
}

