#include "Queue.h"

// ���������� �������� � ����� ����������. � ������ ��������� ���������� ������� ���������� �������� 0, � ������ ������� 1.
int Queue::push(void* elem, size_t size) {
	if (elem == NULL) {
		return 1;
	}
	return list2_->push_back(elem, size);
}

// �������� �������� �� ������ ����������. � ������ ��������� �������� ������� ���������� �������� 0, � ������ ������� 1.
int Queue::pop() {
	if (list2_->empty()) {
		return 1;
	}
	list2_->pop_front();
	return 0;
}

// ������� ���� ���������� ��������� �� �������, ����������� � ������ ����������.
// � �� ���� ���������� ������ ������
void* Queue::front(size_t& size) {
	if (list2_->empty()) {
		return NULL;
	}
	return list2_->front(size);
}

// ������� ���� ���������� ��������� �� �������, ����������� � ����� ����������.
// � ������ ���������� ������ ������
void* Queue::back(size_t& size) {
	if (list2_->empty()) {
		return NULL;
	}
	return list2_->back(size);
}

// ���������� �������� � �������, �� ������� ��������� �������� iter.
// � ������ ��������� ���������� ������� ���������� �������� 0, � ������ ������� 1.
int Queue::insert(Iterator* iter, void* elem, size_t size) {
	if (list2_->empty()) {
		return 1;
	}
	QueueIterator* tmpIt =(QueueIterator*)iter;
	return list2_->insert(tmpIt->getListIterator(), elem, size);
}

// ���������� ���� ��������� �� �������, �� ������� ��������� �������� � ������ ������.
// ������ ���������� ������ ������.
// ���� �������� ���������� �� ������� ���������� (��������, ������ ��������� �������), ���������� NULL.
void* Queue::QueueIterator::getElement(size_t& size) {
	if (list2_->empty()) {
		return NULL;
	}
	return iterator->getElement(size);
}

// ���������� true, ���� ���� ��������� �������, ����� false.
bool Queue::QueueIterator::hasNext() {
	if (list2_->empty()) {
		return NULL;
	}
	return iterator->hasNext();
}

// ������� � ���������� ��������.
void Queue::QueueIterator::goToNext() {
	return iterator->goToNext();
}

// �������� �� ��������� ����������
bool Queue::QueueIterator::equals(Iterator* right) {
	if (list2_->empty()) {
		return NULL;
	}
	return iterator->equals(right);
}

//��� �������� 
int Queue:: size() {
	return list2_->size();
}

// ������� ���������� ��������, ������ ������������ ����������� ���������� � ������.
size_t Queue::max_bytes() {
	return 0;
}

// ������� ������� � ������������ ������ ��������, ����������� �� ������ ���������
// � ���������� �������. ���� ������� �� ������, ������������ ������ ���������.
// �������� ����� ��������� ������ �������� ������������� � ������� ��������� delete.
Container::Iterator* Queue::find(void* elem, size_t size) {
	return list2_->find(elem, size);
}

// ������� ������� � ������������ ������ ��������, ����������� �� ������ �������
// ����������. ���� ��������� ������, ������������ ������� ���������.
// �������� ����� ��������� ������ �������� ������������� � ������� ��������� delete.
Container::Iterator* Queue::newIterator() {
	if (list2_ != NULL) {
		if (!list2_->empty()) {
			QueueIterator* a = new QueueIterator(this);

			return (Container::Iterator*)a;
		}
	}
	return NULL;
}

// �������� �������� �� �������, �� ������� ��������� �������� iter.
// ����� �������� �������� ��������� �� ��������� �� ��������� �������.
void Queue::remove(Iterator* iter) {
	Iterator_for_list* itl = ((QueueIterator*)iter)->getListIterator();
	list2_->remove(itl);
}

// �������� ���� ��������� �� ����������.
void Queue::clear() {
	list2_->clear();
}

// ���� ��������� ���� ���������� true, ����� false
bool Queue::empty() {
	return list2_->empty();
}