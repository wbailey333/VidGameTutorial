#version 130

// The vertex shader operates on each vertex

// Input data from the VBO. Each vertex has 2 floats
in vec2 vertexPosition;

void main (){
	//Set the x,y postion on the screen
	gl_Position.xy = vertexPosition;
	//The z postion is zero since we are in 2d
	gl_Position.z = 0.0;
	//Indicate that the coordinates are normalize
	gl_Position.w = 1.0;
}