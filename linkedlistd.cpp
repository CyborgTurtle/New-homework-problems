//Josue Locandro
//Lab 6

#include <ostream>
#include <cassert>
#include "linkedlistd.h"


namespace LLLAB {

	LinkedList::LinkedList() {
		head = NULL;
	}

	LinkedList::~LinkedList() {
		deleteList();
	}

	void LinkedList::insertItem(ListNode::value_type newdatum) {

		ListNode* ccursor = head;
		ListNode* pcursor = NULL;

		if (head == NULL) {
			insertAt(newdatum, ccursor);
		}
		else {
			while (ccursor != NULL && newdatum > ccursor->getDatum()) {
				pcursor = ccursor;
				ccursor = ccursor->getNext();
			}

			appendAt(newdatum, pcursor);
		}

	}

	void LinkedList::makeList(const ListNode::value_type items[], const size_t& count) {

		deleteList();
		if (count == 0) return;

		insertAt(items[0]);

		ListNode* ccursor = head;

		for (size_t i = 1; i < count; ++i) {
			ccursor = appendAt(items[i], ccursor);

		}

	}

	void LinkedList::deleteList() {

		ListNode* dcursor;

		while (head != NULL) {
			dcursor = head;
			head = head->getNext();
			delete dcursor;
		}
		head = NULL;

	}

	// Left for student to implement

	//void appendAt( const ListNode::value_type& newdatum,ListNode* cursor )

	ListNode* LinkedList::appendAt(const ListNode::value_type& newdataum, ListNode* cursor)
	{//     Precondition: cursor is not NULL
	 //     Postcondition: A new node is created with the datum of newdatum.




	 //		The new node next points to cursor->next
		ListNode* newnode = new ListNode(newdataum);
		if (cursor->getNext() != NULL) {
			newnode->setNext(cursor->getNext());
				

			


			//		The new node prev points to cursor
			newnode->setPrev(cursor);

			//		The cursor->next prev points to the new node
			cursor->getNext()->setPrev(newnode);

			

		}
		//		The cursor next points to the new node
		cursor->setNext(newnode);


		//		Tail is updated when a node is added to the end
		if (cursor->getNext() == NULL) {
			tail = newnode;

		}


		//		Returns a pointer to the new node
		return newnode;

	}

	//void insertAt( const ListNode::value_type& newdatum,ListNode* cursor = NULL )
	//     Precondition: none
	//     Postcondition: A new node is created with the datum of newdatum.
	ListNode* LinkedList::insertAt(const ListNode::value_type& newdataum, ListNode* cursor)
	{//		The new node next points to cursor
		ListNode* newnode = new ListNode(newdataum);
		//		The new node prev points to cursor->prev
		if (cursor != head) {
			newnode->setPrev(cursor->getPrev());


			//		The cursor->prev next points to the new node
			cursor->getPrev()->setNext(newnode);
			//		The cursor prev points to the new node
			cursor->setPrev(newnode);
		}
		//		Head is updated when a node is added to the front
		if (head == cursor) {
			head = newnode;


		}
		//		Tail is updated when a node is added to an empty list
		if (head == NULL && tail == NULL) {
			head = tail = newnode;




		}
		//		Returns a pointer to the new node
		return newnode;


	}



} //end of LLLAB namespace
