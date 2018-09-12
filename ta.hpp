/*********************************************************************
** Program Filename: ta.cpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: implements the ta class which inherits from MazePerson
** Input:
** Output:
*********************************************************************/
#ifndef __TA_HPP
#define __TA_HPP
#include <cstdlib>
#include <iostream>
#include "mazeperson.hpp"

class TA : public MazePerson {
private:
	int row;
	int col;
	bool appeased;
	int appease_time;
public:
	TA();
	virtual char get_move();
	virtual void set_location(int row, int col);
	virtual int get_row();
	virtual int get_col();
	virtual char get_type();
	virtual void appease();
	virtual bool check_appease();
	virtual void decrement_time();
	virtual void reset_appease_time();

}; 


#endif