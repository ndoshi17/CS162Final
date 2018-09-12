/*********************************************************************
** Program Filename: MazeLocation.hpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: interfaces the MazeLocation class
** Input:
** Output:
*********************************************************************/
#ifndef __MAZELOCATION_HPP
#define __MAZELOCATION_HPP
#include <iostream>

class MazeLocation{
private:

public:
	virtual bool is_occupiable() = 0;
	virtual char get_char_rep() = 0;
	virtual void set_is_end(bool is){};
	virtual bool is_end(){};
	virtual void set_is_start(bool is){};
	virtual bool is_start(){};
	virtual void set_has_explorer(bool has){};
	virtual bool has_explorer(){};
	virtual void set_has_ta(bool has){};
	virtual bool has_ta(){};
	virtual void set_has_skill(bool has){};
	virtual bool has_skill(){};
	virtual void set_has_instructor(bool has){};
	virtual bool has_instructor(){};
};


#endif