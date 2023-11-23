//deque의 다양한 사용법, 다음의 사이트 참고
//https://blockdmask.tistory.com/73

#include <iostream>
#include <deque>
using namespace std;

int N;
deque<int> dq;

void print_dq()
{
	cout << "dq의 원소 : ";
	for (int i = 0; i < dq.size(); i++)
		cout << dq.at(i) << " ";
}

int main() {
	cout << "\ndq에 1~3까지 삽입\n";
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	print_dq(); // 1 2 3

	cout << "\n\ndq의 1번째 위치에 4 삽입\n";
	dq.insert(dq.begin() + 1, 4);
	print_dq(); // 1 4 2 3

	cout << "\n\ndq의 첫번째와 마지막 원소 삭제\n";
	dq.pop_front();
	dq.pop_back();
	print_dq(); // 4 2

	cout << "\n\ndq의 첫번째와 마지막 원소에 각각 5와 6 삽입\n";
	dq.push_front(5);
	dq.push_back(6);
	print_dq(); // 5 4 2 6

	cout << "\n\ndq 원소 전체 clear!\n";
	dq.clear();
	print_dq(); // empty
}