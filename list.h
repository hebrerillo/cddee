#ifndef LIST_H
#define	LIST_H

#ifdef	__cplusplus
extern "C"
{
#endif

  typedef struct ListElement_
  {
    void *data;
    struct ListElement *next;
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
   * Prints the list l
   * @param l
   */
  void printList(const List *l);
  void destroyList(List *list);
  

#ifdef	__cplusplus
}
#endif

#endif	/* LIST_H */

