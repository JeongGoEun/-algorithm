#include"���.h"
/*18.01.09 - åp36�� 0.c����
	- ��� �̿��� ��, �ִ��� if���� ���̵��� => �������� �κ��� ������ ���ش�.(����ȭ �ϱ�)
*/
int main() {
	int num = 0,cnt=0;
	cout << "���� �Է� : ";
	cin >> num;

	bitCount(&num, &cnt);

	cout << "1�� ���� : " << cnt << endl;
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