#pragma once
#ifndef RUBIXCUBE_H
#define RUBIXCUBE_H

#include "Cubie.h"
#include <vector>


class RubixCube {


public:

	RubixCube();
	~RubixCube();

	void drawCubes();
	void updateCubes();
private:
	std::vector<Cubie> cubes;
	float angle = .5;

};




#endif // !RUBIXCUBE_H
