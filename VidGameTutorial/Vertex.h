#pragma once

#include <GL/glew.h>

//Should be a multiple of 4
struct Vertex {
	float position[2];
	GLubyte color[4];
};
