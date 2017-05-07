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

#include "rendering/HeightMapMesh.h"

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
	 * @brief testNoDataCase Test the construction
	 * of the height map mesh with empty data
	 * Test indexing as well
	 */
	void testNoDataCase();

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

	/**
	 * @brief testUsualCase Test the construction of the height map mesh
	 * with data that does not correspond to a corner case
	 * Test indexing as well
	 */
	void testUsualCase();

};

#endif // TESTHEIGHTMAPMESH_H
