#ifndef LIST_H
#define	LIST_H

#ifdef	__cplusplus
extern "C"
{
#endif

  typedef struct ListElement_
  {
    void *data;
    struct ListElement_ *next;
  } ListElement;

  typedef struct List_
  {
    int size;
    int (*match)(const void *key1, const void *key2);
    ListElement *head;
    ListElement *end;
    void (*destroy)(void *data);

  } List;


  /**
   * 
   * @param l Initializes a linked list
   * @param destroyList The destroy function
   */
  void init(List *l, void (*destroyList)(void *data));
  
  /**
   * Inserts a new element after element
   * @param l
   * @param element
   * @param data
   * @return -1 In case of error
   */
  int insertAfter(List *l, ListElement *element, const void *data,int size);
  
  /**
   * Inserts a new element at the head of the list
   * @param l
   * @param data
   * @return 
   */
  int insert(List *l, const void *data,int size);
  
  /**
   * Prints the list l
   * @param l
   */
  void printList(const List *l);
  void destroyList(List *list);
  

#ifdef	__cplusplus
}
#endif

#endif	/* LIST_H */

