
#ifndef HEIGHTMAPMESH_H
#define HEIGHTMAPMESH_H

/**
*******************************************************************************
*
*  @file       HeightMapMesh.h
*
*  @brief      Classe permettant de créer  un modèle pour une carte de niveau
*	à patir d'un fichier ou de données pour l'afficher avec OpenGL
*******************************************************************************
*/

//******************************************************************************
//  Include
//******************************************************************************
#include <string>
#include <vector>
#include <QtGui/QOpenGLShaderProgram>
#include <QVector3D>

#include "Mesh.h"

//==============================================================================
/**
*  @class  HeightMapMesh
*  @brief  Classe permettant de créer  un modèle pour une carte de niveau
*	à patir d'un fichier ou de données pour l'afficher avec OpenGL
*/
//==============================================================================
class HeightMapMesh: public Mesh{
public:

	/**
	 * @brief HeightMapMesh Constructeur surcharché avec le nom du fichier.
	 * Le fichier doit contenir la largeur, la hauteur et les données dans l'indervalle [0,1]
	 * @param fileName le nom du fichier de données
	 */
	HeightMapMesh(std::string const& fileName);

	/**
	 * @brief HeightMapMesh Constructeur surchargé avec les données et la taille de la carte de niveau
	 * @param imageData données de la carte de niveau dans l'intervalle [0,1]
	 * @param n hauteur de la carte de niveau
	 * @param m largeur de la carte de niveau
	 */
	HeightMapMesh(std::vector<std::vector<float>> const& imageData, unsigned int n, unsigned int m);

	virtual ~HeightMapMesh();

	/**
	 * @brief getLength calcule la longueur du modèle de la carte de niveau
	 * @return la longueur du modèle de la carte de niveau
	 */
	float getLength() const;

	/**
	 * @brief getWidth calcule la largeur du modèle de la carte de niveau
	 * @return la largeur du modèle de la carte de niveau
	 */
	float getWidth() const;

	//Getters
	unsigned int getN() const;
	unsigned int getM() const;

//******************************************************************************
private:
	//Pas de constructeur par défaut
	HeightMapMesh();

	//Pas de constructeur par copie
	HeightMapMesh(HeightMapMesh const&);

	/**
	 * @brief create crée le modèle
	 * @param imageData les données dans l'intervalle [0,1]
	 */
	void create(std::vector<std::vector<float>> const& imageData);

	/**
	 * @brief transforme le vecteur de données en trois vector<QVector3D>
	 * qui pourront être utilisés par la fenêtre de rendu (position, couleur and vecteurs normaux)
	 * Les bornes permettent de traîter le tableau en parallèle
	 * @param size multiplie la position de tous les points par cette valeur
	 * @param imageData données de la carte de niveau dans l'intervalle [0,1]
	 * @param leftIndex traitement à partir de cet index
	 * @param rightIndex jusqu'à cet index
	 */
	void generateVertices(float size, std::vector<std::vector<float>> const& imageData,
						  unsigned int leftIndex, unsigned int rightIndex);

	unsigned int m_n, //nombre de lignes
		m_m; //nombre de colomnes
};

#endif //HEIGHTMAPMESH_H
