#ifndef TESTHEIGHTMAPMESH_H
#define TESTHEIGHTMAPMESH_H

/**
*******************************************************************************
*
*  @file	TestHeightMapMesh.h
*
*  @brief	Class to test HeightMapMesh class. Test generateVertices  method by
* calling HeightMapMesh constructor. Also test setIndex function from its
* parent class Mesh.
*
*  @author	Andréas Meuleman
*******************************************************************************
*/


//******************************************************************************
//  Include
//******************************************************************************
#include <QString>
#include <QtTest>

//==============================================================================
/**
*  @class  TestHeightMapMesh
*  @brief  TestHeightMapMesh is a Class to test HeightMapMesh class.
* Test generateVertices method by calling HeightMapMesh constructor.
* Also test setIndex function from its parent class: Mesh.
*/
//==============================================================================
class TestHeightMapMesh : public QObject
{
	Q_OBJECT

public:
	TestHeightMapMesh();

private Q_SLOTS:
	/**
	 * @brief testNoDataErrorCase check if the exception is thrown when their is no input data
	 */
	void testNoDataErrorCase();

	/**
	 * @brief wrongDimensionErrorCase check if the exception is thrown when
	 * the specified sizes do not correspond to input data
	 */
	void wrongDimensionErrorCase();

	/**
	 * @brief testZerosCase Test the construction of the height map mesh
	 * with zeros as input data
	 * Test indexing as well
	 */
	void testZerosCase();

	/**
	 * @brief testOnesCaseTest the construction of the height map mesh
	 * with ones as input data
	 * Test indexing as well
	 */
	void testOnesCase();
};

#endif // TESTHEIGHTMAPMESH_H
