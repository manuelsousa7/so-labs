/*
 * list.c - definitions of an account list
 */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "list.h"


list_t* lst_new()
{
	list_t *list = malloc(sizeof(list_t));

	if (list == NULL)
		return NULL;

	list->first = NULL;
	return list;
}

void lst_destroy(list_t *list)
{
	struct lst_item *item = NULL, *nextitem = NULL;

        // FIXME: what if list is NULL?
	item = list->first;
	while (item != NULL){
		nextitem = item->next;
		free(item);
		item = nextitem;
	}
	free(list);
}

void insert_new_account(list_t *list, int accountid, int balance)
{
	lst_item_t *item = malloc(sizeof(lst_item_t));

	// FIXME: what if the allocation fails?
	item->accountid = accountid;
	item->balance = balance;
	item->next = list->first;

	// FIXME: what if list is NULL?
	// FIXME: what if the given accountid already exists?
	list->first = item;
}


void update_account_balance(list_t *list, int accountid, int newbalance)
{
	// TODO
}

void delete_accounts_by_owner(list_t *list, const char *owner)
{
	// TODO
}

void lst_print(list_t *list)
{
	lst_item_t *item;

	printf("Account ID\tBalance\n");

        // FIXME: what if list is NULL?
	item = list->first;
	while(item->next != NULL) {
		printf("%d\t\t%d\n", item->accountid, item->balance);
		item = item->next;
	}

	printf("\n");
}
