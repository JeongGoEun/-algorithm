#include "stdafx.h"
#include<stdio.h>
#include<iostream>
using namespace std;
/*	18.01.11 - 문제 p61 생각해보기 - 지불하는 방법 모두 출력
- 문제를 쪼개서 생각 해 보기.
*/
int partition(int n, int m,int arr_len,int* arr);
int partition2(int n);
int main() {
	int n = 0, m = 0;
	int arr_len = 0, arr[20];
	memset(arr, 0, sizeof(int) * 20);

	cout << "int n, m : ";
	cin >> n >> m;

	cout << "총 갯수 : " << partition(n, m,arr_len,arr) << endl;

	cout << "순서가 있는 수분할 총 갯수 : " << partition2(4) << endl;

}
int partition(int n, int m, int arr_len, int* arr) {	//print도 구현 - 재귀 한 만큼 배열에 저장해서 출력
	int cnt = 0;
	
	if (n < m) {
		m = n;
	}

	if (n == 0) {
		for (int i = 0; i < arr_len; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
		return 1;
	}

	for (int i = 1; i <= m; i++) {
		arr[arr_len] = i;
		cnt += partition(n - i,i, arr_len+1,arr);	//++로 처리하면 재귀가 종속적으로 된다.
	}

	return cnt;
}

int partition2(int n) {
	int cnt = 0;
	
	for (int i = 1; i <n-1; i++) {
		cnt += partition2(n - i);	//n의 하위 수분할을 재귀로 구한다.
	}
	return cnt + 1;	//하위 수분할과 자기 자신(n+0)을 더한 값을 return한다.
}

/*void memoizationFunc(int n, int m) { - 중복을 막기 위한 메모이제이션 적용 함수
	static int arr[200][200];
	int cnt = 0;
	if (arr[n][m] > 0)
	return arr[n][m];
	if (n < m) {
	m = n;
	}

	if (n == 0) {
	cout << endl;
	return arr[n][m]=1;
	}

	for (int i = 1; i <= m; i++) {
	cout << i <<" ";
	cnt += partition(n - i, i);
	}

	return arr[n][m] = cnt;
}*/