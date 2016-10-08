#include "FileIO.h"
#include "Translator.h"
#include <stdio.h>
#include <string>

int main() {
	int i;
	vector<string> v;
	vector<string> v1;
	vector<vector<string>> master;

	v = readFile("474a_circuit3.txt");

	for (i = 0; i < v.size(); ++i) {
		v1 = getInputs(v[i]);
		if(v1.size() != 0)
			master.push_back(v1);
	}

	return 0;
}