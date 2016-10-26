#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Translator2.h"
using namespace std;

vector<string> TranslateMainBlock(vector<string> inVec) {

	vector <string> returnStrVec;
	string tempStr = "";
	string newStr = "";
	int i = 0;
	int j = 0;
	size_t found;
	size_t found2;
	string firstVar = "";
	string secondVar = "";
	string thirdVar = "";
	string fourthVar = "";
	string nameMod = "";

	for (i = 0; i < inVec.size(); i++) {
		tempStr = inVec.at(i);
		
		if (tempStr.find('=') != string::npos) {

			if (tempStr.find('+') != string::npos && tempStr.find("+ 1") == string::npos) {
				//Start of Module
				newStr = string("ADD") + string(" adder") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".b(";

				//Find second variable name
				found2 = tempStr.find_first_of('+');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
				newStr = newStr + secondVar + "),";
				newStr = newStr + ".sum(";

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";

				nameMod = thirdVar;
			}

			else if (tempStr.find('-') != string::npos && tempStr.find("- 1") == string::npos) {
				//Subtract
				//Start of Module
				newStr = string("SUB") + string(" subtractor") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".b(";

				//Find second variable name
				found2 = tempStr.find_first_of('-');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
				newStr = newStr + secondVar + "),";
				newStr = newStr + ".diff(";

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";
			}

			else if (tempStr.find('*') != string::npos) {
				//Mul
				//Start of Module
				newStr = string("MUL") + string(" multiplier") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".b(";

				//Find second variable name
				found2 = tempStr.find_first_of('*');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
				newStr = newStr + secondVar + "),";
				newStr = newStr + ".prod(";

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";
			}

			else if (tempStr.find('/') != string::npos) {
				//Div
				//Start of Module
				newStr = string("DIV") + string(" divider") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".b(";

				//Find second variable name
				found2 = tempStr.find_first_of('/');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
				newStr = newStr + secondVar + "),";
				newStr = newStr + ".quot(";

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";
			}

			else if (tempStr.find('<') != string::npos  &&  tempStr.find("<<") == string::npos) {
				//Less Than
				//Start of Module
				newStr = string("COMP") + string(" comparator") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".b(";

				//Find second variable name
				found2 = tempStr.find_first_of('<');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
				newStr = newStr + secondVar + "),";
				newStr = newStr + ".lt(";

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";

			}

			else if (tempStr.find('>') != string::npos &&  tempStr.find(">>") == string::npos) {
				//Greater Than
				//Less Than
				//Start of Module
				newStr = string("COMP") + string(" comparator") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".b(";

				//Find second variable name
				found2 = tempStr.find_first_of('>');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
				newStr = newStr + secondVar + "),";
				newStr = newStr + ".gt(";

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";

			}

			else if (tempStr.find("==") != string::npos) {
				//Equal
				//Less Than
				//Start of Module
				newStr = string("COMP") + string(" comparator") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".b(";

				//Find second variable name
				found2 = tempStr.find_first_of("==");
				//not working ^^ 
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
				newStr = newStr + secondVar + "),";
				newStr = newStr + ".eq(";

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";

			}

			else if (tempStr.find('?') != string::npos) {
				//Mux
				//Start of Module
				newStr = string("MUX2x1") + string(" multiplexer") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('?');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".b(";

				//Find second variable name
				found2 = tempStr.find_first_of(':');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
				newStr = newStr + secondVar + "),";
				newStr = newStr + ".sel(";

				//Find fourth Variable Name
				found2 = tempStr.find_first_of('=');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					fourthVar = fourthVar + tempStr.at(j);
				}

				newStr = newStr + fourthVar + "),";
				newStr = newStr + ".d(";

				//Find third Variable name
				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";
			}


			else if (tempStr.find(">>") != string::npos) {
				//Shift Right
				//Start of Module
				newStr = string("SHR") + string(" shiftRight") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".sh_amt(";

				//Find second variable name
				found2 = tempStr.find_first_of(">>");
				for (j = found2 + 3; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
				newStr = newStr + secondVar + "),";
				newStr = newStr + ".d(";

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";
			}

			else if (tempStr.find("<<") != string::npos) {
				//Shift Left 
				//Start of Module
				newStr = string("SHL") + string(" shiftLeft") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".sh_amt(";

				//Find second variable name
				found2 = tempStr.find_first_of("<<");
				for (j = found2 + 3; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
				newStr = newStr + secondVar + "),";
				newStr = newStr + ".d(";

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";
			}

			else if (tempStr.find('idk') != string::npos) {
				//Register
			}

			else if (tempStr.find('%') != string::npos) {
				//Register
				//Start of Module
				newStr = string("MOD") + string(" modulo") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".b(";

				//Find second variable name
				found2 = tempStr.find_first_of('%');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
				newStr = newStr + secondVar + "),";
				newStr = newStr + ".rem(";

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";
			}

			else if (tempStr.find("+ 1") != string::npos) {
				//Incrementer
				//Start of Module
				newStr = string("INC") + string(" incrementer") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".d(";

			

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";
			}

			else if (tempStr.find("- 1") != string::npos) {
				//Decrementer
				//Start of Module
				newStr = string("DEC") + string(" decrementer") + string(to_string(i)) + string("( .a(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),";
				newStr = newStr + ".d(";



				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";
			}

			//Invalid Test
			else if(tempStr.find('$') != string::npos){
				newStr = "//Invalid";
			}

			else {
			//Register
			//Start of Module
				newStr = string("REG") + string(" reg") + string(to_string(i)) + string("( .d(");
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				newStr = newStr + firstVar + "),.Clk(Clk),.Rst(Rst),";
				newStr = newStr + ".q(";



				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				newStr = newStr + thirdVar;
				newStr = newStr + "));";

			}





			returnStrVec.push_back(newStr);
			newStr = "";
			firstVar = "";
			secondVar = "";
			thirdVar = "";
			fourthVar = "";

			
		}

	}

	return returnStrVec;
}