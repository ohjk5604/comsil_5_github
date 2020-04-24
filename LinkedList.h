#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
class Node {
public:
	//�����͸� ������ ����
	int data;
	//��屸��ü �̿�; ��������� �ּҸ� ������ ������
	Node *link;

	Node(int element) {
		data = element;
		link = 0;
	}
};

//LinkedList Class
template <class T>
class LinkedList {
protected:
	//ù��° ����� �ּҸ� ������ ������
	Node *first;
	int current_size;
public:
	//������, �ʱ�ȭ 
	LinkedList() {
		first = 0;
		current_size = 0;
	};

	//��� ������ ����
	int GetSize() {
		return current_size;
	};

	//�� �տ� ���Ҹ� ����, LinkedList�� Stack �Ѵ� ����
	void Insert(T element);

	//�� ���� ���Ҹ� ����, ���� ���߿� ���� ���� ����  - LinkedList
	virtual bool Delete(T &element);

	//����Ʈ ���
	void Print();
};


//�� ��带 �� �տ� ���̰� ���� ����
template <class T>
void LinkedList<T>::Insert(T element) {
	//��� ����
	Node *newnode = new Node(element);

	//�� ��尡 ù��° ��带 ����Ŵ
	//newnode�� �������̱� ������ -> �� ����� �Լ�, ������ �ҷ��� newnode.link�� ���� ����
	newnode->link = first;
	first = newnode;
	current_size++;
}

//������ ����� ���� �����ϸ鼭 �޸𸮿��� �Ҵ� ����
template <class T>
bool LinkedList<T>::Delete(T &element) {

	if (first == 0)
		return false;

	Node *current = first;
	Node *previous = 0;

	//������ ������ ã�ư��� �ݺ���
	while (1) {
		if (current->link == 0) {  //������ ��带 ã�°�
			if (previous)
				previous->link = current->link;
			else
				first = first->link;
			break;
		}
		previous = current;
		current = current->link;
	}
	element = current->data;
	delete current;
	current_size--;

	return true;
}

//����Ʈ�� ����ϴ� Print �Լ�
template <class T>
void LinkedList<T>::Print() {
	Node *i;
	int index = 1;

	if (current_size != 0) {
		for (i = first; i != NULL; i = i->link) {
			if (index == current_size) {
				cout << "[" << index << "|";
				cout << i->data << "]";
			}

			else {
				cout << "[" << index << "|";
				cout << i->data << "]";
				index++;
			}

			if (i->link != NULL)
			{
				cout << "->";
			}
		}
		cout << endl;
	}

}


#endif