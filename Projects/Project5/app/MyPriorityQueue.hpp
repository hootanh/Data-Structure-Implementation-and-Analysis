#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

#include "runtimeexcept.hpp"

class PriorityQueueEmptyException : public RuntimeException 
{
public:
	PriorityQueueEmptyException(const std::string & err) : RuntimeException(err) {}
};

template<typename Object>
class MyPriorityQueue
{
	private:
		std::vector<Object> heap;
		int size_queue;
		int left(int parent);
		int right(int parent);
		int parent(int child);
		void heapifyup(int index);
		void heapifydown(int index);
		
	public:
		MyPriorityQueue();
		~MyPriorityQueue();
		size_t size() const noexcept;
		bool isEmpty() const noexcept;
		void insert(const Object & elem);
		const Object & min() const; 
		void extractMin(); 
};

template<typename Object>
inline int MyPriorityQueue<Object>::left(int parent)
{
	int l = 2 * parent + 1;
	if (l < heap.size())
	{
		return l;
	}
	else
	{
		return -1;
	}
}

template<typename Object>
inline int MyPriorityQueue<Object>::right(int parent)
{
	int r = 2 * parent + 2;
	if (r < heap.size())
	{
		return r;
	}
	else
	{
		return -1;
	}
}

template<typename Object>
inline int MyPriorityQueue<Object>::parent(int child)
{
	int p = (child - 1) / 2;
	if (child == 0)
	{
		return -1;
	}
	else
	{
		return p;
	}
}

template<typename Object>
inline void MyPriorityQueue<Object>::heapifyup(int in)
{
	if (in >= 0 && parent(in) >= 0 &&  heap[in] < heap[parent(in)])
	{
		Object temp = heap[in];
		heap[in] = heap[parent(in)];
		heap[parent(in)] = temp;
		heapifyup(parent(in));
	}
}

template<typename Object>
inline void MyPriorityQueue<Object>::heapifydown(int in)
{
	int child = left(in);
	int child1 = right(in);
	if (child >= 0 && child1 >= 0 && heap[child1] < heap[child])
	{
		child = child1;
	}
	if (child > 0 && heap[child] < heap[in]) 
	{
		Object t = heap[in];
		heap[in] = heap[child];
		heap[child] = t;
		heapifydown(child);
	}
}

template<typename Object>
inline MyPriorityQueue<Object>::MyPriorityQueue()
{}

template<typename Object>
inline MyPriorityQueue<Object>::~MyPriorityQueue()
{
	heap.clear();
}

template<typename Object>
size_t MyPriorityQueue<Object>::size() const noexcept
{
	return heap.size();
}

template<typename Object>
bool MyPriorityQueue<Object>::isEmpty() const noexcept
{
	return(heap.size()==0);
}

template<typename Object>
void MyPriorityQueue<Object>::insert(const Object & elem) 
{
	heap.push_back(elem);
	heapifyup(heap.size() - 1);
}

template<typename Object>
const Object & MyPriorityQueue<Object>::min() const
{
	if (isEmpty())
	{
		throw PriorityQueueEmptyException("Queue is Empty therefore no min value");
	}
	else
	{
		return heap.front();
	}
}

template<typename Object>
void MyPriorityQueue<Object>::extractMin() 
{
	if (!isEmpty())
	{
		heap[0] = heap.at(heap.size() - 1);
		heap.pop_back();
		heapifydown(0);
	}
	else
	{
		throw PriorityQueueEmptyException("Cannot remove from an empty queue");
	}
}
#endif