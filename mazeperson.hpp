/*********************************************************************
** Program Filename: mazeperson.hpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: interface the Mazeperson class
** Input:
** Output:
*********************************************************************/
#ifndef __MAZEPERSON_HPP
#define __MAZEPERSON_HPP
#include <cstdlib>

class MazePerson{
public:
	virtual char get_move() = 0;
	virtual void set_location(int row, int col){};
	virtual int get_row(){};
	virtual int get_col(){};
	virtual char get_type(){};
	virtual void add_skill(){};
	virtual void reduce_skill(){};
	virtual int get_skills(){};
	virtual void remove_skills(){};
	virtual void appease(){};
	virtual bool check_appease(){};
	virtual void decrement_time(){};
	virtual void reset_appease_time(){};
}; 


#endif