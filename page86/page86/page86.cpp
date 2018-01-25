#include<stdio.h>
#include<iostream>
using namespace std;
//void getDistance(int** arr,int** path,int i,int j, int n);	//My Code
long long getDistance(int n1,int n2,int **arr);
int n = 0;
int main() {
	cout << "배열 수 입력 : ";
	cin >> n;

	int** arr = new int*[n], **path= new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = (int *)malloc(sizeof(int)*n);
		memset(arr[i], 0, sizeof(int)*n);

		path[i] = (int *)malloc(sizeof(int)*n);
		memset(path[i], 0, sizeof(int)*n);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	printf("총거리 : %lld\n",getDistance(n-1,n-1,arr));
}
long long getDistance(int n1, int n2, int **arr) {

	if (n1 == 0 && n2 == 0)	//처음
		return 1;
	if (arr[n1][n2] == 0)	//갈 수 없는 곳
		return 0;

	return ((n1 > 0) ? getDistance(n1 - 1, n2, arr) : 0) + ((n2 > 0) ? getDistance(n1, n2 - 1, arr) : 0);
	// 세로가 0보다 크다면 -> 세로 이전 값 가져옴 + 가로가 0보다 크다면 -> 가로 이전 값 가져옴
}
void calculate_path(int m, int n,int** arr,int** path) {
	//Dynamic Programming - 동적계획법
	path[0][0] = arr[0][0];
	for (int i = 1; i < n; i++) {
		if (arr[i][0] != 0)
			path[i][0] = arr[i - 1][0];
		else
			path[i][0] = 0;
	}
	for (int j = 1; j < n; j++) {
		if (arr[0][j] != 0) 
			path[0][j] = path[0][j - 1];
		else
			path[0][j] = 0;
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[i][j] != 0)
				path[i][j] = path[i - 1][j] + path[i][j - 1];
			else
				path[i][j] = 0;
		}
	}

	return;
}
/*void getDistance(int** arr, int** path, int i, int j,int n) {
	if (i == n && j == n) {
		return;
	}
	else if (i == n)
		i = 0;
	else if (j == n)
		j = 0;

	if (i == 0 && j == 0) {
		path[i][j] = 1;
		cout << path[i][j] << " " << i << " " << j << endl;
		getDistance(arr, path, i, j + 1,n);
	}
	else if (i > 0 && j == 0 || i == 0 && j > 0) {
		if (arr[i][j] != 0) {
			path[i][j] = 1;
			cout << path[i][j] << " " << i << " " << j << endl;
		}
		if (j != n - 1)
			getDistance(arr, path, i, j + 1, n);
		else
			getDistance(arr, path, i + 1, j + 1, n);
	}
	else if (i > 0 && j > 0) {
		if (arr[i][j] != 0) {
			path[i][j] = path[i - 1][j] + path[i][j - 1];
			cout << path[i][j] << " " << i << " " << j << endl;
		}
		if (j != n - 1)
			getDistance(arr, path, i, j + 1, n);
		else
			getDistance(arr, path, i + 1, j + 1, n);
	}
}*/