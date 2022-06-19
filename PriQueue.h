#pragma once
#include "Node.h"
using namespace std;


template <typename T>
class PriQueue
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	PriQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry, const int& newKey);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	T* toArray(int& count);	//returns array of T (array if items)
	~PriQueue();
};



template <typename T>
T* PriQueue<T>::toArray(int& count)
{
	count = 0;

	if (!frontPtr)
		return nullptr;
	//counting the no. of items in the Queue
	Node<T>* p = frontPtr;
	while (p)
	{
		count++;
		p = p->getNext();
	}


	T* Arr = new T[count];
	p = frontPtr;
	for (int i = 0; i < count;i++)
	{
		Arr[i] = p->getItem();
		p = p->getNext();
	}
	return Arr;
}
    template < typename T>
	PriQueue<T>::PriQueue()
	{
		backPtr = nullptr;
		frontPtr = nullptr;
	}
	template < typename T>
	bool PriQueue<T>::isEmpty() const
	{
		return (frontPtr == nullptr);
	}
	template < typename T>
	bool PriQueue<T>::enqueue(const T& newEntry, const int& newKey)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry, newKey); // Insert the new node
		if (isEmpty())//special case if this is the first node to insert
		{
			frontPtr = newNodePtr; // The queue is empty
			backPtr = newNodePtr;
				return true;
		}
		if (newNodePtr->getKey() <= frontPtr->getKey())
		{
			backPtr = frontPtr;
			frontPtr = newNodePtr;
			frontPtr->setNext(backPtr);
			return true;
		}
		if (newNodePtr->getKey() > frontPtr->getKey() && newNodePtr->getKey() < backPtr->getKey())
		{
			Node<T>* temp = frontPtr->getNext();
			Node<T>* ptr = frontPtr;
			while (temp)
			{
				if (newNodePtr->getKey() <= temp->getKey())
				{
					ptr->setNext(newNodePtr);
					newNodePtr->setNext(temp);
					return true;

				}
				else
				{
					ptr = ptr->getNext();
					temp = temp->getNext();
				}
			}

		}
		if (newNodePtr->getKey() >= backPtr->getKey())
		{
			backPtr->setNext(newNodePtr);
			newNodePtr->setNext(nullptr);
			backPtr = newNodePtr;
			return true;
		}
	} // end enqueue
	template < typename T>
	bool PriQueue<T>::dequeue(T& frntEntry)
	{
		if (isEmpty())
			return false;

		Node<T>* nodeToDeletePtr = frontPtr;
		frntEntry = frontPtr->getItem();
		frontPtr = frontPtr->getNext();
		// Queue is not empty; remove front
		if (nodeToDeletePtr == backPtr)	 // Special case: last node in the queue
			backPtr = nullptr;

		// Free memory reserved for the dequeued node
		delete nodeToDeletePtr;

		return true;

	}
	template < typename T>
	bool PriQueue<T>::peek(T& frntEntry) const
	{
		if (isEmpty())
			return false;

		frntEntry = frontPtr->getItem();
		return true;

	}
	template < typename T>
	PriQueue<T>::~PriQueue()
	{
		T temp;

		//Free (Dequeue) all nodes in the queue
		while (dequeue(temp));
	}

	/*#pragma once
	#include <iostream>
	#include "Node.h"
	#include"LinkedQueue.h"


	template <typename T>
	class PriQueue
	{
	private:
		Node<T>* Head;

	public:
		//Constructor
		PriQueue()
		{
			Head = NULL;
		}

		//Function that enqueues the elemtents sorted according to the key
		bool enqueue(T* newEntry, const int& newKey)
		{
			//Creating the new node to be inserted
			Node<T>* temp = new Node<T>(newEntry, newKey);
			Node<T>* ptr;

			//If the entry is in the first place or the list is empty
			if (Head == NULL || (temp->getKey() < Head->getKey()))
			{
				temp->setNext(Head);
				Head = temp;
			}
			//General Case
			else
			{
				ptr = Head;
				while (ptr->getNext() != NULL && ptr->getNext()->getKey() <= temp->getKey())
					ptr = ptr->getNext();

				temp->setNext(ptr->getNext());
				ptr->setNext(temp);
			}
			return true;
		}

		//Function the takes out elements out of the queue
		bool dequeue(Node<T>*& temp)
		{
			if (isEmpty())
				return false;

			temp = Head;
			Head = Head->getNext();
			return true;

		}

		//Function the checks the first element.
		bool peek(Node<T>*& temp)
		{
			if (isEmpty())
				return false;

			temp = Head;
			return true;

		}

		Function that checks whether the queue is empty or not
		bool isEmpty()
		{
			return (Head == NULL);
		}
		Function that prints all the elements of the queue
		void print() const
		{
			Node<T>* ptr = Head;
			while (ptr)
			{
				cout << ptr->getKey() << " ";
				ptr = ptr->getNext();
			}
			cout << endl;
		}

	};*/
