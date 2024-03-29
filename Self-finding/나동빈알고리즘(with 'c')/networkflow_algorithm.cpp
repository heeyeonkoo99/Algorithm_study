#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 100
#define INF 1000000000
using namespace std;
int n = 6, result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int>a[MAX];

void maxFlow(int start, int end) {
	while (1) {
		fill(d, d + MAX, -1);
		queue<int>q;
		q.push(start);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];
				//방문하지 않은 노드 중에 용량이 남은 경우
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x; //경로를 기억합니다.
					if (y == end)break; // 도착지에 도달한 경우
				}
			}
		}
		if (d[end] == -1) break;// 모든 경로를 찾은 뒤에 탈출합니다.
		int flow = INF;
		for (int i = end; i != start; i = d[i]) { //거꾸로 최소유량탐색
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		//최소 유량만큼 추가합니다.
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
	}
}

int main(void) {
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(2);
	a[4].push_back(4);
	c[2][4] = 3;

	maxFlow(1, 6);
	printf("%d", result);
}