#ifndef VM_H
#define VM_H

#include "main.h"

class Stack {
	int top;

public:
	string a[1000]; // Maximum size of Stack

	Stack() { top = 0; }

	bool push(string x, int y);
	string pop();
	bool isFull();
};
class VM
{
public:
	VM() {
		fill_n(R, 16, "0");
	}
	void run(string filename);
	string zero_handle(string);
	void Arithmetic_funct(int, string);
	void Comp_funct(int, string);
	void Logic1_funct(int, string);
	void Logic2_funct(int, string);
	void L_S_funct(int, string);
	void Jump_funct(int&, string);
	void Jumpif_funct(int&, string);
	void Call_funct(int&,string);
	void Return_funct(int&, string);
	char sh = 'A';
	string R[16];
	string static_memory[65536];
	string memory_bank[65536];
	//string input;
	//stack<int> Ip_arr;
	int memory_bank_pos_0 = 0;
	class Stack S;

};


#endif