#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Translator2.h"
#include "Node.h"
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


double calcCriticalPath(vector<string> inVec, vector <int> bitWidthVec) {

	vector <string> returnStrVec;
	string tempStr = "";
	int i = 0;
	int j = 0;
	size_t found;
	size_t found2;
	string firstVar = "";
	string secondVar = "";
	string thirdVar = "";
	string fourthVar = "";
	string nameMod = "";

	vector <double> allCriticalTimes;
	
	double totalTime = 0;

	double accumulatedTime = 0;

	vector<Node*> allNodes;

	for (i = 0; i < inVec.size(); i++) {
		tempStr = inVec.at(i);

		if (tempStr.find('=') != string::npos) {

			if (tempStr.find('+') != string::npos && tempStr.find("+ 1") == string::npos) {
				//Start of Module

				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}


				//Find second variable name
				found2 = tempStr.find_first_of('+');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}


				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime("add",bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime("add" ,bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);
			}

			else if (tempStr.find('-') != string::npos && tempStr.find("- 1") == string::npos) {
				//Subtract
				//Start of Module
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
			

				//Find second variable name
				found2 = tempStr.find_first_of('-');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
			

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}

				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime("sub" ,bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime( "sub",bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);
			
			}

			else if (tempStr.find('*') != string::npos) {
				//Mul
				//Start of Module
			
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
	
				//Find second variable name
				found2 = tempStr.find_first_of('*');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
			

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				
				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime( "mul",bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime( "mul",bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);
			}

			else if (tempStr.find('/') != string::npos) {
				//Div
				//Start of Module
				
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
			

				//Find second variable name
				found2 = tempStr.find_first_of('/');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
		

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				
				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime( "div",bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime("div" ,bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);

			}

			else if (tempStr.find('<') != string::npos  &&  tempStr.find("<<") == string::npos) {
				//Less Than
				//Start of Module
			
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
			

				//Find second variable name
				found2 = tempStr.find_first_of('<');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
			

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				
				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime( "comp" ,bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime( "comp",bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);
			}

			else if (tempStr.find('>') != string::npos &&  tempStr.find(">>") == string::npos) {
				//Greater Than
				//Less Than
				//Start of Module
				
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
			

				//Find second variable name
				found2 = tempStr.find_first_of('>');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
			

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
			
				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime("comp" ,bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime( "comp",bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);


			}

			else if (tempStr.find("==") != string::npos) {
				//Equal
				//Less Than
				//Start of Module
				
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
			

				//Find second variable name
				found2 = tempStr.find_first_of("==");
				//not working ^^ 
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
			

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
				
				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime( "comp",bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime( "comp",bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);

			}

			else if (tempStr.find('?') != string::npos) {
				//Mux
				//Start of Module
			
				//Find first variable name
				found = tempStr.find_first_of('?');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
			
				//Find second variable name
				found2 = tempStr.find_first_of(':');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
			

				//Find fourth Variable Name
				found2 = tempStr.find_first_of('=');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					fourthVar = fourthVar + tempStr.at(j);
				}

			

				//Find third Variable name
				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
			
				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime("mux" ,bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime( "mux",bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);
			}


			else if (tempStr.find(">>") != string::npos) {
				//Shift Right
				//Start of Module
			
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
				

				//Find second variable name
				found2 = tempStr.find_first_of(">>");
				for (j = found2 + 3; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
			

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
			
				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime("shr" ,bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime( "shr",bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);

			}

			else if (tempStr.find("<<") != string::npos) {
				//Shift Left 
				//Start of Module
			
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
		

				//Find second variable name
				found2 = tempStr.find_first_of("<<");
				for (j = found2 + 3; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
			

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}

				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime( "shl",bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime( "shl",bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);
				
			}

			else if (tempStr.find('%') != string::npos) {
				//Register
				//Start of Module
			
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
			

				//Find second variable name
				found2 = tempStr.find_first_of('%');
				for (j = found2 + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ' || tempStr.at(j) == '\n') {
						break;
					}
					secondVar = secondVar + tempStr.at(j);
				}
				

				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}

				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime("mod" ,bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime("mod" ,bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);
			
			}

			else if (tempStr.find("+ 1") != string::npos) {
				//Incrementer
				//Start of Module
				
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
		



				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}

				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime("inc" ,bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime( "inc",bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);
			
			}

			else if (tempStr.find("- 1") != string::npos) {
				//Decrementer
				//Start of Module
				
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
			



				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
			
				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime("dec" ,bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime( "dec",bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);

			}

			//Invalid Test
			else if (tempStr.find('$') != string::npos) {
				
			}

			else {
				//Register
				//Start of Module
				
				//Find first variable name
				found = tempStr.find_first_of('=');
				for (j = found + 2; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					firstVar = firstVar + tempStr.at(j);

				}
			



				for (j = 0; j < tempStr.size(); j++) {
					if (tempStr.at(j) == ' ') {
						break;
					}
					thirdVar = thirdVar + tempStr.at(j);
				}
		
				nameMod = thirdVar;
				accumulatedTime = calculateTime(firstVar, secondVar, fourthVar, &allNodes);
				if (accumulatedTime != -1) {
					totalTime = accumulatedTime + findNodeTime("reg" ,bitWidthVec.at(i));;
				}
				else {
					totalTime = findNodeTime( "reg",bitWidthVec.at(i));;
				}

				Node* tempNode = new Node(totalTime, nameMod);
				allCriticalTimes.push_back(totalTime);
				allNodes.push_back(tempNode);


			}





		}

		firstVar = "";
		secondVar = "";
		thirdVar = "";
		fourthVar = "";

	}

	for (j = 0; j < allNodes.size(); j++) {
		cout << endl << allNodes.at(j)->name ;
	}

	return findMaxOfVector(allCriticalTimes);

}


double findMaxOfVector(vector <double> inVec) {

	double temp = inVec.at(0);
	int i = 0;
	for (i = 1; i < inVec.size(); i++) {
		if (inVec.at(i) > temp) {
			temp = inVec.at(i);
		}
	}

	return temp;

}


double calculateTime(string firstVar, string secondVar, string thirdVar, vector<Node*> *tempVecIn2) {

	int i = 0;
	double maxTemp = -1;
	double timeOne = -1, timeTwo = -1, timeThree = -1;
	vector<Node*> tempVecIn = *tempVecIn2;

	for (i = 0; i < tempVecIn.size(); i++) {
		if (tempVecIn.at(i)->name == firstVar) {
			
			timeOne = tempVecIn.at(i)->path;
			break;
		}
	}

	for (i = 0; i < tempVecIn.size(); i++) {
		if (tempVecIn.at(i)->name == secondVar) {
			
			timeTwo = tempVecIn.at(i)->path;
			break;
		}
	}

	for (i = 0; i < tempVecIn.size(); i++) {
		if (tempVecIn.at(i)->name == thirdVar) {
			
			timeThree = tempVecIn.at(i)->path;
			break;
		}
	}

	if (timeOne != -1 || timeTwo != -1 || timeThree != -1) {
		maxTemp = max(timeOne, timeTwo);
		return (max(maxTemp, timeThree));
	}

	else {
		return 0;
	}



}

double findNodeTime(string modType, int bitWidth) {

	if (modType == "add") {
		if (bitWidth == 1) {
			return 2.704;
		}

		else if (bitWidth == 2) {
			return 3.713;
		}

		else if (bitWidth == 8) {
			return 4.924;
		}

		else if (bitWidth == 16) {
			return 5.638;
		}

		else if (bitWidth == 32) {
			return 7.270;
		}

		else if (bitWidth == 64) {
			return 9.566;
		}
	}

	else if (modType == "sub") {
		if (bitWidth == 1) {
			return 3.024;
		}

		else if (bitWidth == 2) {
			return 3.412;
		}

		else if (bitWidth == 8) {
			return 4.890;
		}

		else if (bitWidth == 16) {
			return 5.569;
		}

		else if (bitWidth == 32) {
			return 7.253;
		}

		else if (bitWidth == 64) {
			return 9.566;
		}
	}

	else if (modType == "reg") {
		if (bitWidth == 1) {
			return 2.616;
		}

		else if (bitWidth == 2) {
			return 2.644;
		}

		else if (bitWidth == 8) {
			return 2.879;
		}

		else if (bitWidth == 16) {
			return 3.061;
		}

		else if (bitWidth == 32) {
			return 3.602;
		}

		else if (bitWidth == 64) {
			return 3.966;
		}
	}

	else if (modType == "mul") {
		if (bitWidth == 1) {
			return 2.438;
		}

		else if (bitWidth == 2) {
			return 3.651;
		}

		else if (bitWidth == 8) {
			return 7.453;
		}

		else if (bitWidth == 16) {
			return 7.811;
		}

		else if (bitWidth == 32) {
			return 12.395;
		}

		else if (bitWidth == 64) {
			return 15.354;
		}
	}

	else if (modType == "div") {
		if (bitWidth == 1) {
			return 0.619;
		}

		else if (bitWidth == 2) {
			return 2.144;
		}

		else if (bitWidth == 8) {
			return 15.439;
		}

		else if (bitWidth == 16) {
			return 33.093;
		}

		else if (bitWidth == 32) {
			return 86.312;
		}

		else if (bitWidth == 64) {
			return 243.233;
		}
	}

	else if (modType == "comp") {
		if (bitWidth == 1) {
			return 3.031;
		}

		else if (bitWidth == 2) {
			return 3.934;
		}

		else if (bitWidth == 8) {
			return 5.949;
		}

		else if (bitWidth == 16) {
			return 6.256;
		}

		else if (bitWidth == 32) {
			return 7.264;
		}

		else if (bitWidth == 64) {
			return 8.416;
		}
	}

	else if (modType == "mux") {
		if (bitWidth == 1) {
			return 4.083;
		}

		else if (bitWidth == 2) {
			return 4.115;
		}

		else if (bitWidth == 8) {
			return 4.815;
		}

		else if (bitWidth == 16) {
			return 5.623;
		}

		else if (bitWidth == 32) {
			return 8.079;
		}

		else if (bitWidth == 64) {
			return 8.766;
		}
	}

	else if (modType == "shr") {
		if (bitWidth == 1) {
			return 3.644;
		}

		else if (bitWidth == 2) {
			return 4.007;
		}

		else if (bitWidth == 8) {
			return 5.178;
		}

		else if (bitWidth == 16) {
			return 6.460;
		}

		else if (bitWidth == 32) {
			return 8.819;
		}

		else if (bitWidth == 64) {
			return 11.095;
		}
	}

	else if (modType == "shl") {
		if (bitWidth == 1) {
			return 3.614;
		}

		else if (bitWidth == 2) {
			return 3.980;
		}

		else if (bitWidth == 8) {
			return 5.152;
		}

		else if (bitWidth == 16) {
			return 6.549;
		}

		else if (bitWidth == 32) {
			return 8.565;
		}

		else if (bitWidth == 64) {
			return 11.220;
		}
	}

	else if (modType == "mod") {
		if (bitWidth == 1) {
			return 0.758;
		}

		else if (bitWidth == 2) {
			return 2.149;
		}

		else if (bitWidth == 8) {
			return 16.078;
		}

		else if (bitWidth == 16) {
			return 35.563;
		}

		else if (bitWidth == 32) {
			return 88.142;
		}

		else if (bitWidth == 64) {
			return 250.583;
		}
	}

	else if (modType == "inc") {
		if (bitWidth == 1) {
			return 1.792;
		}

		else if (bitWidth == 2) {
			return 2.218;
		}

		else if (bitWidth == 8) {
			return 3.111;
		}

		else if (bitWidth == 16) {
			return 3.471;
		}

		else if (bitWidth == 32) {
			return 4.347;
		}

		else if (bitWidth == 64) {
			return 6.200;
		}
	}

	else if (modType == "dec") {
		if (bitWidth == 1) {
			return 1.792;
		}

		else if (bitWidth == 2) {
			return 2.218;
		}

		else if (bitWidth == 8) {
			return 3.108;
		}

		else if (bitWidth == 16) {
			return 3.701;
		}

		else if (bitWidth == 32) {
			return 4.685;
		}

		else if (bitWidth == 64) {
			return 6.503; 
		}
	}

	else {
		return 0;
	}

}