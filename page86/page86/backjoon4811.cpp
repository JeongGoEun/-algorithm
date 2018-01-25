#include<stdio.h>
#include<iostream>
#define MAX 100
using namespace std;
int calculate(char* input, int index,int cur,int length);
int main() {
	char* input = new char[MAX];
	int l = 0;
	memset(input, 0, sizeof(char)*MAX);

	cin >> input;
	while (input[l] != 0)
		l++;

	printf("%d\n", calculate(input, 0,0, l));


}
int calculate(char* input, int index, int cur, int length) {
	
}