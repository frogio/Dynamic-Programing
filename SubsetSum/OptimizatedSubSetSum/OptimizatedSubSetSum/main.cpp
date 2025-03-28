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
		cout << "�κ����� �� ���� " << target << "�� �κ������� �����մϴ�.";
	else
		cout << "�κ����� �� ���� " << target << "�� �κ������� �������� �ʽ��ϴ�.";

}
bool SearchSubsetSum(vector<int> & set, int index, int sum, int target) {
	// ����ġ�� ���
	// ����
	// True Case
	//		- target�� ã�� ��� true
	// False Case
	//		- target���� ū �κ������� ���� ��� false,
	//		- ������ ���� ������ ��� false,

	if (sum == target)
		return true;

	else if (index == set.size() || sum > target)
		return false;

	return SearchSubsetSum(set, index + 1, sum, target) || SearchSubsetSum(set, index + 1, sum + set[index], target);
			// ���Ұ� �������� ����, ���Ұ� ������
}