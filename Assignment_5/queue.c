//
//  queue.c
//  MOP.Assignments
//
//  Created by Jesper Persson on 2012-11-22.
//  Copyright (c) 2012 Jesper Persson. All rights reserved.
//

#include <stdio.h>
#include "queue.h"

struct qelemstruct
{
    struct qelemstruct *next, *prev;                    // The type for elements in the queue
    int prio;                                           // Pointer to next and previous elements.
    DATA *data;                                         // Priority of the element.
}                                                       // Pointer to the data-element.