#include <stdio.h>
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;
vector<string> TranslateMainBlock(vector<string> inVec);
double calcCriticalPath(vector<string> inVec);
double calculateTime(string firstVar, string secondVar, string thirdVar, vector<Node*> *tempVecIn);
double findMaxOfVector(vector <double> inVec);