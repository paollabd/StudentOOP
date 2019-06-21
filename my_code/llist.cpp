#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	if (!nd)
	{
		os << "nullptr";
	}
	// else if (nd->next == nullptr)
	// {
	// 	os << "Data: " << nd->data;
	// }
	else
	{
		os << "Data: " << nd->data << " | Next ";
	}
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	if (!head) // head == nullptr
	{
		head = new Node(d, nullptr);
	}
	else add_at_end(head->next, d);
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* head) {
	os << head;
	if (head) print_list(os, head->next); // if it's not null
	else os << endl;
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	head = new Node(d, head);
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
	if (!head) return nullptr;
	else if (head->next == nullptr) return head;
	else return last(head->next);
}


/*
 * Delete head by attaching head to head's next:
 * */
bool del_head(Node*& head)
{
	if (!head) return false;
	else
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return true;
	}
}

/*
 * Delete the last node and set prev->next to nullptr.
 * De-allocate the memory for the node deleted.
 * */
bool del_tail(Node*& curr)
{
	if (!curr) return false;
	else
	{
		if(curr->next == nullptr) // when we have the pointer to the last item
		{
			delete curr;
			curr = nullptr;
			return true;
		}
		else
		{
			return del_tail(curr->next);
		}
	}
}


/*
 * Duplicate the entire list -- you must not share memory!
 * */
Node* duplicate(Node* head)
{
	if (!head) return head;
	else
	{
		return new Node(head->data, duplicate(head->next));
	}
}


/*
 * Reverse the list: return a brand new list with everything reversed.
 * */
Node* reverse(Node* curr, Node* new_next)
{
	if (!curr) return new_next;
	else
	{
		return reverse(curr->next, new Node(curr->data, new_next));
	}
}


Node* join(Node*& list1, Node* list2)
{
	if (!list1) return list2;
	else if (!list2) return list1;
	// Node* last = list1; // head of list1
	// while(last->next!=nullptr) // looking for last item in list1
	// {
	// 	last = last->next;
	// }
	Node* tail = last(list1); // looking for last item in list1
	tail->next = list2; //connect tlast item of list1 to head of list2
	return list1;
}

