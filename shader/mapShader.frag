#version 110

void main(void){

	//output: the distance of the fragment
	gl_FragDepth  = gl_FragCoord.z;
}
