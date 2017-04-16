#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

string tidyNumber(string& item) {
	size_t size = item.size();
	if (size < 2)
		return item;

	int endPtr = size - 1, currentPtr;
	int lastSeen = item[endPtr] - '0', digit = lastSeen;
	for (int i = size - 2; i >= 0; --i) {
		digit = item[i] - '0';
		if (digit <= lastSeen) {
			lastSeen = digit;
			continue;
		}

		for (int j = endPtr; j > i; --j) {
			item[j] = '9';
		}
		item[i] = (digit - 1) < 0 ? '0' : (digit - 1 + '0');
		lastSeen = item[i] - '0';
		endPtr = i;
	}

	if (item[0] == '0') {
		return item.substr(1, size - 1);
	}

	return item;
}

int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	size_t testCases = 0;
	inputFile >> testCases;
	inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (int i = 0; i < testCases; i++) {
		string item;
		std::getline(inputFile, item);
		outputFile << "Case #" << i + 1 << ": " << tidyNumber(item) << endl;
	}
	inputFile.close();
	outputFile.close();

    return 0;
}