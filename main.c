#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <stdlib.h>

extern size_t   ft_strlen(const char *str);
extern char*    ft_strcpy(char *dest, const char *src);
extern int      ft_strcmp(char *s1, char *s2);
extern ssize_t  ft_write(int fd, const void *buf, size_t count);
extern ssize_t  ft_read(int fd, void *buf, size_t count);
extern char     *ft_strdup(const char *s);


typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

t_list	*ft_lstnew(void *content);

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());


void test_ft_strlen();
void test_ft_strcpy();
void test_ft_strcmp();
void test_ft_write();
void test_ft_read();
void test_ft_strdup();

int main() {

    test_ft_strlen();
    test_ft_strcpy();
    test_ft_strcmp();
    test_ft_write();
    test_ft_read();
    test_ft_strdup();

    return 0;
}

void test_ft_strlen() {
    printf("ft_strlen\n");

    const char *s = "Foo";

    size_t n = ft_strlen(s);
    printf("%zu\n", n);
}

void test_ft_strcpy() {
    printf("\n\nft_strcpy\n");

    char*   s1 = "Foo";
    char    s2[4];
    char*   s3 = ft_strcpy(s2, s1);

    printf("%s - %p\n", s1, s1);
    printf("%s - %p\n", s2, s2);
    printf("%s - %p\n\n", s3, s3);

    s3[0] = 'B';
    printf("%s - %p\n", s2, s2);
    printf("%s - %p\n", s3, s3);
}

void test_ft_strcmp() {
    printf("\n\nft_strcmp\n");

    char* s1 = "0123";
    char* s2 = "0123";

    size_t n = ft_strcmp(s1, s2);
    printf("%zd \n", n);

    s1 = "01230";
    s2 = "0123";
    n = ft_strcmp(s1, s2);
    printf("%zd \n", n);

    s1 = "0123";
    s2 = "01230";
    n = ft_strcmp(s1, s2);
    printf("%zd \n\n", n);

    s1 = "";
    s2 = "";
    n = ft_strcmp(s1, s2);
    printf("%zd \n", n);

    s1 = "0";
    s2 = "";
    n = ft_strcmp(s1, s2);
    printf("%zd \n", n);

    s1 = "";
    s2 = "0";
    n = ft_strcmp(s1, s2);
    printf("%zd \n", n);
}

void test_ft_write() {
    printf("\n\nft_write\n");

    char *s = "Foo";
    ssize_t n = ft_write(STDOUT_FILENO, s, strlen(s));
    printf("\n%zd\n\n", n);

    s = "Foo";
    n = ft_write(-1, s, strlen(s));
    if (n < 0)
        printf("(%d) write call failed: %s\n\n", errno, strerror(errno));
    else
        printf("\n%zd\n\n", n);
}

void test_ft_read() {
    char buffer[100];
    ssize_t n;

    n = ft_read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
    if (n < 0)
        printf("(%d) read call failed: %s\n\n", errno, strerror(errno));
    else {
        buffer[n] = '\0';
        printf("bytes read: %zd, buffer: %s\n", n, buffer);
    }
}

void test_ft_strdup() {
    char *s1 = "Foo";
    char *s2 = ft_strdup(s1);
    printf("%s : %p\n", s1, s1);
    printf("%s : %p\n", s2, s2);
    free(s2);
}
