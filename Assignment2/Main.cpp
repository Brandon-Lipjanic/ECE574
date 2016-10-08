#include "FileIO.h"
#include "Translator.h"
#include <stdio.h>
#include <string>

int main() {

	vector<string> v;
	vector<string> v1;

	v = readFile("474a_circuit3.txt");

	v1 = getInputs(v[0]);


	return 0;
}