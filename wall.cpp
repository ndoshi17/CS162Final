/*********************************************************************
** Program Filename: wall.hpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: implements the wall class
** Input:
** Output:
*********************************************************************/
#include "wall.hpp"

/*********************************************************************
** Function: constructor
** Description: constructs the wall class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
Wall::Wall(){

}

/*********************************************************************
** Function: is_occupiable
** Description: returns whether the location is occupiable
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool Wall::is_occupiable(){
	return false;
}

/*********************************************************************
** Function: get_char_rep
** Description: returns the character representation of the location
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
char Wall::get_char_rep(){
	return '#';
}
