#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxSize;
vector<double> blocks;
vector<double> nextFit;
vector<double> fastFit;
vector<double> sortedFastFit;

void fillBlocksFromKeyboard();

void randomFillBlocks();

void doNextFit();

void doFastFit();

void doSortedFastFit();

void printResult();
