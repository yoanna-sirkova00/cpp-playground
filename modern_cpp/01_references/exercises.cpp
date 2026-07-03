#include <iostream>
using  namespace std;


void printState(const int& x, int* ptr,const int& ref)
{
    std::cout << "x = "<<x<<std::endl;
    std::cout << "ptr = "<<ptr<<std::endl;
    std::cout << "*ptr = "<<*ptr<<std::endl;
    std::cout << "ref = "<<ref<<std::endl;
    std::cout << "&ref = "<<&ref<<std::endl;
    std::cout << "&x = "<<&x<<std::endl;
    std::cout<<"sizeof(x) = "<<sizeof(x)<<std::endl;
    std::cout<<"sizeof(ptr) = "<<sizeof(ptr)<<std::endl;
    std::cout<<"sizeof(ref) = "<<sizeof(ref)<<std::endl;
}
struct Person
{
    int age;
    double salary;
};
int main()
{
    int x;
    int& ref = x;
    int* ptr = &x;

    *ptr = 30;
    std::cout << "In main : *ptr = 30;"<<std::endl;
    printState(x, ptr, ref);

    x = 20;
    std::cout << "In main : x = 20;"<<std::endl;
    printState(x, ptr, ref);

    int y = 50;
    ref = y; //here x = y
    ptr = &y;
    std::cout << "In main : int y = 50"<<std::endl;
    printState(x, ptr, ref);

    std::cout << "sizeof(int): " << sizeof(int) << '\n';
    std::cout << "sizeof(double): " << sizeof(double) << '\n';
    std::cout << "sizeof(Person): " << sizeof(Person) << '\n';
    std::cout << "sizeof(Person*): " << sizeof(Person*) << '\n';

    return 0;
}