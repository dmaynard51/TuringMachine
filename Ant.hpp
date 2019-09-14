//	
//  Ant.hpp	
//  Langton Ant	
//	
//  Created by Daniel Maynard on 6/28/17.	
//  Copyright å© 2017 Daniel Maynard. All rights reserved.	
//	
#ifndef Ant_hpp	
#define Ant_hpp	
	
class Ant	
{	
private:	
    char direction; // - current direction of the ant	
    int position; // - current position in the array of the ant	
	char color; // color of the ant
	int currentRowOfAnt;
	int currentColumnOfAnt;
    	
    int previousRowOfAnt;	
    int previousColumnOfAnt;
    
    int totalRows;
    int totalColumns;
    	

public:	
    Ant();	

    void setPosition(char **userPos, int rows, int columns, int positionChoice); //- sets current position in the array"
    void makeMove(char **array, int rows, int columns);
	void findAntLocation(char **userPos, int rows, int columns);
    	
    void printMatrix(char **array, int rows, int columns);
    	
    char pressAnyKey;	
    	

    	

    	
    void setSteps(int userSteps);	
    	
    int steps;	
    	
    void setColor(char color);	
    	
    	
;	
    
    void edgeCheck(char **userPos, int rows, int columns);
    
    void setTotalRowsColumns(int rows, int columns);
    
    int inputValidation();
    
    int stepValidation(int rows, int columns);
    
    int inputValidationYN();
    
    	
};	
#endif /* Ant_hpp */	
