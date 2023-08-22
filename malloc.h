#ifndef MALLOC_H_
#define MALLOC_H_

#include <stdint.h>

typedef struct header {
    unsigned int size;
    uint8_t is_used;
    struct header *next;
    struct header *prev;
} header;

void malloc_init(void *start, void *end);

void *malloc(uint32_t size);

void free(void *ptr);

#endif /* MALLOC_H_ */
