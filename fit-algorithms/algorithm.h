#ifndef FIT_ALGORITHMS_ALGORITHM_H
#define FIT_ALGORITHMS_ALGORITHM_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int maxSize;
vector<double> blocks;
vector<vector<double>> nextFit;
vector<vector<double>> fastFit;
vector<vector<double>> sortedFastFit;

void fillBlocksFromKeyboard();

void randomFillBlocks();

void doNextFit();

void doFastFit();

void doSortedFastFit();

void printResult();

double getSum(vector<double>);

#endif //FIT_ALGORITHMS_ALGORITHM_H
