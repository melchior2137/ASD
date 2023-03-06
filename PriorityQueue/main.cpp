#include <iostream>
#include <cassert>
#include "priorityQueue.h"

int main() {
    priorityQueue<int> queue;
    queue.put(10,1);
    queue.put(11, 6);
    queue.put(12,3);
    queue.put(31,2);
    queue.put(33,7);
    queue.put(111, 3);
    queue.put(34,5);
    queue.put(321,2);
    queue.put(21,7);


    std::cout<<"Queue: "<<std::endl;
    queue.print();

    queue.get();
    std::cout<<"Po wyciagnieciu jednego elementu: "<<std::endl;
    queue.print();
    assert(queue.front().priority == 7);
    assert(!queue.is_empty());

    queue.get();
    std::cout<<"Po wyciagnieciu kolejnego elementu: "<<std::endl;
    queue.print();

    queue.make_null();
    assert(queue.is_empty());

    std::cout<<"Po wyczyszczeniu: "<<std::endl;
    queue.print();


}
