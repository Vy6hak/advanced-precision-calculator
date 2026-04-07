#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

int insert_at_last(Dlist **head, Dlist **tail, int data);
int Convert(char ch);
void print_list(Dlist *head);
int validate_args(int argc, char *argv[]);

int insert_at_first(Dlist **head, Dlist **tail, int data);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3);
int compare(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2);
int Substraction(Dlist **head1, Dlist **tall1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3);
int delete_at_first(Dlist **head, Dlist **tail);

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3);
int delete_list(Dlist **head, Dlist **tail);

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **head3, Dlist **tail3/*, int sign1, int sign2*/);
int is_zero(Dlist *head);
void remove_trailing_zeros(Dlist **head, Dlist **tail);


#endif