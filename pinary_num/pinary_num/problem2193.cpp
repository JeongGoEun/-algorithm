#include<iostream>
using namespace std;
int main() {
	long long arr[91];
	int input = 0;

	cin >> input;

	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= input; i++) {
		arr[i]= arr[i - 1] + arr[i-2];
	}
	cout << arr[input]<<endl;
}