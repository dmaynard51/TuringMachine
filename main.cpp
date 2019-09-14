/********************************************
Name: Daniel Maynard
Date: 7/9/17
Description: This program will replicate a Langton ant. 

It will ask the user where they would like to start first, with a starting
direction of north. If the next cell is white it will turn clockwise, if black
it will turn counterclockwise.

If the Ant is current on a white cell, and moves to black 
it will turn that cell to white. 

If the ant is on a white cell, and moves onto another white
cell it will turn the white cell black.

If the ant is about to move onto the end of the array, it will turn in the
opposite direction.

After each enter, the Ant will make it's next move.
*********************************************/

#include <iostream>
#include "Ant.hpp"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    
    
    char yesOrNo = 'y';
    
    while (yesOrNo == 'y' || yesOrNo == 'Y')
    {
    
    int rows, columns,location,steps;
    Ant ant;
    
    
    cout << "How many rows would you like?\n";
    rows = ant.inputValidation();
    cout << "How many columns would you like\n";
    columns = ant.inputValidation();
    cout << "Enter the number of steps you would like to take\n";
    steps = ant.inputValidation();
    ant.setSteps(steps);
	cout << "Where would you like to the ant to appear\n";
    cout << "1. Center of array\n";
    cout << "2. Choose an a location\n";
	cout << "3. Random location\n";



	
	while ((!(cin >> location) || (location < 1)) || (location > 3)) // found this input validation here:https://stackoverflow.com/questions/2075898/good-input-validation-loop-using-cin-c
	{

		cout << "invalid input, enter a number between 1-3\n";
		cin.clear();
		cin.ignore(100, '\n');

	}

	

    
    char **matrix = new char*[rows]; //creates a dynamic array pointing to an array of pointers
    
    
    
    /************************************************
     Description: Creates the array, with what is inputted by the user.
     *************************************************/
    for (int count = 0; count < rows; count++)
    {
        matrix[count] = new char [columns];
        
        for (int count2 = 0; count2 < columns; count2++)
        {
            matrix[count][count2] = ' ';
        }
    }

	//first step choose location on array where ant appears
    
    ant.setPosition(matrix, rows, columns, location); //sets the location of the ant to be in the middle

	/*******************************************************
	2nd step move, begin movement starting area to go north
	*******************************************************/

	while (ant.steps > 0)
	{
        ant.makeMove(matrix, rows, columns);
        
	}

	/*******************************************************
	Description: Deletes dynamic array
	*******************************************************/

	for (int count = 0; count < rows; count++)
	{
		delete[]matrix[count];
	}
		delete []matrix;

	/*******************************************************
	Description: Verifies with user if the program should be run again
	*******************************************************/


    cout << "Would you like to run the program again? Y or N" << endl;
    
        yesOrNo = ant.inputValidationYN();
        
    }
    
    return 0;
}

