#include "AdptArray.h"
#include "book.h"
#include "Person.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct AdptArray_ {
    PElement* array;
    int size;
    int capacity;
    COPY_FUNC copy;
    DEL_FUNC del;
    PRINT_FUNC print;
} AdptArray;



PAdptArray CreateAdptArray(COPY_FUNC copy, DEL_FUNC del, PRINT_FUNC print) {
   
    PAdptArray adptArray = (PAdptArray)malloc(sizeof(AdptArray));
    if (adptArray == NULL) {
        return NULL;
    }


    adptArray->array = (PElement*)malloc(sizeof(PElement));
    if (adptArray->array == NULL) {
        free(adptArray);
        return NULL;
    }
    Print
    adptArray->size = 0;
    adptArray->capacity = 1;
    adptArray->copy = copy;
    adptArray->del = del;
    adptArray->print = print;

    return adptArray;
}
/**
int main()
{
    pperson p = (pperson)malloc(sizeof(pperson));
    p->first_name = "ibrahim";
    p->last_name = "Mj";
    PAdptArray PA=CreateAdptArray(copy_person,delete_person,print_person);
    PA->print(p);
    return 0;
}*/