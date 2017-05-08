#ifndef TESTIMAGEPROCESSOR_H
#define TESTIMAGEPROCESSOR_H

/**
*******************************************************************************
*  @file	TestImageProcessor.h
*
*  @brief	Class to test ImageProcessor class. Test applyLinearFilter, applyGradientNorm,
*  and applyCannyAnlgorithm method by calling processImage. Also check if loadData method
* throws the right exceptions.
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
*  @brief  TestHeightMapMesh is a Class to test ImageProcessor class. Test applyLinearFilter, applyGradientNorm,
*  and applyCannyAnlgorithm method by calling processImage. Also check if loadData method
* throws the right exceptions.
*/
//==============================================================================
class TestImageProcessor : public QObject
{
	Q_OBJECT

public:
	TestImageProcessor();

private Q_SLOTS:
	/**
	 * @brief testErrorWrongFileNameCase Check if the exception
	 * is thrown when the file can't be opened
	 */
	void testErrorWrongFileNameCase();

	/**
	 * @brief testErrorNotGrayScaleCase Check if the exception
	 * is thrown when the file leads to a picture with a non-expected format (e.g. not grayscale)
	 */
	void testErrorNotGrayScaleCase();

	/**
	 * @brief testNoDataCase Check if the exception is thrown
	 * when we try to process an image with no data
	 */
	void testNoDataErrorCase();

	/**
	 * @brief testSizeDoesNotCorrespondErrorCase Check if the exception is thrown
	 * when we try to process an image and the specified sizes do not correspond
	 */
	void testSizesDoNotCorrespondErrorCase();

	/**
	 * @brief testZerosCase Test case with zeros as input data
	 * Check the behaviour of applyLinearFilter, applyGradientNorm and applyCannyAnlgorithm
	 */
	void testZerosCase();

	/**
	 * @brief testOnesCase Test case with ones as input data
	 * Check the behaviour of applyLinearFilter, applyGradientNorm and applyCannyAnlgorithm
	 */
	void testOnesCase();

	/**
	 * @brief testUsualCase Test case with data that does not correspond to a corner case
	 * Expected data are calculated thanks to matlab.
	 * Check the behaviour of applyLinearFilter, applyGradientNorm and applyCannyAnlgorithm
	 */
	void testUsualCase();
};

#endif // TESTIMAGEPROCESSOR_H
