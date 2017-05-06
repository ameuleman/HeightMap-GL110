#ifndef TESTHEIGHTMAPMESH_H
#define TESTHEIGHTMAPMESH_H

#include <QString>
#include <QtTest>

#include "rendering/HeightMapMesh.h"

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
