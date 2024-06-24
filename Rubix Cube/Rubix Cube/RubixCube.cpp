#include "RubixCube.h"


RubixCube::RubixCube() {

	Vector3 position = { -.33, -.33, .33 };
	float angle = 0;
	for (int k = 0; k < 3; k++) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cubes.push_back(Cubie(position));
				cubes.back().angle = angle;
				position.x += .33;
				angle += 40;
			}
			position.x = -.33;
			position.z -= .33;
		}
		angle = 0;
		position.z = .33;
		position.y += .33;
	}

}
RubixCube::~RubixCube() {


}

void RubixCube::drawCubes() {
	for (auto& cubie : cubes) {
		cubie.draw();
	}

}

void RubixCube::updateCubes()
{
	for (int i = 0; i < 1; i++) {
		cubes[i].angle += angle;
		cubes[i].position.x = cubes[i].distance * cosf(cubes[i].angle * DEG2RAD);
		cubes[i].position.z = cubes[i].distance * sinf(cubes[i].angle * DEG2RAD);
	}

}

