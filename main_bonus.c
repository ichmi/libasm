#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

extern void   ft_list_push_front(t_list **begin_list, void *data);

int main() {

    t_list *head = NULL;
    ft_list_push_front(&head, "foo");
    printf("%s\n", (char *)head->data);

    return 0;
}
