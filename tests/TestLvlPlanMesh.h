#ifndef TESTLVLPLANMESH_H
#define TESTLVLPLANMESH_H

#include <QString>
#include <QtTest>

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
	 * @brief testNegativeHeightCase  Test the construction of the plan mesh
	 * with a negative height
	 */
	void testNegativeHeightCase();

	/**
	 * @brief testNegativeSizeCase Make sure an exception is thrown
	 * in case of negative size
	 */
	void testNegativeSizeCase();

	/**
	 * @brief testUsualCase Test the construction of the plan mesh
	 * with data that does not correspond to a corner case
	 */
	void testUsualCase();
};

#endif // TESTLVLPLANMESH_H
