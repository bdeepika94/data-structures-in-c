#include <assert.h>
#include "lisst.h"
#include <stdio.h>

int main()
{
	Slist s = slist_new();
	Slist *list = &s;
/*1.      Create a single list with methods to add and delete elements from head and tail positions.
Provide method to check whether an element is present in the list. Count number of elements in
the list.*/

	list = slist_addhead(list, 10);
	list = slist_addhead(list, 20);
	list = slist_addhead(list, 30);
	list = slist_addhead(list, 40);

	assert (slist_Length(list) == 4);
	list = slist_deletehead(list);
	assert (slist_Length(list) == 3);

	list = slist_addtail(list, 50);
	assert (slist_Length(list) == 4);

	list = slist_deletehead(list);
	assert (slist_Length(list) == 3);

	list = slist_deletetail(list);
	assert (slist_Length(list) == 2);

	assert (slist_lookup(list, 100)==0);

//2.      Add methods to Q1 to find maximum and minimum elements in the list.

	int32_t min,max;
	assert(slist_min(list)==10);
	assert(slist_max(list)==20);

//3.      Modify Q1 such that one can add a new element after any specified element.

	list = slist_spec_ele(list,100,20);
	assert (slist_Length(list) == 3);

//4.      Modify Q1 such that one can delete any specified element from the list.

	list = slist_spec_ele_delete(list,20);
	assert (slist_Length(list) == 2);


//5.      Write a method to reverse the elements in the same list.
	list = reverse_list(list);

/*6.      Create two separate single lists. Check two list are same. If the two lists have the same number
of elements in the same order, then they are treated as same.*/

	Slist s1 = slist_new();
	Slist *list1 = &s1;

	list1 = slist_addhead(list1, 100);
	list1 = slist_addhead(list1, 10);

	//slist_display(list1);
	int32_t c= list_compare(list,list1);
	//assert(list_compare(list,list1)==1);

	list1 = slist_addtail(list1,40);
	//slist_display(list1);
	//assert(list_compare(list,list1)==0);

//7.      Write a method which creates the union of elements from two lists.

	Slist u = slist_new();
	Slist *union_list = &u;

	list1 = slist_addhead(list1, 30);
	//list = 10,100
	//list1 = 30,10,100,40

	union_list = union_twolist(union_list,list,list1);
	assert (slist_Length(union_list) == 4);

//8.      Write a method which creates the intersection of elements from two lists.

	Slist i = slist_new();
	Slist *intersection_list = &i;

	intersection_list= intersection_twolist(intersection_list,list,list1);
	//assert (slist_length(intersection_list) == 2);


/*9.      Create single list such that it should always contain unique elements. Care should be taken that, if element is already present in the list, you should not add it again.
*/
	//list1 = 30,10,100,40
	list1 = unique_slist(list1,40);
	assert(slist_Length(list1)==4);

	list1 = unique_slist(list1,50);
	assert(slist_Length(list1)==5);

	return 0;
}