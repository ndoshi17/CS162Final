/*********************************************************************
** Program Filename: openspace.hpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: interfaces the MazeLevel class
** Input:
** Output:
*********************************************************************/
#ifndef __MAZELEVEL_HPP
#define __MAZELEVEL_HPP
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "MazeLocation.hpp"
#include "wall.hpp"
#include "openspace.hpp"

class MazeLevel{
private:
	std::vector<std::vector<MazeLocation*> > locations;
	int height;
	int width;
	int origin_row;
	int origin_col;
public:
	MazeLevel(std::ifstream& infile, int height, int width);
	MazeLocation* get_location(int row, int col);
	int get_origin_row();
	int get_origin_col();
	void display_mazelevel();
	~MazeLevel();
};


#endif