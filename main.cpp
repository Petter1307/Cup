#include <iostream>
#include <string>
#include <conio.h>
#include "metode.h"
using namespace std;

int main()
{
    cup cana1;
    cana1.set_weight(120);
    cana1.set_color("Red");
    cana1.set_utilization("Tea");
    cana1.set_volume(200);

    cup cana2("Blue", "Coffe", 300, 100);

    cup cana3(cana1);

    if (cana1 >= cana3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (cana3 <= cana3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (cana1 > cana2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    if (cana1 < cana2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cana1.show_cup_details();
    cana2.show_cup_details();
    cana3.show_cup_details();

    return 0;
}