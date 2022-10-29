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
        // Loading the Image File under testing
        Mat image = imread("/home/luis/CLionProjects/Proyecto 1 - Datos II/Control_Brillo/tst/cuadras.jpg");

        // Check whether the image is present or not
        if (image.empty()) {
            cout << "Could not open or find the image" << endl;

            // waiting for any  key to be pressed
            return -1;
        }

        // Declaring the Brightness Instances

        Mat imageBrighnessHigh50;
        // increasing the brightness level by 50
        image.convertTo(imageBrighnessHigh50, -1, 1, 50);

        Mat imageBrighnessHigh100;
        // increasing the brightness level by 100
        image.convertTo(imageBrighnessHigh100, -1, 1, 100);

        Mat imageBrighnessLow50;
        // decreasing the brightness level by 50
        image.convertTo(imageBrighnessLow50, -1, 1, -50);

        Mat imageBrighnessLow100;
        // decreasing the brightness level by 100
        image.convertTo(imageBrighnessLow100, -1, 1, -100);

        // Declaring the windows
        // for images belonging to different brightness level
        String windowNameOriginalImage = "Original Image";
        String windowNameBrightnessHigh50 = "Brightness Increased by 50";
        String windowNameWithBrightnessHigh100 = "Brightness Increased by 100";
        String windowNameBrightnessLow50 = "Brightness Decreased by 50";
        String windowNameBrightnessLow100 = "Brightness Decreased by 100";

        // Running the window instance
        // and opening it
        namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
        namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);
        namedWindow(windowNameWithBrightnessHigh100, WINDOW_NORMAL);
        namedWindow(windowNameBrightnessLow50, WINDOW_NORMAL);
        namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

        // Loading images inside the above created Windows
        imshow(windowNameOriginalImage, image);
        imshow(windowNameBrightnessHigh50, imageBrighnessHigh50);
        imshow(windowNameWithBrightnessHigh100, imageBrighnessHigh100);
        imshow(windowNameBrightnessLow50, imageBrighnessLow50);
        imshow(windowNameBrightnessLow100, imageBrighnessLow100);

        // waiting for any key to be pressed
        waitKey(0);

        // closing all the windows instances
        // when any key is pressed.
        destroyAllWindows();

        return 0;
    }
};

TEST(SeverTEST, Test1){
    Server servidor;
    EXPECT_EQ(servidor.método(),0);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
