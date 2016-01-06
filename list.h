/*
 * Summary: linked list interface
 * Description: Functions to implement the linked lists
 *
 * Author: Jesús Romero <hebrerillo@gmail.com>
 */


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
        void *data; //the data associated with this element
        struct ListElement_ *next; //A pointer to the next element
        size_t size; //The size of the data of this element
    } ListElement;

    typedef struct List_ {
        int size; //The number of elements
        ListElement *head; //A pointer to the first element
        ListElement *end; //A pointer to the last element
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
     * @param destroyList A user defined function to destroy an element from the list
     * @param printList A user defined function to print the elements from the list
     */
    void init(List *l, void (*destroyList)(void *data), void (*printList)(const List *list));

    /**
     * Inserts a new element in the list after element
     * @param l The list
     * @param element The element after which the new element will be inserted. If NULL, the new element will be inserted 
     * in the head
     * @param data Data to be saved with the new element
     * @param size The data size
     * @return 1 if success, 0 otherwise
     */
    int insertAfter(List *l, ListElement *element, void *data, int size);

    /**
     * Inserts a new element at the head of the list
     * @param l The list
     * @param data Data to be saved with the new element
     * @return 1 if success, 0 otherwise
     */
    int insert(List *l, void *data, int size);

    
    /**
     * For every list element, call a user defined function to remove the element
     * @param list
     */
    void destroyList(List *list);
    
    /**
     * Copies the source list in the destination 
     * @param dest The destination list
     * @param source The source list to copy elements from
     * @return 1 if successful, 0 otherwise
     */
    int copyList(List *dest, const List *source);

    /**
     * Builds a new List from data in a FILE
     * @param l The new list
     * @param filename The file name to read data from
     * @return 1 if the operation is successful, 0 otherwise
     */
    int buildFromFile(List *l, const char *filename);


    /**
     * Prints a list using the user-defined function l->printList
     * @param l
     */
    void printList(const List *l);

    /**
     * Concatenates two lists (l1 and l2)
     * Links the end of l1 with the head of l2, and makes the end of l2 the new end
     * @return 1 if the operation is successful, false otherwise
     */
    int concat(List *l1, List *l2);

#ifdef __cplusplus
}
#endif

#endif /* LIST_H */

