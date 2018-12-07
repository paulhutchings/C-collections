#ifndef VECTOR_C
#define VECTOR_C

extern const size_t VECTOR = sizeof(Vector);

typedef struct vector {
    void** data;
    int size;
    int capacity;

} Vector;

Vector* newVector();

#endif