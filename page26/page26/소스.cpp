/*18. 01. 08 - 문제로 풀어보는 알고리즘(p. 26~30)
	- 배열을 queue로 구현 -> circular queue로 구현
*/
#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct queue
{
	int arr[8];
	int size = 0;
	int head = 0;
	int tail = -1;
};

void enqueue(queue* Q,int n);
void dequeue(queue* Q);

int main() {
	queue *Q=new queue();
	memset(Q->arr, 0, sizeof(int) * 8);
	int num = 0;
	do {
		cin >> num;
		if (num != 0) {
			enqueue(Q, num);
		}
		else {
			dequeue(Q);
		}
	} while (num >= 0);
}
void enqueue(queue* Q, int n) {
	if (Q->size == 8) {
		cout << "queue full!" << endl;
	}
	else {
		Q->tail = ((Q->tail)+1)% 8;	//tail을 하나씩 늘려가면서 순회하도록
		(Q->size)++;
		Q->arr[Q->tail] = n;
	}
}
void dequeue(queue* Q) {
	if (Q->size == 0) {
		cout << "queue empty!" << endl;
	}
	else {
		cout << "[ " << Q->arr[Q->head] << " ]" << endl;
		Q->arr[Q->head] = 0;
		Q->head = ((Q->head) + 1) % 8;	//head를 하나씩 늘려가면서 순회하도록
		(Q->size)--;
	}
}

/*void myFunc() {
	//처음에 구현했던 함수
	- if문이 너무 많다, 전역은 되도록이면 사용X, 다시 활용 할 수 있는 방법을 생각하자.

	int cur = 0, input = 0;
	cout << "input number : ";
	cin >> input;

	while (input >= 0) {
		if (input != 0) {	//enqueue
			if (cur == 8) {
				cout << "queue full!" << endl;
			}
			else {
				arr[cur++] = input;
				cout << cur << endl;
			}
		}
		else {	//dequeue
			if (cur == 0) {
				cout << "queue empty!" << endl;
			}
			else {
				cout << "[ " << arr[0] << " ]" << endl;

				for (int i = 0; i < cur; i++) {	//left rotate : 배열의 크기가 크다면 시간이 오래 걸린다.
					arr[i] = arr[i + 1];
				}
				cur--;
			}
		}
		cout << "input number : ";
		cin >> input;
	}
	cout << "프로그램 종료 : ";
}*/