#include "header.h"
void Func(int n, int m,int* arr,int cur);
int main() {
	int n = 0, m = 0;
	cout << "n�� m�� �Է��ϼ��� : ";
	cin >> n >> m;

	int arr[100];
	Func(n, m, arr,0);

	return 0;
}
void Func(int n, int m, int* arr,int cur) {

	if (cur==m) {
		if (n == 0) {
			//�� �������� ���� ���� �Ÿ��� ����
			for (int i = 0; i < cur; i++)
				cout << arr[i] << " ";	//���ݱ��� ���� �� �� ���
			cout << endl;
			return;
		}
	}

	for (int i = 1; i <= n; i++) {
		//i�� 1 -> 2 -> 3 ...���� �÷����鼭 ��������� Ȯ��
		// 1-1-3, 1-2-2, 1-3-1, 2-1-2, ...
		arr[cur] = i;
		Func(n - i, m, arr, cur + 1);
	}
}