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
		cout << "�κ����� �� ���� " << target << "�� �κ������� �����մϴ�.";
	else
		cout << "�κ����� �� ���� " << target << "�� �κ������� �������� �ʽ��ϴ�.";

}
bool SearchSubsetSum(vector<int>& set, int index, int target) {
	// ��Ʈ�� ���
	// ����
	// True Case
	//		- target�� ã�� ��� true => �κ������� �հ� target�� ���� 0�̹Ƿ� target == 0�̸� true,
	// False Case
	//		- target���� ū �κ������� ���� ��� false => target���� ū �κ������� ���� ���� �����̹Ƿ� false,
	//		- ������ ���� ������ ��� false,

	if (target == 0)
		return true;

	else if (index == set.size() || set[index] > target)
		return false;

	return SearchSubsetSum(set, index + 1, target) || SearchSubsetSum(set, index + 1, target - set[index]);
	// ���Ұ� �������� ����, ���Ұ� ������
}