/*********************************************************************
** Program Filename: wall.hpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: interfaces the wall class
** Input:
** Output:
*********************************************************************/
#ifndef __WALL_HPP
#define __WALL_HPP
#include <iostream>
#include "MazeLocation.hpp"


class Wall :public MazeLocation {
public:
	Wall();
	virtual bool is_occupiable();
	virtual char get_char_rep();
};





#endif