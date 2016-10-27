#include <stdio.h>
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;
vector<string> TranslateMainBlock(vector<string> inVec, vector<int> bitWidth);
double calcCriticalPath(vector<string> inVec, vector <int> bitWidthVec);
double calculateTime(string firstVar, string secondVar, string thirdVar, vector<Node*> *tempVecIn);
double findMaxOfVector(vector <double> inVec);
double findNodeTime(string modType, int bitWidth);