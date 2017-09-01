# HeightMap

## Description
The program loads a black and white image and perform edge detection thanks to Canny algorithm. Then it converts the original image, the processed one and the intermediate steps as height maps to display them using OpenGL. 

It is possible to activate a plan that enables to highlight edges over a threshold. 

Shadows, diffuse and specular lightings are simulated for a better rendering.

It is also possible to save the displayed image.

## Instructions
The project requires a ***C++11*** capable compiler, ***OpenGL 2.0***, ***Qt 5.6*** and ***QtCreator 4*** or later.

To launch it, open `heightMap-GL2.pro` with QtCreator.

The subprojct corresponding to the main program is `src`.

Additional data to test the program are available in [`additional_data/`](additional_data/).

For more information, see [`doc/`](doc/).

## Results
The original image is from [niotex.blogspot.kr](http://niotex.blogspot.kr)

![raw](/results/city_raw.png)
*Height map corresponding to the original image*

![Canny](/results/city_canny.png)
*Height map corresponding to the Canny image with a plan to hightlight edges*

## License

[LGPL](http://www.gnu.org/licenses/licenses.en.html)
