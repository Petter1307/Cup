#include <iostream>
#include <string>
#include <conio.h>
#include "metode.h"
using namespace std;

int main()
{
    cup cup1;
    cup1.set_weight(120);
    cup1.set_color("Red");
    cup1.set_utilization("Tea");
    cup1.set_volume(200);

    cup cup2("Blue", "Coffe", 300, 100);

    cup cup3(cup1);

    if (cup1 >= cup3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (cup3 <= cup3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (cup1 > cup2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (cup1 < cup2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cup1.show_cup_details();
    cup2.show_cup_details();
    cup3.show_cup_details();

    return 0;
}