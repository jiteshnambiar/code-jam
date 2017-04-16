#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void setTheStage(vector<vector<int> >& stageMatrix, int N, vector
	<pair<int, int> >& plusPositions, vector<pair<int, int> >& mulPositions) {
}

int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	int testCases = 0;
	inputFile >> testCases;
	inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < testCases; i++) {
		int N, M;
		inputFile >> N >> M;
		vector<vector<int> > stageMatrix(N, vector<int>(N, 0));
		vector<pair<int, int> > plusPositions, mulPositions;
		for (int j = 0; j < M; j++) {
			char symbol;
			inputFile >> symbol;
			int posX, posY;
			inputFile >> posX >> posY;
			//stageMatrix[posX][posY] = (symbol == '+') ? 1 : ((symbol == 'x') ? 2 : 3);
			if (symbol == '+') {
				stageMatrix[posX][posY] = 1;
				plusPositions.push_back(make_pair(posX, posY));
			}
			else if (symbol == 'x') {
				stageMatrix[posX][posY] = 2;
				mulPositions.push_back(make_pair(posX, posY));
			}
			else {
				stageMatrix[posX][posY] = 3;
			}
		}
		outputFile << "Case #" << i + 1 << ": ";
		setTheStage(stageMatrix, N, plusPositions, mulPositions);
		cout << endl;
	}

	inputFile.close();
	outputFile.close();
    return 0;
}