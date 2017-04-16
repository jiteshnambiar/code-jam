#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int flipCount(const string& str) {
	int size = str.size();
	int i = size - 1;
	while (i >= 0 && str[i] == '+') { i--; }
	if (i < 0) {
		return 0;
	}

	int count = 1;
	for (i = i - 1; i >= 0; --i) {
		if (i < size-1 && str[i] != str[i + 1]) {
			count++;
		}
	}
	return count;
}

int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	int _words_size = 0;
	inputFile >> _words_size;
	inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	vector<string> _words;
	string _words_item;
	for (int _words_i = 0; _words_i<_words_size; _words_i++) {
		getline(inputFile, _words_item);
		outputFile << "Case #" << _words_i + 1 << ": " << flipCount(_words_item) << endl;
	}

	inputFile.close();
	outputFile.close();
    return 0;
}

