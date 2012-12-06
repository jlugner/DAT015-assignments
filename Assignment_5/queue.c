//
//  queue.c
//  MOP.Assignments
//
//  Created by Jesper Persson on 2012-11-22.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//

#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

struct qelemstruct
{
    struct qelemstruct *next, *prev;                    
    int prio; 
    DATA *data;                                       
};                                                      

struct qstruct
{
    struct qelemstruct *head;
    int length;
};

struct qiteratorstruct
{
    struct qstruct *q;
    struct qelemstruct *curr;
};


struct qelemstruct *new_Qelemstruct()
{
    struct qelemstruct *qelement = malloc(sizeof(struct qelemstruct));
    qelement->next = qelement;
    qelement->prev = qelement;
    qelement->data = 0;
    qelement->prio = 0;
    
    return qelement;
}


Queue new_queue()
{
    Queue theQueue = malloc(sizeof(struct qstruct));
    theQueue->head = new_Qelemstruct();
    theQueue->length = 0;
    return theQueue;
}


void delete_queue(Queue queue)
{
    clear(queue);
    free(queue->head);
    free(queue);
}

void clear(Queue q)
{
    Iterator it = new_iterator(q);
    
    for(go_to_first(it); is_valid(it); remove_current(it))
        ;
    
    delete_iterator(it);
    q->length = 0;
}

int size(Queue q)
{
    return q->length;
}

void add(Queue q, int priority, DATA *d)
{
    struct qelemstruct *element = new_Qelemstruct();
    element->data = d;
    element->prio = priority;
    
    Iterator it = new_iterator(q);

    for (; (is_valid(it) && element->prio <= it->curr->prio); go_to_next(it))
         ;
                
    element->next = it->curr;
    element->prev = it->curr->prev;          
    it->curr->prev->next = element;
    it->curr->prev = element;
                
    q->length++;
    delete_iterator(it);    
}

DATA *get_first(Queue q)
{
    return q->head->next->data;
}

void remove_first(Queue q)
{
    Iterator it = new_iterator(q);
    go_to_first(it);
    remove_current(it);
    delete_iterator(it);
}

Iterator new_iterator(Queue q)
{
    Iterator it = malloc(sizeof(struct qiteratorstruct));
    it->q = q;

    go_to_first(it);
                         
    return it;
}
                         
void delete_iterator(Iterator it)
{
    if (it != NULL)
        free(it);
}
                         
void go_to_first(Iterator it)
{
    it->curr = it->q->head->next;
}
                         
void go_to_last(Iterator it)              
{
    it->curr = it->q->head->prev;
}
                        
void go_to_next(Iterator it)
{
    if (is_valid(it))
        it->curr = it->curr->next;
}
                         
void go_to_previous(Iterator it)
{
    if (is_valid(it))
        it->curr = it->curr->prev;
}
                         
DATA *get_current(Iterator it)
{
   return it->curr->data;
}
                         
int is_valid(Iterator it)
{
    return it->curr != it->q->head;
}

void change_current(Iterator it, DATA *D)
{
    if (is_valid(it))
        it->curr->data = D;
}
                         
void remove_current(Iterator it)
{
    if(is_valid(it))
    {
        it->curr->next->prev = it->curr->prev;
        it->curr->prev->next = it->curr->next;
        
        struct qelemstruct *tmp = it->curr->next;
        free(it->curr);
        it->curr = tmp;
        
        it->q->length--;
    }
}

                         
void find(Iterator it, DATA *D)
{
    for (go_to_first(it); is_valid(it); go_to_next(it))
        if (it->curr->data == D)
            return;
}