#ifndef TESTLVLPLANMESH_H
#define TESTLVLPLANMESH_H

/**
*******************************************************************************
*
*  @file	TestLvlPlanMesh.h
*
*  @brief	Class to test LvlPlan class. Test its creation by
* calling LvlPlan constructor.
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
*  @brief  TestHeightMapMesh is a Class to test LvlPlan class. Test its creation by
* calling LvlPlan constructor.
*/
//==============================================================================
class TestLvlPlanMesh : public QObject
{
	Q_OBJECT

public:
	TestLvlPlanMesh();

private Q_SLOTS:
	/**
	 * @brief testNullSizeCase Test the construction of the plan mesh
	 * with zero as width and length
	 */
	void testNullSizeCase();

	/**
	 * @brief testNullHeightCase Test the construction of the plan mesh
	 * with one as width and length ans zero as height
	 */
	void testNullHeightCase();

	/**
	 * @brief testUsualCase Test the construction of the plan mesh
	 * with data that does not correspond to a corner case
	 */
	void testUsualCase();
};

#endif // TESTLVLPLANMESH_H
