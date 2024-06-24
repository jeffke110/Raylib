#pragma once
#ifndef CUBIE_H
#define CUBIE_H


#include "raylib.h"
#include <cmath>

class Cubie {


public:
	Cubie(Vector3 position);
	~Cubie();
	void draw();
	Vector3 position;
	float distance;
	float angle;

private:
	Vector3  size;
	float width;
	float height;
	float length;
};






#endif // !CUBIE_H
