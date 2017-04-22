#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

/**
*******************************************************************************
*  @file       ImageProcessor.h
*
*  @brief      Classe permettant de lire une image en niveau de gris et d'effectuer un traitement.
*  Utilise l'algorithme de Canny pour la détection de contours et stock les étapes intermédiaires.
*******************************************************************************
*/


//******************************************************************************
//  Include
//******************************************************************************
#include <QVector2D>
#include <QImage>


//******************************************************************************
//  Type definition
//******************************************************************************
typedef std::vector<float> float_line;
typedef std::vector<float_line> image_matrix;

//==============================================================================
/**
*  @class  ImageProcessor
*  @brief  ImageProcessor Classe permettant de lire une image en niveau de gris
* et d'effectuer un traitement.
* Utilise l'algorithme de Canny pour la détection de contours
* et stock les étapes intermédiaires.
*/
//==============================================================================
class ImageProcessor
{
public:
	/**
	 * @brief ImageProcessor constructeur surchargé avec le nom du fichier à lire
	 * Lit le fichier puis effectue le traitement
	 * @param fileName nom de l'image à lire
	 * @throws
	 */
	ImageProcessor(std::string const& fileName);

	/**
	 * @brief ImageProcessor constructeur par défaut, cré un ImageProcessor vide
	 */
	ImageProcessor();

	/**
	 * @brief loadData Charge le fichier en le stockant en tant que image_matrix
	 * @param fileName nom de l'image à lire
	 * @throws
	 */
	void loadData(std::string const& fileName);

	/**
	 * @brief processImage applique l'algorithme de Canny et stock les étapes intermédiaires.
	 * @throws
	 */
	void processImage();

	/**
	 * @brief getRawData récupère les données correspondant à une image
	 * @return données avant le traitement
	 */
	image_matrix getRawData() const;

	/**
	 * @brief getSmoothedData récupère les données correspondant à une image
	 * @return données après filtrage linéaire
	 */
	image_matrix getSmoothedData() const;

	/**
	 * @brief getGradientData récupère les données correspondant à une image
	 * @return la norme du gradient sur chaque pixel
	 */
	image_matrix getGradientData() const;

	/**
	 * @brief getCannyData récupère les données correspondant à une image
	 * @return données issues de l'algorithme de Canny
	 */
	image_matrix getCannyData() const;

	/**
	 * @brief getM Récupère la taille de l'image
	 * @return nombre de colomnes
	 */
	unsigned int getM() const;

	/**
	 * @brief getN Récupère la taille de l'image
	 * @return nombre de lignes
	 */
	unsigned int getN() const;

//******************************************************************************
private:
	/**
	 * @brief obtainLowerIndices enlève un à chaque index en l'entrée si possible
	 * @param i le premier index
	 * @param j le second index
	 * @return la paire d'indices moins un si au dessus de 0
	 */
	std::pair<int, int> obtainLowerIndices(int i, int j);

	/**
	 * @brief obtainUpperIndices ajoute un à chaque index en l'entrée si possible
	 * @param i le premier index
	 * @param j le second index
	 * @return la paire d'indices plus un si n dessous de la taille des données
	 */
	std::pair<int, int> obtainUpperIndices(int i, int j);

	/**
	 * @brief applyLinearFilter applique un filtre linéaire sur les données originales
	 * et crée les données lissées m_smoothedData
	 * Les bornes permettent de traîter le tableau en parallèle
	 * @param linearFilter le filtre linéaire à appliquer
	 * @param leftIndex traitement à partir de cet index
	 * @param rightIndex jusqu'à cet index
	 */
	void applyLinearFilter(image_matrix const& linearFilter,
						   unsigned int leftIndex, unsigned int rightIndex);

	/**
	 * @brief applyGradientNorm Calcule la norme du gradient pour chaque pixel
	 * et le stock dans m_gradientData. Stock ausi les angles des gradients dans m_gradientsAngles
	 * Les bornes permettent de traîter le tableau en parallèle
	 * @param leftIndex traitement à partir de cet index
	 * @param rightIndex jusqu'à cet index
	 */
	void applyGradientNorm(unsigned int leftIndex, unsigned int rightIndex);

	/**
	 * @brief applyCannyAlgorithm Applique l'algorithm de Canny et stock le résultat dans m_cannyData
	 * Les bornes permettent de traîter le tableau en parallèle
	 * @param leftIndex traitement à partir de cet index
	 * @param rightIndex jusqu'à cet index
	 */
	void applyCannyAlgorithm(unsigned int leftIndex, unsigned int rightIndex);

	image_matrix m_rawData, //Données avant le traitement
		m_smoothedData, //données après filtrage linéaire
		m_gradientData, //la norme du gradient sur chaque pixel
		m_cannyData; //données issues de l'algorithme de Canny

	//les angles des gradients
	image_matrix m_gradientsAngles;

	unsigned int m_m, //nombre de colomnes
		m_n; //,ombre de lignes
};

#endif // IMAGEPROCESSOR_H
