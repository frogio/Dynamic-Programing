#include <iostream>
#include <vector>

using namespace std;

//#define DEBUG

void MakeSubset(vector<int> set, vector<int> subset, int index, vector<vector<vector<int>>> & allSubsets);
void PrintSubsets(vector<vector<vector<int>>>& allSubsets);
bool SearchTargetSum(vector<vector<vector<int>>>& allSubsets, int target);

void main() {

	vector<int> set = { 16, 1058, 22, 13, 46, 55, 3, 92, 47, 7, 98, 367, 807, 106, 333, 85, 577, 9, 3059 };;
	vector<vector<vector<int>>> allSubsets(set.size() + 1);
	MakeSubset(set, {}, 0, allSubsets);

#ifdef DEBUG
	PrintSubsets(allSubsets);
#endif

	int target = 6799;
	bool isAvailable = SearchTargetSum(allSubsets, target);
	
	if (isAvailable)
		cout << "합이 " << target << "인 부분집합이 존재합니다.";
	else
		cout << "합이 " << target << "인 부분집합이 존재하지 않습니다.";

}

void PrintSubsets(vector<vector<vector<int>>>& allSubsets) {

	for (int size = 0; size < allSubsets.size(); size++) {
		cout << "크기가 " << size << "인 부분 집합 : ";
		vector<vector<int>>& subsets = allSubsets[size];		// 크기가 size인 N개의 부분집합

		for (int i = 0; i < subsets.size(); i++) {
			cout << "{ ";
			for (int k = 0; k < subsets[i].size(); k++)
				cout << subsets[i][k] << ", ";
			cout << " }, ";
		}
		cout << endl << endl;

	}

}

bool SearchTargetSum(vector<vector<vector<int>>>& allSubsets, int target) {

	for (int size = 0; size < allSubsets.size(); size++) {
		vector<vector<int>>& subsets = allSubsets[size];		// 크기가 size인 N개의 부분집합

		for (int i = 0; i < subsets.size(); i++) {
			int sum = 0;
			for (int k = 0; k < subsets[i].size(); k++)
				sum += subsets[i][k];

			if (sum == target)
				return true;
		}

	}

	return false;

}


void MakeSubset(vector<int> set, vector<int> subset, int index, vector<vector<vector<int>>>& allSubsets) {
	
	if (index == set.size()) {
		allSubsets[subset.size()].push_back(subset);
		return;
	}

	MakeSubset(set, subset, index + 1, allSubsets);			// 집합에 원소가 있을 경우
	
	subset.push_back(set[index]);
	MakeSubset(set, subset, index + 1, allSubsets);			// 집합에 원소가 없을 경우

}