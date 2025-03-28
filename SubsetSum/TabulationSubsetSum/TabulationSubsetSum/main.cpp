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

	cout << "전체 부분집합의 합은 아래와 같습니다." << endl;

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
			if (sum < set[i - 1])												// 더이상 원소를 추가할 수 없는 경우
				DP[i][sum] = DP[i - 1][sum];									// i - 1인덱스 에서 sum에 도달할 수 있으면 i 인덱스에서도 도달할 수 있다. 
																				// (인덱스 i에서 원소를 추가 안하면 sum에 도달 가능하므로)
			else																// 원소를 추가할 수 있을 경우, 원소를 추가한 경우, 추가하지 않은 경우 두가지를 조사
				DP[i][sum] = DP[i - 1][sum] || DP[i - 1][sum - set[i - 1]];		// i - 1인덱스에서 sum에 도달하거나 또는 i - 1 인덱스에서 원소를 추가한 다음에 sum에 도달할 수 있으면, 
																				// i 번째 인덱스에서 sum 에 도달 가능하다.
		}
	}

	return DP;
}
