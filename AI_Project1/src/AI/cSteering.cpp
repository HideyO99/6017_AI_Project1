#include "cSteering.h"

cSteering::cSteering()
{
}

cSteering::~cSteering()
{
}

cSteering::cSteering(glm::vec3* pos, glm::vec3* dir, glm::vec3* v)
{
	this->position = pos;
	this->faceDir = dir;
	this->velocity = v;
}

void cSteering::Seek(glm::vec3 Target_Pos)
{
	*this->faceDir = Target_Pos - *this->position;
	*this->faceDir = glm::normalize(*this->faceDir);
	
	//return *this->faceDir;
}

void cSteering::Flee(glm::vec3 Target_Pos)
{
	*this->faceDir = *this->position - Target_Pos;
	*this->faceDir = glm::normalize(*this->faceDir);


}

void cSteering::Pursues(glm::vec3 Target_Pos, glm::vec3 Target_velocity)
{
	glm::vec3 lookAhead_Pos = Target_Pos + (Target_velocity);
	*this->faceDir = lookAhead_Pos - (*this->position);
	*this->faceDir = glm::normalize(*this->faceDir);
}

void cSteering::Evades(glm::vec3 Target_Pos, glm::vec3 Target_velocity)
{
	glm::vec3 lookAhead_Pos = Target_Pos + (Target_velocity);
	*this->faceDir = *this->position - lookAhead_Pos;
	*this->faceDir = glm::normalize(*this->faceDir);
}

void cSteering::Approches(glm::vec3 Target_Pos)
{

}
