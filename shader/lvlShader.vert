#version 110

in vec4 position;

uniform mat4 mvpMatrix;

void main() {
	//Output position of the vertex
	gl_Position = mvpMatrix * position;
}
