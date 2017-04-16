#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

// http://stackoverflow.com/a/236803/3479448
template<typename Out>
void split(const std::string &s, char delim, Out result) {
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		*(result++) = item;
	}
}


std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, std::back_inserter(elems));
	return elems;
}

char reverse(char x) {
	if (x == '-')
		return '+';
	return '-';
}

int happyPancakes(string pancake, int K) {
	size_t size = pancake.size();
	int negativeCount = 0;
	for (int i = 0; i < size; ++i) {
		if (pancake[i] == '-') {
			negativeCount++;
		}
	}

	if (!negativeCount)
		return 0;

	int counter = 0;
	for (int i = 0; i < size; ++i) {
		if (pancake[i] == '-' && (size - i) >= K) {
			for (int j = 0; j < K; ++j) {
				pancake[i + j] = reverse(pancake[i + j]);
			}
			counter++;
		}
		else if (pancake[i] == '-' && (size - i) < K) {
			return -1;
		}
	}
	return counter;
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
		vector<string> pancakes = split(item, ' ');
		int val = happyPancakes(pancakes[0], atoi(pancakes[1].c_str()));
		if (val < 0) {
			outputFile << "Case #" << i + 1 << ": IMPOSSIBLE" << endl;
		}
		else {
			outputFile << "Case #" << i + 1 << ": " << val << endl;
		}
	}
	inputFile.close();
	outputFile.close();

    return 0;
}