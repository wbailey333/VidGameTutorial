#version 130
//The fragment shader operates on each pixel in a given polygon

//This is the 3 component float vector that get outputted to the screen for each pixel
out vec3 color;

void main(){
	//Just hardcoded the color to red
	//Color order is (red, green, blue)
	color = vec3(1.0, 0.0, 1.0);
}