#ifndef TESTIMAGEPROCESSOR_H
#define TESTIMAGEPROCESSOR_H

#include <QString>
#include <QtTest>

class TestImageProcessor : public QObject
{
	Q_OBJECT

public:
	TestImageProcessor();

private Q_SLOTS:
	/**
	 * @brief testErrorWrongFileNameCase Check if the right exception
	 * is thrown when the file can't be opened
	 */
	void testErrorWrongFileNameCase();

	/**
	 * @brief testErrorNotGrayScaleCase Check if the right exception
	 * is thrown when the file leads to a picture with a non-expected format (e.g. not grayscale)
	 */
	void testErrorNotGrayScaleCase();

	/**
	 * @brief testNoDataCase Test the case with no input data
	 */
	void testNoDataCase();

	/**
	 * @brief testZerosCase Test case with zeros as input data
	 */
	void testZerosCase();

	/**
	 * @brief testOnesCase Test case with ones as input data
	 */
	void testOnesCase();

	/**
	 * @brief testUsualCase Test case with data that does not correspond to a corner case
	 * Expected data are calculated thanks to matlab.
	 */
	void testUsualCase();
};

#endif // TESTIMAGEPROCESSOR_H
