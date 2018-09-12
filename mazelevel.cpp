/*********************************************************************
** Program Filename: MazeLevel.hpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: implements the MazeLevel class
** Input:
** Output:
*********************************************************************/
#include "mazelevel.hpp"
#include <string>
#include <fstream>

/*********************************************************************
** Function: constructor
** Description: constructs the MazeLevel class
** Parameters: the file to read from, the height, and width of the level
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
MazeLevel::MazeLevel(std::ifstream& infile, int height, int width){
	this->height = height;
	this->width = width;
	std::string line;
	for(int i = 0; i < height; i++){
		std::vector<MazeLocation*> row;
		getline(infile, line);
		for(int j = 0; j <width; j++){
			if(line[j] == '#'){
				MazeLocation* loc = new Wall();
				row.push_back(loc);
			}
			else if(line[j] == '@'){
				MazeLocation* loc = new OpenSpace();
				loc->set_is_start(true);
				loc->set_has_explorer(true);
				this->origin_row = i;
				this->origin_col = j;
				row.push_back(loc);
			}
			else if(line[j] == '^'){
				MazeLocation* loc = new OpenSpace();
				loc->set_is_end(true);
				row.push_back(loc);
			}
			else if(line[j] == '%'){
				MazeLocation* loc = new OpenSpace();
				loc->set_has_instructor(true);
				row.push_back(loc);
			}
			else{
				MazeLocation* loc = new OpenSpace();
				row.push_back(loc);
			}
		}
		this->locations.push_back(row);
	}
};

/*********************************************************************
** Function: get_location
** Description: returns location at the row and columns
** Parameters: the row and column of the location
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
MazeLocation* MazeLevel::get_location(int row, int col){
	return this->locations[row][col];
};

/*********************************************************************
** Function: get_origin_row
** Description: returns the origin row of the location of the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
int MazeLevel::get_origin_row(){
	return this->origin_row;
};

/*********************************************************************
** Function: get_origin_col
** Description: returns the origin column of the location of the person
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
int MazeLevel::get_origin_col(){
	return this->origin_col;
};

/*********************************************************************
** Function: display_mazelevel
** Description: prints the level
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void MazeLevel::display_mazelevel(){
	for(int i = 0; i < height; i++){
		for(int j = 0; j <width; j++){
			std::cout <<this->locations[i][j]->get_char_rep();
		}
		std::cout <<std::endl;
	}
};

/*********************************************************************
** Function: destructor
** Description: destructor of the MazeLevel class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
MazeLevel::~MazeLevel(){
	for(int i =0; i < height; i++){
		for(int j =0; j < width; j++){
			delete this->locations[i][j];
		}
	}
};