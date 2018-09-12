/*********************************************************************
** Program Filename: maze.cpp
** Author: Nihar Doshi
** Date: 5 March 2018
** Description: implements the Maze class
** Input:
** Output:
*********************************************************************/
#include "maze.hpp"

/*********************************************************************
** Function: constructor
** Description: constructs the Maze class
** Parameters: file to read from, number of levels, the height, and width of the levels
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
Maze::Maze(std::ifstream& infile, int num_levels, int rows, int cols){
	srand(time(NULL));
	this->num_levels = num_levels;
	this->rows = rows;
	this->cols = cols;
	this->current_level = 0;
	this->shown_skill = false;
	this->delay = false;
	std::string fline;
	getline(infile, fline);
	for(int i = 0; i < this->num_levels; i++){
		MazeLevel* level = new MazeLevel(infile, rows, cols);
		this->levels.push_back(level);
	}
	MazePerson* student = new IntrepidStudent();
	this->people.push_back(student);
	this->people[0]->set_location(get_cur_level()->get_origin_row(), get_cur_level()->get_origin_col());
	MazePerson* ta1 = new TA();
	this->people.push_back(ta1);
	MazePerson* ta2 = new TA();
	this->people.push_back(ta2);
	add_tas();
	MazePerson* instructor = new Instructor();
	this->people.push_back(instructor);
	int* skill1 = new int[2];
	int* skill2 = new int[2];
	int* skill3 = new int[2];
	this->skills.push_back(skill1);
	this->skills.push_back(skill2);
	this->skills.push_back(skill3);
	add_skills();
};

/*********************************************************************
** Function: add_skills
** Description: adds three skills to the current level
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Maze::add_skills(){
	int i;
	int j;
	bool not_added = true;
	for(int x= 0; x < 3; x++){
		while(not_added){
			i = rand()%this->rows;
			j = rand()%this->cols;
			if(get_cur_level()->get_location(i, j)->is_occupiable()){
				if(!(get_cur_level()->get_location(i, j)->has_skill()) && !(get_cur_level()->get_location(i, j)->is_end()) && !(get_cur_level()->get_location(i, j)->has_instructor())){
					get_cur_level()->get_location(i,j)->set_has_skill(true);
					this->skills[x][0] = i;
					this->skills[x][1] = j;
					not_added = false;
				}
			}
		}
		not_added = true;
	}
};

/*********************************************************************
** Function: add_tas
** Description: adds two tas to the current level
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Maze::add_tas(){
	int i;
	int j;
	bool not_added = true;
	while(not_added){
		i = rand()%this->rows;
		j = rand()%this->cols;
		if(get_cur_level()->get_location(i, j)->is_occupiable()){
			get_cur_level()->get_location(i,j)->set_has_ta(true);
			this->people[1]->set_location(i,j);
			not_added = false;
		}
	}
	not_added = true;
	while(not_added){
		i = rand()%this->rows;
		j = rand()%this->cols;
		if(get_cur_level()->get_location(i, j)->is_occupiable()){
			get_cur_level()->get_location(i,j)->set_has_ta(true);
			this->people[2]->set_location(i,j);
			not_added = false;
		}
	}
};

/*********************************************************************
** Function: decrement_ta_time
** Description: reduces the tas appeasal time 
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Maze::decrement_ta_time(){
	for(int i = 1; i < 3; i++){
		this->people[i]->decrement_time();
	}
};

/*********************************************************************
** Function: get_cur_level
** Description: returns the current level of the maze 
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
MazeLevel* Maze::get_cur_level(){
	return this->levels[this->current_level];
};

/*********************************************************************
** Function: display_cur_level
** Description: prints the current level of the maze 
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Maze::display_cur_level(){
	this->levels[this->current_level]->display_mazelevel();
};

/*********************************************************************
** Function: move
** Description: moves all people in the maze 
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: ends function before getting to all people if player uses p 
*********************************************************************/
bool Maze::move(){
	for(int i = 0; i < people.size(); i++){
		char move = this->people[i]->get_move();
		int move_row = 0;
		int move_col = 0;
		if(move == 'w'){
			move_row = -1;
			move_col = 0;
		}
		else if(move == 'a'){
			move_row = 0;
			move_col = -1;
		}
		else if(move == 's'){
			move_row = 1;
			move_col = 0;
		}
		else if(move == 'd'){
			move_row = 0;
			move_col = 1;
		}
		else if(move == 'u'){
			if(check_at_ladder()){
				//check this
				for(int i =0; i<this->skills.size(); i++){
					get_cur_level()->get_location(this->skills[i][0], this->skills[i][1])->set_has_skill(false);
				}
				for(int i = 1; i < 3; i++){
					get_cur_level()->get_location(this->people[i]->get_row(), this->people[i]->get_col())->set_has_ta(false);
					get_cur_level()->get_location(this->people[i]->get_row(), this->people[i]->get_col())->set_has_ta(false);
				}
				get_cur_level()->get_location(this->people[0]->get_row(), this->people[0]->get_col())->set_has_explorer(false);
				this->current_level += 1;
				this->people[0]->set_location(get_cur_level()->get_origin_row(), get_cur_level()->get_origin_col());
				this->people[1]->reset_appease_time();
				this->people[2]->reset_appease_time();
			}
			add_tas();
			add_skills();  
		}
		else if(move == 'p'){
			if(this->people[i]->get_skills() > 0){
				this->people[i]->reduce_skill();
				for(int i = 1; i < 3; i++){
					this->people[i]->appease();		
				}
				this->shown_skill = true;
				this->delay = true;
				break;
			}
			std::cout << "You have no programming skills" << std::endl;
		}
		else{
			continue;
		}
		if(get_cur_level()->get_location(this->people[i]->get_row() + move_row, this->people[i]->get_col() + move_col)->is_occupiable()){
			if(this->people[i]->get_type() == 'e'){
				get_cur_level()->get_location(this->people[i]->get_row(), this->people[i]->get_col())->set_has_explorer(false);
				get_cur_level()->get_location(this->people[i]->get_row() + move_row, this->people[i]->get_col() + move_col)->set_has_explorer(true);
				this->people[i]->set_location(this->people[i]->get_row() + move_row, this->people[i]->get_col() + move_col);
			}
			else if(this->people[i]->get_type() == 't'){
				get_cur_level()->get_location(this->people[i]->get_row(), this->people[i]->get_col())->set_has_ta(false);
				get_cur_level()->get_location(this->people[i]->get_row() + move_row, this->people[i]->get_col() + move_col)->set_has_ta(true);
				this->people[i]->set_location(this->people[i]->get_row() + move_row, this->people[i]->get_col() + move_col);
			}
		}
		if(this->people[i]->get_type() == 'e'){
			if(get_cur_level()->get_location(this->people[i]->get_row(), this->people[i]->get_col())->has_skill()){
				this->people[i]->add_skill();
				std::cout << "You picked up a new skill. You have " << this->people[i]->get_skills() << " skills." << std::endl;
				get_cur_level()->get_location(this->people[i]->get_row(), this->people[i]->get_col())->set_has_skill(false);
			}
		}
		

	}
	if(check_ta() && !(this->people[1]->check_appease())){
		std::cout << "You were caught by a TA, you have to restart the level" << std::endl;
		reset_level();
	}
	decrement_ta_time();

	if(check_instructor()){
		if(this->people[0]->get_skills() > 3){
			std::cout << "You have won the game!!! Congrats you passed CS 162" << std::endl;
			return false;
		}
		else{
			std::cout << "You failed the class, now you have to restart the maze." << std::endl;
			reset_maze();
		}
	}
	return true;
};

/*********************************************************************
** Function: reset_level
** Description: resets the current level 
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: reset level
*********************************************************************/
void Maze::reset_level(){
	int row_start = get_cur_level()->get_origin_row();
	int col_start = get_cur_level()->get_origin_col();
	get_cur_level()->get_location(this->people[0]->get_row(), this->people[0]->get_col())->set_has_explorer(false);
	get_cur_level()->get_location(row_start, col_start)->set_has_explorer(true);
	this->people[0]->set_location(row_start, col_start);
	for(int i =0; i<this->skills.size(); i++){
		get_cur_level()->get_location(this->skills[i][0], this->skills[i][1])->set_has_skill(false);
	}
	for(int i = 1; i < 3; i++){
		get_cur_level()->get_location(this->people[i]->get_row(), this->people[i]->get_col())->set_has_ta(false);
		get_cur_level()->get_location(this->people[i]->get_row(), this->people[i]->get_col())->set_has_ta(false);
	}
	add_skills();
	add_tas();
	this->people[0]->remove_skills();
};

/*********************************************************************
** Function: reset_maze
** Description: resets the current maze 
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: resets the entire maze
*********************************************************************/
void Maze::reset_maze(){
	get_cur_level()->get_location(this->people[0]->get_row(), this->people[0]->get_col())->set_has_explorer(false);
	for(int i =0; i<this->skills.size(); i++){
		get_cur_level()->get_location(this->skills[i][0], this->skills[i][1])->set_has_skill(false);
	}
	for(int i = 1; i < 3; i++){
		get_cur_level()->get_location(this->people[i]->get_row(), this->people[i]->get_col())->set_has_ta(false);
		get_cur_level()->get_location(this->people[i]->get_row(), this->people[i]->get_col())->set_has_ta(false);
	}
	this->current_level = 0;
	int row_start = get_cur_level()->get_origin_row();
	int col_start = get_cur_level()->get_origin_col();
	get_cur_level()->get_location(row_start, col_start)->set_has_explorer(true);
	this->people[0]->set_location(row_start, col_start);
	this->people[0]->remove_skills();
	add_tas();
	add_skills();
};

/*********************************************************************
** Function: check_ta
** Description: checks if there is a ta adjacent to the player
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool Maze::check_ta(){
	if(get_cur_level()->get_location(this->people[0]->get_row(), this->people[0]->get_col())->is_occupiable()){
		if(get_cur_level()->get_location(this->people[0]->get_row(), this->people[0]->get_col())->has_ta()){
			return true;
		}
	}
	if(get_cur_level()->get_location(this->people[0]->get_row() + 1, this->people[0]->get_col() + 0)->is_occupiable()){
		if(get_cur_level()->get_location(this->people[0]->get_row() + 1, this->people[0]->get_col() + 0)->has_ta()){
			return true;
		}
	}
	if(get_cur_level()->get_location(this->people[0]->get_row() - 1, this->people[0]->get_col() + 0)->is_occupiable()){
		if(get_cur_level()->get_location(this->people[0]->get_row() - 1, this->people[0]->get_col() + 0)->has_ta()){
			return true;
		}
	}
	if(get_cur_level()->get_location(this->people[0]->get_row() + 0, this->people[0]->get_col() + 1)->is_occupiable()){
		if(get_cur_level()->get_location(this->people[0]->get_row() + 0, this->people[0]->get_col() + 1)->has_ta()){
			return true;
		}
	}
	if(get_cur_level()->get_location(this->people[0]->get_row() + 0, this->people[0]->get_col() - 1)->is_occupiable()){
		if(get_cur_level()->get_location(this->people[0]->get_row() + 0, this->people[0]->get_col() - 1)->has_ta()){
			return true;
		}
	}
	return false;
};

/*********************************************************************
** Function: check_instructor
** Description: checks if instructor is adjacent to the player
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool Maze::check_instructor(){
	if(get_cur_level()->get_location(this->people[0]->get_row(), this->people[0]->get_col())->is_occupiable()){
		if(get_cur_level()->get_location(this->people[0]->get_row(), this->people[0]->get_col())->has_instructor()){
			return true;
		}
	}
	if(get_cur_level()->get_location(this->people[0]->get_row() + 1, this->people[0]->get_col() + 0)->is_occupiable()){
		if(get_cur_level()->get_location(this->people[0]->get_row() + 1, this->people[0]->get_col() + 0)->has_instructor()){
			return true;
		}
	}
	if(get_cur_level()->get_location(this->people[0]->get_row() - 1, this->people[0]->get_col() + 0)->is_occupiable()){
		if(get_cur_level()->get_location(this->people[0]->get_row() - 1, this->people[0]->get_col() + 0)->has_instructor()){
			return true;
		}
	}
	if(get_cur_level()->get_location(this->people[0]->get_row() + 0, this->people[0]->get_col() + 1)->is_occupiable()){
		if(get_cur_level()->get_location(this->people[0]->get_row() + 0, this->people[0]->get_col() + 1)->has_instructor()){
			return true;
		}
	}
	if(get_cur_level()->get_location(this->people[0]->get_row() + 0, this->people[0]->get_col() - 1)->is_occupiable()){
		if(get_cur_level()->get_location(this->people[0]->get_row() + 0, this->people[0]->get_col() - 1)->has_instructor()){
			return true;
		}
	}
	return false;
};

/*********************************************************************
** Function: set_level
** Description: sets the level of the maze
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
void Maze::set_level(int level){
	this->current_level = level;
}

/*********************************************************************
** Function: check_at_ladder
** Description: checks if player is on top of the ladder
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
bool Maze::check_at_ladder(){
	if(get_cur_level()->get_location(this->people[0]->get_row(), this->people[0]->get_col())->is_end()){
		display_cur_level();
		return true;
	}
	return false;
};

/*********************************************************************
** Function: destructor
** Description: destructor of the Maze class
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
Maze::~Maze(){
	for(int i = 0; i <num_levels; i++){
		delete levels[i];
	}
	for(int i = 0; i <this->people.size(); i++){
		delete people[i];
	}
	for(int i =0 ; i< this->skills.size(); i++){
		delete[] skills[i];
	}
};