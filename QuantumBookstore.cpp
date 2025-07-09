#include <iostream>
#include <string>
#include <algorithm>
#include "Book.h"
#include "Store.h"
#include "TestCases.h"
using namespace std ;

int main () {
    cout << "Welcome to Quantum Bookstore!" << endl;
    TestCases test;
    test.runAllTests();
    return 0;
}