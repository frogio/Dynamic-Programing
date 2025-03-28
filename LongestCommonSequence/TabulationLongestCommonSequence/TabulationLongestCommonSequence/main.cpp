#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

#define		UNKNOWN		-1

using namespace std;

struct Pair {
	int i;
	int k;
};

int main() {

	string A, B;

	cin >> A >> B;

	vector<vector<int>> table(A.size(), vector<int>(B.size(), UNKNOWN));
	
	int base = 0;

	vector<Pair> LCSIdx;
	
	for (int i = 0; i < table[0].size(); i++) {
		if (A[0] == B[i] && base == 0){
			base = 1;
			LCSIdx.push_back({ 0, i });
		}
		table[0][i] = base;
	}
	// 기저
	
	for (int i = 1; i < table.size(); i++) {
		for (int k = 0; k < table[i].size(); k++) {

			if (A[i] == B[k] && k > 0)
				table[i][k] = table[i - 1][k - 1] + 1;
			
			// A[1] == B[0]
			// table[0][-1] 인 경우 새로운 기저를 삼는다.
			else if (A[i] == B[k] && k == 0)
				table[i][k] = 1;
			
			else{
				int right = 0;

				if (k >= 1)
					right = table[i][k - 1];

				table[i][k] = max(table[i - 1][k], right);
			}

		}
	}
	
	cout << table[A.size() - 1][B.size() - 1];
	
	return 0;
}
