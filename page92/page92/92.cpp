#include<stdio.h>
#include<iostream>
// ���� : �ִ� ��η� �ִ��� joy�� ���� �ִ� ��� ���ϱ�
#define M 100
#define N 100
using namespace std;

int map[M][N]= { { 1,2,2,1,5, },{ 1,0,4,3,1 },{ 2,1,1,1,2 },{ 1,3,0,1,1 },{ 1,5,1,2,2 } };
//0 -> ������ : ������ �� ����
int joy[M][N];
int from[M][N];
enum{LEFT,UP };
void print_path(int m, int n);
int max(int a, int b);
void calculate_joy(int m, int n);

int main() {
	int m, n, i, j;
	cin >> m >> n;
	calculate_joy(m, n);
	cout << joy[m - 1][n - 1] << endl;
	print_path(m - 1, n - 1);
}
void calculate_joy(int m, int n) {
	//Dynamic Programming
	joy[0][0] = map[0][0];

	for (int i = 1; i < M; i++) {
		if (map[i][0] == 0)
			joy[i][0] = 0;
		else {
			joy[i][0] = joy[i - 1][0] + map[i][0];
			from[i][0] = LEFT;
		}
	}
	for (int i = 1; i < N; i++) {
		if (map[0][i] == 0)
			joy[0][i] = 0;
		else {
			joy[0][i] = joy[0][i - 1] + map[0][i];
			from[0][i] = UP;
		}
	}
	for (int i = 1; i < M; i++) {	//����
		for (int j = 1; j < N; j++) {	//����
			if (map[i][j] == 0) {
				joy[i][j] = 0;
			}
			else {
				if (joy[i - 1][j] > joy[i][j - 1])	//�� ū�ʿ��� ���¹����� ���� ��
					from[i][j] = LEFT;
				else
					from[i][j] = UP;
				joy[i][j] = max(joy[i - 1][j], joy[i][j - 1]) + map[i][j];
			}
		}
	}
}
int max(int a, int b) {
	return a > b ? a : b;
}
void print_path(int m, int n) {	//��� �Լ�
	if (m == 0 && n == 0) {
		cout << "(" << m << "," << n << ") ";
		return;
	}
	if (from[m][n] == LEFT)
		print_path(m - 1, n);
	else
		print_path(m, n - 1);
	cout << "(" << m << "," << n << ") ";
}