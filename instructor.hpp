/*********************************************************************
** Program Filename: instructor.cpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: interfaces the instructor class which inherits from MazePerson
** Input:
** Output:
*********************************************************************/
#ifndef __INSTRUCTOR_HPP
#define __INSTRUCTOR_HPP
#include <cstdlib>
#include <iostream>
#include "mazeperson.hpp"

class Instructor : public MazePerson {
private:
	int row;
	int col;
public:
	Instructor();
	virtual char get_move();
	virtual void set_location(int row, int col);
	virtual int get_row();
	virtual int get_col();
	virtual char get_type();
}; 


#endif