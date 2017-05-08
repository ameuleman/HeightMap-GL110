/**
*******************************************************************************
*  @file	TestHeightMapMesh.cpp
*
*  @brief	Class to test HeightMapMesh class. Test generateVertices  method by
* calling HeightMapMesh constructor. Also test setIndex function from its
* parent class Mesh.
*******************************************************************************
*/


//******************************************************************************
//  Include
//******************************************************************************
#include "TestHeightMapMesh.h"
#include "rendering/HeightMapMesh.h"

//------------------------------------------------------------------------------
TestHeightMapMesh::TestHeightMapMesh()
//------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------
void TestHeightMapMesh::testNoDataErrorCase()
//------------------------------------------------------------------------------
{
	Types::float_matrix imageData;

	QVERIFY_EXCEPTION_THROWN(
				HeightMapMesh heightMapMesh(imageData, 0, 0);, std::runtime_error);
}

//------------------------------------------------------------------------------
void TestHeightMapMesh::wrongDimensionErrorCase()
//------------------------------------------------------------------------------
{
	Types::float_matrix imageData({Types::float_line({0.f, 0.f}),
								   Types::float_line({0.f, 0.f})});

	QVERIFY_EXCEPTION_THROWN(
				HeightMapMesh heightMapMesh(imageData, 1, 2);, std::runtime_error);
}

//------------------------------------------------------------------------------
void TestHeightMapMesh::testZerosCase()
//------------------------------------------------------------------------------
{
	Types::float_matrix imageData({Types::float_line({0.f, 0.f}),
								   Types::float_line({0.f, 0.f})});

	HeightMapMesh heightMapMesh(imageData, 2, 2);

	//test vertices generation
	Types::vertices_data expectedPosition({QVector3D(0.f, 0.f, 0.f),
										  QVector3D(150.f, 0.f, 0.f),
										  QVector3D(150.f, 150.f, 0.f),
										  QVector3D(0.f, 0.f, 0.f),
										  QVector3D(150.f, 150.f, 0.f),
										  QVector3D(0.f, 150.f, 0.f)});

	Types::vertices_data expectedNormal({QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f)});

	Types::vertices_data expectedColour({QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f)});

	QVERIFY2(heightMapMesh.getVerticesPosition() == expectedPosition,
			 "vertices position generation problem");

	QVERIFY2(heightMapMesh.getVerticesNormal() == expectedNormal,
			 "vertices normal vectors generation problem");

	QVERIFY2(heightMapMesh.getVerticesColour() == expectedColour,
			 "vertices colour generation problem");

	//test creation of the index
	heightMapMesh.setIndex();

	Types::uint_line expectedIndex({0, 2, 3, 0, 3, 1});

	QVERIFY2(heightMapMesh.getIndex() == expectedIndex, "indexing problem");

	//test data reorganisation
	Types::vertices_data expectedIndexedPosition({QVector3D(0.f, 0.f, 0.f),
												  QVector3D(0.f, 150.f, 0.f),
												  QVector3D(150.f, 0.f, 0.f),
												  QVector3D(150.f, 150.f, 0.f)});

	Types::vertices_data expectedIndexedNormal({QVector3D(0.f, 0.f, 1.f),
												QVector3D(0.f, 0.f, 1.f),
												QVector3D(0.f, 0.f, 1.f),
												QVector3D(0.f, 0.f, 1.f)});

	Types::vertices_data expectedIndexedColour({QVector3D(0.f, 0.f, 1.f),
												QVector3D(0.f, 0.f, 1.f),
												QVector3D(0.f, 0.f, 1.f),
												QVector3D(0.f, 0.f, 1.f)});

	QVERIFY2(heightMapMesh.getVerticesPosition() == expectedIndexedPosition,
			 "vertices position indexing problem");

	QVERIFY2(heightMapMesh.getVerticesNormal() == expectedIndexedNormal,
			 "vertices normal vectors indexing problem");

	QVERIFY2(heightMapMesh.getVerticesColour() == expectedIndexedColour,
			 "vertices colour indexing problem");
}

//------------------------------------------------------------------------------
void TestHeightMapMesh::testOnesCase()
//------------------------------------------------------------------------------
{
	Types::float_matrix imageData({Types::float_line({1.f, 1.f}),
								   Types::float_line({1.f, 1.f})});

	HeightMapMesh heightMapMesh(imageData, 2, 2);

	//test vertices generation
	Types::vertices_data expectedPosition({QVector3D(0.f, 0.f, 50.f),
										  QVector3D(150.f, 0.f, 50.f),
										  QVector3D(150.f, 150.f, 50.f),
										  QVector3D(0.f, 0.f, 50.f),
										  QVector3D(150.f, 150.f, 50.f),
										  QVector3D(0.f, 150.f, 50.f)});

	Types::vertices_data expectedNormal({QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f),
										 QVector3D(0.f, 0.f, 1.f)});

	Types::vertices_data expectedColour({QVector3D(1.f, 0.f, 0.f),
										 QVector3D(1.f, 0.f, 0.f),
										 QVector3D(1.f, 0.f, 0.f),
										 QVector3D(1.f, 0.f, 0.f),
										 QVector3D(1.f, 0.f, 0.f),
										 QVector3D(1.f, 0.f, 0.f)});

	QVERIFY2(heightMapMesh.getVerticesPosition() == expectedPosition,
			 "vertices position generation problem");

	QVERIFY2(heightMapMesh.getVerticesNormal() == expectedNormal,
			 "vertices normal vectors generation problem");

	QVERIFY2(heightMapMesh.getVerticesColour() == expectedColour,
			 "vertices colour generation problem");

	//test creation of the index
	heightMapMesh.setIndex();

	Types::uint_line expectedIndex({0, 2, 3, 0, 3, 1});

	QVERIFY2(heightMapMesh.getIndex() == expectedIndex, "indexing problem");

	//test data reorganisation
	Types::vertices_data expectedIndexedPosition({QVector3D(0.f, 0.f, 50.f),
												  QVector3D(0.f, 150.f, 50.f),
												  QVector3D(150.f, 0.f, 50.f),
												  QVector3D(150.f, 150.f, 50.f)});

	Types::vertices_data expectedIndexedNormal({QVector3D(0.f, 0.f, 1.f),
												QVector3D(0.f, 0.f, 1.f),
												QVector3D(0.f, 0.f, 1.f),
												QVector3D(0.f, 0.f, 1.f)});

	Types::vertices_data expectedIndexedColour({QVector3D(1.f, 0.f, 0.f),
												QVector3D(1.f, 0.f, 0.f),
												QVector3D(1.f, 0.f, 0.f),
												QVector3D(1.f, 0.f, 0.f)});

	QVERIFY2(heightMapMesh.getVerticesPosition() == expectedIndexedPosition,
			 "vertices position indexing problem");

	QVERIFY2(heightMapMesh.getVerticesNormal() == expectedIndexedNormal,
			 "vertices normal vectors indexing problem");

	QVERIFY2(heightMapMesh.getVerticesColour() == expectedIndexedColour,
			 "vertices colour indexing problem");
}
