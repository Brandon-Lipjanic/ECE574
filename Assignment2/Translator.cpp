#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int size = 0;

vector<string> getInputs(string str) {

	vector<string> v;
	string delimiter = " ";
	char chars[] = ",";

	for (unsigned int i = 0; i < strlen(chars); ++i) {
		str.erase(remove(str.begin(), str.end(), chars[i]), str.end());
	}

	size_t pos = 0;
	string token;
	while ((pos = str.find(delimiter)) != string::npos) {
		token = str.substr(0, pos);
		cout << token << endl;
		str.erase(0, pos + delimiter.length());
		v.push_back(token);
	}

	return v;

}