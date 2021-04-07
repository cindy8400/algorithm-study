#include <iostream>
#define MAX_SIZE 13
using namespace std;
int lotto[MAX_SIZE];
int combi[MAX_SIZE];
int k;

void dfs(int start, int depth) {

	if (depth == 6) {		//탈출조건
		for (int i = 0; i < 6; i++) {
			cout << combi[i] << ' ';	//조합 하나를 출력 뒤 탈출
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < k; i++) {	//lotto배열 0 ~ k-1 탐색
		combi[depth] = lotto[i];
		dfs(i + 1, depth + 1);
	}
}

int main() {
	
	while (cin >> k && k) {		//cin >> k == true(읽기 성공)이고 k>0이면 keep going
		for (int i = 0; i < k; i++) {
			cin >> lotto[i];
		}

		dfs(0, 0);
		cout << '\n'; // k 바뀔 때마다 한줄 띄기
	}
	return 0;
}