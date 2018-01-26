#include<stdio.h>
#include<iostream>
#define M 110
#define N 10
using namespace std;
int c[N][M];
int result[M];
void calculate_subset_sum(int s[], int n, int m);

int main() {
	int arr[10] = { 6,9,13,14,20,21,22,30,49,55 };
	calculate_subset_sum(arr, N, M);
	return 0;
}

void calculate_subset_sum(int s[], int n, int m) {
	for (int i = 0; i < N; i++)	//확인 배열 초기화
		c[i][0] = 1;
	for (int i = 0; i < M; i++)
		c[0][i] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			c[i][j] = 0;
			
			if (j >= s[i - 1]) {	//포함하지 않는 원소보다 크고
				if (c[i - 1][j - s[i - 1]]) {	//그 수만큼 이전에 만족 했다면
					c[i][j] = 1;	//true
					//cout << i << "-" << j << " ";
				}
			}
			if (c[i - 1][j] == 1) {	//이전에 만족 한 값이 있었다면
				c[i][j] = 1;		//true
				//cout << i << "-" << j << " ";
			}
		}
	}
	
	if (c[N][M] == 1) {
		cout << "possible : ";
		int num = M;	//수 확인을 위한 초기화

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (num == 0)
					break;
				if (c[j][N - i] == 1|| c[j][num] == 1) {
					num -= s[N - i];
					cout << s[N - i] <<" ";
					break;
				}
			}
		}
	}
}