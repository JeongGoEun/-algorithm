#include"���.h"
/* 18.01.09 - ���� 0.h : �κ� �迭 �ִ� ���� ã��
	- �׻� �������� ������ ���̳ʽ��� �����Ѵ�.(�׻� �����ϰ� �ֱ�)
	- ���� �׻� �ּ�ȭ �ϱ� (���� ���� ã��)
*/
int main() {
	int arr[8] = { -7,-6,9,4,1,8,2,3 };
	findMax(3, 8, arr);
}
void findMax(int p, int n, int* arr) {
	int leftMax = arr[0], rightMax = arr[p+1];
	int leftSum = 0, rightSum = 0;
	int n1 = 0, n2 = 0;

	for (int i = 0; i < p; i++) {	//���� ����
		if (leftSum < 0 ) {	//���� ���� ������ �� -> �� ���� ������ ��ġ ��ȭ
			if (leftMax<arr[i]) {
				leftMax = arr[i];
				n1 = i;
			}
		}
		else {	//���� ���� ����� �� -> ���� ��ġ�� ���� �� Ŭ �� ��ġ ��ȭ
			if (leftMax + arr[i] > leftMax) {
				leftMax = leftMax + arr[i];
				n1 = i;
			}
		}
		leftSum += arr[i];
	}

	for (int i = p; i < n; i++) {	//������ ����
		if (rightSum < 0) {
			if (rightMax<arr[i]) {
				rightMax = arr[i];
				n2 = i;
			}
		}
		else {
			if (rightMax + arr[i] > rightMax) {
				rightMax = rightMax + arr[i];
				n2 = i;
			}
		}
		rightSum += arr[i];
	}

	cout << "i�� " << n1 << " j�� " << n2 << "�Դϴ�." << endl;
	return;
}