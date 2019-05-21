#include <time.h>
#include "algorithm.h"

void printOne(const vector<vector<double>> &fit) {
//    for (const auto &vector:fit) {
//        cout << "[";
//        for (double processed:vector)
//            cout << processed << " ";
//        cout << "] sum: " << getSum(vector) << ";\n";
//    }
    cout << "Size:" << fit.size();
}

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
    srand(time(NULL));
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
            nextFit.push_back({block});
        } else {
            if (getSum(nextFit[nextFit.size() - 1]) + block <= 1) {
                nextFit[nextFit.size() - 1].push_back(block);// += block
            } else {
                nextFit.push_back({block});
            }
        }
    }
}

void doFirstFit() {
    for (double block : blocks) {
        if (fastFit.empty()) {
            fastFit.push_back({block});
        } else {
            bool isInsert = false;
            for (vector<double> &f : fastFit) {
                if (getSum(f) + block <= 1) {
                    f.push_back(block);
                    isInsert = true;
                    break;
                }
            }
            if (!isInsert) {
                fastFit.push_back({block});
            }
        }
    }
}

void doSortedFirstFit() {
    sort(blocks.begin(), blocks.end(), greater<double>());
    for (double block : blocks) {
        if (sortedFastFit.empty()) {
            sortedFastFit.push_back({block});
        } else {
            bool isInsert = false;
            for (vector<double> &f : sortedFastFit) {
                if (getSum(f) + block <= 1) {
                    f.push_back(block);
                    isInsert = true;
                    break;
                }
            }
            if (!isInsert) {
                sortedFastFit.push_back({block});
            }
        }
    }
}

void printResult() {
    cout << "\nNext Fit";
    printOne(nextFit);
    cout << "\nFast fit";
    printOne(fastFit);
    cout << endl << "Sorted Fast Fit: ";
    printOne(sortedFastFit);
}

double getSum(vector<double> vector) {
    double sum = 0;
    for (double s = 0; s < vector.size(); s++)
        sum += vector[s];
    return sum;
}

int main() {
    maxSize = 1;
    //fillBlocksFromKeyboard();
    randomFillBlocks();
    //for (double processed:blocks)
    //    cout << processed << "\t";
    doNextFit();
    doFirstFit();
    doSortedFirstFit();
    printResult();
    return 0;
}