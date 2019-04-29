#include "algorithm.h"

void fillBlocksFromKeyboard() {
    string buffer;
    cout << "Input blocks\nTo stop press enter\n";
    do {
        getline(cin, buffer);
        if (!buffer.empty()) {
            blocks.push_back(atof(buffer.c_str()));
        }
    } while (!buffer.empty());
}

void randomFillBlocks() {
    cout << "Input number of blocks: ";
    int size;
    cin >> size;
    for (int i = 0; i < size; i++) {
        blocks.push_back((double) (rand() % (maxSize * 1000)) / 1000);
    }
}

void doNextFit() {
    for (double block : blocks) {
        if (nextFit.empty()) {
            nextFit.push_back(0);
        }
        if (nextFit[nextFit.size() - 1] + block <= 1) {
            nextFit[nextFit.size() - 1] += block;
        } else {
            nextFit.push_back(block);
        }
    }
}

void doFastFit() {
    for (double block : blocks) {
        bool isInsert = false;
        if (fastFit.empty()) {
            fastFit.push_back(0);
        }
        for (double &f : fastFit) {
            if (f + block <= 1) {
                f += block;
                isInsert = true;
                break;
            }
        }
        if (!isInsert) {
            fastFit.push_back(block);
        }
    }
}

void doSortedFastFit() {
    sort(blocks.begin(), blocks.end(), greater<double>());
    for (double block : blocks) {
        bool isInsert = false;
        if (sortedFastFit.empty()) {
            sortedFastFit.push_back(0);
        }
        for (double &f : sortedFastFit) {
            if (f + block <= 1) {
                f += block;
                isInsert = true;
                break;
            }
        }
        if (!isInsert) {
            sortedFastFit.push_back(block);
        }
    }
}

void printResult() {
    cout << endl << "Next Fit: ";
    cout << "\nBlocks:\t";
    for (double processed:nextFit)
        cout << processed << "\t";
    cout << "\nSize:" << nextFit.size();
    cout << endl << "Fast Fit: ";
    cout << "\nBlocks:\t";
    for (double processed:fastFit)
        cout << processed << "\t";
    cout << "\nSize:" << fastFit.size();
    cout << endl << "Sorted Fast Fit: ";
    cout << "\nBlocks:\t";
    for (double processed:sortedFastFit)
        cout << processed << "\t";
    cout << "\nSize:" << sortedFastFit.size();
}

int main() {
    maxSize = 1;
    //fillBlocksFromKeyboard();
    randomFillBlocks();
    doNextFit();
    doFastFit();
    doSortedFastFit();
    printResult();
    return 0;
}