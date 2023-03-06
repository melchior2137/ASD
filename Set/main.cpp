#include "myset.h"
#include <iostream>

int main()
{
    MySet<int> A;

    A.insert(1);
    A.insert(2);
    A.insert(3);
    A.insert(4);
    A.insert(5);
    A.insert(6);
    A.insert(7);

    // std::cout<<"Head: " << A.front()<<std::endl;
    // std::cout<<"Tail: " << A.back()<<std::endl;


    // //usuwanie head
    // A.remove(1);
    // //usuwanie tail
    // A.remove(7);

    // std::cout<<"Head: " << A.front()<<std::endl;
    // std::cout<<"Tail: " << A.back()<<std::endl;


    std::cout<<"A: ";
    A.display();

    MySet<int> B;
    B.insert(6);
    B.insert(7);
    B.insert(8);
    B.insert(9);
    B.insert(10);
    std::cout<<"B: ";
    B.display();

    std::cout<<"A Union B: ";
    MySet<int> list2 = A.my_union(B);
    list2.display();

    std::cout<<"A Intersection B: ";
    MySet<int> list3 = A.my_intersection(B);
    list3.display();

    std::cout<<"A - B: ";
    MySet<int> list4 = A.my_difference(B);
    list4.display();

    std::cout<<"B - A: ";
    MySet<int> list5 = B.my_difference(A);
    list5.display();

}