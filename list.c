#include <stdlib.h>
#include <stdio.h>

#include "list.h"


llist_t *list_new(val_t val, llist_t *next)
{
    // allocate node //
    llist_t *list = malloc(sizeof(llist_t));
    list->data = val;
    list->next = next;
    return list;
}

uint32_t list_len(llist_t *list)
{
    uint32_t len = 0;
    for(; list; list = list->next)
        ++len;
    return len;
}

/*
 * list_add inserts a new node with the given value val in the list
 * (if the value was absent) or does nothing (if the value is already present).
 */
llist_t *list_add(llist_t *list, val_t val)
{
    llist_t *e = malloc(sizeof(llist_t));
    e->data = val;
    e->next = NULL;
    list->next = e;
    return e;
}

/*
 * get the node specify by index
 * if the index is out of range, it will return NULL
 */
llist_t *list_nth(llist_t *list)
{
    if(!list)
        return list;
    llist_t *fast = list;
    llist_t *slow = list;

    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void list_print(llist_t *list)
{
    llist_t *cur = list;
    /* FIXME: we have to validate the sorted results in advance. */
    printf("\nsorted results:\n");
    while (cur) {
        printf("[%ld] ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
