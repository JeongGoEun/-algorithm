/*18. 01. 08 - ������ Ǯ��� �˰���(p. 26~30)
	- �迭�� queue�� ���� -> circular queue�� ����
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
		Q->tail = ((Q->tail)+1)% 8;	//tail�� �ϳ��� �÷����鼭 ��ȸ�ϵ���
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
		Q->head = ((Q->head) + 1) % 8;	//head�� �ϳ��� �÷����鼭 ��ȸ�ϵ���
		(Q->size)--;
	}
}

/*void myFunc() {
	//ó���� �����ߴ� �Լ�
	- if���� �ʹ� ����, ������ �ǵ����̸� ���X, �ٽ� Ȱ�� �� �� �ִ� ����� ��������.

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

				for (int i = 0; i < cur; i++) {	//left rotate : �迭�� ũ�Ⱑ ũ�ٸ� �ð��� ���� �ɸ���.
					arr[i] = arr[i + 1];
				}
				cur--;
			}
		}
		cout << "input number : ";
		cin >> input;
	}
	cout << "���α׷� ���� : ";
}*/