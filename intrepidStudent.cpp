/*********************************************************************
** Program Filename: intrepidStudent.hpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: implements the intrepidStudent class which inherits from MazePerson
** Input:
** Output:
*********************************************************************/
#include "intrepidStudent.hpp"

/*********************************************************************
** Function: constructor
** Description: constructs the intrepidStudent class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
IntrepidStudent::IntrepidStudent(){
	this->row = -1;
	this->col = -1;
	this->skills = 0;
	srand(time(NULL));
};

/*********************************************************************
** Function: get_move
** Description: returns the character of the move for the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
char IntrepidStudent::get_move(){
	std::string read;
	std::cin>> read;
	return read[0];
};

/*********************************************************************
** Function: set_location
** Description: sets the location of the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void IntrepidStudent::set_location(int row, int col){
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
int IntrepidStudent::get_row(){
	return this->row;
};

/*********************************************************************
** Function: get_col
** Description: returns the column of the location of the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
int IntrepidStudent::get_col(){
	return this->col;
};

/*********************************************************************
** Function: get_type
** Description: returns the type of the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
char IntrepidStudent::get_type(){
	return 'e';
};

/*********************************************************************
** Function: add_skill
** Description: adds one skill to the student
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void IntrepidStudent::add_skill(){
	this->skills += 1;
};

/*********************************************************************
** Function: reduce_skill
** Description: removes one skill to the student
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void IntrepidStudent::reduce_skill(){
	if(this->skills > 0){
		this->skills -= 1;
		std::cout << "You demonstrated a programming skill and have appeased all TAs for 10 turns" << std::endl;
	}
};

/*********************************************************************
** Function: get_skills
** Description: returns the amount of skills the student has
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
int IntrepidStudent::get_skills(){
	return this->skills;
};

/*********************************************************************
** Function: remove_skill
** Description: removes all skills to the student
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void IntrepidStudent::remove_skills(){
	this->skills = 0;
};