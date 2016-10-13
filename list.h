#ifndef LLIST_H_
#define LLIST_H_

#include <stdint.h>

typedef intptr_t val_t;

typedef struct llist {
    val_t data;
    struct llist  *next;
} llist_t;


llist_t *list_new();
llist_t *list_add(llist_t *the_list, val_t val);
void list_print(llist_t *the_list);
llist_t *list_nth(llist_t *list);
uint32_t list_len(llist_t *list);
#endif
