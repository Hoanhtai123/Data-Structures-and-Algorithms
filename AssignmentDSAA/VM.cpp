#include "VM.h"

regex Arithmetic_operand("(Add|Minus|Mul|Div)\\s(R([1-9]|1[0-5])),\\s(\\d+[A]?|R([1-9]|1[0-5])|[1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false|\\d+[A]?)$");

regex Arithmetic("(Add|Minus|Mul|Div|CmpEQ|CmpNE|CmpLT|CmpLE|CmpGT|CmpGE|And|Or|JumpIf|Move|Store|Load)\\s(\\S+),\\s(\\S+|\\S+.\\S+)$");

regex Comparison_operand("Cmp(EQ|NE|LT|LE|GT|GE)\\s(R([1-9]|1[0-5])),\\s(\\d+[A]|R[1-9]|1[0-5]|[1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false|\\d+[A])$");

regex Logical_operand1("(And|Or)\\s(R([1-9]|1[0-5])),\\s(\\d+[A]|R[1-9]|1[0-5]|[1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false|\\d+[A])$");

regex Logical_operand2("(Not|Input|Output)\\s(\\d+[A]|R([1-9]|1[0-5])|[1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false|\\d+[A])$");

regex Onlydest("(Not|Jump|Call|Input|Output)\\s(\\S+)$");

regex L_S_operand("(Move|Load|Store)\\s(R([1-9]|1[0-5])),\\s(\\d+[A]|R[1-9]|1[0-5]|[1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false|\\d+[A])$");

regex Jump_operand("(Jump)\\s(\\d+[A]|R([1-9]|1[0-5])|[1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false|\\d+[A])$");

regex Jumpif_operand("(JumpIf)\\s(R([1-9]|1[0-5])),\\s(\\d+[A]|R([1-9]|1[0-5])|[1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false|\\d+[A])$");

regex Call_operand("(Call)\\s(\\d+[A]|R([1-9]|1[0-5])|[1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false|\\d+[A])$");

regex Return_operand("(Return)$");

smatch P_str;
smatch scr;
smatch scr_new;
smatch dest;
smatch dest_new;
string result;


string VM::zero_handle(string Zero_check) 
{
	if (regex_match(Zero_check, P_str, regex("[1-9]\\d+|[0-9]|\\d+[.]\\d+")))
	{
		//double tmp = stod(Zero_check);
		//Zero_check = to_string(tmp);
		if (Zero_check.find('.') != string::npos) 
		{
			for (unsigned int i = Zero_check.length() - 1; i >= Zero_check.find('.'); i--) 
			{
				if ((Zero_check[i] == '0' )|| (i == Zero_check.find('.') && Zero_check[i] == '.')) {
					Zero_check.erase(i, 1);
				}
				else {
					break;
				}
			}
		}
	}
	else {
		return Zero_check;
	}	
	return Zero_check;
}

void VM::Arithmetic_funct(int memory_bank_pos, string memory_bank_item)
{
			if (regex_match(memory_bank_item, P_str, Arithmetic_operand))
			{

				string src_0 = P_str[4];
				if (regex_match(src_0, scr, regex("^(\\d+)$")) && regex_match(R[stoi(P_str[3])], dest, regex("^(\\d+)$")))
				{
					if (P_str[1] == "Add") {
						R[stoi(P_str[3])] = to_string(stoi(R[stoi(P_str[3])]) + stoi(scr[1]));
					}
					else if (P_str[1] == "Minus") {
						R[stoi(P_str[3])] = to_string(stoi(R[stoi(P_str[3])]) - stoi(scr[1]));
					}
					else if (P_str[1] == "Mul") {
						R[stoi(P_str[3])] = to_string(stoi(R[stoi(P_str[3])]) * stoi(scr[1]));
					}
					else if (P_str[1] == "Div") {
						if (stoi(scr[1]) == 0) {
							throw DivideByZero(memory_bank_pos);
						}
						else {
							R[stoi(P_str[3])] = to_string(stoi(R[stoi(P_str[3])]) / stoi(scr[1]));
						}
						
					}
				}
				else if (regex_match(src_0, scr, regex("^([1-9]\\d+|[0-9]|\\d+[.]\\d+)$")) && regex_match(R[stoi(P_str[3])], dest, regex("^([1-9]\\d+|[0-9]|\\d+[.]\\d+)$")))
				{
					if (P_str[1] == "Add") {
						R[stoi(P_str[3])] = to_string(stod(R[stoi(P_str[3])]) + stod(scr[1]));
					}
					else if (P_str[1] == "Minus") {
						R[stoi(P_str[3])] = to_string(stod(R[stoi(P_str[3])]) - stod(scr[1]));
					}
					else if (P_str[1] == "Mul") {
						R[stoi(P_str[3])] = to_string(stod(R[stoi(P_str[3])]) * stod(scr[1]));
					}
					else if (P_str[1] == "Div") {
						if (stoi(scr[1]) == 0) {
							throw DivideByZero(memory_bank_pos);	
						}
						else {
							R[stoi(P_str[3])] = to_string(stod(R[stoi(P_str[3])]) / stod(scr[1]));
						}
					}
				}
				else if (regex_match(src_0, scr, regex("R([1-9]|1[0-5])"))) 
				{

					if (regex_match(R[stoi(scr[1])], scr_new, regex("^(\\d+)$")) && regex_match(R[stoi(P_str[3])], dest, regex("^(\\d+)$")))
					{
						if (P_str[1] == "Add") {
							R[stoi(P_str[3])] = to_string(stoi(R[stoi(P_str[3])]) + stoi(R[stoi(scr[1])]));
						}
						else if (P_str[1] == "Minus") {
							R[stoi(P_str[3])] = to_string(stoi(R[stoi(P_str[3])]) - stoi(R[stoi(scr[1])]));
						}
						else if (P_str[1] == "Mul") {
							R[stoi(P_str[3])] = to_string(stoi(R[stoi(P_str[3])]) * stoi(R[stoi(scr[1])]));
						}
						else if (P_str[1] == "Div") {
							if (stoi(R[stoi(scr[1])]) == 0) {
								throw DivideByZero(memory_bank_pos);
							}
							else {
								R[stoi(P_str[3])] = to_string(stoi(R[stoi(P_str[3])]) / stoi(R[stoi(scr[1])]));
							}
							
						}
					}
					else if (regex_match(R[stoi(scr[1])], scr_new, regex("^([1-9]\\d+|[0-9]|\\d+[.]\\d+)$")) && regex_match(R[stoi(P_str[3])], dest, regex("^([1-9]\\d+|[0-9]|\\d+[.]\\d+)$")))
					{
						if (P_str[1] == "Add") {
							R[stoi(P_str[3])] = to_string(stod(R[stoi(P_str[3])]) + stod(R[stoi(scr[1])]));
						}
						else if (P_str[1] == "Minus") {
							R[stoi(P_str[3])] = to_string(stod(R[stoi(P_str[3])]) - stod(R[stoi(scr[1])]));
						}
						else if (P_str[1] == "Mul") {
							R[stoi(P_str[3])] = to_string(stod(R[stoi(P_str[3])]) * stod(R[stoi(scr[1])]));
						}
						else if (P_str[1] == "Div") {
							if (stod(R[stoi(scr[1])]) == 0) {
								throw DivideByZero(memory_bank_pos);
							}
							else {
								R[stoi(P_str[3])] = to_string(stod(R[stoi(P_str[3])]) / stod(R[stoi(scr[1])]));
							}
						}
					}
					
				}
				else {
					throw TypeMismatch(memory_bank_pos);
				}
				//R[stoi(P_str[3])] = zero_handle(R[stoi(P_str[3])]);
				//std::cout << zero_handle(R[stoi(P_str[3])]) << endl;
			}

}
void VM::Comp_funct(int memory_bank_pos, string memory_bank_item)
{
			if (regex_match(memory_bank_item, P_str, Comparison_operand))
			{
				string scr_1 = P_str[4];
				if (regex_match(scr_1, scr, regex("^(\\d+)$")) && regex_match(R[stoi(P_str[3])], dest, regex("^(\\d+)$"))) {
					if (P_str[1] == "EQ") {
						if (stoi(R[stoi(P_str[3])]) == stoi(scr[1])) {
							R[stoi(P_str[3])] = "true";
						}
						else {
							R[stoi(P_str[3])] = "false";
						}
						
					}
					else if (P_str[1] == "NE") {
						if (P_str[1] == "NE") {
							if (stoi(R[stoi(P_str[3])]) != stoi(scr[1])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
					else if (P_str[1] == "LT") {
						if (P_str[1] == "LT") {
							if (stoi(R[stoi(P_str[3])]) < stoi(scr[1])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
					else if (P_str[1] == "LE") {
						if (P_str[1] == "LE") {
							if (stoi(R[stoi(P_str[3])]) <= stoi(scr[1])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
					else if (P_str[1] == "GT") {
						if (P_str[1] == "GT") {
							if (stoi(R[stoi(P_str[3])]) > stoi(scr[1])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
					else if (P_str[1] == "GE") {
						if (P_str[1] == "GE") {
							if (stoi(R[stoi(P_str[3])]) >= stoi(scr[1])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
				}
				//*****************************************************//
				else if (regex_match(scr_1, scr, regex("^([1-9]\\d+|[0-9]|\\d+[.]\\d+)$")) && regex_match(R[stoi(P_str[3])], dest, regex("^([1-9]\\d+|[0-9]|\\d+[.]\\d+)$"))) 
				{
					if (P_str[1] == "EQ") {
						if (stod(R[stoi(P_str[3])]) == stod(scr[1])) {
							R[stoi(P_str[3])] = "true";
						}
						else {
							R[stoi(P_str[3])] = "false";
						}

					}
					else if (P_str[1] == "NE") {
						if (P_str[1] == "NE") {
							if (stod(R[stoi(P_str[3])]) != stod(scr[1])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
					else if (P_str[1] == "LT") {
						if (P_str[1] == "LT") {
							if (stod(R[stoi(P_str[3])]) < stod(scr[1])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
					else if (P_str[1] == "LE") {
						if (P_str[1] == "LE") {
							if (stod(R[stoi(P_str[3])]) <= stod(scr[1])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
					else if (P_str[1] == "GT") {
						if (P_str[1] == "GT") {
							if (stod(R[stoi(P_str[3])]) > stod(scr[1])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
					else if (P_str[1] == "GE") {
						if (P_str[1] == "GE") {
							if (stod(R[stoi(P_str[3])]) >= stod(scr[1])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
				}
				else if (regex_match(scr_1, scr, regex("true|false"))) {
				if (P_str[1] == "EQ") {
					if (R[stoi(P_str[3])] == scr[1]) {
						R[stoi(P_str[3])] = "true";
					}
					else {
						R[stoi(P_str[3])] = "false";
					}

				}

				else if (P_str[1] == "NE") {
					if (P_str[1] == "NE") {
						if (R[stoi(P_str[3])] != scr[1]) {
							R[stoi(P_str[3])] = "true";
						}
						else {
							R[stoi(P_str[3])] = "false";
						}

					}
				}
				else if (P_str[1] == "LT") {
					if (P_str[1] == "LT") {
						if (R[stoi(P_str[3])] < scr[1]) {
							R[stoi(P_str[3])] = "true";
						}
						else {
							R[stoi(P_str[3])] = "false";
						}

					}
				}
				else if (P_str[1] == "LE") {
					if (P_str[1] == "LE") {
						if (R[stoi(P_str[3])] <= scr[1]) {
							R[stoi(P_str[3])] = "true";
						}
						else {
							R[stoi(P_str[3])] = "false";
						}

					}
				}
				else if (P_str[1] == "GT") {
					if (P_str[1] == "GT") {
						if (R[stoi(P_str[3])] > scr[1]) {
							R[stoi(P_str[3])] = "true";
						}
						else {
							R[stoi(P_str[3])] = "false";
						}

					}
				}
				else if (P_str[1] == "GE") {
					if (P_str[1] == "GE") {
						if (R[stoi(P_str[3])] >= scr[1]) {
							R[stoi(P_str[3])] = "true";
						}
						else {
							R[stoi(P_str[3])] = "false";
						}

					}
				}
				}
				//*****************************************************//
				else if (regex_match(scr_1, scr, regex("R([1-9]|1[0-5])"))) 
				{
					if (P_str[1] == "EQ") {
						if (stod(R[stoi(P_str[3])]) == stod(R[stoi(scr[1])])) {
							R[stoi(P_str[3])] = "true";
						}
						else {
							R[stoi(P_str[3])] = "false";
						}

					}
					else if (P_str[1] == "NE") {
						if (P_str[1] == "NE") {
							if (stod(R[stoi(P_str[3])]) != stod(R[stoi(scr[1])])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
					else if (P_str[1] == "LT") {
						if (P_str[1] == "LT") {
							if (stod(R[stoi(P_str[3])]) < stod(R[stoi(scr[1])])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
					else if (P_str[1] == "LE") {
						if (P_str[1] == "LE") {
							if (stod(R[stoi(P_str[3])]) <= stod(R[stoi(scr[1])])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
					else if (P_str[1] == "GT") {
						if (P_str[1] == "GT") {
							if (stod(R[stoi(P_str[3])]) > stod(R[stoi(scr[1])])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
					else if (P_str[1] == "GE") {
						if (P_str[1] == "GE") {
							if (stod(R[stoi(P_str[3])]) >= stod(R[stoi(scr[1])])) {
								R[stoi(P_str[3])] = "true";
							}
							else {
								R[stoi(P_str[3])] = "false";
							}

						}
					}
				}
			
				else {
					throw TypeMismatch(memory_bank_pos);
				}
			}
			//cout << R[stoi(P_str[3])] << endl;
}

void VM::Logic1_funct(int memory_bank_pos, string memory_bank_item) {
	if (regex_match(memory_bank_item, P_str, Logical_operand1))
	{
			string scr_2 = P_str[4];
			if (regex_match(scr_2, scr, regex("(true|false)$")) && regex_match(R[stoi(P_str[3])], dest, regex("(true|false)$"))) {
				if (P_str[1] == "And") {
					if (R[stoi(P_str[3])] == "true"  && scr[1] == "true" ) {
						R[stoi(P_str[3])] = "true";
					}
					else if (R[stoi(P_str[3])] == "false" && scr[1] == "false") {
						R[stoi(P_str[3])] = "false";
					}
					else {
						R[stoi(P_str[3])] = "false";
					}

				}
				else if (P_str[1] == "Or") {
					if (R[stoi(P_str[3])] == "true" && scr[1] == "true") {
						R[stoi(P_str[3])] = "true";
					}
					else if (R[stoi(P_str[3])] == "false" && scr[1] == "false") {
						R[stoi(P_str[3])] = "false";
					}
					else {
						R[stoi(P_str[3])] = "true";
					}
				}

			}
			else if (regex_match(scr_2, scr, regex("R([1-9]|1[0-5])"))) {
				if (P_str[1] == "And") {
					if (R[stoi(P_str[3])] == "true" && R[stoi(scr[1])] == "true") {
						R[stoi(P_str[3])] = "true";
					}
					else if (R[stoi(P_str[3])] == "false" && R[stoi(scr[1])] == "false") {
						R[stoi(P_str[3])] = "false";
					}
					else {
						R[stoi(P_str[3])] = "false";
					}

				}
				else if (P_str[1] == "Or") {
					if (R[stoi(P_str[3])] == "true" && R[stoi(scr[1])] == "true") {
						R[stoi(P_str[3])] = "true";
					}
					else if (R[stoi(P_str[3])] == "false" && R[stoi(scr[1])] == "false") {
						R[stoi(P_str[3])] = "false";
					}
					else {
						R[stoi(P_str[3])] = "true";
					}
				}
			}
			else {
				throw TypeMismatch(memory_bank_pos);
			}
			//cout << R[stoi(P_str[3])] << endl;
	}
}

void VM::Logic2_funct(int memory_bank_pos, string memory_bank_item) {
	if (regex_match(memory_bank_item, P_str, Logical_operand2))
	{
		
		string src_3 = P_str[2];
		if (regex_match(src_3, scr, regex("R([1-9]|1[0-5])"))){
			if (P_str[1] == "Not")
			{
				if (regex_match(R[stoi(P_str[3])], dest, regex("(true)$"))) {
					R[stoi(P_str[3])] = "false";
				}
				else if (regex_match(R[stoi(P_str[3])], dest, regex("(false)$"))) {
					R[stoi(P_str[3])] = "true";
				}
				else {
					throw TypeMismatch(memory_bank_pos);
				}
			}
			else if (P_str[1] == "Input") {
				//cin >> R[stoi(P_str[3])];
				getline(cin, R[stoi(P_str[3])]);
				if (!(regex_match(R[stoi(P_str[3])], dest, regex("^([1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false)$")))) {
					throw InvalidInput(memory_bank_pos);
				}
			}
			else if (P_str[1] == "Output") 
			{
				
					cout << zero_handle(R[stoi(P_str[3])]);
				
			}
		}
		else {
			if (P_str[1] == "Output") {
				
				if (regex_match(src_3, dest, regex("(\\d+)[A]$"))) {
					cout << src_3;
				}
				else
				{
					cout << zero_handle(P_str[2]);
				}
			}
		}
		
		//cout << R[stoi(P_str[3])] << endl;
	}

}
void VM::Jump_funct(int &memory_bank_pos, string memory_bank_item) {
	//cout << P_str[2];
	string src_5 = P_str[2];
	if (regex_match(src_5, scr, regex("(\\d+)[A]"))) {
		if (stoi(scr[1]) != 0 && stoi(scr[1]) <= memory_bank_pos_0) {
			memory_bank_pos = stoi(scr[1]);
			memory_bank_pos = memory_bank_pos - 1;
		}
		else {
			throw InvalidDestination(memory_bank_pos);
		}
		
	}
	else {
		throw TypeMismatch(memory_bank_pos);
	}
}
void VM::Jumpif_funct(int& memory_bank_pos, string memory_bank_item) {
	//cout << P_str[2];
	string src_6 = P_str[4];
	if (R[stoi(P_str[3])] == "true") {
		if (regex_match(src_6, scr, regex("(\\d+)[A]"))) {
			if (stoi(scr[1]) != 0 && stoi(scr[1]) <= memory_bank_pos_0) {
				memory_bank_pos = stoi(scr[1]);
				memory_bank_pos = memory_bank_pos - 1;
			}
			else {
				throw InvalidDestination(memory_bank_pos);
			}

		}
		else {
			throw TypeMismatch(memory_bank_pos);
		}
	}
	else if (R[stoi(P_str[3])] == "false") {
		memory_bank_pos = memory_bank_pos;
	}
	else {
		throw TypeMismatch(memory_bank_pos);
	}
}
void VM::L_S_funct(int memory_bank_pos, string memory_bank_item) {
	if (regex_match(memory_bank_item, P_str, L_S_operand))
	{
		string src_4 = P_str[4];

		if (regex_match(src_4, scr, regex("(\\d+)[A]")) && regex_match(R[stoi(P_str[3])], dest, regex("(\\d+)[A]")))
		{
			if (P_str[1] == "Move") {
				R[stoi(P_str[3])] = src_4;
			}
			else if (P_str[1] == "Load") {
				R[stoi(P_str[3])] = static_memory[stoi(scr[1])];
			}
			else if (P_str[1] == "Store") {
				
				static_memory[stoi(dest[1])] = src_4;
			}

		}
		else if (regex_match(src_4, scr, regex("([1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false)$")) && regex_match(R[stoi(P_str[3])], dest, regex("([1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false)$"))) {
			if (P_str[1] == "Move") {
				R[stoi(P_str[3])] = src_4;
			}
			else {
				throw TypeMismatch(memory_bank_pos);
			}
		}
		else if (regex_match(src_4, scr, regex("(\\d+)[A]")) && regex_match(R[stoi(P_str[3])], dest, regex("([1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false)$"))) {
			if (P_str[1] == "Move") {
				R[stoi(P_str[3])] = src_4;
			}
			else if (P_str[1] == "Load") {
				R[stoi(P_str[3])] = static_memory[stoi(scr[1])];
			}
			else {
				throw TypeMismatch(memory_bank_pos);
			}
		}
		else if (regex_match(src_4, scr, regex("([1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false)$")) && regex_match(R[stoi(P_str[3])], dest, regex("(\\d+)[A]"))) {
			if (P_str[1] == "Move") {
				R[stoi(P_str[3])] = src_4;
			}
			else if (P_str[1] == "Store") {
				
				static_memory[stoi(dest[1])] = src_4;
			}
			else {
				throw TypeMismatch(memory_bank_pos);
			}
		}
	
		else if (regex_match(src_4, scr, regex("R([1-9]|1[0-5])")))
		{

			if (regex_match(R[stoi(scr[1])], scr_new, regex("(\\d+)[A]")) && regex_match(R[stoi(P_str[3])], dest, regex("(\\d+)[A]")))
			{
				if (P_str[1] == "Move") {
					R[stoi(P_str[3])] = R[stoi(scr_new[1])];
				}
				else if (P_str[1] == "Load") {
					
					R[stoi(P_str[3])] = static_memory[stoi(scr_new[1])];
				}
				else if (P_str[1] == "Store") {
					
					static_memory[stoi(dest[1])] = R[stoi(scr[1])];
				}

			}

			else if (regex_match(R[stoi(scr[1])], scr_new, regex("([1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false)$")) && regex_match(R[stoi(P_str[3])], dest, regex("([1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false)$"))) {
				if (P_str[1] == "Move") {
					R[stoi(P_str[3])] = R[stoi(scr_new[1])];
				}
				else {
					throw TypeMismatch(memory_bank_pos);
				}
			}
			else if (regex_match(R[stoi(scr[1])], scr_new, regex("(\\d+)[A]")) && regex_match(R[stoi(P_str[3])], dest, regex("([1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false)$"))) {
				if (P_str[1] == "Move") {
					R[stoi(P_str[3])] = R[stoi(scr_new[1])];
				}
				else if (P_str[1] == "Load") {
					
					R[stoi(P_str[3])] = static_memory[stoi(scr_new[1])];
				}
				else {
					throw TypeMismatch(memory_bank_pos);
				}
			}
			else if (regex_match(R[stoi(scr[1])], scr_new, regex("([1-9]\\d+|[0-9]|\\d+[.]\\d+|true|false)$")) && regex_match(R[stoi(P_str[3])], dest, regex("(\\d+)[A]"))) {
				if (P_str[1] == "Move") {
					R[stoi(P_str[3])] = R[stoi(scr_new[1])];
				}
				else if (P_str[1] == "Store") {
				
					static_memory[stoi(dest[1])] = R[stoi(scr[1])];
				}
				else {
					throw TypeMismatch(memory_bank_pos);
				}
			}

		}
		else {
			throw TypeMismatch(memory_bank_pos);
		}
		//cout << R[stoi(P_str[3])] << "--------" << static_memory[stoi(dest[1])] << endl;
	}
	else {
		throw InvalidOperand(memory_bank_pos);
	}
}
bool Stack::push(string x, int y)
{
	if (top >= (1000 - 1)) {
		throw StackFull(y);
		return false;
	}
	else {
		
		a[top] = x;		
		++top;
		//cout << x << " pushed into stack\n";
		return true;
	}
}

string Stack::pop()
{
	if (top < 0) {
		//cout << "Stack Underflow";
		return "0";
	}
	else {
		top--;
		string x = a[top];
		return x;
	}
}


bool Stack::isFull()
{
	if (top >= (1000 - 1)) {
		return false;
	}
	else {
		return true;
	}
}
void VM::Call_funct(int& memory_bank_pos, string memory_bank_item) {
	if (regex_match(memory_bank_item, P_str, Call_operand)) {
		string scr_7 = P_str[2];
		if (regex_match(scr_7, scr, regex("(\\d+)[A]$"))) 
		{
			string address = to_string(memory_bank_pos);
			address.push_back(sh);
			S.push(address,memory_bank_pos);
			if (stoi(scr[1]) != 0 && stoi(scr[1]) <= memory_bank_pos_0) {
				memory_bank_pos = stoi(scr[1])-1;
			}
			else if(stoi(scr[1]) == 0){
				memory_bank_pos = stoi(scr[1]);
			}
			else {
				throw InvalidDestination(memory_bank_pos);
			}
		}
		else if (regex_match(scr_7, scr, regex("R([1-9]|1[0-5])"))) 
		{
			if (regex_match(R[stoi(scr[1])], scr, regex("(\\d+)[A]"))) 
			{
				string address = to_string(memory_bank_pos);
				address.push_back(sh);
				S.push(address,memory_bank_pos);
				if (stoi(scr[1]) != 0) {
					memory_bank_pos = stoi(scr[1]) - 1;
				}
				else {
					memory_bank_pos = stoi(scr[1]);
				}
			}
		}
		else {
			throw TypeMismatch(memory_bank_pos);
		}
	}
}
void VM::Return_funct(int& memory_bank_pos, string memory_bank_item) {
	memory_bank_pos = stoi(S.pop());
}
void VM::run(string filename)
{
	ifstream file;
	file.open(filename);
	string command;
	while (getline(file, command)) {
		memory_bank[memory_bank_pos_0] = command;
		if (regex_match(command, P_str, Arithmetic))
		{
			if (!((regex_match(command, P_str, Arithmetic_operand)) || (regex_match(command, P_str, Comparison_operand)) || (regex_match(command, P_str, Logical_operand1)) || (regex_match(command, P_str, L_S_operand)) || (regex_match(command, P_str, Jumpif_operand))))
			{
				throw InvalidOperand(memory_bank_pos_0);
			}

		}
		else if ((regex_match(command, P_str, Onlydest)))
		{
			if (!((regex_match(command, P_str, Logical_operand2)) || (regex_match(command, P_str, Jump_operand)) || (regex_match(command, P_str, Call_operand)))) {
				throw InvalidOperand(memory_bank_pos_0);
			}
		}
		else if (!((regex_match(command, P_str, regex("(^Return)$"))) || (regex_match(command, P_str, regex("(^Halt)$"))))) {
			throw InvalidInstruction(memory_bank_pos_0);
		}
		memory_bank_pos_0++;
	}
	for (int memory_bank_pos = 0; memory_bank_pos < memory_bank_pos_0; memory_bank_pos++)
	{
		if (regex_match(memory_bank[memory_bank_pos], P_str, Arithmetic))
		{
			if (regex_match(memory_bank[memory_bank_pos], P_str, Arithmetic_operand))
			{
				Arithmetic_funct(memory_bank_pos, memory_bank[memory_bank_pos]);
			}
			else if (regex_match(memory_bank[memory_bank_pos], P_str, Comparison_operand)) {
				Comp_funct(memory_bank_pos, memory_bank[memory_bank_pos]);

			}
			else if (regex_match(memory_bank[memory_bank_pos], P_str, Logical_operand1)) {
				Logic1_funct(memory_bank_pos, memory_bank[memory_bank_pos]);
			}
			else if (regex_match(memory_bank[memory_bank_pos], P_str, L_S_operand)) {
				L_S_funct(memory_bank_pos, memory_bank[memory_bank_pos]);
			}
			else if (regex_match(memory_bank[memory_bank_pos], P_str, Jumpif_operand)) {
				Jumpif_funct(memory_bank_pos, memory_bank[memory_bank_pos]);
			}
			else {
				throw InvalidOperand(memory_bank_pos);
			}
		}
		else if (regex_match(memory_bank[memory_bank_pos], P_str, Onlydest)) {
			if (regex_match(memory_bank[memory_bank_pos], P_str, Logical_operand2)) {
				Logic2_funct(memory_bank_pos, memory_bank[memory_bank_pos]);
			}
			else if (regex_match(memory_bank[memory_bank_pos], P_str, Jump_operand)) {
				Jump_funct(memory_bank_pos, memory_bank[memory_bank_pos]);
			}
			else if (regex_match(memory_bank[memory_bank_pos], P_str, Call_operand)) {
				Call_funct(memory_bank_pos, memory_bank[memory_bank_pos]);
			}
			else {
				throw InvalidOperand(memory_bank_pos);
			}
		}
		else if (regex_match(memory_bank[memory_bank_pos], P_str, regex("(^Return)$"))) {
			Return_funct(memory_bank_pos, memory_bank[memory_bank_pos]);
		}
		else if (regex_match(memory_bank[memory_bank_pos], P_str, regex("(^Halt)$"))) {
			break;
		}
		else
		{
			throw InvalidInstruction(memory_bank_pos);
		}

	}

}
