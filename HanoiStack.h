#ifndef HANOISTACK_H
#define HANOISTACK_H

struct Disk{ // Disk Struct that is linked list functionality within stack
	int val; // value or "size" of each disk
	Disk* next;
};

class HanoiStack{ // Class that are Stacks that hold Disks also referred to as "pegs" in the game

private:
	Disk* head;
	bool isEmpty(){ // function to check if a Stack is empty or not
	if (head == nullptr){
		return true;
	}
	else{
		return false;
	}
}

public:
	HanoiStack();
	int peek();
	void push(Disk*);
	Disk* pop();
	void printState();
};

#endif
