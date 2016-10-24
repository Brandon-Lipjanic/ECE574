#include "FileIO.h"
#include "Translator.h"
#include "Translator2.h"
#include <stdio.h>
#include <string>

int main() {
	int i;
	vector<string> v;
	vector<string> v1;
	vector<vector<string>> master;
	vector<string> tempVecStr,tempVecStr2;

	//Temp strings for testing
	string tempAdd = "dd = xx + yy ";
	string tempSub = "gg = ff - hh";
	string tempMul = "aa = bb * cc";
	string tempDiv = "divNum = num1 / num2";
	string tempMux = "g = a ? d : e";
	string tempShr = "bg = f >> z";
	string tempShl = "gb = z << f";
	string tempMod = "one = two % three";
	string tempInc = "b = c + 1";
	string tempDec = "b = c - 1";
	tempVecStr2.push_back(tempAdd);
	tempVecStr2.push_back(tempSub);
	tempVecStr2.push_back(tempDiv);
	tempVecStr2.push_back(tempMul);
	tempVecStr2.push_back(tempMux);
	tempVecStr2.push_back(tempShr);
	tempVecStr2.push_back(tempShl);
	tempVecStr2.push_back(tempMod);
	tempVecStr2.push_back(tempInc);
	tempVecStr2.push_back(tempDec);

	//End Temp String for testing


	/*
	v = readFile("474a_circuit3.txt");

	for (i = 0; i < v.size(); ++i) {
		v1 = getInputs(v[i]);
		if(v1.size() != 0)
			master.push_back(v1);
	}
	*/
	tempVecStr = TranslateMainBlock(tempVecStr2);


	for (i = 0; i < tempVecStr.size(); i++) {
		cout << tempVecStr.at(i) << endl;
	}

	return 0;
}