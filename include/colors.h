#pragma once


namespace colors {
	constexpr char* RESET	= "\033[0m";
	
	namespace fg {

		constexpr char* BLACK = "\033[30m";
		constexpr char* DARK_RED = "\033[31m";
		constexpr char* DARK_GREEN = "\033[32m";
		constexpr char* DARK_YELLOW = "\033[33m";
		constexpr char* DARK_BLUE = "\033[34m";
		constexpr char* DARK_MAGENTA = "\033[35m";
		constexpr char* DARK_CYAN = "\033[36m";
		constexpr char* GRAY = "\033[37m";

		constexpr char* DARK_GRAY = "\033[90m";
		constexpr char* RED = "\033[91m";
		constexpr char* GREEN = "\033[92m";
		constexpr char* YELLOW = "\033[93m";
		constexpr char* BLUE = "\033[94m";
		constexpr char* MAGENTA = "\033[95m";
		constexpr char* CYAN = "\033[96m";
		constexpr char* WHITE = "\033[97m";
	}

	namespace bg {
		
		constexpr const char* DARK_GRAY = "\033[48;5;8m";
		constexpr const char* RED = "\033[48;5;9m";
		constexpr const char* GREEN = "\033[48;5;10m";
		constexpr const char* YELLOW = "\033[48;5;11m";
		constexpr const char* BLUE = "\033[48;5;12m";
		constexpr const char* MAGENTA = "\033[48;5;13m";
		constexpr const char* CYAN = "\033[48;5;14m";
		constexpr const char* WHITE = "\033[48;5;15m";

		constexpr const char* RESET = "\033[0m";
	}
}