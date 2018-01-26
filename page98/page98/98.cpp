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
	for (int i = 0; i < N; i++)	//Ȯ�� �迭 �ʱ�ȭ
		c[i][0] = 1;
	for (int i = 0; i < M; i++)
		c[0][i] = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			c[i][j] = 0;
			
			if (j >= s[i - 1]) {	//�������� �ʴ� ���Һ��� ũ��
				if (c[i - 1][j - s[i - 1]]) {	//�� ����ŭ ������ ���� �ߴٸ�
					c[i][j] = 1;	//true
					//cout << i << "-" << j << " ";
				}
			}
			if (c[i - 1][j] == 1) {	//������ ���� �� ���� �־��ٸ�
				c[i][j] = 1;		//true
				//cout << i << "-" << j << " ";
			}
		}
	}
	
	if (c[N][M] == 1) {
		cout << "possible : ";
		int num = M;	//�� Ȯ���� ���� �ʱ�ȭ

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