#include <assert.h>
#include "d_list.h"

int main()
{
//10.   Create double linked list with methods to add, remove, to check the existence of element.



	Slist s = slist_new();
	Slist *list = &s;

	list=slist_addtail(list,100);
	list=slist_addtail(list,200);
	list=slist_addtail(list,40);
	list=slist_addtail(list,560);

	list=slist_deletetail(list);
	list=slist_deletetail(list);

	assert(slist_lookup(list,20)==1);
	assert(slist_lookup(list,80)==0);

	slist_addhead(list,320);
	slist_addhead(list,440);

	slist_deletehead(list);
	assert(slist_length(list)!=2);
	slist_deletehead(list);
	slist_deletehead(list);

	slist_deletehead(list);

	assert(slist_length(list)==0);
	slist_addhead(list,30);

	assert(slist_length(list)==1);
	return 0;
}