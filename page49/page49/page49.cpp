#include "stdafx.h"
#include<stdio.h>
#include<iostream>
/*	18.01.10 - 49 nCr 재귀적으로 구하기
	- 재귀는 무조건 stack, tree 생각하기.
	- 전역, 정적 배열은 자동으로 초기화 된다.
	- 재귀는 중복을 최소화 해야한다.
*/
using namespace std;
long long choose(int n, int r);
int main()
{
	int n = 0, r = 0;
	cout << "input n, r : ";
	cin >> n >> r;

	long long rtn = choose(n, r);
	printf("%lld\n", rtn);
    return 0;
}
long long choose(int n, int r) {
	//중복이 없는 계산
	static long long arr[200][200];

	if (arr[n][r] > 0) 	//이미 값을 아는 상태
		return arr[n][r];
	
	if (r == 0 || n == r)
		return 1;

	return arr[n][r] = choose(n - 1, r - 1) + choose(n - 1, r);
	
	/* - 중복이 있는 계산
	if (r == 0 || n == r)
		return 1;
	else
		return choose(n - 1, r - 1) + choose(n - 1, r);
	*/
}

/*void myFunc(int n, int r) {
	if (n == 1) {
		return 1;
	}
	else if (r > 0) {
		long long n1 = 1, n2 = 1;
		for (int i = n - 1; i >= r; i--)
			n1 *= i;
		for (int i = r - 1; i >= 1; i--)
			n2 *= i;

		return (n1 / n2) + choose(n - 1, r);
	}
}*/

