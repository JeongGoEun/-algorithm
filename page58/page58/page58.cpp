#include "stdafx.h"
#include<stdio.h>
#include<iostream>
using namespace std;
/*	18.01.11 - 문제 p61 생각해보기 - 지불하는 방법 모두 출력
	- 문제를 쪼개서 생각 해 보기.
*/

int pay(int m, int* bills, int* print_arr,int n);
int main()
{
	int n = 0, m = 0;
	cout << "input size : ";
	cin >> n;
	int *arr = new int[n];
	int *print_arr = new int[n];
	cout << "input number : ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << "input money : ";
	cin >> m;

	cout << "result : " << pay(m, arr,print_arr,n);	//m(돈)을 n가지로 나타낼 수 있는 cnt를 계산
	return 0;
}
int pay(int m, int* bills, int* print_arr, int n) {
	int cnt = 0;
	if (n == 1) {
		if (m % bills[n - 1] == 0) {
			print_arr[n - 1] = m / bills[n - 1];	//마지막 경우의 수 저장

			for (int i = 0; i < 6; i++)
				cout<<print_arr[i]<<"-";	//각각 경우의 수 갯수 출력
			cout << endl;
			return 1;
		}
		else
			return 0;
	}

	int t = m / bills[n - 1];	//문제를 쪼개서 생각
	
	for (int i = 0; i <= t; i++) {
		print_arr[n - 1] = i;	//갯수 저장을 위한 배열
		cnt += pay(m - bills[n - 1] * i, bills,print_arr, n - 1);	//쪼갠 단위를 다시 재귀
	}

	return cnt;
}

