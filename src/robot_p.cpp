/*
 * robot_p.cpp
 *
 *  Created on: Dec 31, 2015
 *      Author: Joshua Southerland
 */

#include "robot_p.hpp"

namespace Private
{

Robot::Robot()
{
	// TODO Auto-generated constructor stub

}

Robot::~Robot()
{
	// TODO Auto-generated destructor stub
}

Robot * Robot::instance()
{
	static Robot instance;

	return &instance;
}

const battlecreek::robot_states & Robot::getRobotStates() const
{
	return robot_states_;
}

void Robot::setRobotStates(const battlecreek::robot_states & robot_states)
{
	robot_states_ = robot_states;
}

const battlecreek::battlehill_state & Robot::getBattlehillState() const
{
	return battlehill_state_;
}

void Robot::setBattlehillState(const battlecreek::battlehill_state & battlehill_state)
{
	battlehill_state_ = battlehill_state;
}

} /* namespace Private */