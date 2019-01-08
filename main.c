#include <stdlib.h>
#include <stdio.h>
#include "object.h"
#include "./queue/queue.h"

int main(){
    int a, b, c;
    a = 1;
    b = 2;
    c = 3;

    Queue* q = newQueue(&INTEGER);
    offer(q, &a);
    offer(q, &b);
    offer(q, &c);

    int* n = peekQ(q);
    printf("%d\n", *n);
    poll(q);
    n = poll(q);
    printf("%d\n", *n);

    return 0;
}
