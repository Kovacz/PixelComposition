#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <boost/multiprecision/cpp_int.hpp>

class Image
{
public:
	using uns = unsigned;
	using str = std::string;

	void get_info()
	{
		for (uns i = 0; i < N; ++i) {
			std::cout << pixels[i].get_color() << std::endl;
		}
	}
private:
	class Pixel
	{
	public:
		enum color
		{
			black, white, red, green, blue
		};
		Pixel() : r(0), g(0), b(0)
		{

		}
		Pixel(uns r, uns g, uns b)
		{
			this->r = r;
			this->g = g;
			this->b = b;
		}
		color check_color(uns r, uns g, uns b)
		{
			uns breaking_values[][4] = {
				  0,   0,   0, color::black,
				  0,   0, 255, color::blue,
				  0, 255,   0, color::green,
				255,   0,   0, color::red,
				255, 255, 255, color::white
			};
			if ((r >= 0) && (g >= 0) && (b >= 0)) {
				for (uns i = 0; i < 5; ++i) {
					if (
							(r == breaking_values[i][0]) &&
							(g == breaking_values[i][1]) &&
							(b == breaking_values[i][2])
						) {
						return static_cast<color>(breaking_values[i][3]);
					} 
				}
			} 
		}
		str get_color()
		{
			std::vector<str> colors = {
				"black",
				"white",
				"red",
				"green",
				"blue"
			};
			return colors[check_color(this->r, this->g, this->b)];
		}
	private:
		uns r;
		uns g;
		uns b;
	};

	static const uns N = 5;
	Pixel pixels[N] 
	{
		Pixel(  0,  0,    0),
		Pixel(255,   0,   0),
		Pixel(255, 255,	255),
		Pixel(  0, 255,   0),
		Pixel(255,   0,   0)
	};
};



int main()
{
	Image img;
	img.get_info();	
	system("pause");
}
