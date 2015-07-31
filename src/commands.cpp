#include "commands.h"

namespace CREP_CORE{
    Color* searchColor = new Color();
    Color* replaceColor = new Color();

    void handleCommands(int argc, char** argv){
        #ifndef NO_TEST_COMMANDS
        std::cout << argv[0] << std::endl;
        std::cout << argv[1] << std::endl;
        std::cout << argv[2] << std::endl;
        std::cout << argv[3] << std::endl;
        #endif
        CREP_CORE::searchColor = parseColor(argv[3]);
        CREP_CORE::replaceColor = parseColor(argv[4]);
    }

    Color* getReplaceColor( void ){
        return replaceColor;
    }

    Color* getSearchColor( void ){
        return searchColor;
    }
}

