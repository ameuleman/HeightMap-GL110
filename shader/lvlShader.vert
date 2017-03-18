//******************************************************************************
//      OpenGL 2.0
//******************************************************************************
#version 110

/**
*******************************************************************************
*
*  @file       lvlShader.vert
*
*  @brief      vertex shader to display the transparant lvl plan without shading
*
*  @author     Andréas Meuleman
*******************************************************************************
*/

//******************************************************************************
//	Uniform variables
//******************************************************************************
uniform mat4 mvpMatrix;

//---------
void main()
//---------
{
	//Output position of the vertex
        gl_Position = mvpMatrix * gl_Vertex;
}
