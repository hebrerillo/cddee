#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <regex.h>

#ifdef __cplusplus
extern "C" {
#endif

    typedef struct ListElement_ {
        void *data;
        struct ListElement_ *next;
        size_t size;
    } ListElement;

    typedef struct List_ {
        int size;
        int (*match)(const void *key1, const void *key2);
        ListElement *head;
        ListElement *end;
        void (*destroy)(void *data); //user function to destroy the data of this list
        void (*printList)(const struct List_ *list); //user function to print the data of this list

    } List;

    /**
     * Removes an element from the list. If element is NULL, the head is removed
     * @param list
     * @param element
     * @param data
     * @return 1 if success, 0 otherwise
     */
    int removeNext(List *list, ListElement *element, void *data);
    /**
     * 
     * @param l Initializes a linked list
     * @param destroyList The destroy function
     */
    void init(List *l, void (*destroyList)(void *data), void (*printList)(const List *list));

    /**
     * Inserts a new element after element
     * @param l
     * @param element
     * @param data
     * @return -1 In case of error
     */
    int insertAfter(List *l, ListElement *element, const void *data, int size);

    /**
     * Inserts a new element at the head of the list
     * @param l
     * @param data
     * @return 
     */
    int insert(List *l, const void *data, int size);

    void destroyList(List *list);
    /**
     * 
     * @param dest The destination list
     * @param source The source list to copy elements from
     * @return 1 if successful, 0 otherwise
     */
    int copyList(List *dest, const List *source);

    /**
     * Builds a new List from data in a FILE
     * @param l The new list
     * @param FILE The file to read data from
     * @return 1 if the operation is successful, false otherwise
     */
    int buildFromFile(List *l, const char *filename);

    void destroyList(List *l);

    /**
     * Prints a list using the user-defined function l->printList
     * @param l
     */
    void printList(const List *l);

    /**
     * Concatenates two lists (l1 and l2)
     * @return 1 if the operation is successful, false otherwise
     */
    int concat(List *l1, List *l2);




#ifdef __cplusplus
}
#endif

#endif /* LIST_H */

