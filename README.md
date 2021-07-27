
# Mandelbrot Set Fractals

The mandelbrot set is defined by the set of complex numbers c (of the form "x + iy", where i = sqrt(-1)) for which the complex numbers of the sequence z(n) remain bounded in absolute value. The sequence z(n) is defined by:
- z(0) = 0
- z(n+1) = z(n)^2 + c

This graph is created by determining whether z(n) is bounded for each point c on the complex plane. The number of iterations to reach a modulus greater than 2 has been used to determine the color of the pixel.
## Screenshots

![App Screenshot](/Screenshots/Screenshot-1.png?raw=true)
![App Screenshot](/Screenshots/Screenshot-2.png?raw=true)

  
## Controls To Navigate In Graph

| Control Key      |  Action  |
| :--------------- | :------- |
| `Move Upwards`   |  UP      |
| `Move Downwards` |  DOWN    |
| `Move Left`      |  LEFT    |
| `Move Right`     |  RIGHT   |
| `Zoom In`        |    +     |
| `Zoom Out`       |    -     |

  ## Installation

To compile and run this project on CodeBlocks, download the header files from the above "Graphics Libraries" folder and follow the steps from GeeksForGeeks for setting up the required environment: https://www.geeksforgeeks.org/include-graphics-h-codeblocks/