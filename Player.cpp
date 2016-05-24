#include <iostream>
#include <string>
#include <vector>
#include "mhshl.h"
#include "mhshlUtils.h"

Player::Player(){
	team = "NUL";
	name = "NULL";
	gp = g = a = pp = sh = pim = goalStreak = pointStreak = min = shots = ga = gaa = sv = svpercent = 0;
}

Player::Player(std::string tID, std::string gname, int identifier, int num){
	team = tID;
	name = gname;
	number = num;
	id = identifier;
	goalie = false;
	gp = g = a = pp = sh = pim = goalStreak = pointStreak = min = shots = ga = gaa = sv = svpercent = 0;
}

void Player::printHeading(){
	std::cout<<"\n             name                 ID   #  team  gp  g  a  pp  sh  pim  goalStreak  pointStreak\n";
}

void Player::printString(){
	spaceBuffer(30, name);
	spaceBuffer(8, std::to_string(id));
	spaceBuffer(3, std::to_string(number));
	spaceBuffer(6, team);
	spaceBuffer(4, std::to_string(gp));
	spaceBuffer(3, std::to_string(g));
	spaceBuffer(3, std::to_string(a));
	spaceBuffer(4, std::to_string(pp));
	spaceBuffer(4, std::to_string(sh));
	spaceBuffer(5, std::to_string(pim));
	spaceBuffer(12, std::to_string(goalStreak));
	spaceBuffer(13, std::to_string(pointStreak));
	std::cout<<"\n";
}


void Player::printGoalieHeading(){
	std::cout<<"\n             name                 ID   #  team  gp   mins  ga  sa  sv    gaa       svpercent\n";
}

void Player::printGoalieString(){
	spaceBuffer(30, name);
	spaceBuffer(8, std::to_string(id));
	spaceBuffer(3, std::to_string(number));
	spaceBuffer(6, team);
	spaceBuffer(4, std::to_string(gp));
	spaceBuffer(5, std::to_string(min));
	spaceBuffer(5, std::to_string(ga));
	spaceBuffer(5, std::to_string(shots));
	spaceBuffer(5, std::to_string(sv));
	spaceBuffer(10, std::to_string(gaa));
	spaceBuffer(10, std::to_string(svpercent));
	std::cout<<"\n";
}
