#include <iostream>
#include <stdlib.h>
#include "HanoiStack.h"

/*
	* Tower of Hanoi Game by Jacob Duncan @ Salisbury University
*/

HanoiStack operator+=(HanoiStack& from, HanoiStack& to){ // takes in two HanoiStacks by reference
	int top, top1;
	top = to.peek(); // peeks the top of the Stack the value is being moved to
	top1 = from.peek(); // peeks the top of the Stack the value is being taken from
	if (top1 == 11){ // if the top of the Stack being taken from is NULL
		std::cout << "Cannot pop an empty peg!" << std::endl;
	}
	if (top < top1){ // if the top of the Stack being moved to is less than the top of the stack being moved from
		std::cout << "Invalid Move. Cannot be completed" << std::endl;
	}
	if (top > top1){ // if the top of the Stack being moved to is greater than the top of the Stack being moved from
		to.push(from.pop()); // pop from and use that as the parameter for the push to function
	}
}

std::ostream& operator <<(std::ostream& os, HanoiStack n){ // output stream and HanoiStack being passed in
	os << std::endl;
	std::cout << "=============" << std::endl;           // output stream this line
	std::cout << std::endl;
	n.printState(); // print the state of the stack
	return os; // return the stream of characters
}

void solve(int level, std::string one, std::string two, std::string three){ // algorithm to solve towers of hanoi and print the instructions
	if (level == 1){
		std::cout << "Move " << level << " 	from " << one << " to " << three << std::endl;
		return;
	}
	solve(level-1, one, three, two);
	std::cout << "Move " << level << " from " << one << " to " << three << std::endl;
	solve(level-1, two, one, three);
}

int main(){
	HanoiStack arr[3]; // 3 Hanoi Stacks
	int level;
	std::cout << "_______________________________________" << std::endl;
	std::cout << "    ⭐ Welcome to Towers of Hanoi ⭐   " << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	std::cout << "                                       " << std::endl;
	std::cout << "              Information:             " << std::endl;
	std::cout << "              ‾‾‾‾‾‾‾‾‾‾‾‾             " << std::endl;
	std::cout << "                                       " << std::endl;
	std::cout << "  1. The level must be less than 10    " << std::endl;
	std::cout << "  2. Type '1', '2', or '3' for columns " << std::endl;
	std::cout << "  3. Enjoy game and make smart moves!  " << std::endl;
	std::cout << "                                       " << std::endl;
	std::cout << "          To win you must move         " << std::endl;
	std::cout << "           all disks to Peg 3          " << std::endl;
	std::cout << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾" << std::endl;
	do {
		std::cout << "                                       " << std::endl;
		std::cout << "  Enter the number of Disks you want   " << std::endl;
		std::cout << "              play with: ";
		std::cin >> level;
		std::cout << std::endl;
	}while (level < 0 || level > 10);
	Disk* newDisk;
	for (int i = level; i > 0; i--){ // initializing the first peg with level # of disks
		newDisk = new Disk; // creates new Disk
		newDisk -> val = i; // initializes the value of the new disk with the i value the for loop is on
		arr[0].push(newDisk); // pushes new Disk onto first peg
	}
	std::cout << "    Peg 1" << arr[0] << "    Peg 2" << arr[1] << "    Peg 3" << arr[2]; // uses << overloaded operator to print the pegs
	int from, to, move = 0;
	bool check = false;
	do{
		std::cout << "Enter the peg you would like to pop from: ";
		std::cin >> from;
		std::cout << "Enter the peg you would like to push to: ";
		std::cin >> to;
		if (check == true){
			std::cout << "STEPS TO SOLVE:" << std::endl;
			solve(level, "Peg 1", "Peg 2", "Peg 3");
		}
		if (from != 4 && to != 4){ // if they do not want to solve, do this if statement
			arr[from-1] += arr[to-1]; // compares from and to HanoiStack
			move++; // move counter increments
			std::cout << "    Peg 1" << arr[0] << "    Peg 2" << arr[1] << "    Peg 3" << arr[2]; // uses << overloaded operator to print the pegs
		}
		else { // if they do want to solve
			check = true;
			std::cout << "STEPS TO SOLVE:" << std::endl;
			solve(level, "Peg 1", "Peg 2", "Peg 3");
			move++;
			std::cout << "    Peg 1" << arr[0] << "    Peg 2" << arr[1] << "    Peg 3" << arr[2]; // uses << overloaded operator to print the pegs
		}
	}while (!((arr[0].peek() == 11) && (arr[1].peek() == 11))); // continue to ask the user to move pegs until they put all pegs onto the third peg
	std::cout << "*** Congrats. You have beat the Almighty Towers of Hanoi in " << move << " moves! ***" << std::endl; // win condition
	for (int i = 0; i < level; i++){ // pops off all disks on each peg to "de-allocate" memory -> not using deconstructor :0
		if(arr[0].peek() != 11){
			arr[0].pop();
		}
		if (arr[1].peek() != 11){
			arr[1].pop();
		}
		if(arr[2].peek() != 11){
			arr[2].pop();
		}
	}
	return 0;
}
