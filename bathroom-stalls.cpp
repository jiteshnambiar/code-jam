#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
using namespace std;

struct Cache {
	long fromIndex, count;
};

typedef int NIndex, KIndex;
unordered_map<NIndex, vector<KIndex> > stallMapCache;

struct StallDivision {
	StallDivision(long long _start, long long _end) : start(_start), end(_end) {
		size = end - start + 1;
	}
	StallDivision() : start(0), end(0) {
		size = 0;
	}
	void print() const { cout << "start[" << start << "], end[" << end << "]: size = " << size << endl; }
	long long size;
	long long start, end;
};

struct Compare {
	bool operator() (const StallDivision& a, const StallDivision& b) const {
		return (a.size < b.size) || ((a.size == b.size) && (a.start > b.start));
	}
};

pair<long long, long long> bathroomStalls(long long N, long long K) {
	auto search = stallMapCache.find(N);
	if (search != stallMapCache.end()) {
		vector<KIndex>& markers = search->second;
		size_t zero_zero = 0;
		size_t one_zero = 1;
		if (K > markers[zero_zero]) {
			return make_pair(0, 0);
		} else if (K > markers[one_zero]) {
			return make_pair(1, 0);
		}
	}

	priority_queue<StallDivision, vector<StallDivision>, Compare > queue;
	queue.push(StallDivision(1, N));
	
	StallDivision top;
	long long stallPicked;
	for (long long i = 1; i <= K; ++i) {
		top = queue.top();
		queue.pop();

		if (N > 100 && top.size < 3) {
			int counter = 0;
			while (queue.top().size != 1) {
				queue.pop();
				counter++;
			}
			auto search = stallMapCache.find(N);
			if (search != stallMapCache.end()) {
				vector<KIndex>& markers = search->second;
				markers[0] = i + counter;
				markers[1] = i;
			}
			else {
				vector<KIndex> markers;
				markers.push_back(i + counter);
				markers.push_back(i);
				stallMapCache[N] = markers;
			}
			return make_pair(1, 0);
		}

		stallPicked = (top.size % 2 == 0) ? (top.start + (top.size / 2) - 1) : top.start + (top.size / 2);
		if (stallPicked - 1 >= top.start) {
			StallDivision remaningStallLeft(top.start, stallPicked - 1);
			queue.push(remaningStallLeft);
		}
		if (stallPicked + 1 <= top.end) {
			StallDivision remaningStallRight(stallPicked + 1, top.end);
			queue.push(remaningStallRight);
		}
	}
	return make_pair(max(stallPicked - top.start, top.end - stallPicked), min(stallPicked - top.start, top.end - stallPicked));
}

int main()
{
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");

	int testCases = 0;
	inputFile >> testCases;
	inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < testCases; i++) {
		long long N, K;
		inputFile >> N >> K;
		pair<long long, long long> finalStall = bathroomStalls(N, K);
		outputFile << "Case #" << i + 1 << ": " << finalStall.first << " " << finalStall.second << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}