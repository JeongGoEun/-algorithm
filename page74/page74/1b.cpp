#include "header.h"
int pascalFunc(int x, int y);
/*   18. 01. 17 - 파스칼 재귀
	(행, 열)로 파악, 예외일때 잘 처리해주면 쉬움
*/
int main() {
	int k = 0;

	cout << "k를 입력하세요 : ";
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
		//이미 존재한다면
		return arr[x][y];
	}
	else {
		//이전의 왼쪽 값 + 오른쪽 값
		return arr[x][y] = pascalFunc(x-1, y) + pascalFunc(x-1, y - 1);
	}

}