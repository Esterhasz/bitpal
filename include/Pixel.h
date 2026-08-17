#pragma once

namespace bitpal {
	struct Pixel {
		char left;
		char right;
		char* color;

		Pixel(char l, char r)
		{
			left = l;
			right = r;
		}
		Pixel() {
			left = ' ';
			right = ' ';
		}
	};
}