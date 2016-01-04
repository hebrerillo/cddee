/* 
 * Functions to be defined by the user that will complete some data structures
 */

#ifndef USERFUNCTIONS_H
#define	USERFUNCTIONS_H

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


#ifdef	__cplusplus
}
#endif

#endif	/* USERFUNCTIONS_H */

