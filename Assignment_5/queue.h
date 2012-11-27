//
//  queue.h
//  MOP.Assignments
//
//  Created by Jesper Persson on 2012-11-22.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//
#ifndef DATA
#define DATA    void
#endif

#ifndef QUEUE_H
#define QUEUE_H
    
struct qstruct;
struct qiteratorstruct;

typedef struct qstruct *Queue;
typedef struct qiteratorstruct *Iterator;

Queue new_queue();                          // Allocate memory for new queue
void delete_queue();                        // Remove the entire queue
void clear(Queue q);                        // Clear a queue, but keep it
int size(Queue q);                          // Return the length of the queue
void add(Queue q, int priority, DATA *d);   // Place d in the specified index
DATA *get_first(Queue q);                   // Return the first element
void remove_first(Queue q);                 // Removes the first element

Iterator new_iterator(Queue q);             // Allocate memory for a new Iterator
void delete_iterator(Iterator it);          // Remove the entire Iterator
void go_to_first(Iterator it);              // Go to the first element in the queue
void go_to_last(Iterator it);               // Go to the last element in the queue
void go_to_next(Iterator it);               // Go to the next element in the queue
void go_to_previous(Iterator it);           // Go to the previous element in the queue
DATA *get_current(Iterator it);             // Returns a pointer to the current element
                                            // or zero, should no element be selected
int is_valid(Iterator it);                  // Returns 0 if the iterator is invalid,
                                            // that is, not pointing at a element.
                                            // Will return 1 if iterator is valid.

void change_current(Iterator it, DATA *D);  // Point at d
void remove_current(Iterator it);           // Remove the element currently pointed at
void find(Iterator it, DATA *d);            // Try to find d, if d is found, the iterator
                                            // will point at it, if not, it will take value 0.

#endif
