#include "userFunctions.h"
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
    element = NULL;
}

/**
 * Destroy a list of lists
 * @param data
 */
void destroyComplexList(void *data)
{
    ListElement *element = (ListElement*)data;
    List *list = (List*)element->data;
    destroyList(list);
    free(element->data);
    free(element);
    element = NULL;
}
