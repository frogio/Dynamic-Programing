#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool SearchSubsetSum(vector<int>& set, int index, int target);

void main() {
	vector<int> set = { 13, 79, 45, 29 };
	int target = 166;

	sort(set.begin(), set.end());

	if (SearchSubsetSum(set, 0, target))
		cout << "부분집합 중 합이 " << target << "인 부분집합이 존재합니다.";
	else
		cout << "부분집합 중 합이 " << target << "인 부분집합이 존재하지 않습니다.";

}
bool SearchSubsetSum(vector<int>& set, int index, int target) {
	// 백트랙 기법
	// 기저
	// True Case
	//		- target을 찾을 경우 true => 부분집합의 합과 target을 빼면 0이므로 target == 0이면 true,
	// False Case
	//		- target보다 큰 부분집합의 합일 경우 false => target보다 큰 부분집합의 합을 빼면 음수이므로 false,
	//		- 집합의 끝에 도달할 경우 false,

	if (target == 0)
		return true;

	else if (index == set.size() || set[index] > target)
		return false;

	return SearchSubsetSum(set, index + 1, target) || SearchSubsetSum(set, index + 1, target - set[index]);
	// 원소가 존재하지 않음, 원소가 존재함
}