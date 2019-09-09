#ifndef _INCLUDED_SLIST
#define _INCLUDED_SLIST
#include<stdint.h>


typedef struct _node_ Node;
typedef struct _slist_ Slist;


struct _node_{
int32_t data;       // node def(data and next node address)
Node *next;
};


struct _slist_{
Node *head;
Node *tail;           //head and tail data
uint32_t length;
};



/* public interface for user*/
Slist slist_new();
uint32_t slist_Length(Slist *list);
uint32_t slist_lookup(Slist *list,int32_t key);
Slist* slist_addhead(Slist *list,int32_t element);
Slist* slist_addtail(Slist *list,int32_t element);
Slist* slist_deletehead(Slist *list);
Slist* slist_deletetail(Slist *list);
int32_t slist_min(Slist *list);
int32_t slist_max(Slist *list);
Slist* slist_spec_ele(Slist *list, int32_t element,int32_t spec_ele);
Slist* slist_spec_ele_delete(Slist *list, int32_t spec_ele);
uint32_t list_compare(Slist *list1,Slist *list2);
Slist* reverse_list(Slist *list);
Slist* union_twolist(Slist *union_list,Slist *list1,Slist *list2);
Slist* intersection_twolist(Slist *intersection_list,Slist *list1,Slist *list2);
Slist* unique_slist(Slist* list,uint32_t element);
Slist* slist_display(Slist *list);
#endif // SLIST_H_INCLUDED
