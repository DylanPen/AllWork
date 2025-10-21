#include <iostream>

#include "linked_list.hpp"

linked_list::linked_list(const linked_list& other) {
	// TODO Complete this function (feel free to give it a member initializer
	// list)
}

void linked_list::operator=(const linked_list& other) {
	// TODO Complete this function
}

linked_list::~linked_list() {
	// TODO Complete this function.
}

int linked_list::get_length() {
	// TODO Complete this function.
	// TODO Remove the below return statement. It's a placeholder just to
	// get the starter code to compile and run.
	return length;
}

void linked_list::print() {
	// TODO Complete this function.
	current = head;
    while (current != nullptr) {  //prints out value of the node while the node exists
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void linked_list::clear() {
	// TODO Complete this function.
	do{  
		node* temp = head; //makes a temp node equal to head
        head = head->next; //sets head to the next element
        delete temp;       //deletes the temp node to clear the memory of the last node
	}
	while(head != nullptr);
	length = 0;
}

void linked_list::push_front(int value) { //makes a linked list of nodes where the new values are set to the front 
	// TODO Complete this function.
	length++;
	current = new node;   //makes a new node
	current->val = value; //sets value of current
    current->next = head; //sets the node after current to head
    head = current;       //sets head equal to current
}

void linked_list::push_back(int value) { //makes a linked list of nodes where the new values are set to the back 
	// TODO Complete this function.
	length++;
    node* new_node = new node; //makes a new node to hold data
    new_node->val = value;     //sets value of new node
    new_node->next = nullptr;
    if (head == nullptr) {
        head = new_node; //if head doesnt exist make it equal to the new node
    } 
	else {
        current = head;
        while (current->next != nullptr) {
            current = current->next; //goes to the very end of the linked list
        }
        current->next = new_node; //sets the last element equal to the new value
    }
}

void linked_list::insert(int value, int index) {
	// TODO Complete this function.
	if (index < 0 || index > length) {
        return; //makes sure index is valid
    }
    node* new_node = new node;
    new_node->val = value;
    new_node->next = nullptr;

    if (index == 0) { //makes first elemets the new value and second element current value
        new_node->next = head; 
        head = new_node;
    } else { 
        current = head;
        for (int i = 0; i < index - 1; ++i) { //itterates through list until at the index position
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;  //makes next value current value and position at index thenew value
    }
    length++;
}

void linked_list::pop_front() {
	// TODO Complete this function.
	if(head != nullptr){ //if list exists
		length--;
		current = head;
    	head = head->next;
    	delete current; //moves head up and deletes the first element
	}
}

void linked_list::pop_back() {
	// TODO Complete this function.
    if (head == nullptr) { //case where there is no list
        return;
    }
    else if (head->next == nullptr) { //case where list is one long
        delete head;
        head = nullptr;
    } 
	else { //if list is more than one long
        current = head;
        while (current->next->next != nullptr) { //contunies through list
            current = current->next;
        }
        delete current->next; //deletes last element of list
        current->next = nullptr;
    }
    length--;
}

void linked_list::remove(int index) {
	// TODO Complete this function.
	current = head;
    if (index < 0 || index >= length) { //makes sure index is valid
        return;
    }
    else if (index == 0) { 
        head = head->next;
		delete current; //deletes first element
		current = nullptr;
    } 
	else {
        current = head;
        for (int i = 0; i < index - 1; ++i) { //continues through and finds index position
            current = current->next;
        }
		node* temp = current->next;
		current->next = current->next->next;  //moves node
		delete temp;  //deletes node
		temp = nullptr;
    }
    length--;
}

void linked_list::sort_ascending() {
	// TODO Complete this function.
    up_or_down = 1;
    head = merge_sort(head);
}

void linked_list::sort_descending() {
	// TODO Complete this function.
    up_or_down = 2;
    head = merge_sort(head);
}

node* linked_list::split(node* head){
    node* fast = head;
    node* slow = head;

    while(fast != nullptr && fast->next != nullptr){ //finds end and middle of list
        fast = fast->next->next;
        if(fast != nullptr){ 
            slow = slow->next;
        }
    }

    node* temp = slow->next; //sets temp to position after middle
    slow->next = nullptr;
    return temp;
}

node* linked_list::merge_ascending(node* first, node* second){
    if(first == nullptr){
        return second;
    }
    if(second == nullptr){
        return first;
    }

    if(first->val < second->val){
        first->next = merge_ascending(first->next, second); 
        return first;
    }
    else{
        second->next = merge_ascending(first, second->next);
        return second; 
    }
}

node* linked_list::merge_descending(node* first, node* second){
    if(first == nullptr){
        return second;
    }
    if(second == nullptr){
        return first;
    }

    if(first->val > second->val){
        first->next = merge_descending(first->next, second); //recursively calls this function and check through first and second values moving them to ordered position
        return first;
    }
    else{
        second->next = merge_descending(first, second->next);
        return second; 
    }
}

node* linked_list::merge_sort(node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    node* second = split(head);

    head = merge_sort(head); //recursively calls this function over to split every element
    second = merge_sort(second);
    if(up_or_down == 1){
        return merge_ascending(head, second);
    }
    else{
        return merge_descending(head, second);
    }
}