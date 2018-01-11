#include "stdafx.h"
#include<stdio.h>
#include<iostream>
using namespace std;
/*	18.01.11 - ���� p61 �����غ��� - �����ϴ� ��� ��� ���
- ������ �ɰ��� ���� �� ����.
*/
int partition(int n, int m,int arr_len,int* arr);
int partition2(int n);
int main() {
	int n = 0, m = 0;
	int arr_len = 0, arr[20];
	memset(arr, 0, sizeof(int) * 20);

	cout << "int n, m : ";
	cin >> n >> m;

	cout << "�� ���� : " << partition(n, m,arr_len,arr) << endl;

	cout << "������ �ִ� ������ �� ���� : " << partition2(4) << endl;

}
int partition(int n, int m, int arr_len, int* arr) {	//print�� ���� - ��� �� ��ŭ �迭�� �����ؼ� ���
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
		cnt += partition(n - i,i, arr_len+1,arr);	//++�� ó���ϸ� ��Ͱ� ���������� �ȴ�.
	}

	return cnt;
}

int partition2(int n) {
	int cnt = 0;
	
	for (int i = 1; i <n-1; i++) {
		cnt += partition2(n - i);	//n�� ���� �������� ��ͷ� ���Ѵ�.
	}
	return cnt + 1;	//���� �����Ұ� �ڱ� �ڽ�(n+0)�� ���� ���� return�Ѵ�.
}

/*void memoizationFunc(int n, int m) { - �ߺ��� ���� ���� �޸������̼� ���� �Լ�
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