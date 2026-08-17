#include <iostream>
#include "ansi.h"
#include "Canvas.h"

using namespace std;
using namespace bitpal;

int main()
{
	std::cout << "asdfasdf";

	Canvas canvas(30, 15);

	while (true) {
		std::string result = std::string(ansi::fg::DARK_GRAY) + ansi::bg::RED;

		canvas.Clear(ANSI_BG_DARK_GRAY);

		auto& p = canvas.get_pixel(5, 5);
		p.color = ANSI_BG_BLUE;
		
		canvas.Draw();
	}


	return 0;
}