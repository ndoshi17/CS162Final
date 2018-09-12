/*********************************************************************
** Program Filename: intrepidStudent.cpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: interfaces the intrepidStudent class which inherits from MazePerson
** Input:
** Output:
*********************************************************************/
#ifndef __INTREPIDSTUDENT_HPP
#define __INTREPIDSTUDENT_HPP
#include <cstdlib>
#include <iostream>
#include "mazeperson.hpp"

class IntrepidStudent : public MazePerson {
private:
	int row;
	int col;
	int skills;
public:
	IntrepidStudent();
	virtual char get_move();
	virtual void set_location(int row, int col);
	virtual int get_row();
	virtual int get_col();
	virtual char get_type();
	virtual void add_skill();
	virtual void reduce_skill();
	virtual int get_skills();
	virtual void remove_skills();
}; 


#endif