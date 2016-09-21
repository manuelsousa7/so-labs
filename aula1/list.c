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
		free(item->owner);
		free(item);
		item = nextitem;
	}
	free(list);
}

void insert_new_account(list_t *list, int accountid, int balance, char * owner)
{
	lst_item_t *item = malloc(sizeof(lst_item_t));
	item->owner=strdup(owner);
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
	for(lst_item_t *a=list->first;a->next!=NULL;a=a->next){
		if(a->accountid == accountid){
			a->balance=newbalance;
			break;
		}
	}
}

void delete_accounts_by_owner(list_t *list, const char *owner)
{
	for(lst_item_t *prev=list->first,*cur=list->first->next;cur->next!=NULL;prev=cur,cur=cur->next){
		if (strcmp(cur->owner,owner)==0){
			prev->next=cur->next;
			lst_item_t * old=cur;
			free(old->owner);
			free(old);
		}
	}
}

void lst_print(list_t *list)
{
	lst_item_t *item;
	printf("Account ID\tBalance\n");
        // FIXME: what if list is NULL?
	item = list->first;
	while(item != NULL) {
		printf("%d\t\t%d\n", item->accountid, item->balance);
		item = item->next;
	}

	printf("\n");
}
