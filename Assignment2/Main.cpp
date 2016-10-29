#include "FileIO.h"
#include "Translator.h"
#include <stdio.h>
#include "FileIO.h"
#include "Translator.h"
#include "Translator2.h"
#include <stdio.h>
#include <string>

int main() {
	int i, j;
	vector<string> v;
	vector<string> v1;
	vector<string> v2;
	vector<string> modulesString;
	vector<vector<string>> master;
	vector<int> signs;
	vector<string> tempVecStr, tempVecStr2;
	vector<int> bitWidth;

	double criticalPath = -1;

	
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
	string tempReg = "greg = h";
	string tempEq = "dEQe = d == e";
	string tempLt = "dLTe = d < e";
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
	tempVecStr2.push_back(tempReg);
	tempVecStr2.push_back(tempEq);
	tempVecStr2.push_back(tempLt);
	//End Temp String for testing
	


	v = readFile("474a_circuit1.txt");

	for (i = 0; i < v.size(); i++) {
		if (v.at(i).find('=') != string::npos) {
			modulesString.push_back(v.at(i));
		}
	}
	for (i = 0; i < v.size(); ++i) {
		v1 = getInputs(v[i]);
		if (v1.size() != 0)
			master.push_back(v1);
	}

	for (j = 0; j < v.size(); ++j) {
		if (v[j] != "")
			v2.push_back(v[j]);
	}

	signs = determineSign(master);
	bitWidth.push_back(8);
	bitWidth.push_back(8);
	bitWidth.push_back(8);
	bitWidth.push_back(8);
	bitWidth.push_back(8);
	bitWidth.push_back(8);
	bitWidth.push_back(8);

	tempVecStr = TranslateMainBlock(modulesString,signs, bitWidth);
	criticalPath = calcCriticalPath(modulesString, bitWidth);

	cout << criticalPath << endl;
	/*
	for (i = 0; i < tempVecStr.size(); i++) {
		cout << tempVecStr.at(i) << endl;
	}
	*/

	return 0;
}