#include "header.h"
double Func(int n, int k,int i);
/*	
	18.01.17- 1.8 �߰����� : n, k�Է¹޾� i^k + ... + n^k�� ���ϴ� ���α׷�
*/
int main() {
	int n = 0, k = 0;

	cout << "n�� k�� �Է��ϼ��� : ";
	cin >> n >> k;

	printf("%d\n",(int)Func(n, k, 1));
	return 0;
}
double Func(int n, int k,int i) {
	if (i == n) {
		return pow((double)n, (double)k);
	}
	return pow((double)i, (double)k)+Func(n, k, i+1);
}