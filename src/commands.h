#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED

#ifndef NO_TEST_COMMANDS
#include <iostream>
#endif

#include "includes.h"
namespace CREP_CORE{
    void handleCommands( int, char** );
    Color* getReplaceColor( void );
    Color* getSearchColor( void );
    cv::Vec4b* getLegDiff( void );
    cv::Vec4b getColorVector(Color* color);
}
#endif // COMMANDS_H_INCLUDED
