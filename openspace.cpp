/*********************************************************************
** Program Filename: openspace.hpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: implements the OpenSpace class
** Input:
** Output:
*********************************************************************/
#include "openspace.hpp"

/*********************************************************************
** Function: constructor
** Description: constructs the openspace class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
OpenSpace::OpenSpace(){
	this->explorer = false;
	this->start = false;
	this->end = false;
	this->instructor = false;
	this->ta = false;
	this->skill = false;
}

/*********************************************************************
** Function: is_occupiable
** Description: returns whether the location is occupiable
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::is_occupiable(){
	return true;
};

/*********************************************************************
** Function: get_char_rep
** Description: returns the character representation of the location
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
char OpenSpace::get_char_rep(){
	if(is_start()){
		return '@';
	}
	else if(has_explorer()){
		return '*';
	}
	else if(is_end()){
		return '^';
	}
	else if(has_instructor()){
		// std::cout << "instructor" << std::endl;
		return '%';
	}
	else if(has_ta()){
		return 'T';
	}
	else if(has_skill()){
		return '$';
	}
	else{
		return ' ';
	}
};

/*********************************************************************
** Function: set_has_explorer
** Description: sets the location to have an explorer
** Parameters: whether the location have an explorer
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void OpenSpace::set_has_explorer(bool has){
	this->explorer = has;
};

/*********************************************************************
** Function: has_explorer
** Description: returns whether the location has an explorer
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::has_explorer(){
	return this->explorer;
};

/*********************************************************************
** Function: set_has_instructor
** Description: sets the location to have an instructor
** Parameters: whether the location have an instructor
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void OpenSpace::set_has_instructor(bool has){
	this->instructor = has;
};

/*********************************************************************
** Function: has_instructor
** Description: returns whether the location has an instructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::has_instructor(){
	return this->instructor;
};

/*********************************************************************
** Function: set_has_ta
** Description: sets the location to have an ta
** Parameters: whether the location have an ta
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void OpenSpace::set_has_ta(bool has){
	this->ta = has;
};

/*********************************************************************
** Function: has_ta
** Description: returns whether the location has an ta
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::has_ta(){
	return this->ta;
};

/*********************************************************************
** Function: set_has_skill
** Description: sets the location to have an skill
** Parameters: whether the location have a skill
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void OpenSpace::set_has_skill(bool has){
	this->skill = has;
};

/*********************************************************************
** Function: has_skill
** Description: returns whether the location has an skill
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::has_skill(){
	return this->skill;
};

/*********************************************************************
** Function: set_is_start
** Description: sets the location to have a start
** Parameters: whether the location is the start
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void OpenSpace::set_is_start(bool is){
	this->start = is;
};

/*********************************************************************
** Function: is_skill
** Description: returns whether the location is the beginning of the level
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::is_start(){
	return this->start;
};

/*********************************************************************
** Function: set_is_end
** Description: sets the location to be the end
** Parameters: whether the location is the end
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void OpenSpace::set_is_end(bool is){
	this->end = is;
};

/*********************************************************************
** Function: is_end
** Description: returns whether the location is the end of the level
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool OpenSpace::is_end(){
	return this->end;
}