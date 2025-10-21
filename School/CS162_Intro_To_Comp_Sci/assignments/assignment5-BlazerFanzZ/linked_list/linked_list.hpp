#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "node.hpp"

class linked_list {
private:
	int length = 0; // the number of nodes contained in the list.
	node* head = nullptr; // a pointer to the first node in the list.
	node* current = nullptr;
	int up_or_down = 0;
public:
	// Empty default constructor
	linked_list() = default;

	// Copy constructor
	linked_list(const linked_list& other);

	// Assignment operator overload
	void operator=(const linked_list& other);

	// Destructor
	~linked_list();

	/*********************************************************************
	 ** Function: get_length()
	 ** Description: Returns length of list.
	 ** Returns (int): Length of list (# of nodes).
	 ********************************************************************/
	int get_length();

	/*********************************************************************
	 ** Function: print()
	 ** Description: Prints all values in the list.
	 ********************************************************************/
	void print();

	/*********************************************************************
	 ** Function: clear()
	 ** Description: Removes all nodes from list (and deletes them from the
	 ** 	heap).
	 ** Post-Conditions: length = 0, head = nullptr.
	 ********************************************************************/
	void clear();

	/*********************************************************************
	 ** Function: push_front()
	 ** Description: Inserts a new value at the front (beginning) of the
	 	list in a new node. All subsequent elements should be shifted
		over to make room for it.
	 ** Parameters: int - value being added to list.
  	 ** Post-Conditions: given value inserted at the beginning of the list
	 	in a new node, and all subsequent elements are shifted over
		to make room for it.
	 ********************************************************************/
	void push_front(int value);

	/*********************************************************************
	 ** Function: push_back()
	 ** Description: Insert a new value at the back (end) of the list in a
	 		new node.
	 ** Parameters: int - value being added to list.
  	 ** Post-Conditions: given value inserted at the end of the list in a
		new node
	 ********************************************************************/
	void push_back(int value);

	/*********************************************************************
	 ** Function: insert()
	 ** Description: insert a new value at a specified index. If the given
  		index is invalid, then this function should do nothing. A valid
    		index is anything within [0, N], where N is the current length
      		of the list (if N is given as the index, then the given value
		should be inserted at the end of the list). When inserting an
  		element, all subsequent elements should be shifted over to make
    		room for it.
	 ** Parameters: int value - value being added to list.
	                int index - index of where element is being added.
	 ** Post-Conditions: given value inserted at given index in a new node,
		and all subsequent elements shifted over to make room for it.
	 ********************************************************************/
	void insert(int value, int index);

	/*********************************************************************
	 ** Function: pop_front()
	 ** Description: Remove node at the front (beginning) of the list. If
  		the list is empty, nothing should happen.
	 ** Post-Conditions: Node at the front of the list is removed from the
	 		list and deleted from the heap
	 ********************************************************************/
	void pop_front();

	/*********************************************************************
	 ** Function: pop_back()
	 ** Description: Remove node at the back (end) of the list. If the list
  		is empty, nothing should happen.
	 ** Post-Conditions: Node at the back of the list is removed from the
	 		list and deleted from the heap
	 ********************************************************************/
	void pop_back();

	/*********************************************************************
	 ** Function: remove()
	 ** Description: Remove node at the given index. If the given index
  		is invalid, then this function should do nothing. A valid
    		index is anything within [0, N-1], where N is the current length
      		of the list.
	 ** Parameters: int - index of where node is being removed.
	 ** Post-Conditions: Node at given index is removed. Subsequent nodes
		are shifted over to accommodate. Length of list should be one
		less than before.
	 ********************************************************************/
	void remove(int index);

	/*********************************************************************
	 ** Function: sort_ascending()
	 ** Description: Sorts the list in ascending order.
	 ** Post-Conditions: List's nodes are rearranged to be sorted in
	 		ascending order of their respective values.
	 ********************************************************************/
	void sort_ascending();

	/*********************************************************************
	 ** Function: sort_descending()
	 ** Description: Sorts list in descending order.
	 ** Post-Conditions: List's nodes are rearranged to be sorted in
	 		descending order of their respective values.
	 ********************************************************************/
	void sort_descending();

	/*********************************************************************
	 ** Function: split()
	 ** Description: splits the linked list.
	 ** Parameters: node* - the head of the linked list
	 ** Post-Conditions: lists nodes are split
	 ********************************************************************/

	node* split(node* head);

	/*********************************************************************
	 ** Function: merge_ascending()
	 ** Description: merges the linked list in ascending order
	 ** Parameters: node* - first and second elements of list
	 ** Post-Conditions: List's nodes are rearranged to be sorted in
	 		ascending order of their respective values.
	 ********************************************************************/

	node* merge_ascending(node* first, node* second);

	/*********************************************************************
	 ** Function: merge_sort()
	 ** Description: calls functions to split and sort list
	 ** Post-Conditions: returns the finished list after sorting
	 ********************************************************************/

	node* merge_sort(node* head);

	/*********************************************************************
	 ** Function: merge_descending()
	 ** Description: merges the linked list in descending order
	 ** Parameters: node* - first and second elements of list
	 ** Post-Conditions: List's nodes are rearranged to be sorted in
	 		descending order of their respective values.
	 ********************************************************************/

	node* merge_descending(node* first, node* second);
};

#endif
