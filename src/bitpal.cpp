#include <iostream>
#include "ansi.h"
#include "Canvas.h"

using namespace bitpal;

int main()
{
	std::cout 
		<< ANSI_CLEAR 
		<< ANSI_HOME
        << ANSI_CURSOR_HIDE;

	Canvas canvas(15, 15);

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
		
		canvas.clear(ANSI_BG_BLACK, "  ");
		auto& p = canvas(0, 0);
        
        auto color = gradient[(size_t)(i += 0.001) % 16].c_str();
        p.color = color;

		
		canvas.draw();
	}

	return 0;
}