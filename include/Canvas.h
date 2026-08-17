#pragma once
#include <memory>
#include "Pixel.h"
#include <iostream>

namespace bitpal {
	class Canvas {

		std::unique_ptr<Pixel[]> _buffer;

		size_t _width;
		size_t _height;


	public:
		Canvas(size_t width, size_t height)
		{
			_width = width;
			_height = height;

			_buffer = std::make_unique<Pixel[]>(_width * _height);
		}

		void Clear(const char* color, const char* str) {
			//constexpr char CLEAR_SCREEN[] = "\033[2J\033[H";
			//std::cout << CLEAR_SCREEN, sizeof(CLEAR_SCREEN) - 1;

			for (size_t y = 0; y < _height; y++)
			{
				for (size_t x = 0; x < _width; x++)
				{
					Pixel& p = get_pixel(x, y);

					p.str = str;
					p.color = color;
				}
			}


			std::cout << ANSI_RESET;
		}

		void Draw()
		{
			std::string out{};

			for (size_t y = 0; y < _height; y++)
			{
				for (size_t x = 0; x < _width; x++)
				{
					Pixel& p = get_pixel(x, y);
					out += p.color;
					out += p.str;
				}
				out += '\n';
			}

			std::cout << ANSI_HOME;
			std::cout << out;
		}

		Pixel& get_pixel(size_t x, size_t y) {
			return _buffer[y * _width + x];
		}
	};
}