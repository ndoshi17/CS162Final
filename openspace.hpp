/*********************************************************************
** Program Filename: openspace.cpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: interfaces the OpenSpace class
** Input:
** Output:
*********************************************************************/
#ifndef __OPENSPACE_HPP
#define __OPENSPACE_HPP
#include <iostream>
#include "MazeLocation.hpp"


class OpenSpace :public MazeLocation {
private:
	bool explorer;
	bool start;
	bool end;
	bool instructor;
	bool ta;
	bool skill;
public:
	OpenSpace();
	virtual bool is_occupiable();
	virtual char get_char_rep();
	virtual void set_has_explorer(bool has);
	virtual bool has_explorer();
	virtual void set_has_instructor(bool has);
	virtual bool has_instructor();
	virtual void set_has_ta(bool has);
	virtual bool has_ta();
	virtual void set_has_skill(bool has);
	virtual bool has_skill();
	virtual void set_is_start(bool is);
	virtual bool is_start();
	virtual void set_is_end(bool is);
	virtual bool is_end();

};


#endif