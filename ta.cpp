/*********************************************************************
** Program Filename: ta.hpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: implements the ta class which inherits from MazePerson
** Input:
** Output:
*********************************************************************/
#include "ta.hpp"

/*********************************************************************
** Function: constructor
** Description: constructs the ta class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
TA::TA(){
	this->row = -1;
	this->col = -1;
	this->appeased = false;
	this->appease_time = 0;
};

/*********************************************************************
** Function: get_move
** Description: returns the character of the move for the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: return move
*********************************************************************/
char TA::get_move(){
	int ran = (int)rand()%4;
	if(ran == 0){
		return 'w';
	}
	else if(ran == 1){
		return 'a';
	}
	else if(ran == 2){
		return 's';
	}
	else{
		return 'd';
	}
};

/*********************************************************************
** Function: set_location
** Description: sets the location of the person
** Parameters: row and columns
** Pre-Conditions: None
** Post-Conditions: sets locations
*********************************************************************/
void TA::set_location(int row, int col){
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
int TA::get_row(){
	return this->row;
};

/*********************************************************************
** Function: get_col
** Description: returns the column of the location of the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
int TA::get_col(){
	return this->col;
};

/*********************************************************************
** Function: get_type
** Description: returns the type of the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
char TA::get_type(){
	return 't';
};

/*********************************************************************
** Function: appease
** Description: appeases the ta
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void TA::appease(){
	this->appeased = true;
	this->appease_time = 10;
};

/*********************************************************************
** Function: check_appease
** Description: returns whether the ta is appeased or not
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool TA::check_appease(){
	return this->appeased;
};

/*********************************************************************
** Function: decrement_time
** Description: reduces the time of appeasement
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void TA::decrement_time(){
	this->appease_time -= 1;
	if(this->appease_time <= 0){
		this->appeased = false;
	}
};

/*********************************************************************
** Function: reset_appease_time
** Description: sets appease time to 0
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void TA::reset_appease_time(){
	this->appease_time = 0;
};