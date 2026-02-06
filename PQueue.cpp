/*
 * LaQueue
 * 
 * 
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *  
 * (c) copyright 2018, James Shockey - all rights reserved
 * 
 * */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "PQueue.h"



/*
 * Class Priority Queue
 */

		
/*
* Insert into Priority Queue
*/
void PQueue::push(void *item, int priority)
{
	/* Your code here */
	node* tmp = new node;
	tmp->data = item;
	tmp->priority = priority;
	tmp->link = NULL;
	
	
	if (front == NULL || priority < front->priority) {
	    tmp->link = front;
	    front = tmp;
	} else {
	    node* current = front;
	    
	    while (current->link && priority >= current->link->priority) {
	        current = current->link;
	    }
	    
	    tmp->link = current->link;
	    current->link = tmp;
	}
	
	
}

/*
 * Delete from Priority Queue
 */
void* PQueue::top()
{
	/* Your code here */
	if (front == NULL) {
	    return NULL;
	}
	return front->data;
}
/*
 * Delete from Priority Queue
 */
void PQueue::pop()
{
	/* Your code here */
	if (front == NULL) {
	    return;
	}
	
	node* t = front;
	front = front->link;
	delete t;
}

/*
 * Print Priority Queue
 */
void PQueue::display()
{

	/* Your code here */
	
	/* Use the following out command for the data */
	node* ptr = front;
	
	while (front != NULL) {
	    std::cout<<ptr->priority<<" "<<(char*)ptr->data<<std::endl;
	    
	    ptr = ptr->link;
	}
	

}
	
	
void PQueue::setFlag(long flag) {
	 this->flag = flag;
}
	

long PQueue::getFlag() {
	 return flag;
}

long PQueue::getCur() {
    return currentmsg;
}


