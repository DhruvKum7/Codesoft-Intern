#include <iostream>
#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat image;
  
   
    string image_path;
    cout << "Enter image path: ";
    cin >> image_path;
    image = imread( image_path );

    if( image.empty() )
    {
        cout << "Error loading image!" << endl;
        return -1;
    }

    // Display Image
    namedWindow("Original Image", WINDOW_NORMAL);
    imshow("Original Image", image);
    waitKey(0);

    // Image Filters
    Mat gray_image, blur_image, sharpen_image;
    cvtColor(image, gray_image, COLOR_BGR2GRAY);
    GaussianBlur(image, blur_image, Size(5, 5), 0);
    addWeighted(image, 1.5, blur_image, -0.5, 0, sharpen_image);

    
    Mat adjusted_image;
    image.convertTo(adjusted_image, -1, 1.2, 20);

   
    Rect crop_region(100, 100, 300, 300);
    Mat cropped_image = image(crop_region);
    Mat resized_image;
    resize(image, resized_image, Size(), 0.5, 0.5);

    
    imwrite("processed_image.jpg", resized_image);

   
    namedWindow("Processed Image", WINDOW_NORMAL);
    imshow("Processed Image", resized_image);
    waitKey(0);

    return 0;
}
