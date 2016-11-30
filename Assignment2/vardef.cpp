#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "vardef.h"

using namespace std;

vector<string> vardef(vector<vector<string> > master) {
	unsigned int i = 0;
	unsigned int k = 0;//DELETEME
	int j = 0;
	int var = 0;
	int n_int;
	string n_string;
	int counter = 0;
	vector<vector<string>> inputs;	//vector of input variables
	vector<vector<string>>  outputs;	//vector of output variabels
	vector<vector<string>>  wires;	//vector of wire variabels
	vector<vector<string>>  registers;	//vector of wire variabels
	vector<string> out;
	int x = 0;
	//seperate vector into input strings and output strings
	
	while (i != master.size() - 1) {
		var = 0;
		//check if variable def
		if (master.at(i).at(0).compare("input") == 0 || master.at(i).at(0).compare("output") == 0 || master.at(i).at(0).compare("register") == 0 || master.at(i).at(0).compare("wire") == 0) {
			var = 1;
			if (master.at(i).at(0).compare("register") == 0) {
				out.push_back("wire");
			}
			else {
				out.push_back(master.at(i).at(0));
			}
			
		}
		if (var == 1) {
					//vd.at(x).at(1).erase(0,4);
				out.at(i).append(" [");
				size_t temp2 = master.at(i).at(1).find_first_of("t");
				//master.at(i).at(1) = master.at(i).at(1).at(temp2 + 1);
				for (j = temp2 + 1; j < master.at(i).at(1).length(); j++) {
					master.at(i).at(1)= (master.at(i).at(1).substr(temp2+1, master.at(i).at(1).length()));
				}
			
			//else if (master.at(i).at(1).find("int") == std::string::npos) {
			//	/*
			//	out.at(i).append(" uint [");*/
			//	out.at(i).append(" [");
			//	master.at(i).at(1).erase(0, 3);
			//}
			//add data width
			n_string = master.at(i).at(1);
			n_int = stoi(n_string);
			n_int = n_int - 1;
			n_string = std::to_string(n_int);

			out.at(i).append(n_string);
			out.at(i).append(": 0] ");

			k = 2;
			while (k < master.at(i).size())
			{
				if (master.at(i).at(k).compare("") != 0) {
					out.at(i).append(master.at(i).at(k));

					/*if (k != (master.at(i).size() - 1)) {*/

						out.at(i).append(", ");
					//}
					/*else {
						out.at(i).append(";");
					}*/
				}
				k++;
			}
		}
		//out.at(i).replace(out.at(i).length()-1, out.at(i).length()-1, ',', ';');
		//out.at(i).erase(out.at(i).length()-2, out.at(i).length());
		
		if (counter < out.size()) {

			out.at(i).at(out.at(i).length() - 2) = ';';
		}
		counter = out.size();
		i++;
	}
	out.insert(out.begin(), "input Rst, Clk;");
	return out;
}

string module(vector<vector<string> > master) {
	string output;
	int i = 0;
	int j = 0;
	output.append(" Rst, Clk,");
	while (i < master.size()) {
		if (master.at(i).at(0).compare("input") == 0 || master.at(i).at(0).compare("output") == 0) {
			for (j = 2; j < master.at(i).size(); j++) {

				output.append(" " + master.at(i).at(j) + ",");
			}
		}
		i++;
	}
	output.erase(output.end());
	output.append(");");

	return output;
}