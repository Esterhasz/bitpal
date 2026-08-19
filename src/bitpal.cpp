#include <iostream>
#include "bitpal.h"

using namespace bitpal;

int main()
{
	std::cout 
		<< ANSI_CLEAR 
		<< ANSI_HOME
        << ANSI_CURSOR_HIDE;

	Buffer2D buf(15, 15, 2);

    std::string gradient[] = {
        ANSI_BG_BLACK,
        ANSI_BG_DARK_RED,
        ANSI_BG_DARK_GREEN,
        ANSI_BG_DARK_YELLOW,
        ANSI_BG_DARK_BLUE,
        ANSI_BG_DARK_MAGENTA,
        ANSI_BG_DARK_CYAN,
        ANSI_BG_GRAY,

        ANSI_BG_DARK_GRAY,
        ANSI_BG_RED,
        ANSI_BG_GREEN,
        ANSI_BG_YELLOW,
        ANSI_BG_BLUE,
        ANSI_BG_MAGENTA,
        ANSI_BG_CYAN,
        ANSI_BG_WHITE,
    };

    float i = 0;

	while (true) {
        buf.fill(Pixel(" ", nullptr));
		
        auto color = gradient[(size_t)(i += 0.001) % 16].c_str();
        
        buf.drawRect(0, 0, 10, 10, Pixel(" ", color));

		buf.draw();
	}

	return 0;
}