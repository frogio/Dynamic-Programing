#include <string>
#include <iostream>
#include <vector>
#include <math.h>

#define UNKNOWN		-1

using namespace std;

int LongestCommonSequence(string A, string B, int i, int k, vector<vector<int>> & cache);

int main() {

	cin.tie(NULL);

	string A, B;
	cin >> A >> B;
	
	vector<vector<int>> cache(A.size(), vector<int>(B.size(), UNKNOWN));

	cout << LongestCommonSequence(A, B, 0, 0, cache);

	return 0;
}



int LongestCommonSequence(string A, string B, int i, int k, vector<vector<int>>& cache) {

	if (A.size() == 0 || B.size() == 0 || i >= A.size() || k >= B.size())
		return 0;

	else if (cache[i][k] != UNKNOWN)
		return cache[i][k];

	else {

		if (A[i] == B[k])
			cache[i][k] = LongestCommonSequence(A, B, i + 1, k + 1, cache) + 1;

		else{
			cache[i][k] = max(LongestCommonSequence(A, B, i + 1, k, cache),
				LongestCommonSequence(A, B, i, k + 1, cache));
		
		}
	}

	return cache[i][k];
}