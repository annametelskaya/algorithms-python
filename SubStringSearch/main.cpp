#include <iostream>
#include <string.h>
#include <time.h>
#include <vector>

using namespace std;
int posicion;

int bruteForceSearch(string pattern, string text) {
    int patternLen = pattern.size();
    int textLen = text.size();
    for (int i = 0; i <= textLen - patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == patternLen) return i;
    }
    return textLen;
}

int boyerMooreSearch(string pattern, string text) {
    int patternLen = pattern.size();
    int textLen = text.size();
    int right[256];
    for (int &c : right) c = -1;
    for (int p = 0; p < patternLen; p++) right[(int) pattern[p]] = p;
    int skip;
    for (int i = 0; i <= textLen - patternLen; i += skip) {
        skip = 0;
        for (int j = patternLen - 1; j >= 0; j--)
            if (text[i + j] != pattern[j]) {
                skip = max(1, j - right[(int) text[i + j]]);
                break;
            }
        if (skip == 0) return i;
    }
    return textLen;
}

long hashRK(string key, int len, long prime) {
    long hash = 0;
    for (int j = 0; j < len; j++)
        hash = (hash * 256 + key[j]) % prime;
    return hash;
}

int rabinKarpSearch(string pattern, string text, long prime) {
    int patternLen = pattern.size();
    int textLen = text.size();
    long RM1 = 1;
    for (int i = 1; i < patternLen; i++)
        RM1 = (256 * RM1) % prime;
    long patternHash = hashRK(pattern, patternLen, prime);
    int textHash = hashRK(text, patternLen, prime);
    if (patternHash == textHash) return 0;
    for (int i = patternLen; i < textLen; i++) {
        textHash = (textHash + prime - RM1 * text[i - patternLen] % prime) % prime;
        textHash = (textHash * 256 + text[i]) % prime;
        if (patternHash == textHash) return i - patternLen + 1;
    }
    return textLen;
}

vector<vector<int>> createDFA(string pattern, int patternLen) {
    int R = 256;
    vector<vector<int>> dfa = vector<vector<int>>(256);
    for (int i = 0; i < R; i++) {
        dfa[i] = vector<int>(patternLen);
    }
    dfa[pattern[0]][0] = 1;
    for (int x = 0, j = 1; j < patternLen; j++) {
        for (int c = 0; c < R; c++) {
            dfa[c][j] = dfa[c][x]; // Copy mismatch cases.
        }
        dfa[pattern[j]][j] = j + 1; // Set match case.
        x = dfa[pattern[j]][x]; // Update restart state.
    }

    return dfa;
}

int kmp(string text, string pattern) {
    int patternLen = pattern.length();
    int textLen = text.length();
    vector<vector<int>> dfa = createDFA(pattern, patternLen);
    int i, j;
    for (i = 0, j = 0; i < textLen && j < patternLen; i++) {
        j = dfa[text[i]][j];
    }
    if (j == patternLen) {
        return i - patternLen;
    }
    return textLen;
}

void printResult(string text, string pattern) {
    if (posicion != text.size()) {
        cout << endl << "substring on position " << posicion + 1 << endl;
        for (int i = 0; i < pattern.size(); i++)
            cout << text[posicion + i];
        cout << endl;
    } else
        cout << "no substring" << endl;
}

int main() {
    string text = "aaabbcccce";
    string pattern = "cce";
    cout << "BRUTE-FORCE" << endl;
    srand(time(0));
    posicion = bruteForceSearch(pattern, text);
    cout << "Time: " << ((float) clock()) / CLOCKS_PER_SEC;
    printResult(text, pattern);
    cout << "BOYER MOORE" << endl;
    srand(time(0));
    posicion = boyerMooreSearch(pattern, text);
    cout << "Time: " << ((float) clock()) / CLOCKS_PER_SEC;
    printResult(text, pattern);
    cout << "RABIN KARP" << endl;
    long prime = 101;
    srand(time(0));
    posicion = rabinKarpSearch(pattern, text, prime);
    cout << "Time: " << ((float) clock()) / CLOCKS_PER_SEC;
    printResult(text, pattern);
    cout << "KMP" << endl;
    srand(time(0));
    posicion = kmp(text, pattern);
    cout << "Time: " << ((float) clock()) / CLOCKS_PER_SEC;
    printResult(text, pattern);
}