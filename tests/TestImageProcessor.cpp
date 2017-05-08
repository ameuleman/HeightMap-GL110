/**
*******************************************************************************
*
*  @file	TestImageProcessor.cpp
*
*  @brief	Class to test ImageProcessor class. Test applyLinearFilter, applyGradientNorm,
*  and applyCannyAnlgorithm method by calling processImage. Also check if loadData method
* throws the right exceptions.
*
*  @author	Andréas Meuleman
*******************************************************************************
*/


//******************************************************************************
//  Include
//******************************************************************************
#include "TestImageProcessor.h"
#include "imageProcessing/ImageProcessor.h"

//------------------------------------------------------------------------------
TestImageProcessor::TestImageProcessor()
//------------------------------------------------------------------------------
{
}

//------------------------------------------------------------------------------
void TestImageProcessor::testErrorWrongFileNameCase()
//------------------------------------------------------------------------------
{
	QVERIFY_EXCEPTION_THROWN(
				ImageProcessor imageProcessor("WrongFileName");, std::runtime_error);
}

//------------------------------------------------------------------------------
void TestImageProcessor::testErrorNotGrayScaleCase()
//------------------------------------------------------------------------------
{
	QVERIFY_EXCEPTION_THROWN(
				ImageProcessor imageProcessor(":/notGrayScale.png");, std::runtime_error);
}

//------------------------------------------------------------------------------
void TestImageProcessor::testNoDataErrorCase()
//------------------------------------------------------------------------------
{
	ImageProcessor imageProcessor;
	Types::float_matrix emptyData;

	QVERIFY_EXCEPTION_THROWN(
				imageProcessor.setRawData(emptyData, 0, 0);, std::runtime_error);
}

//------------------------------------------------------------------------------
void TestImageProcessor::testSizesDoNotCorrespondErrorCase()
//------------------------------------------------------------------------------
{
	ImageProcessor imageProcessor;

	Types::float_matrix inputData({Types::float_line({0.f, 0.f}),
								   Types::float_line({0.f, 0.f})});

	QVERIFY_EXCEPTION_THROWN(
				imageProcessor.setRawData(inputData, 2, 1);, std::runtime_error);
}

//------------------------------------------------------------------------------
void TestImageProcessor::testZerosCase()
//------------------------------------------------------------------------------
{
	ImageProcessor imageProcessor;

	Types::float_matrix inputData({Types::float_line({0.f, 0.f}),
								   Types::float_line({0.f, 0.f})});

	imageProcessor.setRawData(inputData, 2, 2);

	Types::float_matrix expectedSmoothedData({Types::float_line({0.f, 0.f}),
								   Types::float_line({0.f, 0.f})});

	Types::float_matrix expectedGradientData({Types::float_line({0.f, 0.f}),
								   Types::float_line({0.f, 0.f})});

	Types::float_matrix expectedCannyData({Types::float_line({0.f, 0.f}),
								   Types::float_line({0.f, 0.f})});

	QVERIFY2(imageProcessor.getSmoothedData() == expectedSmoothedData,
			 "Problem during linear filtering");

	QVERIFY2(imageProcessor.getGradientData() == expectedGradientData,
			 "Problem while calculating gradient norm");

	QVERIFY2(imageProcessor.getCannyData() == expectedCannyData,
			 "Problem while applying Canny algorithm");
}

//------------------------------------------------------------------------------
void TestImageProcessor::testOnesCase()
//------------------------------------------------------------------------------
{
	ImageProcessor imageProcessor;

	Types::float_matrix inputData({Types::float_line({1.f, 1.f}),
								   Types::float_line({1.f, 1.f})});

	imageProcessor.setRawData(inputData, 2, 2);


	Types::float_matrix expectedSmoothedData({Types::float_line({1.f, 1.f}),
								   Types::float_line({1.f, 1.f})});

	Types::float_matrix expectedGradientData({Types::float_line({0.f, 0.f}),
								   Types::float_line({0.f, 0.f})});

	Types::float_matrix expectedCannyData({Types::float_line({0.f, 0.f}),
								   Types::float_line({0.f, 0.f})});

	QVERIFY2(imageProcessor.getCannyData() == expectedCannyData,
			 "Problem while applying Canny algorithm");

	//Calculate a difference between expected and found results to compensate
	//float imprecision.
	const float acceptance = 0.0001f;

	float smoothDataDelta(0.f);
	float gradientDataDelta(0.f);

	for(int i(0); i<2;i++)
		for(int j(0); j<2; j++)
		{
			smoothDataDelta = std::max(
						std::abs(expectedSmoothedData[i][j]-imageProcessor.getSmoothedData()[i][j]),
						smoothDataDelta);

			gradientDataDelta = std::max(
						std::abs(expectedGradientData[i][j]-imageProcessor.getGradientData()[i][j]),
						gradientDataDelta);
		}


	//check if the delta is small enough to accept the results
	QVERIFY2(smoothDataDelta < acceptance,
			 "Problem during linear filtering");

	QVERIFY2(gradientDataDelta < acceptance,
			 "Problem while calculating gradient norm");
}

//------------------------------------------------------------------------------
void TestImageProcessor::testUsualCase()
//------------------------------------------------------------------------------
{
	ImageProcessor imageProcessor;

	Types::float_matrix inputData({Types::float_line({0.2f, 0.8f}),
								   Types::float_line({0.8f, 0.5f})});

	imageProcessor.setRawData(inputData, 2, 2);

	Types::float_matrix expectedSmoothedData({Types::float_line({0.5075f, 0.5962f}),
								   Types::float_line({0.5962f, 0.6f})});

	Types::float_matrix expectedGradientData({Types::float_line({0.1254f, 0.0888f}),
								   Types::float_line({0.0888f, 0.00534f})});

	Types::float_matrix expectedCannyData({Types::float_line({1.f, 0.f}),
								   Types::float_line({0.f, 0.f})});

	QVERIFY2(imageProcessor.getCannyData() == expectedCannyData,
			 "Problem while applying Canny algorithm");

	//Calculate a difference between expected and found results to compensate
	//float imprecision.
	const float acceptance = 0.0001f;

	float smoothDataDelta(0.f);
	float gradientDataDelta(0.f);

	for(int i(0); i<2;i++)
		for(int j(0); j<2; j++)
		{
			smoothDataDelta = std::max(
						std::abs(expectedSmoothedData[i][j]-imageProcessor.getSmoothedData()[i][j]),
						smoothDataDelta);

			gradientDataDelta = std::max(
						std::abs(expectedGradientData[i][j]-imageProcessor.getGradientData()[i][j]),
						gradientDataDelta);
		}


	//check if the delta is small enough to accept the results
	QVERIFY2(smoothDataDelta < acceptance,
			 "Problem during linear filtering");

	QVERIFY2(gradientDataDelta < acceptance,
			 "Problem while calculating gradient norm");
}
