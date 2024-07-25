#include "Queue.h"

// Добавление элемента в конец контейнера. В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
int Queue::push(void* elem, size_t size) {
	if (elem == NULL) {
		return 1;
	}
	return list2_->push_back(elem, size);
}

// Удаление элемента из начала контейнера. В случае успешного удаление функция возвращает значение 0, в случае неудачи 1.
int Queue::pop() {
	if (list2_->empty()) {
		return 1;
	}
	list2_->pop_front();
	return 0;
}

// Функция явно возвращает указатель на элемент, находящийся в начале контейнера.
// и не явно возвращает размер данных
void* Queue::front(size_t& size) {
	if (list2_->empty()) {
		return NULL;
	}
	return list2_->front(size);
}

// Функция явно возвращает указатель на элемент, находящийся в конце контейнера.
// и неявно возвращает размер данных
void* Queue::back(size_t& size) {
	if (list2_->empty()) {
		return NULL;
	}
	return list2_->back(size);
}

// Добавление элемента в позицию, на которую указывает итератор iter.
// В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
int Queue::insert(Iterator* iter, void* elem, size_t size) {
	if (list2_->empty()) {
		return 1;
	}
	QueueIterator* tmpIt =(QueueIterator*)iter;
	return list2_->insert(tmpIt->getListIterator(), elem, size);
}

// Возврашает явно указатель на элемент, на который указывает итератор в данный момент.
// Неявно возвращает размер данных.
// Если итератор показывает за пределы контейнера (например, удален последний элемент), возвращает NULL.
void* Queue::QueueIterator::getElement(size_t& size) {
	if (list2_->empty()) {
		return NULL;
	}
	return iterator->getElement(size);
}

// Возвращает true, если есть следующий элемент, иначе false.
bool Queue::QueueIterator::hasNext() {
	if (list2_->empty()) {
		return NULL;
	}
	return iterator->hasNext();
}

// Переход к следующему элементу.
void Queue::QueueIterator::goToNext() {
	return iterator->goToNext();
}

// проверка на равенство итераторов
bool Queue::QueueIterator::equals(Iterator* right) {
	if (list2_->empty()) {
		return NULL;
	}
	return iterator->equals(right);
}

//для счетчика 
int Queue:: size() {
	return list2_->size();
}

// Функция возвращает значение, равное максимальной вместимости контейнера в байтах.
size_t Queue::max_bytes() {
	return 0;
}

// Функция создает в динамической памяти итератор, указывающий на первый найденный
// в контейнере элемент. Если элемент не найден, возвращается пустой указатель.
// Удаление этого итератора должно делаться пользователем с помощью оператора delete.
Container::Iterator* Queue::find(void* elem, size_t size) {
	return list2_->find(elem, size);
}

// Функция создает в динамической памяти итератор, указывающий на первый элемент
// контейнера. Если контейнер пустой, возвращается нулевой указатель.
// Удаление этого итератора должно делаться пользователем с помощью оператора delete.
Container::Iterator* Queue::newIterator() {
	if (list2_ != NULL) {
		if (!list2_->empty()) {
			QueueIterator* a = new QueueIterator(this);

			return (Container::Iterator*)a;
		}
	}
	return NULL;
}

// Удаление элемента из позиции, на которую указывает итератор iter.
// После удаления итератор указывает на следующий за удаленным элемент.
void Queue::remove(Iterator* iter) {
	Iterator_for_list* itl = ((QueueIterator*)iter)->getListIterator();
	list2_->remove(itl);
}

// Удаление всех элементов из контейнера.
void Queue::clear() {
	list2_->clear();
}

// Если контейнер пуст возвращает true, иначе false
bool Queue::empty() {
	return list2_->empty();
}