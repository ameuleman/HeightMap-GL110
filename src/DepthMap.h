#ifndef DEPTHMAP_H
#define DEPTHMAP_H

/**
*******************************************************************************
*
*  @file       DepthMap.h
*
*  @brief      Classe permettant de rendre un modèle à un buffer afin
*			de créer, par exemple, une shadow map.
*******************************************************************************
*/


//******************************************************************************
//  Include
//******************************************************************************
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QMatrix4x4>
#include <QOpenGLTexture>
#include <vector>
#include <memory>

#include "Mesh.h"

//==============================================================================
/**
*  @class  DepthMap
*  @brief  La classe DepthMap permet de rendre un modèle vers un buffer afin
*			de créer, par exemple, une shadow map
*/
//==============================================================================
class DepthMap: protected QOpenGLFunctions {

public:
	DepthMap();

	~DepthMap();

	/**
	 * @brief initialize Initialise le buffer
	 */
	void initialize();

	/**
	 * @brief render rend vers le frame buffer,
	 * appel initialize() si elle n'a jamais été appelée auparavant
	 * @param mesh le modèle à rendre
	 * @param matrix la matrice de projection
	 * @param program le programme de shader OpenGL pour créer la depth map
	 */
	void render(Mesh &mesh, QMatrix4x4 const& matrix,
				std::unique_ptr<QOpenGLShaderProgram> const& program);

	/**
	 * @brief getMapTexture
	 * @return La texture correspondant au rendu
	 */
	GLuint getMapTexture() const;

//******************************************************************************
private:
	//pas de constructeur par copie
	DepthMap(DepthMap const&);

	//pour savoir si initialize() a déjà été appelé
	bool m_isInitialized;

	//ID de la MVP dans le programme de shader
	GLuint m_matrixID;

	//framebufer et texture pour stocker le rendu
	GLuint	m_mapFrameBuffer,
		m_mapTexture;
};

#endif //DEPTHMAP_H
