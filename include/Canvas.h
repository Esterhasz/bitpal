#pragma once
#include <memory>
#include <iostream>
#include "Pixel.h"

namespace bitpal {
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