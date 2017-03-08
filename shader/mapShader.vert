#version 110

uniform mat4 matrix;

void main(void){

	//output: the position of the vertex for the map
        gl_Position =  matrix * gl_Vertex;
}
