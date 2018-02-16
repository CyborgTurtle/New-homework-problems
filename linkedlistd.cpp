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
		
		ListNode* newnode = new ListNode(newdataum);


	 //		The new node next points to cursor->next
		if (head == NULL) {
			head = tail = newnode;
			

		}
		else if (cursor == tail) {
		
			cursor->setNext(newnode);
			newnode->setPrev(cursor);
			tail = newnode;

			

			
			//cursor->setNext(newnode);

			////		The new node prev points to cursor
			//cursor->getNext()->setPrev(newnode);

			
			
			

		}
		else   {
			
			newnode->setNext(cursor->getNext());
			newnode->setPrev(cursor);
			cursor->getNext()->setPrev(newnode);
			cursor->setNext(newnode);
			
			
			
		}
		return newnode;
	
//		The cursor next points to the new node
		

		//		Tail is updated when a node is added to the end
		


		//		Returns a pointer to the new node
		

	}

	//void insertAt( const ListNode::value_type& newdatum,ListNode* cursor = NULL )
	//     Precondition: none
	//     Postcondition: A new node is created with the datum of newdatum.
	ListNode* LinkedList::insertAt(const ListNode::value_type& newdataum, ListNode* cursor)
	{//		The new node next points to cursor
		
		//		The new node prev points to cursor->prev
		if (cursor != head) {
			ListNode* newnode = new ListNode(newdataum,cursor,cursor->getPrev());
			


			//		The cursor->prev next points to the new node
			cursor->getPrev()->setNext(newnode);
			//		The cursor prev points to the new node
			cursor->setPrev(newnode);
			
			


		
		
		}
		//		Head is updated when a node is added to the front
		else if (cursor == head && cursor!= NULL) {
			ListNode* newnode = new ListNode(newdataum);
			cursor->setPrev(newnode);
			newnode->setNext(cursor);
			head = newnode;

		}
			
		//		Tail is updated when a node is added to an empty list
		 else {
			 ListNode* newnode = new ListNode(newdataum);
			 head = newnode;
			tail = newnode;

			return newnode;


		}
		//		Returns a pointer to the new node
	


	}



} //end of LLLAB namespace
