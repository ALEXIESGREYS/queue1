#include "Queue.h"

class TestQueue {
private:
    Queue* a = NULL;
    int kolvo;
public: 
    TestQueue(int count, size_t busy_plase);
    ~TestQueue();

    int push();//*

    int pop(int num);//*

    int front();//*

    int back();

    int insert(int num1);

    int size();

    size_t max_bytes();

    int remove(int count);

    int clear();

    bool empty();
    
    int find(int num);
    
    //1 - нечетные, 2- четные, 3 и любое другое число - все
    int remove2(int flag);
};