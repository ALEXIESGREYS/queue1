#include "List2.h"
#include "Mem.h"

void start() {
	int kolvo = 5;
	Mem a(10);
	List2 tmp = List2(a);

	for (int i = 0; i < kolvo; i++) { // добавляем в начало пустого листа 5 элементов 
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
	if (tmp.empty())// проверка на наличие элементов в листе
		cout << "list is empty";
	else {
		cout << "list isn't empty" << endl;
	}

	int _size = tmp.size();//колво элементов
	cout << "size = " << _size << endl;
	cout << endl;

	delete b;
	tmp.clear();// очищаем лист что бы потом создать грубо говоря новый

	for (int i = 0; i < kolvo; i++) {// добавляем в конец элементы 
		tmp.push_back(&i, sizeof(i));
	}
	Iterator_for_list* c = (Iterator_for_list*)tmp.newIterator();
	for (int i = 0; i < tmp.size(); i++) {
		cout << *(int*)c->getElement(size) << endl;
		c->goToNext();
	}
	delete c;
	cout << endl;

	tmp.pop_back();//удаляем с конца и начала по 1 элементу
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
	cout << tmp.insert(w, &elem, sizeof(elem)) << endl;//сдвинуть итератора и коменты + 
}