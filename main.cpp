#include <iostream>
#include "employee.h"
using std::cout, std::endl, Records::Employee, std::string;

int main()
{
	cout << "Testing the Employee class." << endl;

	Employee emp{"Jane", "Doe"};
	emp.setFirstName("John");
	emp.setLastName("Doe");
	emp.setEmployeeNumber(71);
	emp.setSalary(50'000);
	emp.promote();
	emp.promote(50);
	emp.hire();
	emp.display();
}
