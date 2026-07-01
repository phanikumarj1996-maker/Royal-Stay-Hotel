#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct sLL {
    int data;
    struct sLL* next;
} sLL;

sLL* create_node(int data, sLL* next) {
    sLL* n = malloc(sizeof(sLL));
    if(!n) return NULL;
    n->data = data;
    n->next = next;
    return n;
}

/* Task 1 */
sLL* insert_at_start(int data, sLL* list) {
    return create_node(data, list);
}

/* Task 2 */
sLL* insert_at_pos(int data, sLL* list, unsigned int pos) {
    if(pos == 0) return insert_at_start(data, list);

    sLL* temp = list;
    for(int i = 0; i < pos - 1 && temp; i++)
        temp = temp->next;

    if(!temp) return NULL;

    temp->next = create_node(data, temp->next);
    return list;
}

/* Task 3 */
int get_from_pos(sLL* list, unsigned int pos) {
    for(int i = 0; i < pos && list; i++)
        list = list->next;

    return list ? list->data : INT_MAX;
}

/* Task 4 */
unsigned int find(int data, sLL* list) {
    int pos = 0;
    while(list) {
        if(list->data == data) return pos;
        list = list->next;
        pos++;
    }
    return -1;
}

/* Task 5 */
sLL* delete_at_pos(sLL* list, unsigned int pos) {
    if(!list) return NULL;

    if(pos == 0) {
        sLL* t = list->next;
        free(list);
        return t;
    }

    sLL* temp = list;
    for(int i = 0; i < pos - 1 && temp->next; i++)
        temp = temp->next;

    if(!temp->next) return NULL;

    sLL* del = temp->next;
    temp->next = del->next;
    free(del);

    return list;
}

void print_list(sLL* list) {
    while(list) {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}

int main() {
    sLL* list = NULL;

    for(int i = 0; i < 5; i++)
        list = insert_at_start(i, list);

    print_list(list);

    list = insert_at_pos(99, list, 2);
    print_list(list);

    printf("Value at pos 2: %d\n", get_from_pos(list, 2));
    printf("Find 99 at pos: %d\n", find(99, list));

    list = delete_at_pos(list, 2);
    print_list(list);

    return 0;
}