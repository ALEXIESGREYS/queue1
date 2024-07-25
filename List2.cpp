#include "List2.h"
#include <memory.h>

int List2::push_back(void* elem, size_t elemSize) {
    if (busy_plase > _memory.size()) {
        return 1;
    }
    Uzel* new_block;
    if (elemSize <= 0) {
        return 1;
    }
     new_block = new Uzel();
    if (new_block == NULL) {
        return 1;
    }
    new_block->data = _memory.allocMem(elemSize);
    memcpy(new_block->data, elem, elemSize);
    new_block->size = elemSize;
    new_block->next = NULL;
    new_block->back = teil;
    if (teil != NULL) {
        teil->next = new_block;
    }
    teil = new_block;
    if (head == NULL) {
        head = teil;
    }
    count++;
    busy_plase += elemSize;
    return 0;
}

// Добавление элемента в начало контейнера.
// В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
int List2::push_front(void* elem, size_t elemSize) {
    if (busy_plase > _memory.size()) {
        return 1;
    }
    Uzel* first_block;

    if (elemSize <= 0) {
        return 1;
    }
    first_block = new Uzel();
    if (first_block == NULL) {
        return 1;
    }
    first_block->data = _memory.allocMem(elemSize);//выделение памяти
    memcpy(first_block->data, elem, elemSize);
    first_block->size = elemSize;
    first_block->next = head;
    first_block->back = NULL;

    if (head != NULL) {
        head->back = first_block;
    }
    head = first_block;
    if (teil == NULL) {
        teil = head;
    }
    count++;
    busy_plase += elemSize;
    return 0;
}

// Удаление элемента из конца контейнера
void List2:: pop_back() {
    if (teil == NULL) {
        return;
    }

    Uzel* new_teil;
    new_teil = teil->back;
    if (new_teil != NULL) {
        new_teil->next = NULL;
    }
    if (head == teil) {
        head = NULL;
    }
    busy_plase -= teil->size;
    delete teil;
    teil = new_teil;
    teil->next = NULL;
    count--;

}

// Удаление элемента из начала контейнера.+
void List2::pop_front() {
    if (head == NULL) {
        return;
    }

    Uzel* new_head;
    new_head = head->next;
    if (new_head != NULL) {
        new_head->back = NULL;
    }
    if (teil == head) {
        teil = NULL;
    }
    busy_plase -= head->size;
    delete head;
    head = new_head;
    if (head != NULL) {
        head->back = NULL;
    }
    count--;
}

// Функция явно возвращает указатель на элемент, находящийся в начале контейнера.
// и не явно возвращает размер данных
void* List2::front(size_t& size) {
    if (head == NULL) {
        return NULL;
    }
    size = head->size;
    return head->data;
}

// Функция явно возвращает указатель на элемент, находящийся в конеце контейнера.
// и не явно возвращает размер данных
void* List2::back(size_t& size) {
    if (teil == NULL) {
        return NULL;
    }
    size = teil->size;
    return teil->data;
}

// Добавление элемента в позицию, на которую указывает итератор iter.
// В случае успешного добавления функция возвращает значение 0, в случае неудачи 1.
int List2::insert(Iterator* iter, void* elem, size_t elemSize) {// ###label
    if (busy_plase > _memory.size()) {
        return 1;
    }
    if (iter == NULL && head != NULL) {//элементы есть но итератор не указывает
        return 1;
    }
    if (head == NULL) {
        push_front(elem, elemSize);
    }//если голова и интератор или по отдельности они NULL то  возвращаем 1
    
    Uzel* b;
    b = new Uzel();
    b->data = _memory.allocMem(elemSize);
    memcpy(b->data, elem, elemSize);
    b->size = elemSize;
    
    Iterator_for_list* it = (Iterator_for_list*)iter;

    Uzel* data_of_uzel = it->current_uzel();//data_of_uzel - next
    b->next = data_of_uzel;
    b->back = data_of_uzel->back;
    
    if (data_of_uzel->back != NULL) {
        data_of_uzel->back->next = b;
    }
    data_of_uzel->back = b;

    count++;
    busy_plase += elemSize;
    return 0;
}
// Возврашает явно указатель на элемент, на который указывает итератор в данный момент.
// Неявно возвращает размер данных.
// Если итератор показывает за пределы контейнера (например, удален последний элемент), возвращает NULL.
void* Iterator_for_list:: getElement(size_t& size) {
    if (this_uzel == nullptr)
        return NULL;
    size = this_uzel->size;
    return this_uzel->data;
}

    // Возвращает true, если есть следующий элемент, иначе false.
bool Iterator_for_list::hasNext() {
    return this_uzel->next != NULL;
}

    // Переход к следующему элементу.
void Iterator_for_list::goToNext() {
    if (this_uzel == NULL || this_uzel->next == NULL) { 
        return;
    }
    this_uzel = this_uzel->next;
}

    // проверка на равенство итераторов
bool Iterator_for_list::equals(Iterator* right) {
    Iterator_for_list* right_ = (Iterator_for_list*)right;// преобразование
    size_t num = 0;
    if (this_uzel->data == right->getElement(num)) {
        if (this_uzel->size == num) {
            return true;//return this.data == right.data;
        }
    }
    return false;
}

Uzel* Iterator_for_list::current_uzel() {
    return this_uzel;
}

// Функция возвращает значение, равное количеству элементов в контейнере.
int List2::size() {//
    return count;
}

// Функция возвращает значение, равное максимальной вместимости контейнера в байтах.
size_t List2::max_bytes() {
    /*/заглушка*/
    return 0;
}

// Функция создает в динамической памяти итератор, указывающий на первый найденный
// в контейнере элемент. Если элемент не найден, возвращается пустой указатель.
// Удаление этого итератора должно делаться пользователем с помощью оператора delete.
Container::Iterator* List2::find(void* elem, size_t size) {
    Iterator_for_list* a = (Iterator_for_list*)newIterator();
    size_t tmp_size;
    bool flag = false;
    int j;
    for (int i = 0; i < count; i++) {
        void* tmp_data = a->getElement(tmp_size);
        j = *(int*)tmp_data;
        if (memcmp(tmp_data, elem, tmp_size) == 0) {
            if (tmp_size == size) {
                flag = true;
                break;
            }
        }
        if (a->hasNext())
            a->goToNext();
        else
            break;
    }
    return flag ? a : NULL;
}// memcmp

// Функция создает в динамической памяти итератор, указывающий на первый элемент
// контейнера. Если контейнер пустой, возвращается нулевой указатель.
// Удаление этого итератора должно делаться пользователем с помощью оператора delete.
Container::Iterator* List2::newIterator() {
    if (head == NULL)
        return NULL;
    Iterator_for_list* a = new Iterator_for_list(head);
    return a;
}

// Удаление элемента из позиции, на которую указывает итератор iter.
// После удаления итератор указывает на следующий за удаленным элемент.
void List2::remove(Iterator* iter) {//#
    if (head == NULL || iter == NULL) {
        return;
    }

    Iterator_for_list* t_it = (Iterator_for_list*)iter;
    Uzel* now_uzel = t_it->current_uzel();
    
    Uzel* back_uzel = now_uzel->back;
    Uzel* next_uzel = now_uzel->next;
    if(t_it->hasNext())
        t_it->goToNext();

    busy_plase -= now_uzel->size;

    if (now_uzel == head) {
        head = next_uzel;
        delete now_uzel;
    }
    else if (now_uzel == teil) {
        teil = back_uzel;
        teil->next = NULL;
        delete now_uzel;
    }
    else {
        back_uzel->next = next_uzel;
        next_uzel->back = back_uzel;
        delete now_uzel;
    }
}

// Удаление всех элементов из контейнера.
void List2::clear() {
    Uzel* this_block;
    for (int i = 0; i < count; i++) {
        this_block = head->next;
        delete head;
        head = this_block;
        /*if (head->next == NULL) { // когда пройдем все коробочки последнюю удалить
            delete head;
            break;
        }*/
    }
    teil = NULL;
    count = 0;//надо занулить счетчик после успешного удаления
}

// Если контейнер пуст возвращает true, иначе false
bool List2::empty() {
    return (head == NULL);
    //return (count == 0);
}