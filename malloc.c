#include "malloc.h"

header *head = 0;
void *_curr_brk;

extern uint8_t __heap_start__[];

void *sbrk(uint32_t size) {
    _curr_brk += size;
    return _curr_brk - size;
}

void *malloc(uint32_t size) {

    if (size == 0) {
        return 0;
    }

    if (!head) {
        _curr_brk = (void*) __heap_start__;
        head = sbrk(size + sizeof(header));
        if (head == (void *) -1) {
            return 0;
        }
        head->size = size;
        head->is_used = 1;
        head->prev = 0;
        head->next = 0;
        return ((void *) head) + sizeof(header);
    }

    //search if somewhere is free mem
    void *itt = head;
    void *last = 0;

    while (itt != 0) {

        if (((header *) itt)->size >= size && ((header *) itt)->is_used == 0) {

            ((header *) itt)->is_used = 1;

            //big enough to split
            if ((size + sizeof(header)) + 1 < ((header *) itt)->size) {

                //next header
                (((header *) itt)->next)->prev = (itt + size + sizeof(header));

                //new
                ((header *) (itt + size + sizeof(header)))->is_used = 0;
                ((header *) (itt + size + sizeof(header)))->next = ((header *) itt)->next;
                ((header *) (itt + size + sizeof(header)))->prev = itt;
                ((header *) (itt + size + sizeof(header)))->size = ((header *) itt)->size - sizeof(header) - size;

                //old
                ((header *) itt)->next = (itt + size + sizeof(header));
                ((header *) itt)->size = size;

            }

            return (itt + sizeof(header));
        }
        last = itt;
        itt = ((header *) itt)->next;
    }

    void *new = sbrk(size + sizeof(header));
    if (new == (void *) -1) {
        return 0;
    }

    //create new node
    ((header *) new)->size = size;
    ((header *) new)->is_used = 1;
    ((header *) last)->next = new;
    ((header *) new)->prev = last;
    ((header *) new)->next = 0;

    return (new + sizeof(header));
}

void free(void *ptr) {
    if (!ptr)
        return;

    void *elem = (void *) (ptr - sizeof(header));

    //if(((header*)elem)->is_used == 0)
    //  exit(-1);

    //check if elem is in list    //remove this?
    void *itt = head;
    while (itt) {

        if (elem == itt) {
            break;
        }
        itt = ((header *) itt)->next;
    }

    /*
    if(itt == NULL){
      exit(-1);
    }
     */

    ((header *) elem)->is_used = 0;

    //merge prev
    if (((header *) elem)->prev) {
        if (((header *) elem)->prev->is_used == 0) {
            ((header *) elem)->prev->next = ((header *) elem)->next;
            ((header *) elem)->prev->size += ((header *) elem)->size + sizeof(header);
            if (((header *) elem)->next) {
                ((header *) elem)->next->prev = ((header *) elem)->prev;
            }

            //we are no longer living, lets become the prev
            elem = (void *) ((header *) elem)->prev;
        }
    }

    //merge next
    if (((header *) elem)->next) {
        if (((header *) elem)->next->is_used == 0) {

            ((header *) elem)->size += ((header *) elem)->next->size + sizeof(header);
            if (((header *) elem)->next->next) {
                ((header *) elem)->next->next->prev = elem;
                ((header *) elem)->next = ((header *) elem)->next->next;
            } else {
                ((header *) elem)->next = ((header *) elem)->next->next;
            }
        }
    }

    //free if last element
    if (!((header *) elem)->next) {

        if (((header *) elem)->prev) {
            ((header *) elem)->prev->next = 0;
        }

        //its the header
        if (!((header *) elem)->prev)
            head = 0;

        //brk(elem);
        _curr_brk = elem;           //new
    }
}
