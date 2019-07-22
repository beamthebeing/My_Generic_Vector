#include <stdio.h>
#include <stdlib.h>
#include "generic_vector.h"

void integer_assignment(ITEM* pLeft, ITEM right);
void integer_destroy(ITEM* phItem);

int main(int argc, char* argv[])
{
    GENERIC_VECTOR hVector;
    int i;
    
    hVector = generic_vector_init_default(integer_assignment, integer_destroy);
    
    for (i = 0; i < 10; i++)
    {
        generic_vector_push_back(hVector, &i);
    }
    
    for (i = 0; i < generic_vector_get_size(hVector); i++)
    {
        printf("%d\n", *((int*)(*generic_vector_at(hVector, i))));
    }
    
    generic_vector_destroy(&hVector);
    return 0;
}

void integer_assignment(ITEM* pLeft, ITEM right)
{
    //A = B; //case 1 where both A and B exist
    //NULL = B //case 2 where only B exists and we have to make a new object
    //A = A //both objects are the same...what happens?
    if (*pLeft == NULL)
    {
        *pLeft = (ITEM)((int*) malloc(sizeof(int)));
        if (*pLeft == NULL)
        {
            return;
        }
    }
    *((int*)(*pLeft)) = *((int*)right);
    
}
void integer_destroy(ITEM* phItem)
{
    int* pInt = (int*)*phItem;
    
    if (pInt != NULL)
    {
        free(pInt);
        *phItem = NULL;
    }
}
