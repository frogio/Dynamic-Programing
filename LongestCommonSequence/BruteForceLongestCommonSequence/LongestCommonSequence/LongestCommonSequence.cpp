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
	cout << A << "와 " << B << "의 최장 공통 부분 시퀀스 길이 : " << LCS_BruteForce(A, B, 0, 0, {}) << endl;
	PrintSubSequences(A, B);

}

int LCS_BruteForce(string A, string B, int i, int j, vector<pair<int, int>> subsequence) {

	// A 또는 B가 문자열 끝에 도달할 경우 탐색 종료
	if (i >= A.size() || j >= B.size()) {
		found.push_back(subsequence);
		return subsequence.size();
	}

	// 만약 문자가 일치하면
	if (A[i] == B[j]) {

		// 동일한 문자 인덱스 추가
		subsequence.push_back({ i, j });
		return LCS_BruteForce(A, B, i + 1, j + 1, subsequence);
	}

	/* 문자가 일치하지 않다면
		A 또는 B의 문자열 인덱스를 증가시키고,
		LCS는 A 인덱스를 증가시켜 구한 LCS 또는, B 인덱스를 증가시켜 구한 LCS이다.
	*/

	return max(LCS_BruteForce(A, B, i + 1, j, subsequence),
		LCS_BruteForce(A, B, i, j + 1, subsequence));


}

void PrintSubSequences(string A, string B) {
	
	// 부분 시퀀스 길이를 기준으로 정렬
	sort(found.begin(), found.end(), [](auto a, auto b) {			// 람다 비교 함수
		if (a.size() != b.size())
			return a.size() < b.size();

		return a < b;
	});

	found.erase(unique(found.begin(), found.end()), found.end());	// 중복 제거

	int previousSize = 0;

	for (auto subsequence : found) {

		if(subsequence.size() != previousSize){
			previousSize = subsequence.size();
			PRINT("SIZE = " << previousSize << endl);
		}

		// 밑줄을 이용하여 문자의 자리를 표현
		string a_seq(A.size(), '_');
		string b_seq(B.size(), '_');

		for (auto pair : subsequence) {
			a_seq[pair.first] = A[pair.first];
			b_seq[pair.second] = B[pair.second];
		}

		PRINT("\t" << a_seq << " " << b_seq << endl);

	}
}