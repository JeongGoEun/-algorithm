#include "stdafx.h"
#include<stdio.h>
#include<iostream>
using namespace std;
void print_gray(int* code, int n, int index);
void print_gray_reverse(int* code, int n, int index);
void print_code(int *code, int length);
int main()
{
	int n = 0;
	int code[20];
	memset(code, 0, sizeof(int) * 20);

	cout << "input bit num : ";
	cin >> n;

	print_gray(code, n, 0);

    return 0;
}
void print_gray(int* code, int n, int index) {	
	if (index == n) {
		print_code(code, n);
		return;
	}
	code[index] = 0;
	print_gray(code, n, index + 1);

	code[index] = 1;
	print_gray_reverse(code, n, index + 1);

}
void print_gray_reverse(int* code, int n, int index) {	//����
	if (index == n) {
		print_code(code, n);
		return;
	}

	code[index] = 1;
	print_gray(code, n, index + 1);

	code[index] = 0;
	print_gray_reverse(code, n, index + 1);
}
void print_gray2(int* code, int n, int index, int reverse) {
	//print_gray + print_gray_reverse
	if (index == n) {
		print_code(code, n);
		return;
	}
	//0�� 1�� �ݺ��ؼ� 
	
	code[index] = reverse;
	print_gray2(code, n, index + 1,reverse);

	code[index] = 1-reverse;	//0�� �� -> 1, 1�� �� ->0 ���� ==> ������ ���� �� �� �ֵ���
	print_gray2(code, n, index + 1,reverse);
}
void print_code(int *code, int length) {
	for (int i = 0; i < length; i++)
		cout << code[i] << " ";
	cout << endl;
}

