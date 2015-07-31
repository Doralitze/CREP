//This file implements the color functions

#include "color_functions.h"

Color* parseColor(std::string data){
    std::string s = "scott>=tiger>=mushroom";
    std::string delimiter = "COLOR_SEPERATOR";
    //std::list<std::string> *valve = new std::list<std::string>();
    size_t pos = 0;
    short position = 0;//rgba
    Color *c = new Color();
    std::string token;
    while ((pos = data.find(delimiter)) != std::string::npos) {
        token = data.substr(0, pos);
        #ifndef NO_TEST_COLOR
        std::cout << token << std::endl;
        #endif
        position++;
        if(position == 0){
            c->setRed(atol(token.c_str()));
        }
        else if(position == 1){
            c->setGreen(atol(token.c_str()));
        }
        else if(position == 2){
            c->setBlue(atol(token.c_str()));
        }
        else if(position == 3){
            c->setAlpha(atol(token.c_str()));
        }
        data.erase(0, pos + delimiter.length());
    }
    #ifndef NO_TEST_COLOR
    std::cout << data << std::endl;
    #endif
    position++;
    if(position == 0){
        c->setRed(atol(token.c_str()));
    }
    else if(position == 1){
        c->setGreen(atol(token.c_str()));
    }
    else if(position == 2){
        c->setBlue(atol(token.c_str()));
    }
    else if(position == 3){
        c->setAlpha(atol(token.c_str()));
    }
    return c;
}
