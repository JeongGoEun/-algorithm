#include"헤더.h"
/* 18.01.09 - 문제 0.h : 부분 배열 최댓값 범위 찾기
	- 항상 정수에는 예외인 마이너스도 존재한다.(항상 인지하고 있기)
	- 조건 항상 최소화 하기 (최적 조건 찾기)
*/
int main() {
	int arr[8] = { -7,-6,9,4,1,8,2,3 };
	findMax(3, 8, arr);
}
void findMax(int p, int n, int* arr) {
	int leftMax = arr[0], rightMax = arr[p+1];
	int leftSum = 0, rightSum = 0;
	int n1 = 0, n2 = 0;

	for (int i = 0; i < p; i++) {	//왼쪽 범위
		if (leftSum < 0 ) {	//현재 합이 음수일 때 -> 더 작은 값에서 위치 변화
			if (leftMax<arr[i]) {
				leftMax = arr[i];
				n1 = i;
			}
		}
		else {	//현재 합이 양수일 때 -> 현재 위치의 합이 더 클 때 위치 변화
			if (leftMax + arr[i] > leftMax) {
				leftMax = leftMax + arr[i];
				n1 = i;
			}
		}
		leftSum += arr[i];
	}

	for (int i = p; i < n; i++) {	//오른쪽 범위
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

	cout << "i는 " << n1 << " j는 " << n2 << "입니다." << endl;
	return;
}