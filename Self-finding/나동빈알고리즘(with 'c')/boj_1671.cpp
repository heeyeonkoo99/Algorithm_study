/*이 문제도 단순히 2번씩 매칭을 수행해주면 되는 간단한 문제이다. 다만 문제에서는 상어들의 
능력수치에 따라서 매칭을 시켜주라고 지시하고 있으므로 능력 수치를 비교하는 부분만 신경써서 작성해주면 정답처리받을수 있다.*/
#include<iostream>
#include<vector>
#define MAX 1001
using namespace std;


vector<int>a[MAX];
int stat[MAX][3];
int d[1001];
bool c[1001];
int n;

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
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		scanf("%d %d %d", &stat[i][0], &stat[i][1], &stat[i][2]);
	}
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (stat[i][0] == stat[j][0] && stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2]) {
				a[i].push_back(j);
			}
			else if (stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2]) {
				a[i].push_back(j);
			}
			else if (stat[i][0] <= stat[j][0] && stat[i][1] <= stat[j][1] && stat[i][2] <= stat[j][2]) {
				a[j].push_back(i);
			}
		}
	}


	int count = 0;
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i <= n; i++) { //최대한 우겨넣습니다.
			fill(c, c + MAX, false);
			if (dfs(i)) count++;
		}
	}
	printf("%d\n", n-count);
	return 0;
}
