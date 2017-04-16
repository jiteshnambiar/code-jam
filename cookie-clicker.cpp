#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

double fastestCookieClicker(double C, double F, double X) {
	double speed = 2.0, minTime = X / 2.0, time = 0.0;
	while (true) {
		time += C / speed;
		double remainingTime = X / (speed + F);
		if ((time + remainingTime) > minTime) {
			break;
		}
		minTime = time + remainingTime;
		speed += F;
	}

	return minTime;
}

int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	int _words_size = 0;
	inputFile >> _words_size;
	inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int _words_i = 0; _words_i<_words_size; _words_i++) {
		double C, F, X;
		inputFile >> C >> F >> X;
		outputFile << "Case #" << _words_i + 1 << ": " << std::fixed << std::setprecision(7) << fastestCookieClicker(C, F, X) << endl;
	}

	inputFile.close();
	outputFile.close();
	return 0;
}