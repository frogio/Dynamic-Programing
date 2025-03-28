#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool SearchSubsetSum(vector<int>& set, int index, int sum, int target);

void main() {
	vector<int> set = { 13, 79, 45, 29 };
	int target = 166;

	sort(set.begin(), set.end());

	if (SearchSubsetSum(set, 0, 0, target))
		cout << "부분집합 중 합이 " << target << "인 부분집합이 존재합니다.";
	else
		cout << "부분집합 중 합이 " << target << "인 부분집합이 존재하지 않습니다.";

}
bool SearchSubsetSum(vector<int> & set, int index, int sum, int target) {
	// 가지치기 기법
	// 기저
	// True Case
	//		- target을 찾을 경우 true
	// False Case
	//		- target보다 큰 부분집합의 합일 경우 false,
	//		- 집합의 끝에 도달할 경우 false,

	if (sum == target)
		return true;

	else if (index == set.size() || sum > target)
		return false;

	return SearchSubsetSum(set, index + 1, sum, target) || SearchSubsetSum(set, index + 1, sum + set[index], target);
			// 원소가 존재하지 않음, 원소가 존재함
}