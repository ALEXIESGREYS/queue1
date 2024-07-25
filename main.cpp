//#include "Mem.h"
//#include "Queue.h"
#include "TestQueue.h"


int main() {
	TestQueue* q = new TestQueue(1000, 5000);
	int a1 = q->push();
	if (a1 != 0) {
		return 11;
	}
	int a5 = q->remove2(1);
	if (a5 != 0) {
		return 15;
	}
	int a2 = q->front();
	if (a2 != 0) {
		return 12;
	}

	int a3 = q->back();
	if (a3 != 0) {
		return 13;
	}

	int a4 = q->pop(50);
	if (a4 != 0) {
		return 14;
	}

	int a9 = q->insert(100);
		if (a9 != 0) {
			return 15;
		}
}
