#include <iostream>

// ==========================================================
// C++ Interview Exercise #1
// Topic:
// - Pass by value
// - Pass by pointer
// - Pass by reference
// - Pointer reassignment
// - Pointer vs Reference semantics
//
// DO NOT RUN THE PROGRAM FIRST.
//
// Predict the output.
// Then run it.
// Explain WHY.
// ==========================================================

void foo(int x, int* ptr, int& ref)
{
    std::cout << "\n===== Inside foo() =====\n";

    x = 100;
    *ptr = 200;
    ref = 300;

    ptr = nullptr;

    // -------------------------
    // QUESTIONS
    // -------------------------

    // Q1
    // What is the value of x? -> Answer x = 100
    std::cout << "x = " << x << '\n';

    // Q2
    // Why is ptr nullptr here? - > Because we set it to nullptr in the function on line 27, but the original value will not be lost 
    if (ptr)
        std::cout << "*ptr = " << *ptr << '\n';
    else
        std::cout << "ptr is nullptr\n";

    // Q3
    // What is ref? -> Answer ref = 300
    std::cout << "ref = " << ref << '\n';
}

int main()
{
    int value = 10;

    int* p = &value;
    int& r = value;

    std::cout << "===== Before foo() =====\n";

    std::cout << "value = " << value << '\n';
    std::cout << "*p    = " << *p << '\n';
    std::cout << "r     = " << r << '\n';

    foo(value, p, r);

    std::cout << "\n===== After foo() =====\n";

    std::cout << "value = " << value << '\n';
    std::cout << "*p    = " << *p << '\n';
    std::cout << "r     = " << r << '\n';

    std::cout << "p == nullptr ? "
              << (p == nullptr ? "YES" : "NO")
              << '\n';

    //------------------------------------------------------
    // QUESTIONS
    //------------------------------------------------------

    /*
        Q4

        Why didn't changing x modify value?

        --------------------------------------------------

        Your Answer: Because we coppy the value of the variable "value", we dont use a reference to the memory. 



    */

    /*
        Q5

        Why did changing *ptr modify value?

        --------------------------------------------------

        Your Answer:



    */

    /*
        Q6

        Why did changing ref modify value?

        --------------------------------------------------

        Your Answer: Because ref is a refference to the address of value and we changed it in foo(), we actualy overwrite the value saved in that address



    */

    /*
        Q7

        Why is p NOT nullptr after foo() returns?

        --------------------------------------------------

        Your Answer: Because in foo() ptr is the  copy of the value of p, which is a copy of the address where the variable "value" is stored



    */

    /*
        Q8

        What exactly is copied when calling

            foo(value, p, r);

        Describe EACH parameter separately.

        x ->. x will be a copy of the actual value of the variable "value"

        ptr -> ptr will be a copy of the value of p, which is the address where "value" is stored 

        ref -> is not a copy, it is a reference of the "value"

        --------------------------------------------------

        Your Answer: x ->. x will be a copy of the actual value of the variable "value"

        ptr -> ptr will be a copy of the value of p, which is the address where "value" is stored 

        ref -> is not a copy, it is a reference of the "value"
    */

    /*
        ==========================================================
        PART 2
        ==========================================================

        Change the function signature to

            void foo(int& x, int*& ptr)

        Answer:

        Q9

        What changes?

        Във функция вече не се приема копие на стойността на х, и така очакван пойнтър, ако му се подаде дирекно p, a не &p, 
        все ще получим рефернция към паметта, където е запазена стойността на пойнтъра




        Q10

        If foo() executes

            ptr = nullptr;

        what happens to p inside main()?
        will be set to nullptr and lost




    */

    /*
        ==========================================================
        PART 3
        ==========================================================

        Explain the following declarations.

        Q11

            int* p; -> pointer 

        ----------------------------------




        Q12

            const int* p; -> pointer to a const int, points to address which value is const and wont be changed

        ----------------------------------



        Q13

            int* const p; -> const pointer, only points to the one exact address in the memory and cant be changed 

        ----------------------------------



        Q14

            const int* const p; -> const pointer const, we set it one time to one address, which value will not be changed, and cant change the address after that 

        ----------------------------------



    */

    /*
        ==========================================================
        BONUS
        ==========================================================

        Implement:

            void swap(int& a, int& b);

        WITHOUT std::swap

        void swap(int& a, int& b)
        {
            int help = a;
            a = b;
            b = help;

        }

    */

    return 0;
}