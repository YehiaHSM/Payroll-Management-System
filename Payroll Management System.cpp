// This program calculates the net (take-home) 
// pay for an employee after tax deductions
// given the number of hours he worked and his dependents
#include <iostream>
using namespace std;
#define uDues 10.0 // union dues

void main()
{
    // Define constants and variables
	const int numEmployees = 5, info = 4;
	double Emps[numEmployees][info];
	double const rate = 16.78; // hourly rate
	int const normalRatehours = 40; // normal working hours per week

	// Declare variables for tax calculations
	double ssTax, // social security tax
		   fiTax, // federal income tax
		   siTax, // state income tax
		   healthIn = 0; // health insurance 
	double grossPay; // gross pay before taxes
	
	// Set output precision for double numbers
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// Input hours worked and number of dependents for each employee
	for(int i=0; i<numEmployees; i++)
	{
	    // Initialize health insurance
	    healthIn = 0;
	    
	    // Input number of hours worked
	    cout << "Hours worked per week: "; 
	    cin >> Emps[i][0];

	    // Input number of dependents
	    cout << "Number of dependents: "; 
	    cin >> Emps[i][1];
	
	    // Calculate gross pay based on hours worked
	    if(Emps[i][0] <= normalRatehours)
		    grossPay = Emps[i][0] * rate;
	    else
	    {
		    grossPay = normalRatehours * rate;
		    double extraRate = 1.5 * rate;
		    int extraHrs = Emps[i][0] - normalRatehours;
		    grossPay += extraHrs * extraRate; // Include overtime pay
	    }
	
	    // Calculate taxes
	    ssTax = grossPay * 6.0 / 100;
	    fiTax = grossPay * 14.0 / 100;
	    siTax = grossPay * 5.0 / 100;
	
	    // Determine health insurance based on number of dependents
	    if(Emps[i][1] >= 3)
		    healthIn = 35;
	
	    // Calculate total deductions
	    Emps[i][2] = ssTax + fiTax + siTax + uDues + healthIn;
	
	    // Calculate net salary (take-home pay)
	    Emps[i][3] = grossPay - Emps[i][2]; // Net salary
		
	}
	
	// Clear screen
	system("cls");
	
	// Display employee data in tabular format
	cout << "ENo\tHrs\tDep\tTaxes\tSalary\n";
	for(int r=0; r<numEmployees; r++)
	{
		cout << r+1 << "\t";
		for(int c=0; c<info; c++)
		{
			cout << Emps[r][c] << "\t";
		}
		cout << endl;
	}
	
} // end main
