#include "stdafx.h"
#include<stdio.h>
#include<iostream>
/*	18.01.10 - 56 3�� ���� ������ ���� ���� Ȯ��
*/
using namespace std;
double fibo(int n);

int main() {
	printf("%f\n",fibo(20));	//20�� ����Ѵٰ� ����
}
double fibo(int n) {
	/*
	P(n) := n�ϰ� ������� ��, �ѹ��� ȥ���� ���� Ȯ�� ��

	P(n) = 1/2 * P(n-1) + 1/2 * 1/2 * P(n-2) + 1/2 * 1/2 * 1/2 * P(n-3)
	��ù�� �� �������� ���� + ��ù�� ���� & ��° �� �� �������� ���� + ��ù�� �� ��° �� ���� & ��° �� �� �������� ����

	P(0) = P(1) = P(2) = 1
	*/
	if (n == 0 || n == 1 || n == 2) {
		return 1;
	}
	return 0.5*fibo(n - 1);
}