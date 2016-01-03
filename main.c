#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char** argv)
{  
    List l;
    init(&l, NULL);
    buildFromFile(&l,"phonenumbers.txt");

    printListString(&l);
    return (EXIT_SUCCESS);
}
