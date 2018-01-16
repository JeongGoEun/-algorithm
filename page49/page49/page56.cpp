#include "stdafx.h"
#include<stdio.h>
#include<iostream>
/*	18.01.10 - 56 3일 연속 지각을 하지 않을 확률
*/
using namespace std;
double fibo(int n);

int main() {
	printf("%f\n",fibo(20));	//20번 출근한다고 가정
}
double fibo(int n) {
	/*
	P(n) := n일간 출근했을 때, 한번도 혼나지 않을 확률 값

	P(n) = 1/2 * P(n-1) + 1/2 * 1/2 * P(n-2) + 1/2 * 1/2 * 1/2 * P(n-3)
	“첫날 안 지각했을 때” + “첫날 지각 & 둘째 날 안 지각했을 때” + “첫날 및 둘째 날 지각 & 셋째 날 안 지각했을 때”

	P(0) = P(1) = P(2) = 1
	*/
	if (n == 0 || n == 1 || n == 2) {
		return 1;
	}
	return 0.5*fibo(n - 1);
}