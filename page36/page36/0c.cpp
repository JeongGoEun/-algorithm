#include"헤더.h"
/*18.01.09 - 책p36쪽 0.c문제
	- 재귀 이용할 땐, 최대한 if문을 줄이도록 => 공통적인 부분은 밖으로 빼준다.(습관화 하기)
*/
int main() {
	int num = 0,cnt=0;
	cout << "숫자 입력 : ";
	cin >> num;

	bitCount(&num, &cnt);

	cout << "1의 갯수 : " << cnt << endl;
}
void bitCount(int* num, int* cnt) {
	if (*num == 0) {
		return;
	}
	else if((*num) % 2 == 1) {
		(*cnt)++;
	}
	(*num) /= 2;
	bitCount(num, cnt);
}