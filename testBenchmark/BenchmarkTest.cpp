/**
*******************************************************************************
*
*  @file	BenchmarkTest.cpp
*
*  @brief	Class to benchmark image processing and vertices generation and indexing.
* Concern HeightMapMesh and ImageProcessing classes
*
*  @author	Andréas Meuleman
*******************************************************************************
*/


//******************************************************************************
//  Include
//******************************************************************************
#include <QString>
#include <QtTest>
#include <iostream>

#include "imageProcessing/ImageProcessor.h"
#include "rendering/HeightMapMesh.h"

/**
 * @brief The BenchmarkTest class benchmark image processing and
 * vertices generation and indexing.
 * Concern HeightMapMesh and ImageProcessing classes
 */
class BenchmarkTest : public QObject
{
	Q_OBJECT

public:
	BenchmarkTest();

private Q_SLOTS:
	/**
	 * @brief testImageProcessingCase test the performance of
	 * image processing methods from ImageProcessing
	 */
	void testImageProcessingCase();

	/**
	 * @brief testVerticesGenerationCase test the performance of
	 * generateVertices method from HeightMapMesh by calling its constructor
	 */
	void testVerticesGenerationCase();

	/**
	 * @brief testSetIndexCase test the performance of setIndex
	 * method from mesh using its child class HeightMapMesh
	 */
	void testSetIndexCase();
};

//------------------------------------------------------------------------------
BenchmarkTest::BenchmarkTest()
//------------------------------------------------------------------------------
{
}

//------------------------------------------------------------------------------
void BenchmarkTest::testImageProcessingCase()
//------------------------------------------------------------------------------
{
	try
	{
		ImageProcessor imageProcessor(":/largeImage.jpg");
		QBENCHMARK
		{
			imageProcessor.processImage();
		}
	}
	catch(std::exception e)
	{
		std::cerr<<e.what();
	}
}

//------------------------------------------------------------------------------
void BenchmarkTest::testVerticesGenerationCase()
//------------------------------------------------------------------------------
{
	try
	{
		ImageProcessor imageProcessor(":/largeImage.jpg");
		QBENCHMARK
		{
			HeightMapMesh heightMapMesh(imageProcessor.getRawData(), imageProcessor.getN(), imageProcessor.getM());
		}
	}
	catch(std::exception e)
	{
		std::cerr<<e.what();
	}
}

//------------------------------------------------------------------------------
void BenchmarkTest::testSetIndexCase()
//------------------------------------------------------------------------------
{
	try
	{
		ImageProcessor imageProcessor(":/largeImage.jpg");
		HeightMapMesh heightMapMesh(imageProcessor.getRawData(), imageProcessor.getN(), imageProcessor.getM());

		QBENCHMARK
		{
			heightMapMesh.setIndex();
		}
	}
	catch(std::exception e)
	{
		std::cerr<<e.what();
	}
}

QTEST_APPLESS_MAIN(BenchmarkTest)

#include "BenchmarkTest.moc"
