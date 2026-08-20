#define STB_IMAGE_IMPLEMENTATION 
#include <iostream>
#include <filesystem>
#include <chrono>
#include <thread>
#include <vector>
#include <fstream>
#include <cstring>
#include <regex>
#include "bytepal.h"
#include "stb_image.h"

using namespace bytepal;
namespace fs = std::filesystem;

const int TargetFPS		= 15;

// must fit in console window
const int OutputWIdth	= 40;
const int OutputHeight	= 40;

// if it's wide, set to 1
const int PixelWidth	= 2;

const char* PathToPlay	= "content/heart_transparent.gif";

static constexpr unsigned char ALPHA_THRESHOLD = 12;

struct Frame {

	int width;
	int height;
	int channels;

	unsigned char* image;

	Frame(unsigned char* img, int w, int h, int c) :
		image(img),
		width(w),
		height(h),
		channels(c){
	}
};

struct Color {
	unsigned char r, g, b, a;
	const char* ansi;
};

const std::vector<Color> ansi_palette = {
	{ 0,   0,   0,   255, ANSI_BG_BLACK			},
	{ 128, 0,   0,   255, ANSI_BG_DARK_RED		},
	{ 0,   128, 0,   255, ANSI_BG_DARK_GREEN	},
	{ 128, 128, 0,   255, ANSI_BG_DARK_YELLOW	},
	{ 0,   0,   128, 255, ANSI_BG_DARK_BLUE		},
	{ 128, 0,   128, 255, ANSI_BG_DARK_MAGENTA	},
	{ 0,   128, 128, 255, ANSI_BG_DARK_CYAN		},
	{ 192, 192, 192, 255, ANSI_BG_GRAY			},
	{ 128, 128, 128, 255, ANSI_BG_DARK_GRAY		},
	{ 255, 0,   0,   255, ANSI_BG_RED			},
	{ 0,   255, 0,   255, ANSI_BG_GREEN			},
	{ 255, 255, 0,   255, ANSI_BG_YELLOW		},
	{ 0,   0,   255, 255, ANSI_BG_BLUE			},
	{ 255, 0,   255, 255, ANSI_BG_MAGENTA		},
	{ 0,   255, 255, 255, ANSI_BG_CYAN			},
	{ 255, 255, 255, 255, ANSI_BG_WHITE			},
};

std::vector<Frame> load_gif_frames(const std::string& filepath) {
	std::ifstream file(filepath, std::ios::binary | std::ios::ate);
	if (!file.is_open()) 
		return {};

	std::streamsize size = file.tellg();
	file.seekg(0, std::ios::beg);
	std::vector<char> buffer(size);
	file.read(buffer.data(), size);

	int width, height, frameCount, channels;
	int* delays = nullptr;

	unsigned char* rawData = stbi_load_gif_from_memory(
		(const stbi_uc*)buffer.data(),
		(int)buffer.size(),
		&delays,
		&width,
		&height,
		&frameCount,
		&channels,
		4
	);

	if (!rawData) return {};

	std::vector<Frame> frames;
	int frameSizeBytes = width * height * 4;

	for (int i = 0; i < frameCount; ++i) {
		unsigned char* frameData = new unsigned char[frameSizeBytes];
		std::memcpy(frameData, rawData + (i * frameSizeBytes), frameSizeBytes);

		frames.push_back(Frame(frameData, width, height, 4));
	}

	STBI_FREE(delays);
	stbi_image_free(rawData);

	return frames;
}

static int frame_number(const fs::path& path) {
	std::string filename = path.filename().string();
	std::smatch match;

	if (std::regex_search(filename, match, std::regex(R"(\d+)"))) {
		return std::stoi(match.str());
	}
	return 0;
}


std::vector<Frame> load_framebyframe_video(const std::string& dirPath) {
	std::vector<fs::path> paths;
	std::vector<Frame> frames;

	for (auto& entry : fs::directory_iterator(dirPath)) {
		paths.push_back(entry.path());
	}

	std::sort(paths.begin(), paths.end(), [](const fs::path& a, const fs::path& b) {
		return frame_number(a) < frame_number(b);
		});

	for (fs::path& p : paths) {
		std::string fpath = p.string();

		int width, height, channels;
		auto frame = stbi_load(fpath.c_str(), &width, &height, &channels, 4);
		channels = 4;

		frames.push_back(Frame(frame, width, height, channels));
	}

	return frames;
}

static const char* get_closest_ansi(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {

	if (a < ALPHA_THRESHOLD)
		return ANSI_RESET;

	const char* best_ansi = ansi_palette[0].ansi;
	double min_dist = std::numeric_limits<double>::max();

	for (const auto& color : ansi_palette) {
		double dr = (double)r - color.r;
		double dg = (double)g - color.g;
		double db = (double)b - color.b;

		double dist = dr * dr + dg * dg + db * db;

		if (dist < min_dist) {
			min_dist = dist;
			best_ansi = color.ansi;
		}
	}
	return best_ansi;
}

int main()
{
	std::vector<Frame> frames = load_gif_frames(PathToPlay);

	std::cout 
		<< ANSI_CLEAR 
		<< ANSI_HOME
        << ANSI_CURSOR_HIDE;

	Buffer2D buf(OutputWIdth, OutputHeight, PixelWidth);

    std::size_t frameNum = 0;
	const auto frameDuration = std::chrono::milliseconds(1000 / TargetFPS);

	Pixel background = Pixel(nullptr, nullptr);

	while (true) {
		auto frameStart = std::chrono::high_resolution_clock::now();

        buf.fill(background);
		
		Frame& f = frames[frameNum % frames.size()];
		for (int y = 0; y < OutputHeight; ++y) {
			int sourceY = y * f.height / OutputHeight;

			for (int x = 0; x < OutputWIdth; ++x) {
				int sourceX = x * f.width / OutputWIdth;

				int index = (sourceY * f.width + sourceX) * f.channels;

				unsigned char r = f.image[index + 0];
				unsigned char g = f.image[index + 1];
				unsigned char b = f.image[index + 2];
				unsigned char a = f.image[index + 3];

				Pixel finalPixel = Pixel(nullptr, get_closest_ansi(r, g, b, a));

				buf.plot(x, y, finalPixel);
			}
		}

		buf.draw(ANSI_HOME, nullptr);
		frameNum++;

		auto frameTime = std::chrono::high_resolution_clock::now() - frameStart;
		if (frameTime < frameDuration) {
			std::this_thread::sleep_for(frameDuration - frameTime);
		}
	}

	return 0;
}