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

void destroyComplexList(void *data)
{
    ListElement *element = (ListElement*) data;
    List *list = (List*) element->data;
    destroyList(list);
    free(element);
}

void printListString(const List *l)
{
    ListElement *aux = l->head;

    while (aux != NULL)
    {
        printf("%s ", (char*) aux->data);
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
            printf("%d ", ((int*) aux->data)[i]);
        }
        printf("\n");
        aux = aux->next;
    }
    printf("\n");
    printf("Size = %d\n", l->size);
}
