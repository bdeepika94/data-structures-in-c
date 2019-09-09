#include<stdlib.h>
#include<stddef.h>
#include<assert.h>
#include "lisst.h"
#include<stdio.h>
Slist slist_new()
{
    Slist s={NULL,NULL,0};
    return s;
}



static Node* slist_new_node(int32_t element)
{
    Node *new_node=(Node *)malloc(sizeof(Node));
    new_node -> data=element;
    new_node->next=NULL;
    return new_node;
}


Slist* slist_addhead(Slist *list,int32_t element)
{
assert(list!=NULL);
Node *new_node=slist_new_node(element);
new_node->next=list->head;
list->head=new_node;
if(list->tail ==NULL)
    {
        list->tail=new_node;
    }
++list->length;
assert((list->length==1 && list->head==list->tail) || (list->length>0 && list->head!=list->tail));
return list;
}


uint32_t slist_Length(Slist *list)
{

        assert(list!=NULL);
        return list->length;

}


uint32_t slist_lookup(Slist *list,int32_t key)
{

        assert(list!=NULL);
        Node *current;
        for(current=list->head;current!=NULL;current=current->next)
        { if(current->data==key){
          break;

         }
        }
        return (current!=NULL);
}


Slist* slist_deletehead(Slist *list)
{
  Node* tmp;
  if(list->head!=NULL){
        tmp=list->head;
        list->head=list->head->next;
        if(list->head==NULL){
                list->tail=NULL;
        }
        --list->length;
  }free(tmp);
  return list;
}

Slist* slist_display(Slist *list){
Node *tmp;
int count=0;

    if(list->head == NULL)
    {
        printf("List is empty.");
        return list;
    }

    tmp = list->head;
    while(tmp != NULL)
    {
        count=count+1;
        printf("Data = %d\n", tmp->data); // Print data of current node
        tmp = tmp->next;

     }
     printf("length of list: %d\n",count);
 }

Slist* slist_addtail(Slist *list,int32_t element)
{
        assert(list!=NULL);
        Node *new_node=slist_new_node(element);
        if(list->tail!=NULL){
                list->tail->next=new_node;
                list->tail=new_node;
        }
        else{
                list->tail=list->head=new_node;
        }
        ++list->length;
        return list;
}


Slist* slist_deletetail(Slist *list)
{
        assert(list!=NULL);
        Node *current,*tmp;
        if(list->tail!=NULL)
        {
            tmp=list->tail;
            for(current=list->head;current->next!=tmp;current=current->next);
            list->tail=current;
            current->next=NULL;
            --list->length;
        }
        return list;
}


int32_t slist_min(Slist *list) {
    Node *tmp = list->head;
    int32_t min=tmp->data;
    assert(list!=NULL);
    while (tmp!=NULL) {
        if (tmp -> data < min) {
            min = tmp -> data;
        }
        tmp = tmp -> next;
    }
   return min;
}

int32_t slist_max(Slist *list) {
    Node *tmp = list->head;
    int32_t max=0;
    assert(list!=NULL);
    while (tmp!=NULL) {
        if (tmp -> data > max) {
            max = tmp -> data;
        }
        tmp = tmp -> next;
    }
    return max;
}

Slist* slist_spec_ele(Slist *list, int32_t element,int32_t spec_ele)
{
    assert(list!=NULL);
    Node *new_node=slist_new_node(element);
    Node *tmp;
    for(tmp=list->head;tmp!=NULL;tmp=tmp->next)
    {
        if(tmp->data==spec_ele)
        {
            new_node->next=tmp->next;
            tmp->next=new_node;
            if(tmp->next==NULL)
            {
                assert(tmp->next==NULL);
                list->tail=new_node;
            }
        }

    }
    ++list->length;
    return list;

}

Slist* slist_spec_ele_delete(Slist *list, int32_t spec_ele)
{
    assert(list != NULL);
    Node *tmp,*prev;
    prev->next = NULL;
    tmp=list->head;
    if(list->length == 1){
        list->head=NULL;
        list->tail=NULL;
        list->length = 0;
    }
    else if (tmp != NULL && tmp->data == spec_ele)
    {
        list->head= tmp->next;
	--list->length;
        return list;
    }
    else{
    for(tmp=list->head;tmp!=NULL;tmp=tmp->next){


        if(tmp->data == spec_ele)
        {
            prev->next=tmp->next;

	//temp=prev;
        }
        prev = tmp;
    }
    free(tmp);
--list->length;
   }

    return list;
}

Slist* reverse_list(Slist *list)
{
assert(list!=NULL);
Node *prev=NULL,*nxt=NULL,*tmp,*temp1;
tmp=list->head;
temp1= tmp;
while(tmp!=NULL)
{
    nxt = tmp->next;
    tmp->next = prev;
    prev = tmp;
    tmp = nxt;
}
list->tail = temp1;
list->head = prev;
return list;
}

uint32_t list_compare(Slist *list1,Slist *list2)
{
    assert(list1!=NULL);
    assert(list2!=NULL);
    Node *temp1,*temp2;
    temp1=list1->head;
    temp2=list2->head;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data == temp2->data)
        {
            return 1;
        }
        else{
            return 0;
        }

        temp1=temp1->next;
        temp2=temp2->next;
    }
    return (list1 == NULL && list2==NULL);
}


Slist* union_twolist(Slist *union_list,Slist *list1,Slist *list2)
{
    assert(list1!=NULL);
    assert(list2!=NULL);

    Node *temp1,*temp2;
    temp1=list1->head;
    temp2=list2->head;

    while(temp1!=NULL)
    {
	if(!(slist_lookup(union_list, temp1->data)))
        {
            union_list = slist_addtail(union_list,temp1->data);
        }
        //union_list = slist_add_tail(union_list,temp1->data);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        if(!(slist_lookup(list1, temp2->data)))
        {
            union_list = slist_addtail(union_list,temp2->data);
        }
        temp2=temp2->next;
    }
    return union_list;
}

Slist* intersection_twolist(Slist *intersection_list,Slist *list1,Slist *list2)
{
    assert(list1!=NULL);
    assert(list2!=NULL);

    Node *temp1,*temp2;
    temp1=list1->head;
    temp2=list2->head;
    while(temp1!=NULL)
    {
        if(slist_lookup(list2, temp1->data))
        {
            intersection_list = slist_addtail(intersection_list,temp1->data);
        }
        temp1=temp1->next;
    }
return intersection_list;
}


Slist* unique_slist(Slist* list,uint32_t element)
{
 assert(list!=NULL);
    Node *tmp;
    tmp=list->head;

    //Node *cur;
    while(tmp!=NULL)
	{if(!(slist_lookup(list,element)))
        {
            list = slist_addtail(list,element);
	    //++list->length;
        }
tmp= tmp->next;
}



return list;
}
