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
    n->size = size;
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
    size_t i;
    while (aux != NULL)
    {
        for(i=0;i < (aux->size/sizeof(int)) ;i++)
        {
            
            printf("%d \n", ((int*)aux->data)[i]);
        }
        printf("\n");
        aux = aux->next;
    }
    printf("\n");
    printf("Size = %d\n",l->size);
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
        n->size = size;
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
    
    const int n1[] = {1,2,3,4};
    const int n2[] = {5,6,7,8,9};
    
    insert(&l,n1,sizeof(n1));
    insert(&l,n2,sizeof(n2));
    printList(&l);
    return (EXIT_SUCCESS);
}

