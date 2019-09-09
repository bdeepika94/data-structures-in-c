#ifndef _INCLUDED_SLIST
#define _INCLUDED_SLIST
#include<stdint.h>


typedef struct _node_ Node;
typedef struct _slist_ Slist;


struct _node_{
int32_t data;
Node *next,*prev;
};


struct _slist_{
Node *head;
Node *tail;
uint32_t length;
};



/* public interface for user*/
Slist slist_new();
uint32_t slist_length(Slist *list);
uint32_t slist_lookup(Slist *list,int32_t key);
Slist* slist_addtail(Slist *list,int32_t element);
Slist* slist_addhead(Slist *list,int32_t element);
Slist* slist_deletetail(Slist *list);
Slist* slist_deletehead(Slist *list);
Slist* slist_display(Slist *list)