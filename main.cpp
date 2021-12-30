#include <iostream>
#include <string>
#include <conio.h>
#include "methods.h"
using namespace std;

int main()
{
    // In this test I will exced the clay limit.
    cup cups_1st_set[] = {cup("Red", "Tea", 1000, 300), cup("Blue", "Coffe", 200, 300), cup("Green", "Noodles", 3000, 500)};

    cup_set Set1(3, cups_1st_set);
    Set1.show_set();

    return 0;
}