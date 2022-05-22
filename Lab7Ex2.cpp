//////////////////////////////////////////////////////////////////////////////////////////////////////
//							ECC CIS-121 Summer 2021 												//
//																									//
//	Type of Assignment:		Lab 7																    //
//	Problem Number:			Exercise 2																//
//	Section Number			700																		//
//	Author:					Kehinde Abioye														    //
//	Date Assigned:			July 19, 2021														    //
//	Project Name:			Valid Password  											            //
//	File Name:				Lab7Ex2.cpp													            //
//																									//
//	Purpose of Program:																				//
//		The purpose of this program is obtain user input for a password. The password must          //
//      be at least 6 characters, have at least one uppercase, lowercase, and digit in the password.//																								        
//																							        //
//  Algorithm:																						//
//		1. Declare an array for  user input 												        //
//		2. Check if the input meets the requiements									                //
//		3. If requirements are not met, ask user to enter a new password					        //						
//////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    //Declare and initialize variables
    const int LENGTH = 20; //arbitrary length
    char password[LENGTH]; //password input variable
    bool validUpper, validLower, validDigit;//conditions for password

    /*The password should be at least six characters long.
    • The password should contain at least one uppercase and at least one lowercase letter.
    • The password should have at least one digit.*/
    //'Do' this part as long as password is invalid

    do
    {
        //Conditions equal false until proven true to satisfy do-while loop and initialize variables
        validUpper = false;//uppercase letter
        validLower = false;//lowercase letter
        validDigit = false;//digit

        cout << "Enter a password: "; 
        cin.getline(password, LENGTH); //user input

        for (int i = 0; i < strlen(password); i++)
        {
            if (isupper(password[i])) //if there is an uppercase letter then true
            {
                validUpper = true;
            }
            if (islower(password[i]))//if there is an lowercase letter then true
            {
                validLower = true;
            }
            if (isdigit(password[i]))//if there is a digit then true
            {
                validDigit = true;
            }
        }

        if (strlen(password) < 6)//if password less than 6 print error
        {
            cout << "password is not at least six characters long.\n";
        }
        if (validUpper == false)//is no uppercase print error
        {
            cout << "*The password must have at least one uppercase letter\n";
        }
        if (validLower == false)//if no lowercase print error
        {
            cout << "*The password must have at least one lowercase letter\n";
        }
        if (validDigit == false)//if no digit print error
        {
            cout << "*The password must have at least one Digit\n";
        }
        if (validUpper == false || validLower == false || validDigit == false || strlen(password) < 6)//if any condition false then password invalid
        {
            cout << "The password is invalid\n\n";
        }

    } while (validUpper == false || validLower == false || validDigit == false || strlen(password) < 6);//if any condition false repeat

    cout << "The password is valid.\n";//if all conditions are true then password is valid

    return 0;
}