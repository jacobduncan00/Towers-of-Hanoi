#include <iostream>
#include <stdlib.h>
#include "HanoiStack.h"

HanoiStack::HanoiStack(){ // constructor, sets head of each linked list to nullptr
	head = nullptr;
}

int HanoiStack::peek(){ // peek function approved by Dr.Anderson, that checks the top each stack
	if (head == nullptr){
		return 11; // if head is nullptr, return 11, this will be used later in the program
	}
	return head -> val; // if head is not pointer, return the value at the top of the stack
}

void HanoiStack::push(Disk* newDisk){ // push function that takes in a pointer to a Disk
	newDisk -> next = nullptr;
	if (head == nullptr){ // if the stack is empty
		head = newDisk; // set the head of the list to the newDisk being passed in
		return;
	}
	newDisk -> next = head; // if the stack is not empty, put newDisk on top of head
	head = newDisk; // set head equal to newDisk
}

Disk* HanoiStack::pop(){ // pop function that returns a pointer to a disk
	if (head == nullptr){ // if head of list in Stack is empty
		std::cout << "Peg is empty, nothing to Pop!" << std::endl;
		return nullptr; // return nullptr
	}
	Disk* holder = new Disk;
	holder -> val = head -> val;
	Disk* temp = head;
	delete head;                                 // this is where I leak memory but do not know how to fix :(
	head = temp -> next;
	return holder;
}

void HanoiStack::printState(){ // print state function that prints the linked list within the Stack
	if (isEmpty()){ // if stack is empty
		std::cout << "    EMPTY" << std::endl;
		std::cout << std::endl;
		return;
	}
	Disk* curr = head;
	while(curr){ // while stack is not empty
		int DiskPrint = curr -> val;
		std::cout << "      " << DiskPrint << std::endl; // print the values within the stack 
		curr = curr -> next;
	}
	std::cout << std::endl;
}
