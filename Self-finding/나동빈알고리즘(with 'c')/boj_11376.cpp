/*������ȣ 2������ ������ ������ �ִ� �ΰ��� �����Ҽ� �ִٴ°��� ���� �ι��� DFS�� �������ָ� �ȴ�.*/
#include<iostream>
#include<vector>
#define MAX 1001
using namespace std;

vector<int>a[MAX];
int d[MAX];
bool c[MAX];
int n, m;

//��Ī�� ������ ��� True, ������ ��� False
bool dfs(int x) {
	//����� ��� ��忡 ���ؼ� ���� �ִ��� �õ�
	for (int i = 0; i < a[x].size(); i++) {
		int t = a[x][i];
		//�̹� ó���� ���� ���̻� ���ʿ䰡 ����
		if (c[t]) continue;
		c[t] = true;
		//����ְų� ���� ��忡 �� �� ������ �ִ� ���
		if (d[t] == 0 || dfs(d[t])) {
			d[t] = x;
			return true;
		}
	}
	return false;
}


int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			int t;
			scanf("%d", &t);
			a[i].push_back(t);
		}
	}
	int count = 0;
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i <= n; i++) { //�ִ��� ��ֽܳ��ϴ�.
			fill(c, c + MAX, false);
			if (dfs(i)) count++;
		}
	}
	printf("%d\n", count);
	return 0;
}
