#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> TabulationSubsetSum(vector<int>& set);

void main() {
	vector<int> set = { 16, 1058, 22, 13, 46, 55, 3, 92, 47, 7, 98, 367, 807, 106, 333, 85, 577, 9, 3059};
	int total = 0;
	
	for (int i = 0; i < set.size();i++)
		total += set[i];

	sort(set.begin(), set.end());

	vector<vector<bool>> DP = TabulationSubsetSum(set);
	vector<int>	subsetSum;

	for (int sum = 0; sum <= total; sum++) {
		if (DP[set.size()][sum])
			subsetSum.push_back(sum);
	}

	cout << "��ü �κ������� ���� �Ʒ��� �����ϴ�." << endl;

	for (int i = 0; i < subsetSum.size(); i++)
		cout << subsetSum[i] << ' ';

}

vector<vector<bool>> TabulationSubsetSum(vector<int>& set) {
	int maxSum = 0;

	for (int i = 0; i < set.size(); i++)
		maxSum += set[i];

	vector<vector<bool>> DP(set.size() + 1, vector<bool>(maxSum + 1, 0));

	for (int i = 0; i < set.size(); i++)
		DP[i][0] = true;

	for (int i = 1; i <= set.size(); i++) {
		for (int sum = 1; sum <= maxSum; sum++) {
			if (sum < set[i - 1])												// ���̻� ���Ҹ� �߰��� �� ���� ���
				DP[i][sum] = DP[i - 1][sum];									// i - 1�ε��� ���� sum�� ������ �� ������ i �ε��������� ������ �� �ִ�. 
																				// (�ε��� i���� ���Ҹ� �߰� ���ϸ� sum�� ���� �����ϹǷ�)
			else																// ���Ҹ� �߰��� �� ���� ���, ���Ҹ� �߰��� ���, �߰����� ���� ��� �ΰ����� ����
				DP[i][sum] = DP[i - 1][sum] || DP[i - 1][sum - set[i - 1]];		// i - 1�ε������� sum�� �����ϰų� �Ǵ� i - 1 �ε������� ���Ҹ� �߰��� ������ sum�� ������ �� ������, 
																				// i ��° �ε������� sum �� ���� �����ϴ�.
		}
	}

	return DP;
}
