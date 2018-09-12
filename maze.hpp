/*********************************************************************
** Program Filename: maze.hpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: interfaces the Maze class
** Input:
** Output:
*********************************************************************/
#ifndef __MAZE_HPP
#define __MAZE_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include "MazeLocation.hpp"
#include "wall.hpp"
#include "openspace.hpp"
#include "mazelevel.hpp"
#include "mazeperson.hpp"
#include "intrepidStudent.hpp"
#include "ta.hpp"
#include "instructor.hpp"

class Maze{
private:
	std::vector<MazeLevel*> levels;
	int num_levels;
	int rows;
	int cols;
	int current_level;
	bool shown_skill;
	bool delay;
	std::vector<MazePerson*> people;
	std::vector<int*> skills;
	void add_skills();
	void add_tas();
public:
	Maze(std::ifstream& infile, int levels, int rows, int cols);
	void decrement_ta_time();
	MazeLevel* get_cur_level();
	void display_cur_level();
	bool move();
	void reset_level();
	void reset_maze();
	bool check_ta();
	bool check_instructor();
	void set_level(int level);
	bool check_at_ladder();
	~Maze();
};


#endif