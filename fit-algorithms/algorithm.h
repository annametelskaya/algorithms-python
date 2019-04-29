//
// Created by Miatselskaya_H on 29.04.2019.
//
#ifndef UNTITLED_FIT_H
#define UNTITLED_FIT_H

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

#endif //UNTITLED_FIT_H
