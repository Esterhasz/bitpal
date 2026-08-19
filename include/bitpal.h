#pragma once
#define BITPAL_IMPLEMENTATION

#ifdef BITPAL_IMPLEMENTATION

#define ANSI_RESET			 "\033[0m"
#define ANSI_CLEAR			 "\033[2J"
#define ANSI_HOME			 "\033[H"

#define ANSI_CURSOR_HIDE	 "\033[?25l"
#define ANSI_CURSOR_SHOW	 "\033[?25h"

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

#define ANSI_BG_BLACK        "\033[40m"
#define ANSI_BG_DARK_RED     "\033[41m"
#define ANSI_BG_DARK_GREEN   "\033[42m"
#define ANSI_BG_DARK_YELLOW  "\033[43m"
#define ANSI_BG_DARK_BLUE    "\033[44m"
#define ANSI_BG_DARK_MAGENTA "\033[45m"
#define ANSI_BG_DARK_CYAN    "\033[46m"
#define ANSI_BG_GRAY         "\033[47m"

#define ANSI_BG_DARK_GRAY    "\033[100m"
#define ANSI_BG_RED          "\033[101m"
#define ANSI_BG_GREEN        "\033[102m"
#define ANSI_BG_YELLOW       "\033[103m"
#define ANSI_BG_BLUE         "\033[104m"
#define ANSI_BG_MAGENTA      "\033[105m"
#define ANSI_BG_CYAN         "\033[106m"
#define ANSI_BG_WHITE        "\033[107m"

#include <memory>
#include <iostream>

namespace bitpal {

	struct Pixel {
		const char* str;
		const char* color;

		Pixel() {
			str = " ";
			color = ANSI_BG_BLACK ANSI_FG_WHITE;
		}
	};

	class Canvas {

		std::unique_ptr<Pixel[]> _buffer;

		size_t _width;
		size_t _height;

		std::string _out;

	public:
		Canvas(size_t width, size_t height)
		{
			_width = width;
			_height = height;

			_buffer = std::make_unique<Pixel[]>(_width * _height);

			_out.reserve(_width * _height);
		}

		void clear(const char* color, const char* str) {

			for (size_t y = 0; y < _height; y++)
			{
				for (size_t x = 0; x < _width; x++)
				{
					Pixel& p = (*this)(x, y);

					p.str = str;
					p.color = color;
				}
			}

			std::cout << ANSI_RESET;
			_out.clear();
		}

		void draw()
		{

			for (size_t y = 0; y < _height; y++)
			{
				for (size_t x = 0; x < _width; x++)
				{
					Pixel& p = (*this)(x, y);
					_out += p.color;
					_out += p.str;
				}
				_out += '\n';
			}

			std::cout << ANSI_HOME;
			std::cout << _out;
		}

		Pixel& operator()(std::size_t x, std::size_t y) {
			return _buffer[y * _width + x];
		}
	};
}

#endif