#include <iostream>
#include <vector>
#include <algorithm>

#define UNKNOWN		-1

using namespace std;

bool SearchSubsetSum(vector<int>& set, int index, int target, vector<vector<int>>& cache);

void main() {
	vector<int> set = { 13, 79, 45, 29, 16};
	vector<vector<int>> cache(set.size(), vector<int>(7000, UNKNOWN));
	
	int target = 108;

	sort(set.begin(), set.end());

	if (SearchSubsetSum(set, 0, target, cache))
		cout << "부분집합 중 합이 " << target << "인 부분집합이 존재합니다.";
	else
		cout << "부분집합 중 합이 " << target << "인 부분집합이 존재하지 않습니다.";

}
bool SearchSubsetSum(vector<int>& set, int index, int target, vector<vector<int>> & cache) {

	if (target == 0)
		return true;

	else if (index == set.size() || set[index] > target)
		return false;

	if (cache[index][target] == UNKNOWN) {				// 캐시가 존재하지 않으면
	
		bool append = SearchSubsetSum(set, index + 1, target - set[index], cache);
		bool ignore = SearchSubsetSum(set, index + 1, target, cache);

		cache[index][target] = append || ignore;		// 캐시에 기록 후

	}

	return cache[index][target];						// 캐시에 저장된 값 리턴
}