#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
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

int standingOvation(const string shynessString) {
	vector<string> str = split(shynessString, ' ');
	int waitingOnMax = atoi(str[0].c_str());
	int invitees = 0, attendees = 0;
	const string& attendeeList = str[1];

	for (int waitingOn = 0; waitingOn <= waitingOnMax; ++waitingOn) {
		if (waitingOn > attendees) {
			invitees += waitingOn - attendees;
			attendees += waitingOn - attendees;
		}
		attendees += attendeeList[waitingOn] - '0';
	}
	return invitees;
}

int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	int _word_size = 0;
	inputFile >> _word_size;
	inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int _words_i = 0; _words_i < _word_size; ++_words_i) {
		string item;
		std::getline(inputFile, item);
		outputFile << "Case #" << _words_i + 1 << ": " << standingOvation(item) << endl;
	}
	inputFile.close();
	outputFile.close();

    return 0;
}