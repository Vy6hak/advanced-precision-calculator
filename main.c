#include "apc.h"

int main(int argc, char *argv[])
{

    if(validate_args(argc, argv) == FAILURE)
    {
        printf("Invalid Arguments\n");
        return FAILURE;
    }
    Dlist *head1 = NULL; //initialize the header to NULL
    Dlist *tail1 = NULL; //initialize the tail to NULL

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    //for result list
    Dlist *head3 = NULL; 
    Dlist *tail3 = NULL;

    int sign1 = 1;
    int sign2 = 1;

    int i = 0;

    if(argv[1][0] == '+')
    {
        sign1 = 1;
        i = 1;
    }
    if(argv[1][0] == '-')
    {
        sign1 = -1;
        i = 1;
    }
    while(argv[1][i] != '\0')
    {
        insert_at_last(&head1, &tail1, Convert(argv[1][i]));
        i++;
    }
    printf("num1 : ");
    print_list(head1);

    i = 0;
    if(argv[3][0] == '+')
    {
        sign2 = 1;
        i = 1;
    }
    else if(argv[3][0] == '-')
    {
        sign2 = -1;
        i = 1;
    }
    while(argv[3][i] != '\0')
    {
        insert_at_last(&head2, &tail2, Convert(argv[3][i]));
        i++; 
    }
    printf("num2 : ");
    print_list(head2);

    int resultSign = 1;
    if(strcmp(argv[2], "+") == 0)
    { 
        if(sign1 > 0 && sign2 > 0)
        {
            addition(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            remove_trailing_zeros(&head3, &tail3);
            printf("\nResult : ");
            print_list(head3);
        }
        else if(sign1 < 0 && sign2 < 0)
        {
            addition(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            remove_trailing_zeros(&head3, &tail3);
            printf("\nResult : ");
            printf("-");
            print_list(head3);
        }
        else if(sign1 > 0 && sign2 < 0) 
        {
            int s = Substraction(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            remove_trailing_zeros(&head3, &tail3);
            printf("\nResult : ");
            if(s == -1)
                printf("-");
            print_list(head3);
        }
        else if(sign1 < 0 && sign2 > 0)
        {
            int s = Substraction(&head2, &tail2, &head1, &tail1, &head3, &tail3);
            remove_trailing_zeros(&head3, &tail3);
            printf("\nResult : ");
            /* is Substraction result is negative */
            if(s == -1)
                printf("-");
            print_list(head3);       
        }
    }
    else if(strcmp(argv[2], "-") == 0)
    {
        if(sign1 > 0 && sign2 > 0)
        {
            int s = Substraction(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            remove_trailing_zeros(&head3, &tail3);
            printf("\nResult : ");
            if(s == -1)
                printf("-");
            print_list(head3);
        }
        else if(sign1 < 0 && sign2 < 0)
        {
            int s = Substraction(&head2, &tail2, &head1, &tail1, &head3, &tail3);
            remove_trailing_zeros(&head3, &tail3);
            printf("\nResult : ");
            if(s == -1)
                printf("-");
            print_list(head3);
        }
        else if(sign1 > 0 && sign2 < 0)
        {
            addition(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            remove_trailing_zeros(&head3, &tail3);
            printf("\nResult : ");
            print_list(head3);
        }
        else if(sign1 < 0 && sign2 > 0)
        {
            int s = addition(&head2, &tail2, &head1, &tail1, &head3, &tail3);
            remove_trailing_zeros(&head3, &tail3);
            printf("\nResult : ");
            if(s == -1)
                printf("-");
            print_list(head3);           
        }
    }
    else if((strcmp(argv[2], "x") == 0) || ((strcmp(argv[2], "X"))) == 0)
    {
       // multiplication(&head1, &tail1, &head2, &tail2, &head3, &tail3);
        if((sign1 * sign2) < 0)
        {
            multiplication(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            remove_trailing_zeros(&head3, &tail3);
            printf("\nResult : ");
            printf("-");
            print_list(head3);
        }
        else
        {
            multiplication(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            remove_trailing_zeros(&head3, &tail3);
            printf("\nResult : ");
            print_list(head3);
        }
    }
    else if(strcmp(argv[2], "/") == 0)
    {
        if((sign1 * sign2) < 0)
        {
            division(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            remove_trailing_zeros(&head3, &tail3);
            printf("\nResult : ");
            printf("-");
            print_list(head3);
        }
        else
        {
            division(&head1, &tail1, &head2, &tail2, &head3, &tail3);
            remove_trailing_zeros(&head3, &tail3);
            printf("\nResult : ");
            print_list(head3);
        }
    }

    return 0;
    
}
int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    if(new == NULL)
    {
        return FAILURE;
    }
    new -> data = data;
    new -> next = NULL;
    new -> prev = NULL;
    if(*head == NULL && *tail == NULL)
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    new -> prev = *tail;
    (*tail) -> next = new;
    *tail = new;
    return SUCCESS;

}
int Convert(char ch)
{
    return ch - '0';
}

void print_list(Dlist *head)
{
    Dlist *temp = head;
    while(temp != NULL)
    {
        printf("%d",temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}
int validate_args(int argc, char *argv[])
{
    if(argc != 4)
    {
        printf("Usage: ./a.out <num1> <op> <num2>\n");
        return FAILURE;
    }
    // Validating Operands
    int i = 0;   /* operand 1*/
    if(argv[1][0] == '+' || argv[1][0] == '-')
        i=1;
    if(argv[1][i] == '\0')
        return FAILURE;

    while(argv[1][i] != '\0') 
    {
        if(isdigit(argv[1][i]) == 0)
            return FAILURE;
        i++;
    }

    i = 0; /* operand 2*/
    if(argv[3][0] == '+' || argv[3][0] == '-')
        i=1;
    if(argv[3][i] == '\0')
        return FAILURE;

    while(argv[3][i] != '\0')
    {
        if(isdigit(argv[3][i]) == 0)
            return FAILURE;
        i++;
    }

    // Validation Operator
    if((strcmp(argv[2], "+") != 0) && (strcmp(argv[2], "-") != 0) && (strcmp(argv[2], "/") != 0) && (strcmp(argv[2], "x") != 0) && (strcmp(argv[2], "X") != 0))
    {
        return FAILURE;
    }
    return SUCCESS;
}
