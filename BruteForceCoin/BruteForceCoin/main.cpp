#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void MakeCoinCases(vector<bool> coins, int coinCount, int index, vector<vector<bool>> & cases);

void main() {

	int coins;
	cout << "동전의 개수 ? ";
	cin >> coins;
	
	vector<bool> coin(coins, false);
	vector<vector<bool>> cases;
	MakeCoinCases(coin, coins, 0, cases);

	for (int i = 0; i < cases.size(); i++) {
		cout << i + 1 << "번째 case " << endl;
		cout << "\t";
		for (int k = 0; k < cases[i].size(); k++){
			if (cases[i][k])
				cout << "앞";
			else
				cout << "뒤";
		}
		cout << endl << endl;
	}

}

void MakeCoinCases(vector<bool> coins, int coinCount, int index, vector<vector<bool>>& cases) {

	if (index == coinCount){
		cases.push_back(coins);
		return;
	}

	MakeCoinCases(coins, coinCount, index + 1, cases);			// 뒤집지 않은 경우

	coins[index] = true;
	MakeCoinCases(coins, coinCount, index + 1, cases);			// 뒤집은 경우

}