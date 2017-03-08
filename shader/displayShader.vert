#version 110

varying  vec3 col;
varying  vec3 nor;
varying  vec3 eyeDir;
varying  vec4 shadowCoord;

uniform mat4 mvpMatrix;
uniform vec3 cameraPos;
uniform mat4 shadowMapMatrix;

void main() {
        col = gl_Color.xyz;
        nor = gl_Normal;

	//direction of the eye (from the camera to the vertex, because reflexion of lightDir is from the light to the fragment)
        eyeDir = normalize(gl_Vertex.xyz - cameraPos);

	//coordinates of the vertex for the shadow map
        shadowCoord = shadowMapMatrix * gl_Vertex;
	
	//Output position of the vertex
        gl_Position = mvpMatrix * gl_Vertex;
}
