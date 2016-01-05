/* 
 * Functions to be defined by the user that will complete some data structures
 */

#ifndef USERFUNCTIONS_H
#define	USERFUNCTIONS_H
#include "list.h"
#ifdef	__cplusplus
extern "C"
{
#endif


/**
 * Destroy a list with single data associated
 * @param data
 */
void destroySimpleList(void *data);

/**
 * Destroy a list of lists
 * @param data
 */
void destroyComplexList(void *data);

/**
 * Print a list with string characters as elements
 * @param l
 */
void printListString(const List *l);
  
/**
 * Print a list with integers arrays as elements
 * @param l
 */
void printListInt(const List *l);
  
#ifdef	__cplusplus
}
#endif

#endif	/* USERFUNCTIONS_H */

