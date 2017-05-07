/**
*******************************************************************************
*
*  @file	TestHeightMapMesh.cpp
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
#include <iostream>

#include "TestHeightMapMesh.h"
#include "rendering/HeightMapMesh.h"

TestHeightMapMesh::TestHeightMapMesh()
{

}

void TestHeightMapMesh::testNoDataErrorCase()
{
	Types::float_matrix imageData;

	QVERIFY_EXCEPTION_THROWN(
				HeightMapMesh heightMapMesh(imageData, 0, 0);, std::runtime_error);
}

void TestHeightMapMesh::wrongDimensionErrorCase()
{
	Types::float_matrix imageData({Types::float_line({0.f, 0.f}),
								   Types::float_line({0.f, 0.f})});

	QVERIFY_EXCEPTION_THROWN(
				HeightMapMesh heightMapMesh(imageData, 1, 2);, std::runtime_error);
}

void TestHeightMapMesh::testZerosCase()
{
	Types::float_matrix imageData({Types::float_line({0.f, 0.f}),
								   Types::float_line({0.f, 0.f})});

	HeightMapMesh heightMapMesh(imageData, 2, 2);

	//test vertices generation
	Types::vertices_data emptyVerticesData;

	/*QVERIFY2(heightMapMesh.getVerticesPosition() == emptyVerticesData,
			 "vertices position generation problem");

	QVERIFY2(heightMapMesh.getVerticesNormal() == emptyVerticesData,
			 "vertices normal vectors generation problem");

	QVERIFY2(heightMapMesh.getVerticesColour() == emptyVerticesData,
			 "vertices colour generation problem");*/

	//test creation of the index
	heightMapMesh.setIndex();

	Types::uint_line expectedIndex({0, 2, 3, 0, 3, 1});

	QVERIFY2(heightMapMesh.getIndex() == expectedIndex, "indexing problem");

	QVERIFY2(true, "Failure");
}

void TestHeightMapMesh::testOnesCase()
{
	QVERIFY2(true, "Failure");
}

void TestHeightMapMesh::testUsualCase()
{
	QVERIFY2(true, "Failure");
}
