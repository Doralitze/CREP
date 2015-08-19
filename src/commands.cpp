#include "commands.h"

namespace CREP_CORE{
    Color* searchColor = new Color();
    Color* replaceColor = new Color();
    cv::Vec4b diffSet = cv::Vec4b(0,0,0,0);

    void handleCommands(int argc, char** argv){
        #ifndef NO_TEST_COMMANDS
        std::cout << argv[0] << std::endl;
        std::cout << argv[1] << std::endl;
        std::cout << argv[2] << std::endl;
        std::cout << argv[3] << std::endl;
        #endif
        CREP_CORE::searchColor = parseColor(argv[3]);
        CREP_CORE::replaceColor = parseColor(argv[4]);

        for(int i = 5; i < argc; i++){
            #ifndef NO_DEBUG_PRINT
            std::cout << argv[i] << std::endl;
            #endif
            if(argv[i] == "--tollerance"){
                i++;
                diffSet = CREP_CORE::getColorVector(parseColor(argv[i]));
            }
        }
    }

    Color* getReplaceColor( void ){
        return replaceColor;
    }

    Color* getSearchColor( void ){
        return searchColor;
    }

    cv::Vec4b* getLegDiff( void ){
        return &diffSet;
    }

    cv::Vec4b getColorVector(Color* color){
        return cv::Vec4b(color->getRed(), color->getGreen(), color->getBlue(), color->getAlpha());
    }
}

