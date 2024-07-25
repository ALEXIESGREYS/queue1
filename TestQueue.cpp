#include "TestQueue.h"

TestQueue :: TestQueue(int count, size_t busy_plase) {
	Mem* test = new Mem(5000);
	a = new Queue(*test);
	kolvo = count;
}

TestQueue:: ~TestQueue() {
	delete a;
}

int TestQueue::find(int num)
{
	size_t size = 0;
	for (int i = 0; i < num; i++) {
		Container::Iterator* it = a->find(&i, sizeof(i));//проверка фаинд
	}
	return 0;
}

int TestQueue::push() {
	size_t size = 0;
	for (int i = 0; i < kolvo; i++) {//создаем элементы в потом контейнере
		int tar = a->push(&i, sizeof(i));
		if (tar != 0) {//та самая проверка
			return 1;
		}
		//Container::Iterator* it = a->find(&i, size);//проверка фаинд
		//if (it == NULL) {
		//	return 1;
		//}
	}
	find(kolvo);

	return 0;
}

int TestQueue:: pop(int num) {
	size_t size =0 ;
	for (int i = 0; i < num; i++) {// удаление элементов из кон
		int res = a->pop();
		if (res != 0)
			return res;
		//Container::Iterator* it = a->find(&i, size);//проверка фаинд
		//if (it != NULL) {
		//	return 1;
		//}
	}
	find(kolvo);
	return 0;
}

int TestQueue::front() {// 
	size_t size, _size;
	Queue::QueueIterator* it = (Queue::QueueIterator*)a->newIterator();
	if (it == NULL) {
		return 1;
	}
	void* tmp = it->getElement(size);//указывает на 1
	void* _tmp = a->front(_size);// берет первый
	if (memcmp(tmp, _tmp, _size) == 0) {
		return 0;
	}
	return 1;
}

int TestQueue::back() {
	size_t size, _size;
	Queue::QueueIterator* it = (Queue::QueueIterator *)a->newIterator();
	if (it == NULL)
		return 1;
	while (it->hasNext()) {
		it->goToNext();
	}
	void* tmp = it->getElement(size);
	void* _tmp = a->back(_size);
	if (memcmp(tmp, _tmp, _size) == 0) {
		return 0;
	}
	return 1;
}

/*int TestQueue::insert(int num1) {
	Queue::QueueIterator* it = (Queue::QueueIterator*)a->newIterator();// дочерний класс
	if (it != NULL) {
		if (it->hasNext())
			it->goToNext();
		int k = 0;
		if (a->insert((Container::Iterator*)it, &k, sizeof(k)) == 0) {
			if (it->hasNext())
				it->goToNext();
			for (int i = 1; i < num1; i++) {
				if (a->insert((Container::Iterator*)it, &i, sizeof(i)) == 0) {
					if (a->find(&i, sizeof(i)) == NULL) {
						delete it;
						return 1;
					}
				}
			}
			delete it;
			return 0;
		}
	}
	else
	{
		for (int i = 0; i < num1; i++) {//создаем элементы в потом контейнере
			int tar = a->push(&i, sizeof(i));
			if (tar != 0) {//та самая проверка
				printf("%d ", tar);
				return 1;
			}
		}
	}
	if (it != NULL) {
		delete it;
	}
	find(num1);
	return 1;

		
		
}*/

int TestQueue::insert(int num1) {
	int num = num1;
	Queue::QueueIterator* it = (Queue::QueueIterator*)a->newIterator();
	int tmp = num - 1;
	size_t size;
	
	for (int i = 0; i < num; i++) {//создаем элементы в потом контейнере
		int tar = a->push(&i, sizeof(i));
		if (tar != 0) {//та самая проверка
			return 1;
		}
	}

	while (it->hasNext()) {
		it->goToNext();
		void* num = it->getElement(size);
		if (*(int*)num != tmp) {
			printf("error 1");
			printf(" %d ", tmp);
			return 1;
		}
		else {
			tmp--;
		}
	}
	printf("*** %d ok ", tmp);
	return 0;
}



int TestQueue::size() {
	return a->size();
}

size_t max_bytes();

int TestQueue::remove(int count) {
	Container::Iterator * it = a->newIterator();
	if (it == NULL){
		return 1;
		}
	for (int i = 0; i < count; i++) {
		a->remove(it);
		it->goToNext();
		if (a->find(&i, sizeof(i)) == NULL) {
			return 1;
		}
	}
	return 0;
}

int TestQueue::clear() {
	a->clear();
	if (empty()) {
		return 0;
	}
	return 1;
}

bool TestQueue::empty() {
	bool empty = a->empty();
	Container::Iterator* q = a->newIterator();
	if (q == NULL) {
		return empty ? true : false;
	}
	if (q != NULL) {
		if (empty) {
			return false;
		}
		return true;
	}
	return empty;
}

int TestQueue::remove2(int flag)
{
	Queue::QueueIterator* it = (Queue::QueueIterator*)a->newIterator();
	if (it == NULL) {
		return 1;
	}
	bool k = false;
	for (int i = 0; i < kolvo; i++) {
		if (flag == 1)
		{
			if (i % 2 != 0)
			{
				a->remove((Container::Iterator*)it);
				continue;
			}
			
		}
		else if (flag == 2)
		{
			if (i % 2 == 0)
			{
				a->remove((Container::Iterator*)it);
				continue;
			}
			
		}
		else
		{
			a->remove((Container::Iterator*)it);
			continue;
		}
		if(it->hasNext())
			it->goToNext();
	}
	find(kolvo);
	return 0;
}