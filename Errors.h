

#ifndef Errors_h
#define Errors_h

#include <stdio.h>
#include <stdlib.h>


typedef struct element
{
    int code_error;
    struct element *next;
} list_errors;

list_errors *init_list (int c);
void add_error_list_end(int c, list_errors *head);
list_errors *free_list(list_errors *head);
void print_list_errors(list_errors *head);

#endif /* Errors_h */

