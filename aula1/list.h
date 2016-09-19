/*
 * list.h - declarations of an account list
 */

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


/* lst_iitem - each element of the list points to the next element */
typedef struct lst_item {
	struct lst_item *next;
	int accountid;
	int balance;
} lst_item_t;

/* list_t */
typedef struct {
	lst_item_t *first;
} list_t;


/* lst_new - allocates and initializes a list_t */
list_t* lst_new(void);

/* lst_destroy - free memory of 'list' and its items */
void lst_destroy(list_t *list);

/* insert_new_account - insert into 'list' a new account with given 'accountid'
 * and 'balance' */
void insert_new_account(list_t *list, int accountid, int balance);

/* update_account_balance - updates the 'balance' for a given 'accountid' in
 * 'list' */
void update_account_balance(list_t *list, int accountid, int newbalance);

/* delete_accounts_by_owner - deletes all accounts of a given 'owner' in 'list'
 */
void delete_accounts_by_owner(list_t *list, const char *owner);

/* lst_print - print the content of 'list' to standard output */
void lst_print(list_t *list);

#endif 
