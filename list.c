#include "list.h"

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
    
    ret = regcomp (&r, regex_text, REG_EXTENDED);
    if (ret != 0)
    {	   
        
	regerror (ret, &r, error_message, sizeof(error_message));
        printf ("Regex error compiling '%s': %s\n",regex_text, error_message);
        
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
        ret = regexec (&r, line, n_matches, m, 0);
        if(ret == 0)
        {
            insert(l,line,sizeof(line));
        }
    }
    regfree (&r);
    fclose(fp);
    return 1;
}

int insert(List *l, const void *data, int size)
{
    ListElement *n = NULL;
    if ((n = (ListElement *) malloc(sizeof (ListElement))) == NULL)
    {
        return -1;
    }
    n->data = (void *) malloc(size);
    memcpy(n->data, data, size);
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

void init(List *l, void (*destroyList)(void *data))
{
    l->size = 0;
    l->head = l->end = NULL;
    l->destroy = destroyList;
}

void destroyList(List *l)
{
    ListElement *old = NULL;
    if(l->destroy!=NULL)
    {
        
        while(l->head!=NULL)
        {
            old = l->head->next;
            //destroy head
            l->destroy(l->head);
            l->size--;
            l->head = old;
        }
    }
}

void printListString(const List *l)
{
    ListElement *aux = l->head;
    
    while (aux != NULL)
    {
        printf("%s\n",(char*)aux->data);
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

int insertAfter(List *l, ListElement *element, const void *data, int size)
{
    ListElement *n = NULL;
    if (element == NULL)
    {
        return insert(l, data, size);
    }
    else
    {

        if ((n = (ListElement *) malloc(sizeof (ListElement))) == NULL)
        {
            return -1;
        }
        n->data = (void *) malloc(size);
        memcpy(n->data, data, size);
        n->next = NULL;
        n->size = size;
        if (element == l->end)
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
    int length = source->size, i = 0;
    ListElement *aux = source->head;
    while (i < length && aux != NULL)
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
