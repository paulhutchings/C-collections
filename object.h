//basic object definition
#ifndef OBJECT_H
#define OBJECT_H

extern const void* Object;

//Basic definition for comparing objects. Since this prototype uses void*, you must supply your own implementation of it based on the data type you want to compare
int isEqual(const void* a, const void* b);

#endif