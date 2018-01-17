#include "header.h"
int pascalFunc(int x, int y);
/*   18. 01. 17 - �Ľ�Į ���
	(��, ��)�� �ľ�, �����϶� �� ó�����ָ� ����
*/
int main() {
	int k = 0;

	cout << "k�� �Է��ϼ��� : ";
	cin >> k;

	for (int i = 0; i < k; i++) {
		for (int j = 0; j <= i; j++) {
			printf("  %d", pascalFunc(i, j));
		}
		cout << endl;
	}
	return 0;
}
int pascalFunc(int x, int y) {
	static int arr[30][30];

	if (x == 0 || y == 0 || x == y) {
		return arr[x][y] = 1;
	}
	if (arr[x][y] != 0) {
		//�̹� �����Ѵٸ�
		return arr[x][y];
	}
	else {
		//������ ���� �� + ������ ��
		return arr[x][y] = pascalFunc(x-1, y) + pascalFunc(x-1, y - 1);
	}

}