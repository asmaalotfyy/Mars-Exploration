#include "Node.h"
#include "PQueueADT.h"
using namespace std;


template <typename T>
class LinkedPQueue : public PQueueADT<T>
{
private:

	Node<T>* backPtr;
	Node<T>* frontPtr;
public:
	LinkedPQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry, const int& newKey);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~LinkedPQueue();

	LinkedPQueue<T>::LinkedPQueue()
	{
		backPtr = nullptr;
		frontPtr = nullptr;

	}

	bool LinkedPQueue<T>::isEmpty() const
	{
		return (frontPtr == nullptr);
	}
	bool LinkedPQueue<T>::enqueue(const T& newEntry, const int& newKey)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry,newKey); // Insert the new node
		if (isEmpty())//special case if this is the first node to insert
		{
			frontPtr = newNodePtr; // The queue is empty
			backPtr = newNodePtr
			return true;
		}
		 if (newNodePtr->getKey() <= frontPtr->getKey())
		 {
			backPtr = frontPtr;
			frontPtr = newNodePtr;
			frontPtr->setNext(backPtr);
			return true;
		 }
	    if (newNodePtr->getKey() > frontPtr->getKey()&& newNodePtr->getKey() < backPtr->getKey())
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
		}
	} // end enqueue
	bool LinkedPQueue<T>::dequeue(T& frntEntry)
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
	bool LinkedPQueue<T>::peek(T& frntEntry) const
	{
		if (isEmpty())
			return false;

		frntEntry = frontPtr->getItem();
		return true;

	}

	LinkedPQueue<T>::~LinkedQueue()
	{
		T temp;

		//Free (Dequeue) all nodes in the queue
		while (dequeue(temp));
	}
	
};


