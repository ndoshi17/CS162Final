/*********************************************************************
** Program Filename: instructor.hpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: implements the instructor class which inherits from MazePerson
** Input:
** Output:
*********************************************************************/
#include "instructor.hpp"

/*********************************************************************
** Function: constructor
** Description: constructs the instructor class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
Instructor::Instructor(){
	this->row = -1;
	this->col = -1;
};

/*********************************************************************
** Function: get_move
** Description: returns the character of the move for the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
char Instructor::get_move(){
	return 'o';
};

/*********************************************************************
** Function: set_location
** Description: sets the location of the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Instructor::set_location(int row, int col){
	this->row = row;
	this->col = col;
};

/*********************************************************************
** Function: get_row
** Description: returns the row of the location of the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
int Instructor::get_row(){
	return this->row;
};

/*********************************************************************
** Function: get_col
** Description: returns the column of the location of the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
int Instructor::get_col(){
	return this->col;
};

/*********************************************************************
** Function: get_type
** Description: returns the type of the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
char Instructor::get_type(){
	return 'i';
};
