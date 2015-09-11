#include "includes.h"
#include "main.h"

using namespace std;
using namespace cv;

int main( int argc, char** argv )
{

    #ifndef NO_TEST_CV
    cout << "Compiled as testing target" << endl;
    #endif

    //Test Framekit
    //vector<cl::Platform> CLplatforms = getAllPlatforms();
    Dimension* d = new Dimension();
    RGBAPixel* p = new RGBAPixel();
    p->setRed(128);
    p->setBlue(128);
    d->SetHeight(500);
    d->SetWidth(500);
    Frame* f = new Frame(*d, p);
    for(unsigned int x = 0; x < 500; x++)
        for(unsigned int y = 0; y < 500; y++)
            if(!(f->getDataAt(x, y) == *p))
                cout << "found invalid pixel @" << to_string(x) << "," << to_string(y) << endl;
    cout << "passed FK test" << endl;

    if( argc < 4)
    {
        displayHelp();
        return EXIT_ERROR_NOARGS;
    } else {
        CREP_CORE::handleCommands(argc, argv);
    }

    Mat image;
    image = imread(argv[1], CV_LOAD_IMAGE_UNCHANGED);

    if(!image.data){
        cerr << "Could not load image" << endl;
        #ifndef NO_DEBUG_PRINT
        for(int i = 0; i < argc; i++)
            cout << "[" << to_string(i) << "] " <<argv[i] << endl;
        #endif
        return EXIT_ERROR_IMAGED;
    }

    #ifndef NO_TEST_CV
    cout << "testing opencv... This will display the imgage specified by the first argument" << endl;
    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show the image inside it.
    waitKey(0);
    #endif

    //modify image
    for( int x = 0; x < image.rows; x++ ) {
      for( int y = 0; y < image.cols; y++ ) {
          if ( image.at<Vec4b>(x, y) == CREP_CORE::getColorVector(CREP_CORE::getSearchColor()) ) {
            image.at<Vec4b>(x, y)[0] = CREP_CORE::getReplaceColor()->getRed();
            image.at<Vec4b>(x, y)[1] = CREP_CORE::getReplaceColor()->getGreen();
            image.at<Vec4b>(x, y)[2] = CREP_CORE::getReplaceColor()->getBlue();
            image.at<Vec4b>(x, y)[3] = CREP_CORE::getReplaceColor()->getAlpha();
          }
        }
    }
    //Save the image
    imwrite(argv[2], image);
    return EXIT_ERROR_NOERROR;
}

void displayHelp(){
    cout <<"Usage: input output searchColor replacColor [options]" << endl;
    cout <<"Options --format=<format>" << endl;
}







