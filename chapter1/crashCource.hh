// until page 74 of professional C++

#pragma once
#include <iostream>
#include <exception>
#include <initializer_list>
#include <optional>
#include <cstddef>
#include <array>
#include <optional>
#include <vector>

using std::cout, std::cin, std::endl, std::string, std::vector;

enum class Courtiers
{
    CourtiersKing,
    CourtiersQueen,
    CourtiersSoldier,

};

namespace first
{
    void separateOddsAndEvens(const vector<int> &arr,
                              vector<int> &odds, vector<int> &evens);
    int firstX{1};

    namespace second
    {
        int secondX{first::firstX + 1};

        namespace third
        {
            int thirdX{first::second::secondX + 1};

            Courtiers person1 = Courtiers::CourtiersKing;
        } // third

    } // namespace second

} // namespace first

namespace fs = first::second;
namespace fst = first::second::third;

void funFunction()
{
    cout << first::firstX << fs::secondX << fst::thirdX << endl; // 123

    if (first::second::third::thirdX == 1)
    {
        cout << "shit! " << endl;
    }
    else if (fst::thirdX == 2)
    {
        cout << "shit more !" << endl;
    }
    else
    {
        cout << "No shit ! ! !" << endl;
    }

    switch (fst::person1)
    {
    case Courtiers::CourtiersKing:
        cout << "It's the king" << endl;
        break;
    case Courtiers::CourtiersQueen:
        cout << "It's the queen" << endl;

    default:
        cout << "It's a soldier " << endl;
        break;
    }

    (fst::person1 == Courtiers::CourtiersKing) ? cout << "it's king \n" : cout << "it's not king\n";
}

[[nodiscard("Some explanation")]] int func(int value1, [[maybe_unused]] int value2)
{
    return 212;
}

std::optional<int> getData(bool giveIt)
{
    /*
    optional
    removes the need to return “special” values from functions such as nullptr, end(), -1, EOF,
    and so on. It also removes the need to write the function as return
    */

    if (giveIt)
    {
        return 42;
    }
    return std::nullopt; // or simply return {};
}

void looper()
{
    int x{};
    while (x < 2)
    {
        cout << "while looping ! \n";
        ++x;
    }

    int xx{};
    do
    {
        cout << "do while ing ! \n";
        ++xx;
    } while (xx < 3);

    for (int i = 0; i < 4; i++)
    {
        cout << "for looping ! \n";
    }

    std::array arr{1, 2, 3, 4, 5};
    for (int i : arr)
    {
        cout << i << endl;
    }
}

int makeSum(std::initializer_list<int> values)
{
    int total{0};
    for (int value : values)
    {
        total += value;
    }
    cout << total << endl;
    return total;
}

class AirlineTicket
{
public:
    double calculatePriceInDollars(){

    }; // read-only & not change anything
    void setPassengerName(std::string name) { m_passengerName = name; }
    int getNumberOfMiles() { return m_numberOfMiles; }
    void setNumberOfMiles(int miles) { m_numberOfMiles = miles; }
    bool hasEliteSuperRewardsStatus() { return m_hasEliteSuperRewardsStatus; }
    void setHasEliteSuperRewardsStatus(bool status)
    {
        m_hasEliteSuperRewardsStatus = status;
    }

private:
    std::string m_passengerName{"Unknown Passenger"};
    int m_numberOfMiles{0};
    bool m_hasEliteSuperRewardsStatus{false};
};

// scopes
class Demo
{
public:
    int get() { return 5; }
};

int get() { return 10; }

namespace NS
{
    int get() { return 20; }
}
//

struct CircleStruct
{
    int x, y;
    double radius;
};
class CircleClass
{
public:
    CircleClass(int x, int y, double radius)
        : m_x{x}, m_y{y}, m_radius{radius} {}

private:
    int m_x, m_y;
    double m_radius;
};

struct Employee
{

    char firstInitial;
    char lastInitial;
    int employeeNumber;
    int salary;
};
//! Variables that are stack allocated do not need to be deallocated (deleted) by the programmer; it happens automatically

class MyClass
{
public:
    MyClass(int &ref) : m_ref{ref}
    { /* Body of constructor */
    }

private:
    int &m_ref;
};

void addOne(int i)
{
    i++; // Has no real effect because this is a copy of the original
}
void addOne(int &i)
{
    i++; // Actually changes the original variable
}

constexpr double inchToMm(double inch) { return inch * 25.4; }

void first::separateOddsAndEvens(const vector<int> &arr,
                                 vector<int> &odds, vector<int> &evens)
{
    for (int i : arr)
    {
        if (i % 2 == 1)
        {
            odds.push_back(i);
        }
        else
        {
            evens.push_back(i);
        }
    }
}

struct OddsAndEvens
{
    vector<int> odds, evens;
};
OddsAndEvens separateOddsAndEvens(const vector<int> &arr)
{
    vector<int> odds, evens;
    for (int i : arr)
    {
        if (i % 2 == 1)
        {
            odds.push_back(i);
        }
        else
        {
            evens.push_back(i);
        }
    }
    return OddsAndEvens{.odds = odds, .evens = evens};
}

double divideNumbers(double numerator, double denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument{"Denominator cannot be 0."};
    }
    return numerator / denominator;
}

//!
//!
//!
//!
//!

/*
#include "chapter1\crashCource.hh"
using std::cout, std::cin, std::endl, std::vector;
using str_t = std::string;

int main()
{
    str_t hello{"Hello, world !"};
    cout << "Hello, world !\n"
         << hello << '\n'
         << endl;

    funFunction();

    Employee mia;
    mia.employeeNumber = 19;
    mia.salary = 9000;

    // func(12, 2);
    // forceProgramTermination();
    // funct();

    std::array arr{1, 2, 3};
    std::vector myVec{1, 2, 3, 4};
    myVec.push_back(5);
    cout << std::size(arr) << endl;
    cout << std::size(myVec) << endl;

    std::pair myPair{9.2, 2};

    std::optional<int> data1{getData(true)};
    std::optional<int> data2{getData(false)}; //<utility>
    cout << "data1.has_value = " << data1.has_value() << endl;
    if (data2)
    {
        cout << "data2 has a value." << endl;
    }

    struct Point
    {
        double m_x, m_y, m_z;
    };
    Point point;
    point.m_x = 1.0;
    point.m_y = 2.0;
    point.m_z = 3.0;
    auto [x, y, z]{point};		 // order is important
    cout << x << y << z << endl; // 1,2,3

    looper();
    makeSum({1, 2, 3, 4, 5, 6});

    std::string myString = "Hello to the C++";

    AirlineTicket myTicket;
    myTicket.setPassengerName("Sherman T. SocketWrench");
    myTicket.setNumberOfMiles(700);
    double cost{myTicket.calculatePriceInDollars()};
    cout << "This ticket will cost " << cost << endl;

    Demo d;
    cout << d.get() << endl;   //  5
    cout << NS::get() << endl; //  20
    cout << ::get() << endl;   //  10
    cout << get() << endl;	   //  10

    CircleStruct myCircle5;
    myCircle5.radius = 2.5;
    myCircle5.x = 10;
    myCircle5.y = 10;
    // OR
    CircleClass myCircle6{10, 10, 2.5};

    // int *myArray = new int[]{0, 1, 2, 3};
    // cout << myArray[2] << endl;
    // delete[] myArray;

    Employee anEmployee{
        .firstInitial = 'J',
        .lastInitial = 'D',
        .employeeNumber = 42,
        .salary = {80'000},
    };
    // OR
    Employee anEmployee2{'J', 'D', 0, 80'000};
    cout << anEmployee2.salary << endl;

    /*
        To prevent memory leaks, every call to new should be paired with a
        call to delete, and every call to new[] should be paired with a call to delete[].
        Not calling delete or delete[], or mismatching calls, results in memory leaks or
        worse.
    */
/*
int *myIntegerInFreeStore1{nullptr}; // declare uninitialized variable
myIntegerInFreeStore1 = new int;     // allocate in free space
*myIntegerInFreeStore1 = 8;          // initializing
int i{9};
int *myIntegerInFreeStore2{&i};  // pointing to Address of i
delete myIntegerInFreeStore2;    // deallocate in free space
myIntegerInFreeStore2 = nullptr; // prevent using after deallocation

Employee *anEmployee3{&anEmployee2}; // pointing to address of anEmployee2 by variable anEmployee3
(*anEmployee3).employeeNumber;       // dereference then access
// OR
int en3 = anEmployee3->employeeNumber; // dereference and access
cout << en3 << endl;
bool isValidSalary{(anEmployee3 != nullptr && anEmployee3->salary > 0)};

int arraySize{5};                              // on the stack
int *myVariableSizedArray{new int[arraySize]}; // Dynamically Allocated Arrays in free store(heap)
myVariableSizedArray[0] = 10;
myVariableSizedArray[1] = 20;
myVariableSizedArray[2] = 30;
cout << myVariableSizedArray[0] << myVariableSizedArray[1] << myVariableSizedArray[2] << endl;
delete[] myVariableSizedArray;
myVariableSizedArray = nullptr;

//! read from right to left
const int *ipp;
// SIMILAR, both const the value
int const *ip;
ipp = new int[10];
// ipp[4] = 5; // DOES NOT COMPILE!
ip = new int[10];
// ip[4] = 5; // DOES NOT COMPILE!

delete[] ipp;
delete[] ip;

int *const iip{nullptr}; // initialization required; const the iip itself
// iip = new int[10]; // DOES NOT COMPILE!
// iip[4] = 5;		   // Error: dereferencing a null pointer

int *const ippp{new int[10]};
ippp[4] = 5;
delete[] ippp;

int const *const ip41{nullptr};
// SIMILAR: const both ip4 itself and value
const int *const ip42{nullptr};
int const *const ip43{nullptr};
delete ip41, ip42, ip43;

string myString2{"The string\n"};
cout << myString2;

int xz{3}, yz{4};
int &xRef{xz};
int &yRef{yz};
yRef = xRef;
cout << yRef << endl; // 3

// int &unnamedRef1{5};	   // DOES NOT COMPILE
const int &unnamedRef2{5}; // Works as expected

//! WTF ?!
int *intP{nullptr};
int *&ptrRef{intP};
ptrRef = new int;
*ptrRef = 5;
cout << ptrRef << endl;  // address
cout << *ptrRef << endl; // 5
cout << intP << endl;    // another address
cout << *intP << endl;   // 5
delete ptrRef;

int x5{3};
int &xRef5{x5};
int *xPtr5{&xRef5}; // Address of a reference is pointer to value.
*xPtr5 = 100;
cout << x5 << endl;     // 100
cout << xPtr5 << endl;  // address
cout << *xPtr5 << endl; // 100

std::pair myPair3{"Hello", 9};
auto [myStr, myInt]{myPair3};
cout << myStr << myPair3.first << endl;

// auto &[theString11, theInt11]{myPair3}; //err // Decompose into references-to-non-const
const auto &[theString11, theInt11]{myPair3}; // Decompose into references-to-const

/*
 A reference can be thought of as a constant pointer (not to be confused with a pointer to
 a constant value!) with automatic indirection, i.e., the compiler will apply the * operator for you.
*/
vector<int> vecUnSplit{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector<int> odds, evens;
first::separateOddsAndEvens(vecUnSplit, odds, evens);

// const_cast<T>()

// divideNumbers(1, 0);

try
{
    cout << divideNumbers(2.5, 0.5) << endl;
    cout << divideNumbers(4.5, 2.00) << endl;
    cout << divideNumbers(2.3, 0) << endl;
}
catch (const std::invalid_argument &exception)
{
    cout << exception.what() << endl;
}

int intType{99};
decltype(intType) anotherIntType{100};
}
* /