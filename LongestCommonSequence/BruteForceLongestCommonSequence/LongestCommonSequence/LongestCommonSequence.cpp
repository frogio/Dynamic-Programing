#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>


using namespace std;

#define DEBUG		1

#if DEBUG
#define PRINT(x) cerr << x
#else
#define PRINT(x)
#endif




int LCS_BruteForce(string A, string B, int i, int j, vector<pair<int, int>> subsequence);
void PrintSubSequences(string A, string B);
vector<vector<pair<int, int>>> found;

void main() {
	
	string A, B;
	//cout << A << B;
	cin >> A >> B;
	cout << A << "�� " << B << "�� ���� ���� �κ� ������ ���� : " << LCS_BruteForce(A, B, 0, 0, {}) << endl;
	PrintSubSequences(A, B);

}

int LCS_BruteForce(string A, string B, int i, int j, vector<pair<int, int>> subsequence) {

	// A �Ǵ� B�� ���ڿ� ���� ������ ��� Ž�� ����
	if (i >= A.size() || j >= B.size()) {
		found.push_back(subsequence);
		return subsequence.size();
	}

	// ���� ���ڰ� ��ġ�ϸ�
	if (A[i] == B[j]) {

		// ������ ���� �ε��� �߰�
		subsequence.push_back({ i, j });
		return LCS_BruteForce(A, B, i + 1, j + 1, subsequence);
	}

	/* ���ڰ� ��ġ���� �ʴٸ�
		A �Ǵ� B�� ���ڿ� �ε����� ������Ű��,
		LCS�� A �ε����� �������� ���� LCS �Ǵ�, B �ε����� �������� ���� LCS�̴�.
	*/

	return max(LCS_BruteForce(A, B, i + 1, j, subsequence),
		LCS_BruteForce(A, B, i, j + 1, subsequence));


}

void PrintSubSequences(string A, string B) {
	
	// �κ� ������ ���̸� �������� ����
	sort(found.begin(), found.end(), [](auto a, auto b) {			// ���� �� �Լ�
		if (a.size() != b.size())
			return a.size() < b.size();

		return a < b;
	});

	found.erase(unique(found.begin(), found.end()), found.end());	// �ߺ� ����

	int previousSize = 0;

	for (auto subsequence : found) {

		if(subsequence.size() != previousSize){
			previousSize = subsequence.size();
			PRINT("SIZE = " << previousSize << endl);
		}

		// ������ �̿��Ͽ� ������ �ڸ��� ǥ��
		string a_seq(A.size(), '_');
		string b_seq(B.size(), '_');

		for (auto pair : subsequence) {
			a_seq[pair.first] = A[pair.first];
			b_seq[pair.second] = B[pair.second];
		}

		PRINT("\t" << a_seq << " " << b_seq << endl);

	}
}