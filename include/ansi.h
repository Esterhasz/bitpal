#pragma once

#define ANSI_RESET       "\033[0m"
#define ANSI_CLEAR       "\033[2J"
#define ANSI_HOME        "\033[H"

#define ANSI_FG_BLACK        "\033[30m"
#define ANSI_FG_DARK_RED     "\033[31m"
#define ANSI_FG_DARK_GREEN   "\033[32m"
#define ANSI_FG_DARK_YELLOW  "\033[33m"
#define ANSI_FG_DARK_BLUE    "\033[34m"
#define ANSI_FG_DARK_MAGENTA "\033[35m"
#define ANSI_FG_DARK_CYAN    "\033[36m"
#define ANSI_FG_GRAY         "\033[37m"

#define ANSI_FG_DARK_GRAY    "\033[90m"
#define ANSI_FG_RED          "\033[91m"
#define ANSI_FG_GREEN        "\033[92m"
#define ANSI_FG_YELLOW       "\033[93m"
#define ANSI_FG_BLUE         "\033[94m"
#define ANSI_FG_MAGENTA      "\033[95m"
#define ANSI_FG_CYAN         "\033[96m"
#define ANSI_FG_WHITE        "\033[97m"

#define ANSI_BG_DARK_GRAY    "\033[48;5;8m"
#define ANSI_BG_RED          "\033[48;5;9m"
#define ANSI_BG_GREEN        "\033[48;5;10m"
#define ANSI_BG_YELLOW       "\033[48;5;11m"
#define ANSI_BG_BLUE         "\033[48;5;12m"
#define ANSI_BG_MAGENTA      "\033[48;5;13m"
#define ANSI_BG_CYAN         "\033[48;5;14m"
#define ANSI_BG_WHITE        "\033[48;5;15m"

namespace bitpal::ansi {
	constexpr char* RESET	= "\033[0m";
	constexpr char* CLEAR	= "\033[2J";
	constexpr char* HOME	= "\033[H";

	namespace fg {
		constexpr char* BLACK			= "\033[30m";
		constexpr char* DARK_RED		= "\033[31m";
		constexpr char* DARK_GREEN		= "\033[32m";
		constexpr char* DARK_YELLOW		= "\033[33m";
		constexpr char* DARK_BLUE		= "\033[34m";
		constexpr char* DARK_MAGENTA	= "\033[35m";
		constexpr char* DARK_CYAN		= "\033[36m";
		constexpr char* GRAY			= "\033[37m";

		constexpr char* DARK_GRAY		= "\033[90m";
		constexpr char* RED				= "\033[91m";
		constexpr char* GREEN			= "\033[92m";
		constexpr char* YELLOW			= "\033[93m";
		constexpr char* BLUE			= "\033[94m";
		constexpr char* MAGENTA			= "\033[95m";
		constexpr char* CYAN			= "\033[96m";
		constexpr char* WHITE			= "\033[97m";
	}

	namespace bg {
		
		constexpr char* DARK_GRAY = "\033[48;5;8m";
		constexpr char* RED		= "\033[48;5;9m";
		constexpr char* GREEN		= "\033[48;5;10m";
		constexpr char* YELLOW	= "\033[48;5;11m";
		constexpr char* BLUE		= "\033[48;5;12m";
		constexpr char* MAGENTA	= "\033[48;5;13m";
		constexpr char* CYAN		= "\033[48;5;14m";
		constexpr char* WHITE		= "\033[48;5;15m";
	}
}