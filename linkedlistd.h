// LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstdlib>

namespace LLLAB {

	class ListNode
	{
	public:
		typedef int value_type;
		ListNode(value_type d = value_type(), ListNode* n = NULL, ListNode* p = NULL) { datum = d; next = n; prev = p; }

		//Assessor
		ListNode const* getPrev() const { return prev; }
		value_type getDatum() const { return datum; }
		ListNode const* getNext() const { return next; }

		//Mutator
		ListNode* getPrev() { return prev; }
		void setDatum(const value_type& d) { datum = d; }
		ListNode* getNext() { return next; }
		void setPrev(ListNode* new_link) { prev = new_link; }
		void setNext(ListNode* new_link) { next = new_link; }

	private:
		ListNode * prev;
		value_type datum;
		ListNode* next;
	};


	class LinkedList
	{
	public:
		LinkedList();
		virtual ~LinkedList();

		ListNode* appendAt(const ListNode::value_type&, ListNode*);
		ListNode* insertAt(const ListNode::value_type&, ListNode* = NULL);
		void insertItem(ListNode::value_type);
		void makeList(const ListNode::value_type[], const size_t& count);
		void deleteList();

		//The following two assessors are for testing purpose and implemented inline
		//Therefore, you do not need to implement in the cpp file
		ListNode* getHead() { return head; };
		ListNode* getTail() { return tail; };

		//The following friend function is implemented in lablinklist.cpp
		friend std::ostream& operator<<(std::ostream&, const LinkedList&);
		friend std::ostream& operator>>(std::ostream&, const LinkedList&);
	private:
		ListNode * head;
		ListNode* tail;
	};

} //end namespace

#endif /* LINKEDLIST_H_ */
