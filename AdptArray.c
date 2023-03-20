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


    adptArray->array = (PElement*)malloc(1 * sizeof(PElement));
    if (adptArray->array == NULL) {
        free(adptArray);
        return NULL;
    }

/**/
    
    adptArray->size = 1;
    //adptArray->capacity = 1;
    adptArray->copy = copy;
    adptArray->del = del;
    adptArray->print = print;

    return adptArray;
}
int GetAdptArraySize(PAdptArray PA) {
    return PA->size;
}

void PrintDB(PAdptArray PA) {
    for (int i = 0; i < PA->size; i++) {
        PA->print(PA->array[i]);
    }
}
Result SetAdptArrayAt(PAdptArray PA, int index, PElement element) {
    if (index < 0 ) {
        return FAIL;
    }
    if (index >= PA->size) {
        printf("Yes\n");
        // Need to reallocate the array
        int newCapacity = (index +1)*2; // Double the capacity
        PElement* newArray = (PElement*)realloc(PA->array, newCapacity * sizeof(PElement));
        if (newArray == NULL) {
            free(newArray);
            return FAIL;
        }

        PA->array = newArray;
        PA->size = newCapacity;
        free(newArray);
    }

  //  PA->del(PA->array[index]);

    PA->array[index] = PA->copy(element);
   
    return SUCCESS;
}


/**
Result SetAdptArrayAt(PAdptArray PA, int, PElement);
PElement GetAdptArrayAt(PAdptArray, int);
int GetAdptArraySize(PAdptArray);
void PrintDB(PAdptArray);
*/
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