#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_CITY_N		1000
#define UNKNOWN			-1

using namespace std;

vector<unsigned long long> cache;
vector<int> transposeGraph[MAX_CITY_N];
vector<int> graph[MAX_CITY_N];
int dirCount = 0;

unsigned long long MemoizationJourney(int startCity, int targetCity);
unsigned long long TabulationJourney(int city_n);
void DFS(int startCity, int targetCity);
void PrintGraph(int city_n);
void PrintTransposeGraph(int city_n);

void main() {
	int city_n;
	cin >> city_n;

	cache.reserve(city_n);
	
	cache.push_back(UNKNOWN);
	for (int i = 0; i < city_n; i++)
		cache.push_back(UNKNOWN);


	vector<int> availableMove(city_n);

	for (int i = 0; i < availableMove.size(); i++)
		cin >> availableMove[i];

	for (int i = 0; i < availableMove.size(); i++) {

		int move = availableMove[i];
		for (int k = 1; k <= move; k++){
			graph[i].push_back(i + k);
			transposeGraph[i + k].push_back(i);
		}
	
	}

	cout << "가능한 가짓수, 메모이제이션 : " << MemoizationJourney(0, city_n) << endl;

	cout << "가능한 가짓수, 타뷸레이션 : " << TabulationJourney(city_n);

	//PrintTransposeGraph(city_n);
}

void PrintGraph(int city_n) {
	for (int i = 0; i < city_n; i++) {
		cout << i << "번째 도시에서 이동 가능한 도시들" << endl;
		for (int k = 0; k < graph[i].size(); k++)
			cout << graph[i][k] << ' ';
		cout << endl;
	}
}
void PrintTransposeGraph(int city_n) {
	for (int i = 0; i <= city_n; i++) {
		cout << i << "번째 도시에서 이동 가능한 도시들" << endl;
		for (int k = 0; k < transposeGraph[i].size(); k++)
			cout << transposeGraph[i][k] << ' ';
		cout << endl;
	}


}

void DFS(int startCity, int targetCity) {
	
	if (startCity == targetCity){
		dirCount++;
		return;
	}
	
	for (int i = 0; i < graph[startCity].size(); i++)
		DFS(graph[startCity][i], targetCity);
	
}

unsigned long long MemoizationJourney(int startCity, int targetCity) {
	
	unsigned long long dirCount = 0;
	if (startCity == targetCity)
		return 1;
	
	if (graph[startCity].size() == 0)
		return cache[startCity] = 0;

	for (int i = 0; i <  graph[startCity].size(); i++) {
		int dstNode = graph[startCity][i];
		if (cache[dstNode] != UNKNOWN)
			dirCount += cache[dstNode];
		
		else 
			dirCount += MemoizationJourney(dstNode, targetCity);

	}
	// 탐색이 종료하면 캐시에 기록 후, 탐색된 경로의 가짓수 리턴

	cache[startCity] = dirCount % 1000000007;
	return cache[startCity];
}

unsigned long long TabulationJourney(int city_n) {
	
	vector<unsigned long long> table(city_n + 1, 0);
	
	table[city_n] = 1;

	for (int visitOrder = city_n; visitOrder > 0; visitOrder--) {
		for (int i = 0; i < transposeGraph[visitOrder].size(); i++) {
			int dstNode = transposeGraph[visitOrder][i];
			table[dstNode] += table[visitOrder];
			table[dstNode] %= 1000000007;
		}
	}

	return table[0];

}