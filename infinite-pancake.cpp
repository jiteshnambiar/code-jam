#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int finishPancakes(const vector<int> &pancakes, int size) {
	const int maxStack = *max_element(pancakes.begin(), pancakes.end());
	int ret = maxStack;
	for (int itr = 1; itr < maxStack; itr++) {
		int totalMoves = 0;
		for (int plate = 0; plate < size; plate++) {
			totalMoves += (pancakes[plate] - 1) / itr;
		}
		ret = min(ret, totalMoves + itr);
	}
	return ret;
}

int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	size_t testCases = 0;
	inputFile >> testCases;
	inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	for (int i = 0; i < testCases; i++) {
		int plates;
		inputFile >> plates;
		inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		vector<int> pancakes;
		for (int j = 0; j < plates; j++) {
			int pancake;
			inputFile >> pancake;
			pancakes.push_back(pancake);
		}
		outputFile << "Case #" << i + 1 << ": " << finishPancakes(pancakes, plates) << endl;
	}
	inputFile.close();
	outputFile.close();
    return 0;
}