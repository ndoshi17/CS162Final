/*********************************************************************
** Program Filename: main.cpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: runs the game, but all the logic happens in the maze class
** Input:
** Output:
*********************************************************************/
#include <iostream>
#include "MazeLocation.hpp"
#include "wall.hpp"
#include "openspace.hpp"
#include "mazelevel.hpp"
#include "mazeperson.hpp"
#include "intrepidStudent.hpp"
#include "maze.hpp"
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <ctime>

int main(int argc, char const *argv[]){
	std::string datafile = argv[1];
	std::ifstream infile;
	infile.open(datafile.c_str());
	if(infile.fail()){
		std:: cerr << "Error opening file. Please check the file name." << std::endl;
		return 1;
	}
	else{
		std:: cout << "File opened!" << std:: endl;
	}
	int levels;
	int rows;
	int cols;
	infile >> levels;
	infile >> rows;
	infile >> cols;
	std::cout << "Welcome to the game of CS 162. You will be traversing a maze. If TA gets into an adjacent spot or the same spot as you, you will be reset to the beginning of the level unless you have demonstrated a programming skill which will appease the TAs for ten turns." << std::endl;
	Maze m(infile, levels, rows, cols);
	m.display_cur_level();
	char move;
	int count = 1;
	while(m.move()){
		m.display_cur_level();
	}
	return 0;
}