#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void MakeCoinCases(vector<bool> coins, int coinCount, int index, vector<vector<bool>> & cases);

void main() {

	int coins;
	cout << "������ ���� ? ";
	cin >> coins;
	
	vector<bool> coin(coins, false);
	vector<vector<bool>> cases;
	MakeCoinCases(coin, coins, 0, cases);

	for (int i = 0; i < cases.size(); i++) {
		cout << i + 1 << "��° case " << endl;
		cout << "\t";
		for (int k = 0; k < cases[i].size(); k++){
			if (cases[i][k])
				cout << "��";
			else
				cout << "��";
		}
		cout << endl << endl;
	}

}

void MakeCoinCases(vector<bool> coins, int coinCount, int index, vector<vector<bool>>& cases) {

	if (index == coinCount){
		cases.push_back(coins);
		return;
	}

	MakeCoinCases(coins, coinCount, index + 1, cases);			// ������ ���� ���

	coins[index] = true;
	MakeCoinCases(coins, coinCount, index + 1, cases);			// ������ ���

}