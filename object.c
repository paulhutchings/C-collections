#include "object.h"
#include <string.h>

int INTEGER(int a, int b){
    return a == b;
}

int CHARACTER(char a, char b){
    return INTEGER(a, b);
}

int STRING(char* a, char* b){
    return strcmp(a, b) == 0;
}

int DOUBLE(double a, double b){
    return a == b;
}

int FLOAT(float a, float b){
    return a == b;
}