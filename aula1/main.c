/*
 * main.c -- main program function
 */


#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "list.h"


/*
 * main program
 */

int main(int argc, char *argv[])
{
	list_t *list;

	printf("<<BEGIN>>\n");

	/* initialize list */
	list = lst_new();

	/* insert several elements into list */
	insert_new_account(list, 1, 100);
	sleep(1);
	insert_new_account(list, 2, 200);
	sleep(2);
	insert_new_account(list, 3, 300);
	sleep(2);
	insert_new_account(list, 0, 400);
	sleep(1);
	insert_new_account(list, 5, 500);

	/* print list 'list' */
	lst_print(list);

	/* remove elements from list */
	update_account_balance(list, 1, 150);
	sleep(1);
	update_account_balance(list, 2, 300);
	sleep(2);
	update_account_balance(list, 5, 1000);

	/* print list */
	lst_print(list);

	/* clean up list */
	lst_destroy(list);

	printf("<<END>>\n");

	return 0;
}
