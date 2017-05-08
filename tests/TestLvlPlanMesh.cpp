/**
*******************************************************************************
*  @file	TestLvlPlanMesh.cpp
*
*  @brief	Class to test LvlPlan class. Test its creation by
* calling LvlPlan constructor.
*******************************************************************************
*/

//******************************************************************************
//  Include
//******************************************************************************
#include "TestLvlPlanMesh.h"
#include "rendering/LvlPlan.h"

//------------------------------------------------------------------------------
TestLvlPlanMesh::TestLvlPlanMesh()
//------------------------------------------------------------------------------
{

}

//------------------------------------------------------------------------------
void TestLvlPlanMesh::testNullSizeCase()
//------------------------------------------------------------------------------
{
	LvlPlan lvlPlan(0.f, 0.f, 0.f);

	Types::vertices_data expectedPosition({QVector3D(0.f, 0.f, 0.f),
										   QVector3D(0.f, 0.f, 0.f),
										   QVector3D(0.f, 0.f, 0.f),
										   QVector3D(0.f, 0.f, 0.f),
										   QVector3D(0.f, 0.f, 0.f),
										   QVector3D(0.f, 0.f, 0.f)});

	Types::vertices_data emptyNormal;

	Types::vertices_data emptyColour;

	QVERIFY2(lvlPlan.getVerticesPosition() == expectedPosition,
			 "vertices position generation problem");

	QVERIFY2(lvlPlan.getVerticesNormal() == emptyNormal,
			 "vertices normal vectors generation problem");

	QVERIFY2(lvlPlan.getVerticesColour() == emptyColour,
			 "vertices colour generation problem");
}

//------------------------------------------------------------------------------
void TestLvlPlanMesh::testNullHeightCase()
//------------------------------------------------------------------------------
{
	LvlPlan lvlPlan(0.f, 2.f, 1.f);

	Types::vertices_data expectedPosition({QVector3D(0.f, 0.f, 0.f),
										   QVector3D(0.f, 1.f, 0.f),
										   QVector3D(2.f, 0.f, 0.f),
										   QVector3D(0.f, 1.f, 0.f),
										   QVector3D(2.f, 1.f, 0.f),
										   QVector3D(2.f, 0.f, 0.f)});

	Types::vertices_data emptyNormal;

	Types::vertices_data emptyColour;

	QVERIFY2(lvlPlan.getVerticesPosition() == expectedPosition,
			 "vertices position generation problem");

	QVERIFY2(lvlPlan.getVerticesNormal() == emptyNormal,
			 "vertices normal vectors generation problem");

	QVERIFY2(lvlPlan.getVerticesColour() == emptyColour,
			 "vertices colour generation problem");
}

//------------------------------------------------------------------------------
void TestLvlPlanMesh::testUsualCase()
//------------------------------------------------------------------------------
{
	LvlPlan lvlPlan(5.f, 2.f, 3.f);

	Types::vertices_data expectedPosition({QVector3D(0.f, 0.f, 5.f),
										   QVector3D(0.f, 3.f, 5.f),
										   QVector3D(2.f, 0.f, 5.f),
										   QVector3D(0.f, 3.f, 5.f),
										   QVector3D(2.f, 3.f, 5.f),
										   QVector3D(2.f, 0.f, 5.f)});

	Types::vertices_data emptyNormal;

	Types::vertices_data emptyColour;

	QVERIFY2(lvlPlan.getVerticesPosition() == expectedPosition,
			 "vertices position generation problem");

	QVERIFY2(lvlPlan.getVerticesNormal() == emptyNormal,
			 "vertices normal vectors generation problem");

	QVERIFY2(lvlPlan.getVerticesColour() == emptyColour,
			 "vertices colour generation problem");
}
