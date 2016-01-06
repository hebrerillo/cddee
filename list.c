#include "list.h"

int concat(List *l1, List *l2)
{
    if (l1->head == NULL || l2->head == NULL)//do not allow empty list concatenation
        return 0;

    if (l1->printList != l2->printList) //check that both lists have the same 'printList' function
    {
        return 0;
    }

    if (l1->destroy != l2->destroy)//check that both lists have the same 'destroy' function
    {
        return 0;
    }

    l1->end->next = l2->head;
    l1->end = l2->end;
    l1->size += l2->size;

    return 1;
}

int buildFromFile(List *l, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    char line[50];
    regex_t r;
    int ret;
    char error_message[1000];
    const char *regex_text = "(\\+[0-9]{2})?[0-9]{3}\\s*[0-9]{2}\\s*[0-9]{2}\\s*[0-9]{2}";


    const int n_matches = 1;
    regmatch_t m[n_matches];

    ret = regcomp(&r, regex_text, REG_EXTENDED);
    if (ret != 0)
    {

        regerror(ret, &r, error_message, sizeof (error_message));
        printf("Regex error compiling '%s': %s\n", regex_text, error_message);

        return 0;
    }

    if (fp == NULL)
    {
        fprintf(stderr, "%s\n", strerror(errno));
        return 0;
    }

    while (fgets(line, sizeof line, fp) != NULL)
    {
        line[strcspn(line, "\n")] = '\0';
        ret = regexec(&r, line, n_matches, m, 0);
        if (ret == 0)
        {
            insert(l, line, sizeof (line));
        }
    }
    regfree(&r);
    fclose(fp);
    return 1;
}

int insert(List *l, void *data, int size)
{
    ListElement *n = NULL;
    if ((n = (ListElement *) malloc(sizeof (ListElement))) == NULL)
    {
        return 0;
    }
    n->data = data;
    n->size = size;
    n->next = NULL;

    if (l->head == NULL)
    {
        l->head = n;
        l->end = l->head;
        //        l->end->next = NULL;
    }
    else
    {
        n->next = l->head;
        l->head = n;
    }
    l->size++;
    return 1;
}

void init(List *l, void (*destroyList)(void *data), void (*printList)(const List *list))
{
    l->size = 0;
    l->head = l->end = NULL;
    l->destroy = destroyList;
    l->printList = printList;
}

void destroyList(List *l)
{
    ListElement *old = NULL;
    if (l->destroy != NULL)
    {

        while (l->head != NULL)
        {
            old = l->head->next;
            l->destroy(l->head);//call user defined function to destroy the data
            l->size--;
            l->head = old;
        }
    }
}

void printList(const List *l)
{
    if (l->printList != NULL)
        l->printList(l);//call user defined function to print the list
}

int insertAfter(List *l, ListElement *element, void *data, int size)
{
    ListElement *n = NULL;
    if (element == NULL) //if element is NULL, insert at the head
    {
        return insert(l, data, size);
    }
    else
    {

        if ((n = (ListElement *) malloc(sizeof (ListElement))) == NULL)
        {
            return 0;
        }
        n->data = data;
        n->next = NULL;
        n->size = size;
        if (element == l->end)//the new element is inserted after the end, so it becomes the new end
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

int copyList(List *dest, const List *source)
{
    if (dest == NULL || source == NULL)return 0;
    int i = 0;
    ListElement *aux = source->head;
    while (i < source->size && aux != NULL)
    {
        insert(dest, aux->data, aux->size);
        aux = aux->next;
        i++;
    }
    return 1;
}

int removeNext(List *list, ListElement *element, void *data)
{
    if (list == NULL || list->size == 0 || list->head == NULL)return 0;
    ListElement *old;
    if (element == NULL)//remove head
    {
        old = list->head;
        list->head = list->head->next;
    }
    else
    {
        if (element->next != NULL)
        {
            old = element->next;
            if (element->next == list->end)
            {
                list->end = element;
                list->end->next = NULL;
            }
            else if (element->next->next != NULL)
            {
                element->next = element->next->next;
            }
        }
        else
        {
            return 0;
        }
    }

    free(old->data);
    old->data = NULL;
    free(old);
    old = NULL;

    list->size--;
    return 1;
}
