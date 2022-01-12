#pragma once
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

class ceramic_tableware
{
    string type;

protected:
    float weight;

public:
    ceramic_tableware()
    {
        weight = 0.0;
        type = " ";
    };
    ceramic_tableware(float weight) : weight(weight)
    {
        type = "";
    };
    ceramic_tableware(float weight, string type) : weight(weight), type(type){};
    ~ceramic_tableware(){};
};

class cup : public ceramic_tableware
{
    string color;
    string utilization;
    float volume;
    int id_cup = -1;
    static int n;
    static float total_priamrymaterial_weight;          // The total mass of clay.
    static int generateID();                            //
    static void weight_rem(float weight);               //
    static void show_remaine_primary_material_weight(); //
    static int verify_eought_clay(float weight);        //

public:
    cup();                                                                                                  //
    cup(string color, string utilization, float weight, float volume) : ceramic_tableware(weight, "Cup"){}; //
    cup(const cup &c);                                                                                      //
    ~cup(){};                                                                                               //
    void set_color(string color);                                                                           //
    void set_utilization(string utilization);                                                               //
    void set_weight(float weight);                                                                          //
    void set_volume(float volume);                                                                          //
    string get_color();                                                                                     //
    string get_utilization();                                                                               //
    float get_weight();                                                                                     //
    float get_volume();                                                                                     //
    void show_cup_details();                                                                                //
    int operator>(cup &x);                                                                                  //
    int operator<(cup &x);                                                                                  //
    int operator==(cup &x);                                                                                 //
    friend int operator<=(cup &x, cup &y);
    friend int operator>=(cup &x, cup &y);
};
//----------------------------------------------------------------------------------------
// Initializing the static members cup class
float cup::total_priamrymaterial_weight = 3000;
int cup::n = 0;
//----------------------------------------------------------------------------------------
// Basic Constructor
cup::cup()
{
    color = "";
    utilization = "";
    weight = 0.0;
    volume = 0.0;
};
//----------------------------------------------------------------------------------------
// Constructor with parameters(?)
cup::cup(string color, string utilization, float weight, float volume)
{
    if (verify_eought_clay(weight))
    {
        this->color = color;
        this->utilization = utilization;
        // this->weight = weight;
        this->volume = volume;
        weight_rem(weight);
        id_cup = generateID();
        cout << endl;
        cout << "Constructor with parameters id =" << id_cup << endl;
        show_remaine_primary_material_weight();
    }
    else
    {
        cout << endl;
        cout << "There is not enough clay to create this cup." << endl;
    }
};
//----------------------------------------------------------------------------------------
// Copy Constructor
cup::cup(const cup &c)
{
    // The cup will be created only if it`s enough clay.
    if (verify_eought_clay(c.weight))
    {

        color = c.color;

        utilization = c.utilization;

        weight = c.weight;

        volume = c.volume;

        weight_rem(weight);

        id_cup = generateID();
        cout << endl;
        cout << "Copy constructor, id = " << id_cup << endl;
        show_remaine_primary_material_weight();
    }
    else
    {
        cout << endl;
        cout << "There is not eought clay to create this cup. Try again!" << endl;
    }
};
//----------------------------------------------------------------------------------------
// SETTERS
void cup::set_color(string color)
{
    // Fail safe
    if (this->weight == 0)
    {
        cout << "Please set the weight first!" << endl;
        return;
    }
    else
        this->color = color;
};
void cup::set_utilization(string utilization)
{
    // Fail safe
    if (this->weight == 0)
    {
        cout << "Please set the weight first!" << endl;
        return;
    }
    else
        this->utilization = utilization;
};
void cup::set_weight(float weight)
{
    // If it`s not enough clay in the deposit the cup won`t be created.
    if (verify_eought_clay(weight))
    {
        this->weight = weight;
        weight_rem(weight);
        show_remaine_primary_material_weight();
        if (this->id_cup == -1)
        {
            this->id_cup = generateID();
            cout << "Cup created, id = " << id_cup << endl;
        }
    }
    else
    {
        cout << "There is to less clay to create this cup. Try again with less caly" << endl;
    }
};
void cup::set_volume(float volume)
{
    // Fail safe
    if (this->weight == 0)
    {
        cout << "Please set the weight first!" << endl;
        return;
    }
    else
        this->volume = volume;
};
//----------------------------------------------------------------------------------------
// GETTERS
string cup::get_color()
{
    return this->color;
};
string cup::get_utilization()
{
    return this->utilization;
}
float cup::get_volume()
{
    return this->volume;
}
float cup::get_weight()
{
    return this->weight;
};
//----------------------------------------------------------------------------------------
// STATIC
int cup::generateID()
{
    return ++n;
};
void cup::weight_rem(float weight)
{
    total_priamrymaterial_weight -= weight; // total_priamrymaterial_weight = total_priamrymaterial_weight - weight
};
void cup::show_remaine_primary_material_weight()
{
    cout << "There is " << total_priamrymaterial_weight << " grams in the deposit of clay" << endl;
};
int cup::verify_eought_clay(float weight)
{
    if (total_priamrymaterial_weight >= 0 && total_priamrymaterial_weight - weight >= 0)
        return 1;
    else
        return 0;
};
//----------------------------------------------------------------------------------------
void cup::show_cup_details()
{
    if (id_cup != -1)
    {
        cout << endl;
        cout << "Cup ID: " << id_cup << endl;
        cout << "Collor: " << color << endl;
        cout << "Utilization: " << utilization << endl;
        cout << "Weight: " << weight << endl;
        cout << "Volume: " << volume << endl;
    }
    else
    {
        cout << endl;
    }
}
//----------------------------------------------------------------------------------------
// OPERATORS
// Overloading some operators. Nothing much but it`s honest work.
int cup::operator>(cup &x)
{
    if (this->weight > x.weight)
        return 1;
    else
        return 0;
};
int cup::operator<(cup &x)
{
    if (this->weight < x.weight)
        return 1;
    else
        return 0;
};
int cup::operator==(cup &x)
{
    if (this->weight == x.weight)
        return 1;
    else
        return 0;
};
int operator>=(cup &x, cup &y)
{
    if (x.weight > y.weight || x.weight == y.weight)
        return 1;
    else
        return 0;
};
int operator<=(cup &x, cup &y)
{
    if (x.weight < y.weight || x.weight == y.weight)
        return 1;
    else
        return 0;
};
//----------------------------------------------------------------------------------------
// Relations between Classes. Lab 10 HOMEWORK
class cup_set
{
    int n;
    cup *cups;

public:
    cup_set(int n, cup cups[]);
    void show_set();
    ~cup_set();
};
cup_set::cup_set(int n, cup cups[])
{
    this->n = n;
    this->cups = new cup[n];
    for (int i = 0; i < n; i++)
    {
        this->cups[i] = cups[i];
    }
}
void cup_set::show_set()
{

    for (int i = 0; i < n; i++)
    {
        cups[i].show_cup_details();
    }
};
