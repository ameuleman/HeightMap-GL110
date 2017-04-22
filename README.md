# HeightMap

## Description
Le programme lit une image en noir et blanc et effectue un traitement de détection de contours grâce à l'algorithme de Canny. puis de convertir cette image ainsi que les étapes menant au résultat en cartes de niveau afin de les afficher en 3D grâce à OpenGL. 

Il est possible d'afficher un plan pour souligner les coutours au dessus d'un certains seuil. 

Lors de l'affichage, le programme simule des effets d'ombres, d'éclairage diffus et spéculaire.

Il est aussi possible d'enregistrer l'image rendu.


## Instructions
Le projet nécessite un compilateur ***C++11***, ***OpenGL 2.0***, ***Qt 5.6*** et ***QtCreator 4*** ou plus récent.

Pour le lancer, ouvrir ***src/heightMapQt.pro*** avec QtCreator.

## Results
![raw](/results/city_raw.png)
*Carte de niveau correspondant à l'image originale*

![Canny](/results/city_canny.png)
*Carte de niveau correspondant à l'image après traitement, avec un plan pour souligner les contours*
