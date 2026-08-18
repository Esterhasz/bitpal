#pragma once

namespace bitpal {
	struct Pixel {
		const char* str;
		const char* color;

		Pixel() {
			str = " ";
			color = ANSI_BG_BLACK ANSI_FG_WHITE;
		}
	};
}