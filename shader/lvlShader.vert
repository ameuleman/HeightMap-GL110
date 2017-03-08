#version 110

uniform mat4 mvpMatrix;

void main() {
	//Output position of the vertex
        gl_Position = mvpMatrix * gl_Vertex;
}
