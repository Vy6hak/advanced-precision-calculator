#include "apc.h"
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    int carry = 0, res;
    /*case1 : both lists still have digits*/
    while(temp1 != NULL && temp2 != NULL)
    {
        res = ((temp1 -> data) + (temp2 -> data) + (carry));
        if(res > 9)
        {
            carry = 1;
            res = res % 10;
        }
        else
        {
            carry = 0;
        }
        insert_at_first(head3, tail3, res);

        temp1 = temp1 -> prev;
        temp2 = temp2 -> prev;
    }

    /*case 2 remaining digits in list1*/
    while(temp1 != NULL)
    {
        res = temp1 -> data + carry;

        if(res > 9)
        {
            carry = 1;
            res = res % 10;
        }
        else
        {
            carry = 0;
        }
        insert_at_first(head3, tail3, res);
        temp1 = temp1 -> prev;
    }
    
    /*case3 : remaining digits in list2*/
    while(temp2 != NULL)
    {
        res = temp2 -> data + carry;

        if(res > 9)
        {
            carry = 1;
            res = res % 10;
        }
        else
        {
            carry = 0;
        }
        insert_at_first(head3, tail3, res);
        temp2 = temp2 -> prev;
    }  

    /*final carry in the addition*/
    if(carry == 1)
        insert_at_first(head3, tail3, carry);
    return SUCCESS;
}
int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *result = malloc(sizeof(Dlist));
    if(result == NULL)
        return FAILURE;
    result -> data = data;
    result -> next = NULL;
    result -> prev = NULL;

    /* If list empty*/
    if(*head == NULL &&  *tail == NULL)
    {
        *head = result;
        *tail = result;
        return SUCCESS;
    }
    
    /* Non empty*/
    result -> next = *head;
    (*head) -> prev = result;
    *head = result;
    
    return SUCCESS;

}
int compare(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2)
{
    Dlist *temp1 = *head1;
    Dlist *temp2 = *head2;
    int count1 = 0;
    /* removing trailing zeros in list1 */
    while((*head1)->data == 0 && (*head1)->next != NULL)
    {
        if(temp1 -> data == 0)
        {
            delete_at_first(head1, tail1);
        }
        temp1 = temp1 -> next;
    }
    /* removing trailing zeros in list2 */
    
    while((*head2)->data == 0 && (*head2)->next != NULL)
    {
        if(temp2 -> data == 0)
        {
            delete_at_first(head2, tail2);
        }
        temp2 = temp2 -> next;
    }
    temp1 = *head1;
    temp2 = *head2;
    /* count list 1 digits */
    while(temp1 != NULL)
    {
       count1 ++;
       temp1 = temp1 ->  next;
    }
    /* count list 2 digits */
    int count2 = 0;
    while(temp2 != NULL)
    {
       count2 ++;
       temp2 = temp2 -> next;
    }

    if(count1 > count2)          /* list 1 is large*/
       return 1;

    else if(count1 < count2)     /* list 2 is large */
        return 2;
    else                         /* if lengths are equal compare digits by digits */
    {
        temp1 = *head1;
        temp2 = *head2;
        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->data > temp2->data)
                return 1;
            else if(temp1->data < temp2->data)
                return 2;
    
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return 0;  //equal
    }
    
}
int Substraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3)
{
 
    Dlist *temp1, *temp2;
    int negative = 0; 
    if(compare(head1, tail1, head2, tail2) == 2)
    {
        temp1 = *head1;
        *head1 = *head2;
        *head2 = temp1;

        temp2 = *tail1;
        *tail1 = *tail2;
        *tail2 = temp2;
        
        negative = 1;
    }

    temp1 = *tail1;
    temp2 = *tail2;
    int borrow = 0, res;
    /* case1 : Both list have digits */
    while(temp1 != NULL && temp2!= NULL)
    {
        if((temp1->data - borrow) < temp2->data)
        {
            res = ((temp1->data - borrow + 10) - (temp2->data));
            borrow = 1;
        }
        else
        {
            res = (temp1->data - borrow) - temp2->data;
            borrow = 0;
        }
        insert_at_first(head3, tail3, res);

        temp1 = temp1 -> prev;
        temp2 = temp2 -> prev;
    }

    /*case2 : remaining digit in list1*/
    while(temp1 != NULL)
    {
        res = temp1->data - borrow;
        if(res < 0)
        {
            res = res + 10;
            borrow = 1;
        }
        else
            borrow = 0;
        insert_at_first(head3, tail3, res);
        temp1 = temp1->prev;

    }

    /*while((*head3)->data == 0 && (*head3)->next != NULL)
    {
        Dlist *temp = *head3;
        *head3 = (*head3)->next;
        (*head3)->prev = NULL;
        free(temp);
    }*/
    
  /* negative  
    if(negative)
    {
        printf("-");
    }*/

    return negative ? -1 : SUCCESS; 

}
int delete_at_first(Dlist **head, Dlist **tail)
{
    Dlist *temp = *head;
    if(*head == NULL)
    {
        return FAILURE;
    }
    if(*head == *tail)
    {
        free(temp);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }
    *head = temp -> next;
    (*head) -> prev = NULL; 
    free(temp);
    return SUCCESS;
}

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3)
{
    Dlist *temp2 = *tail2;  /* for each digit in number2 */
    int shift = 0;

    int mul;
    int digit;
    while(temp2 != NULL)
    {
        Dlist *temp1 = *tail1;  /* Reset each digit */
        int carry = 0;

        /* final reult initially empty */
        Dlist *rhead = NULL;
        Dlist *rtail = NULL;

        while(temp1 != NULL)
        {
            mul = (temp1->data * temp2->data) + carry; 
            carry = mul / 10;
            digit = mul % 10;

            insert_at_first(&rhead, &rtail, digit);


            temp1 = temp1 -> prev;
        }
        if(carry != 0)
            insert_at_first(&rhead, &rtail, carry);

        /* add extra zeros to end */
        for(int i=0; i<shift; i++)
            insert_at_last(&rhead, &rtail, 0);

        /* add each multiply */
        Dlist *temp_h = NULL;
        Dlist *temp_t = NULL;
        addition(head3, tail3, &rhead, &rtail, &temp_h, &temp_t);
        delete_list(head3, tail3);

        *head3 = temp_h;
        *tail3 = temp_t;

        shift ++;
        temp2 = temp2 -> prev;

       /* while((*head3)->data == 0 && (*head3)->next != NULL)
        {
            Dlist *temp = *head3;
            *head3 = (*head3)->next;
            (*head3)->prev = NULL;
            free(temp);
        }*/
    }
    return SUCCESS;
}
void remove_trailing_zeros(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
        return;
    while((*head)->data == 0 && (*head)->next != NULL)
    {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
    if(*head == NULL)
        *tail = NULL;
}
int delete_list(Dlist **head, Dlist **tail)
{
    if(*head == NULL)
    {
        return FAILURE;
    }
    if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return SUCCESS;
    }
    Dlist *temp = *head;
    while(temp != NULL)
    {
        *head = temp -> next;
        temp -> prev = NULL;
        free(temp);
        temp = *head;
    }
    *tail = NULL;
    return SUCCESS;
}
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3/*, int sign1, int sign2*/)
{
    /*int resultSign = sign1 * sign2;*/
    if(is_zero(*head2))
    {
        printf("Error: Division by zero\n");
        insert_at_first(head3, tail3, 0);
        return FAILURE;
    }
    if(compare(head1, tail1, head2, tail2) == 2)
    {
        insert_at_first(head3, tail3, 0);
        //return resultSign;
        return SUCCESS;
    } 

    /* Build count = 0 */
    Dlist *count_head = NULL;
    Dlist *count_tail = NULL;
    insert_at_first(&count_head, &count_tail, 0);

    /* Build count = 1 */
    Dlist *one_head = NULL;
    Dlist *one_tail = NULL;
    insert_at_first(&one_head, &one_tail, 1);

    /* divident >= divisor */
    while(compare(head1, tail1, head2, tail2) != 2)
    {
        Dlist *temp_h = NULL;
        Dlist *temp_t = NULL;
        /* divident = divident - divisor */
        Substraction(head1, tail1, head2, tail2, &temp_h, &temp_t);

        /* free old divident  and update*/
        delete_list(head1, tail1);
        *head1 = temp_h;
        *tail1 = temp_t;

        Dlist *sum_h = NULL;
        Dlist *sum_t = NULL;
        /* quotient = quotient + 1 */
        addition(&count_head, &count_tail, &one_head, &one_tail, &sum_h, &sum_t);

        /* free old quaotient */
        delete_list(&count_head, &count_tail);
        count_head = sum_h;
        count_tail = sum_t;

    }

    /* result = count */
    *head3 = count_head;
    *tail3 = count_tail;

    return SUCCESS;

}
int is_zero(Dlist *head)
{
    return(head->data == 0 && head->next == NULL);
}