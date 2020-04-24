#include "LinkedList.h"


//1. ���ø� Ŭ������ Ȯ���ؾ���
//2. Stack�������� Delete �Լ� �������ؾ���
//����: first, current_size�� class�� ��� �����̱� ������ this �����͸� ����Ͽ� �����;���

//LinkedList class�� ��ӹ���

template <class T>
class Stack : public LinkedList<int> {
public:
	bool Delete(int &element) {
		//first�� 0�̸� false��ȯ
		if (this->first == 0)
			return false;

		Node *current = this->first;
		Node *previous = 0;

		// LinkedList�� �޸� Stack�� current�� ����Ű�� ���� ����
		
		this->first = this->first->link;

		element = current->data;
		delete current;
		current_size--;

		return true;
	}
};
