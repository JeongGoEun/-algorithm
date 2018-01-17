#include "header.h"
void Func(int n, int m,int* arr,int cur);
int main() {
	int n = 0, m = 0;
	cout << "n과 m을 입력하세요 : ";
	cin >> n >> m;

	int arr[100];
	Func(n, m, arr,0);

	return 0;
}
void Func(int n, int m, int* arr,int cur) {

	if (cur==m) {
		if (n == 0) {
			//딱 떨어지지 않은 수를 거르기 위해
			for (int i = 0; i < cur; i++)
				cout << arr[i] << " ";	//지금까지 저장 된 수 출력
			cout << endl;
			return;
		}
	}

	for (int i = 1; i <= n; i++) {
		//i를 1 -> 2 -> 3 ...으로 늘려가면서 재귀적으로 확인
		// 1-1-3, 1-2-2, 1-3-1, 2-1-2, ...
		arr[cur] = i;
		Func(n - i, m, arr, cur + 1);
	}
}