#include "header.h"
double Func(int n, int k,int i);
/*	
	18.01.17- 1.8 추가문제 : n, k입력받아 i^k + ... + n^k를 구하는 프로그램
*/
int main() {
	int n = 0, k = 0;

	cout << "n과 k를 입력하세요 : ";
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