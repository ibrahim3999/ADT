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


    adptArray->array = (PElement*)malloc( sizeof(PElement));
    if (adptArray->array == NULL) {
        free(adptArray);
        return NULL;
    }

/**/
    adptArray->size = 0;
    //adptArray->capacity = 1;
    adptArray->copy = copy;
    adptArray->del = del;
    adptArray->print = print;

    return adptArray;
}
int GetAdptArraySize(PAdptArray PA) {
    if(PA->size==0)return -1;
    return PA->size;
}

void PrintDB(PAdptArray PA) {
    for (int i = 0; i < GetAdptArraySize(PA); i++) {
        if(PA->array[i]!= NULL)
        {
            PA->print(PA->array[i]);
        }
    }
}

PElement GetAdptArrayAt(PAdptArray PA, int index) {
    if (index < 0 || index >= PA->size) {
        return NULL;
    }
    if(PA->array[index]==NULL)
    {
        return NULL;
    }

    return PA->copy(PA->array[index]);
}

void DeleteAdptArray(PAdptArray PA)
{
    if(PA==NULL)
    {
        return;
    }
    free(PA->array);
    free(PA);
}
Result SetAdptArrayAt(PAdptArray PA, int index, PElement element) {
    if (index < 0 ) {
        return FAIL;
    }
    if (index >= PA->size) {
        printf("\n");
        // Need to reallocate the array
        int newCapacity = index +1; //  index +1
        PElement* newArray = (PElement*)realloc(PA->array, newCapacity * sizeof(PElement));
        if (newArray == NULL) {
           // free(newArray);
            return FAIL;
        }

        PA->array = newArray;
        PA->size = newCapacity;
        //free(newArray);
    }
    if(PA->array[index]!=NULL)
    {
        PA->del(PA->array[index]);// delete & free
    }
    PA->array[index] = PA->copy(element);
   
    return SUCCESS;
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