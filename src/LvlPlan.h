#ifndef LVLPLAN_H
#define LVLPLAN_H

/**
*******************************************************************************
*  @file       LvlPlan.h
*
*  @brief      Classe servant de modèle de plan afin de souligner les contours
*******************************************************************************
*/

//******************************************************************************
//  Include
//******************************************************************************
#include "Mesh.h"

//==============================================================================
/**
*  @class  LvlPlan
*  @brief  LvlPlan Classe servant de modèle de plan afin de souligner les contours
*/
//==============================================================================
class LvlPlan: public Mesh
{
public:
	/**
	 * @brief LvlPlan constructeur surchargé avec ses dimentions
	 * @param height la hauteur
	 * @param length la longueur
	 * @param width la largeur
	 */
	LvlPlan(float height, float length, float width);

	/**
	 * @brief changeHeight Change la hauteur du plan
	 * @param delta ajoute cette valeur à la hauteur du plan
	 */
	void changeHeight(float delta);

//******************************************************************************
private:
	//Pas de constructeur par défaut
	LvlPlan();

	float m_height, //The height of the lvl plan. Can be seen as a threshold for the edge detection.
		m_length, //Size of a side of the plan
		m_width; //Size of the other side
};

#endif // LVLPLAN_H
