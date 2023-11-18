//deque�� �پ��� ����, ������ ����Ʈ ����
//https://blockdmask.tistory.com/73

#include <iostream>
#include <deque>
using namespace std;

int N;
deque<int> dq;

void print_dq()
{
	cout << "dq�� ���� : ";
	for (int i = 0; i < dq.size(); i++)
		cout << dq.at(i) << " ";
}

int main() {
	cout << "\ndq�� 1~3���� ����\n";
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	print_dq(); // 1 2 3

	cout << "\n\ndq�� 1��° ��ġ�� 4 ����\n";
	dq.insert(dq.begin() + 1, 4);
	print_dq(); // 1 4 2 3

	cout << "\n\ndq�� ù��°�� ������ ���� ����\n";
	dq.pop_front();
	dq.pop_back();
	print_dq(); // 4 2

	cout << "\n\ndq�� ù��°�� ������ ���ҿ� ���� 5�� 6 ����\n";
	dq.push_front(5);
	dq.push_back(6);
	print_dq(); // 5 4 2 6

	cout << "\n\ndq ���� ��ü clear!\n";
	dq.clear();
	print_dq(); // empty
}