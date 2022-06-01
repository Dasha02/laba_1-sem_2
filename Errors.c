#include "Errors.h"

list_errors *init_list (int code_error)
{
    list_errors *temp=(list_errors*)calloc(1, sizeof(list_errors));
    temp->code_error=code_error;
    temp->next=NULL;
    return temp;
}

void add_error_list_end(int code_error, list_errors *head)
{
    list_errors *temp=(list_errors*)calloc(1,sizeof(list_errors));
    temp->code_error=code_error;
    temp->next=NULL;
    list_errors *f=head;
    while (f->next!=NULL)
        f=f->next;
    f->next=temp;
}



list_errors *free_list(list_errors *head)
{
    while (head!=NULL)
    {
        list_errors *f=head;
        head=head->next;
        free(f);
    }
    return NULL;
}

void print_list_errors(list_errors *head)
{
    char* msg_errors [4];
    msg_errors[0]="0 ошибок  зарегестировано при выполнении программы";
    msg_errors[1]="Ошибка! Несовместимость типов дянных";
    msg_errors[2]="Ошибка! Не определен аргумент";
    
    int i=0;
    if (head==NULL)
    {
        printf ("%s /n",msg_errors[0]);
        return;
    }
    list_errors *f=head;
    while (f->next!=NULL)
    {
        i++;
        printf ("%d - ошибка:  %s \n", i, msg_errors[(f->code_error)]);
        f=f->next;
    }
    i++;
    printf ("%d - ошибка:  %s \n", i, msg_errors[(f->code_error)]);
    printf ("Всего  зарегестиировано: %d - ошибок\n", i);
    return;
}
