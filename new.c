#include "new.h"
#include <stdlib.h>

void* new(size_t datasize){
    return malloc(datasize);
}