/********************************************
Description: This class will hold all of the rules for the ant.


*********************************************/

#include "Ant.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::endl;
using std::cin;



/********************************************
Description: Set the ant to be black and facing north at creation.
*********************************************/
    Ant::Ant()
	{


		color = 'b';
		direction = 'n';
        
	}











/**************************
 Description: Makes a move on the board depending on the direction of the ant,
 and the
 *************************/


void Ant::makeMove(char **array, int rows, int columns)
{
    edgeCheck(array, rows, columns);
    /*
    Next two rules:
    this will go black east -> if white will go south and will stay black
                 black east -> if black will go north and will turn white
     
     
     */
    
    if ((direction == 'e') && (array[currentRowOfAnt][currentColumnOfAnt + 1] == ' ') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'b')) //current color is black
    {
        array[currentRowOfAnt][currentColumnOfAnt + 1] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = '#';
        direction = 's';
        findAntLocation(array,rows, columns);
        setColor('b');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;

        
    }
    
    if ((direction == 'e') && (array[currentRowOfAnt][currentColumnOfAnt + 1] == '#') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'b')) //current color is black
    {
        array[currentRowOfAnt][currentColumnOfAnt + 1] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = '#';
        direction = 'n';
        findAntLocation(array,rows, columns);
        setColor('w');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
        
        
    }
    
    
    
    
    /*
	Next two rules:
     this will go white east -> if white will go south and turn black
                  white east -> if black will go north and turn white
     */
    
    if ((direction == 'e') && (array[currentRowOfAnt][currentColumnOfAnt + 1] == ' ') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'w')) //current color is white
    {
        array[currentRowOfAnt][currentColumnOfAnt + 1] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = ' ';
        direction = 's';
        findAntLocation(array,rows, columns);
        setColor('b');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
        
        
    }
    
    if ((direction == 'e') && (array[currentRowOfAnt][currentColumnOfAnt + 1] == '#') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'w')) //current color is white
    {
        array[currentRowOfAnt][currentColumnOfAnt + 1] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = ' ';
        direction = 'n';
        findAntLocation(array,rows, columns);
        setColor('w');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
        
        
    }
    
    
    
    
    
    
    
    /*
     Next two rules:
     this will go black south -> if white will go west and turn black
     this will go black south -> if black will go east and turn white
     
     
     */
    
    if ((direction == 's') && (array[currentRowOfAnt + 1][currentColumnOfAnt] == ' ') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'b')) //current color is white
    {
        array[currentRowOfAnt + 1][currentColumnOfAnt] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = '#';
        direction = 'w';
        findAntLocation(array,rows, columns);
        setColor('b');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
    }
    
    
    if ((direction == 's') && (array[currentRowOfAnt + 1][currentColumnOfAnt] == '#') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'b')) //current color is white
    {
        array[currentRowOfAnt + 1][currentColumnOfAnt] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = '#';
        direction = 'e';
        findAntLocation(array,rows, columns);
        setColor('w');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
    }
    /*
     Next two rules:
     this will go white south -> if white will face west and turn black
     this will go white south -> if black will face east and turn white
     
     
     */
    
    
    if ((direction == 's') && (array[currentRowOfAnt + 1][currentColumnOfAnt] == ' ') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'w')) //current color is white
    {
        array[currentRowOfAnt + 1][currentColumnOfAnt] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = ' ';
        direction = 'w';
        findAntLocation(array,rows, columns);
        setColor('b');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
    }
    
    if ((direction == 's') && (array[currentRowOfAnt + 1][currentColumnOfAnt] == '#') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'w')) //current color is white
    {
        array[currentRowOfAnt + 1][currentColumnOfAnt] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = ' ';
        direction = 'e';
        findAntLocation(array,rows, columns);
        setColor('w');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
    }
    
    
    
    /*
	Next two rules:
     this will go white west -> if white will turn north and turn black
     this will go white west -> if black will turn south and turn white
  */
    
    if ((direction == 'w') && (array[currentRowOfAnt][currentColumnOfAnt - 1] == ' ') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'w')) //current color is white
    {
        array[currentRowOfAnt][currentColumnOfAnt - 1] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = ' ';
        direction = 'n';
        findAntLocation(array,rows, columns);
        setColor('b');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
    }
    
    if ((direction == 'w') && (array[currentRowOfAnt][currentColumnOfAnt - 1] == '#') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'w')) //current color is white
    {
        array[currentRowOfAnt][currentColumnOfAnt - 1] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = ' ';
        direction = 's';
        findAntLocation(array,rows, columns);
        setColor('w');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
    }
    
    /*
	Next two rules:
     this will go black west -> if white will turn north and turn black
     this will go black west -> if black will turn south and turn white
     */
    
    if ((direction == 'w') && (array[currentRowOfAnt][currentColumnOfAnt - 1] == ' ') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'b')) //current color is white
    {
        array[currentRowOfAnt][currentColumnOfAnt - 1] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = '#';
        direction = 'n';
        findAntLocation(array,rows, columns);
        setColor('b');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
    }
    
    if ((direction == 'w') && (array[currentRowOfAnt][currentColumnOfAnt - 1] == '#') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'b')) //current color is white
    {
        array[currentRowOfAnt][currentColumnOfAnt - 1] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = '#';
        direction = 's';
        findAntLocation(array,rows, columns);
        setColor('w');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
    }
    
    /*
	Next two rules:
     this will go black north -> if white will turn east and turn black
     this will go black north -> if black will turn west and turn white
     */
    
    if ((direction == 'n') && (array[currentRowOfAnt - 1][currentColumnOfAnt] == ' ') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'b')) //current color is white
    {
        array[currentRowOfAnt - 1][currentColumnOfAnt] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = '#';
        direction = 'e';
        findAntLocation(array,rows, columns);
        setColor('b');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
    }
    
    if ((direction == 'n') && (array[currentRowOfAnt - 1][currentColumnOfAnt] == '#') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'b')) //current color is white
    {
        array[currentRowOfAnt - 1][currentColumnOfAnt] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = '#';
        direction = 'w';
        findAntLocation(array,rows, columns);
        setColor('w');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
    }
    
    /*
	Next two rules:
     this will go white north -> if white will turn east and turn black
     this will go white north -> if black will turn west and turn white
     */
    
    
    if ((direction == 'n') && (array[currentRowOfAnt - 1][currentColumnOfAnt] == ' ') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'w')) //current color is white
    {
        array[currentRowOfAnt - 1][currentColumnOfAnt] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = ' ';
        direction = 'e';
        findAntLocation(array,rows, columns);
        setColor('b');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
    }
    
    if ((direction == 'n') && (array[currentRowOfAnt - 1][currentColumnOfAnt] == '#') && (array[currentRowOfAnt][currentColumnOfAnt] == '@') && (color == 'w')) //current color is white
    {
        array[currentRowOfAnt - 1][currentColumnOfAnt] = '@';
        array[currentRowOfAnt][currentColumnOfAnt] = ' ';
        direction = 'w';
        findAntLocation(array,rows, columns);
        setColor('w');
        printMatrix(array, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        return;
    }
}

/************************
 Description: Searches for the current position of the ant
 ***********************/



void Ant::findAntLocation(char **userPos, int rows, int columns)
{
	for (int count = 0; count < rows; count++)
	{
		for (int count2 = 0; count2 < columns; count2++)
		{
			if (userPos[count][count2] == '@')
			{
				currentRowOfAnt = count;
				currentColumnOfAnt = count2;
               
			}

			
		}

	}
}


/****************************
 Description: Prints out the current array
 ***************************/

void Ant::printMatrix(char **array, int rows, int columns)
{
    for (int count = 0; count < rows; count++)
    {
        for (int count2 = 0; count2 < columns; count2++)
        {
            cout << array[count][count2] << " ";
        }
        cout << endl;
    }
    
    
    
}

/*******************************************************************************
Description: this function will set the users position depending on what they choose.
it will then show where the ant is located. after that, since the ant is facing north
it will then move north one and then show the array.
 ******************************************************************************/
void Ant::setPosition(char **userPos, int rows, int columns, int positionChoice) //- sets current position in the array
{
    int firstArrayNumber, secondArrayNumber;
    
    if (positionChoice == 1)
    {
        userPos[rows / 2][columns / 2] = '@';
        
        
        findAntLocation(userPos, rows, columns);
        printMatrix(userPos, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        cin.get(pressAnyKey);
        
        
        
        
        if ((direction == 'n') && (userPos[currentRowOfAnt - 1][currentColumnOfAnt] == ' ') && (userPos[currentRowOfAnt][currentColumnOfAnt] == '@'))
        {
            userPos[currentRowOfAnt - 1][currentColumnOfAnt] = '@'; //tile above will now be the ant
            userPos[currentRowOfAnt][currentColumnOfAnt] = '#'; // tile below will be black
            
            direction = 'e';
            findAntLocation(userPos, rows, columns);
            setColor('b'); //makes the starting ant sitting in a black cell
            printMatrix(userPos, rows, columns);
            
            steps = steps - 1;
            cin.get(pressAnyKey);
            
            return;
        }
        
    }
    
    if (positionChoice == 2) //chosen in case the user chooses the top of the screen
    {
        cout << "Choose a number between 0 and " << (rows - 1) << endl;
        firstArrayNumber = stepValidation(rows, columns);
        cout << "Choose a number between 0 and " << (columns - 1) << endl;
        secondArrayNumber =  stepValidation(rows, columns);
        userPos[firstArrayNumber][secondArrayNumber] = '@';
        direction = 'n';
        
        
        findAntLocation(userPos, rows, columns);
        printMatrix(userPos, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        cin.get(pressAnyKey);
        edgeCheck(userPos,rows, columns);
        return;
        
        
    }

	    if (positionChoice == 3) //chosen in case the user chooses the top of the screen
    {
		srand(time(0));

        firstArrayNumber = (rand() % rows + 0);
        cout << "A a random location will be chosen." << endl;
        secondArrayNumber =  (rand() % columns + 0);
        userPos[firstArrayNumber][secondArrayNumber] = '@';
        direction = 'n';
        
        
        findAntLocation(userPos, rows, columns);
        printMatrix(userPos, rows, columns);
        steps = steps - 1;
        cin.get(pressAnyKey);
        cin.get(pressAnyKey);
        edgeCheck(userPos,rows, columns);
        return;
        
        
    }



}






void Ant::setSteps(int userSteps)
{
    steps = userSteps;
}

void Ant::setColor(char newColor)
{
    color = newColor;
}



void Ant::edgeCheck(char **array, int rows, int columns)
{
    if ((currentRowOfAnt == 0) && (direction == 'n'))
        direction = 's';
    
    if ((currentRowOfAnt == (rows -1)) && (direction == 's'))
        direction = 'n';
    
    if ((currentColumnOfAnt == 0) && (direction == 'w'))
        direction = 'e';
    
    if ((currentColumnOfAnt == (columns - 1)) && (direction == 'e'))
        direction = 'w';
}



void Ant::setTotalRowsColumns(int rows, int columns)
{
    totalRows = rows;
    totalColumns = columns;
}

int Ant::inputValidation()
{
    int number;
    while ((!(cin >> number) || (number < 1)))
    {
        cout << "Must be a number or greater than 0\n";
        cin.clear();
        cin.ignore(100, '\n');
        
        
        
    }
    return number;
}

int Ant::stepValidation(int rows, int columns)
{
    
    int number;
    while ((!(cin >> number) || (number < 0)) || (number >= rows))
    {
        cout << "Must be a number or greater than 0\n" << totalRows;
        cin.clear();
        cin.ignore(100, '\n');
        
        
        
    }
    return number;
    
}

int Ant::inputValidationYN()
{
    
    char inputYN;
    
    
    while (((cin >> inputYN)) || (inputYN != 'Y') || (inputYN != 'y') || (inputYN != 'N') || (inputYN != 'n'))
    {
        cout << "You must enter Y or N!\n";
        cin.clear();
        cin.ignore(100, '\n');
        
        if ((inputYN == 'y') || (inputYN == 'Y'))
        {
            cout << "Program restarting\n" << endl;
            return inputYN;
        }
        
        if ((inputYN == 'n') || (inputYN == 'N'))
        {
            cout << "Program ending\n" << endl;
            return inputYN;
        }


    }
    return 0;
    }

