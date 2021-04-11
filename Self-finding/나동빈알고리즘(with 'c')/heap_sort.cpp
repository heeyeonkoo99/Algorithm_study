#include<stdio.h>

int number = 9;
int heap[9] = { 7,6,5,8,3,5,8,1,6 };

int main(void) {
	// ���� ��ü Ʈ�� ������ �ִ� �������� �ٲߴϴ�.
	for (int i = 1; i < number; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	
	}
	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
	printf("\n");

	//ũ�⸦ �ٿ����� �ݺ������� ���� ����(�������� ������ ����)
	for (int i = number - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = i;
		do {
			c = 2 * root + 1;
			// �ڽ� �߿� �� ū ���� ã��
			if (heap[c] < heap[c + 1] && c < i - 1) {
				c++;
			}
			// ��Ʈ���� �ڽ��� �� ũ�ٸ� ��ȯ (A - HA! ������ ���� Ŀ�� root��带 �ǵڷ� �����ٰŴϱ� �̷������� �ʿ��Ѱ��̴�. )
			if (heap[root] < heap[c] && c < i) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}
	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}