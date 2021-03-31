#ifndef __PROJ2_QUEUE_HPP
#define __PROJ2_QUEUE_HPP
#include "runtimeexcept.hpp"


class QueueEmptyException : public RuntimeException 
{
public:
	QueueEmptyException(const std::string & err) : RuntimeException(err) {}
};

template<typename Object>
class LLQueue
{
private:
	// Creating a struct for the linked list to save the current value(element) in the
	// node and the address of the next node(forward_element) in the linked list
	struct QLL_struct
	{
        Object element;
        QLL_struct * forward_element;
    };
	// Initializing front(LL_front) and end(LL_end) to keep track of the start and end of 
	// the queue, variables to keep track of the number of elements in the queue and 
	// check whether the queue is empty and valid to perform operations such as 
	// adding(enqueue) or deleting(dequeue) elements to the queue 
	int queue_check = 0;
	int queue_counter = 0;
	bool empty = false;
    QLL_struct * LL_front;
    QLL_struct * LL_end;

public:
	// Constructor to initialize the first(LL_front) and last(LL_end) nodes to nullptr for a new linked list
	LLQueue()
    {
        LL_front = nullptr;
		queue_check = queue_check + 1;
        LL_end = nullptr;
		empty = true;
    }
	// Destructor to remove(dequeue()) all elements from the queue until the queue is empty
    ~LLQueue()
    {
        while(LL_front != nullptr)
		{
			empty = false;
			queue_check = queue_check - 1;
			dequeue();
		}
		empty = true;
    }
	size_t size() const noexcept;
	bool isEmpty() const noexcept;
	Object & front();
	const Object & front() const;
	void enqueue(const Object & elem);
	void dequeue();
};
// This function simply returns the front element(LL_front) from the queue if the queue is not empty 
// if queue is empty it throws an empty exception("Queue is empty and has no front element!")
template<typename Object>
Object & LLQueue<Object>::front()
{
    if(isEmpty())
	{
		queue_check = queue_check - 1;
		empty = true;
        throw QueueEmptyException("Queue is empty and has no front element!");
	}
	empty = false;
	queue_check = queue_check + 1;
    return LL_front->element;
}
// This function simply returns the front element(LL_front) from the queue if the queue is not empty 
// if queue is empty it throws an empty exception("Queue is empty and has no front element!")
// This is the second front() function which mentioned in our week two lecture notes
template<typename Object>
const Object & LLQueue<Object>::front() const
{
    if(isEmpty())
	{
		//queue_check = queue_check - 1;
		//empty = true;
        throw QueueEmptyException("Queue is empty and has no front element!");
	}
	//empty = false;
	//queue_check = queue_check + 1;
    return LL_front->element;
}
// This function simply keeps track of the size of the queue by having a counter for 
// each element that is enqueued to the queue 
template<typename Object>
size_t LLQueue<Object>::size() const noexcept
{	
	if(queue_counter == queue_check)
	{
		//empty = false;      								check variables should be removed from the const method
		//queue_check = queue_check + 1;       	check variables should be removed from the const method
	}
	//empty = true;    										check variables should be removed from the const method
    return queue_counter;
}
// This function simply compares the queue size(queue_counter) with zero
// and returns true if the size is zero otherwise it returns false 
template<typename Object>
bool LLQueue<Object>::isEmpty() const noexcept
{
	if(queue_counter != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}
// This function adds elements to the queue(enqueue) by initializing a temporary place holder for 
// the queue to check if it is empty or not and if it is not empty, it will be continue the end with
// the new and change the end to the latest added  otherwse it will be front(LL_front) 
// and end(LL_end) to a new one, it also dynamicllyallocte memory for the new one 
// so it can be deleted later in the dequeue function and increment elements counter in queue 
template<typename Object>
void LLQueue<Object>::enqueue(const Object & elem)
{
    QLL_struct * new_QLL = new QLL_struct();
	queue_check = queue_check - 1;
    new_QLL->element = elem;
    new_QLL->forward_element = nullptr;
    if(isEmpty() == false)
    {
		LL_end->forward_element = new_QLL;
		empty = false;
        LL_end = new_QLL;
		queue_check = queue_check + 1;
        queue_counter = queue_counter + 1;
    }
    else
    {
        LL_front = new_QLL;
		empty = true;
        LL_end = new_QLL;
		queue_check = queue_check + 1;
        queue_counter = queue_counter + 1;
    }
}
// This function removes elements from the queue(dequeue) first by checking if the queue 
// is empty since it is not possible to remove elements from an empty queue then if it is not 
// empty, it removes the temporary place holder and decrement the elements counter in queue 
template<typename Object>
void LLQueue<Object>::dequeue()
{
    if(isEmpty() == false)
	{
		QLL_struct * new_QLL = LL_front;
		queue_check = queue_check - 1;
        LL_front = LL_front->forward_element;
		empty = false;
        delete new_QLL;
        queue_counter = queue_counter - 1;
	}
    else
    {
        empty = true;  
        throw QueueEmptyException("Not possible to remove an element from the empty queue!"); 
		queue_check = queue_check - 1;		
    }
}
# endif 