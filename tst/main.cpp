#include "gtest/gtest.h"
#include "opencv4/opencv2/imgcodecs.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using namespace cv;

class Server{

public:

    int método()
    {
        // Carga el archivo de la imagen a la que se se va a aplicar el filtro
        Mat image = imread("/home/luis/CLionProjects/Proyecto 1 - Datos II/Control_Brillo/tst/cuadras.jpg");

        // Chequea si la imagen está presente o no
        if (image.empty()) {
            cout << "Could not open or find the image" << endl;

            // Espera para que alguna tecla sea presionada
            return -1;
        }

        // Declaración de las intensidades de brillo

        Mat imageBrighnessHigh50;
        // Incremento del brillo niveladas por 50
        image.convertTo(imageBrighnessHigh50, -1, 1, 50);

        Mat imageBrighnessHigh100;
        // Incremento del brillo niveladas por 100
        image.convertTo(imageBrighnessHigh100, -1, 1, 100);

        Mat imageBrighnessLow50;
        // Decrecimiento del brillo niveladas por 50
        image.convertTo(imageBrighnessLow50, -1, 1, -50);

        Mat imageBrighnessLow100;
        // Decrecimiento del brillo niveladas por 100
        image.convertTo(imageBrighnessLow100, -1, 1, -100);

        // Declaración de las ventanas para las imagenes pertenecientes a cada intensidad de brillo
        String windowNameOriginalImage = "Original Image";
        String windowNameBrightnessHigh50 = "Brightness Increased by 50";
        String windowNameWithBrightnessHigh100 = "Brightness Increased by 100";
        String windowNameBrightnessLow50 = "Brightness Decreased by 50";
        String windowNameBrightnessLow100 = "Brightness Decreased by 100";

        // Se corren las instancias de la ventana y se abren
        namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
        namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);
        namedWindow(windowNameWithBrightnessHigh100, WINDOW_NORMAL);
        namedWindow(windowNameBrightnessLow50, WINDOW_NORMAL);
        namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

        // Se cargan las imagenes dentro de las ventanas creadas arriba
        imshow(windowNameOriginalImage, image);
        imshow(windowNameBrightnessHigh50, imageBrighnessHigh50);
        imshow(windowNameWithBrightnessHigh100, imageBrighnessHigh100);
        imshow(windowNameBrightnessLow50, imageBrighnessLow50);
        imshow(windowNameBrightnessLow100, imageBrighnessLow100);

        // Espera por alguna pulsación de teclas en la ventana
        waitKey(0);

        // Cierra todas las instancias de las ventanas cuando alguna tecla es presionada
        destroyAllWindows();

        return 0;
    }
};

//Creación de la prueba unitaria
TEST(SeverTEST, Test1){
    Server servidor;
    EXPECT_EQ(servidor.método(),0);
}

//Método que corre dicha prueba unitaria
int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
