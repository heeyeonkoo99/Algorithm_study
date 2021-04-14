/*열혈강호 3문제로 특정한 직원에 한해서만 2번씩 일을 할수 있도록 매칭하는 문제이다. 따라서 모든 직원에 대해
1번씩 매칭을 해주고, 나머지 특정한 직원의 숫자만큼만 추가적으로 한번씩 더 매칭을 수행시켜주면 된다.*/
#include<iostream>
#include<vector>
#define MAX 1001
using namespace std;

vector<int>a[MAX];
int d[MAX];
bool c[MAX];
int n, m,k,s;

//매칭에 성공한 경우 True, 실패한 경우 False
bool dfs(int x) {
	//연결된 모든 노드에 대해서 들어갈수 있는지 시도
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		//이미 처리한 노드는 더이상 볼필요가 없음
		if (c[t]) continue;
		c[t] = true;
		//비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}


int main(void) {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= s; j++) {
			int t;
			cin >> t;
			a[i].push_back(t);
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		fill(c, c + MAX, false);
		if (dfs(i))count++;
	}
	//2번씩 작업 할수 있는 사람을 추가적으로 계산합니다.
	int extra = 0;
	for (int i = 1; i <= n && extra < k; i++) {
		fill(c, c + MAX, false);
		if (dfs(i))extra++;
	}
	cout << count + extra << "\n";


	return 0;
}
