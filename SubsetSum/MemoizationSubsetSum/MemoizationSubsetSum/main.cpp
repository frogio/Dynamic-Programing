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
		cout << "�κ����� �� ���� " << target << "�� �κ������� �����մϴ�.";
	else
		cout << "�κ����� �� ���� " << target << "�� �κ������� �������� �ʽ��ϴ�.";

}
bool SearchSubsetSum(vector<int>& set, int index, int target, vector<vector<int>> & cache) {

	if (target == 0)
		return true;

	else if (index == set.size() || set[index] > target)
		return false;

	if (cache[index][target] == UNKNOWN) {				// ĳ�ð� �������� ������
	
		bool append = SearchSubsetSum(set, index + 1, target - set[index], cache);
		bool ignore = SearchSubsetSum(set, index + 1, target, cache);

		cache[index][target] = append || ignore;		// ĳ�ÿ� ��� ��

	}

	return cache[index][target];						// ĳ�ÿ� ����� �� ����
}