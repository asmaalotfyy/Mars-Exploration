#pragma once
template<class ItemType>
class PQueueADT
{
public:
	virtual bool isEmpty() const = 0;

	virtual bool enqueue(const ItemType& newEntry, const ItemType& newKey) = 0;

	virtual bool dequeue(ItemType& FrontEntry) = 0;

	virtual bool peek(ItemType& FrontEntry) const = 0;


	virtual ~PQueueADT() { }
};