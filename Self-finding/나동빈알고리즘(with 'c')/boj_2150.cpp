#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 10001
using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int>a[MAX];
vector<vector<int>>SCC;
stack<int>s;


//항상 처음 방문하는 노드만 실행됩니다.즉 N번 수행
int dfs(int x) {
	d[x] = ++id; //노드마다 고유한 번호를 입힙니다.
	s.push(x); //스택에 자기자신을 넣습니다.

	int result = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		//아직 방문하지 않은 이웃 노드인 경우
		if (d[y] == 0) result = min(result, dfs(y));
		//방문은 했지만 아직 처리중인 이웃 노드인 경우
		else if (!finished[y]) result = min(result, d[y]);
	}

	//부모 노드가 자기 자신인 경우 SCC를 형성합니다.
	if (result == d[x]) {
		vector<int>scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x)break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);

	}
	//자신의 부모값을 반환합니다.
	return result;
}

int main(void) {
	int v, e;
	scanf_s("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		int x, y;
		scanf_s("%d %d", &x, &y);
		a[x].push_back(y);
	}
	for (int i = 1; i <= v; i++) {
		if (d[i] == 0)dfs(i);
	}
	printf("%d\n", SCC.size());
	sort(SCC.begin(), SCC.end());
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			printf("%d ", SCC[i][j]);
		}
		printf("-1\n");
	}
	return 0;
}