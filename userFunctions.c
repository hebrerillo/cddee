#include "userFunctions.h"

void printComplexList(const List *l)
{
    ListElement *aux = l->head;
    List *current;
    while (aux != NULL)
    {
        current = (List*) aux->data;
        printList(current);
        aux = aux->next;
    }
    printf("\n");
    printf("Size = %d\n", l->size);
}

void destroySimpleList(void *data)
{
    ListElement *element = (ListElement*) data;
    free(element->data);
    free(element);
    element = NULL;
}

void destroyComplexList(void *data)
{
    ListElement *element = (ListElement*) data;
    List *list = (List*) element->data;
    destroyList(list);
    free(element->data);
    free(element);
    element = NULL;
}

void printListString(const List *l)
{
    ListElement *aux = l->head;

    while (aux != NULL)
    {
        printf("%s\n", (char*) aux->data);
        aux = aux->next;
    }
    printf("\n");
    printf("Size = %d\n", l->size);
}

void printListInt(const List *l)
{
    ListElement *aux = l->head;
    size_t i;
    while (aux != NULL)
    {
        for (i = 0; i < (aux->size / sizeof (int)); i++)
        {
            printf("%d \n", ((int*) aux->data)[i]);
        }
        printf("\n");
        aux = aux->next;
    }
    printf("\n");
    printf("Size = %d\n", l->size);
}
