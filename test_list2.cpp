#include "List2.h"
#include "Mem.h"

void start() {
	int kolvo = 5;
	Mem a(10);
	List2 tmp = List2(a);

	for (int i = 0; i < kolvo; i++) { // ��������� � ������ ������� ����� 5 ��������� 
		tmp.push_front(&i, sizeof(i));
	}
	size_t size= 0;
	Iterator_for_list* b = (Iterator_for_list*)tmp.newIterator();
	for (int i = 0; i < tmp.size(); i++) {
		cout << *(int*)b->getElement(size) << endl;
		if (b->hasNext())
			b->goToNext();
	}
	cout << endl;
	if (tmp.empty())// �������� �� ������� ��������� � �����
		cout << "list is empty";
	else {
		cout << "list isn't empty" << endl;
	}

	int _size = tmp.size();//����� ���������
	cout << "size = " << _size << endl;
	cout << endl;

	delete b;
	tmp.clear();// ������� ���� ��� �� ����� ������� ����� ������ �����

	for (int i = 0; i < kolvo; i++) {// ��������� � ����� �������� 
		tmp.push_back(&i, sizeof(i));
	}
	Iterator_for_list* c = (Iterator_for_list*)tmp.newIterator();
	for (int i = 0; i < tmp.size(); i++) {
		cout << *(int*)c->getElement(size) << endl;
		c->goToNext();
	}
	delete c;
	cout << endl;

	tmp.pop_back();//������� � ����� � ������ �� 1 ��������
	tmp.pop_front();
	Iterator_for_list* d = (Iterator_for_list*)tmp.newIterator();
	for (int i = 0; i < tmp.size(); i++) {
		cout << *(int*)d->getElement(size) << endl;
		d->goToNext();
	}
	cout << endl;
	cout << *(int*)tmp.front(size) << "   " << size << endl;

	cout << endl;
	cout << *(int*)tmp.back(size) << "   " << size << endl;
	delete d;
	cout << endl;

	Iterator_for_list* w = (Iterator_for_list*)tmp.newIterator();
	int elem = 8;
	cout << tmp.insert(w, &elem, sizeof(elem)) << endl;//�������� ��������� � ������� + 
}