#include <stdio.h>

struct color{

   int red;
   int green;
   int blue;
}black = {0, 0, 0};

struct color brighter(struct color c);
struct color make_color(int red, int green, int blue);
int main()
{
	struct color white= {255, 255, 255};

        struct color magenta={255, 0, 255};
	
	struct color color2, color3, color4;
	color2 = make_color(-5, 357, 93);
	color4 = make_color(255, 215, 0); 
	color3 = brighter(color4);

	printf("%d %d %d\n", color2.red, color2.green, color2.blue);
	printf("%d %d %d\n", color3.red, color3.green, color3.blue);
	return 0;
}

struct color make_color(int red, int green, int blue)
{
	struct color c;
	if(red < 0) red =0;
	if (red > 255) red = 255;
	if(green < 0) green =0;
	if (green > 255) green = 255;
	if(blue < 0) blue =0;
	if (blue > 255) blue = 255;
	c.red = red;
	c.green = green;
	c.blue = blue;
	return c;
}

struct color brighter(struct color c)
{
	struct color c2;
	if(c.red == 0) c.red = 3;
	if(c.green ==0) c.green = 3;
	if(c.blue ==0) c.blue = 3;

	c2.red = (c.red/0.7>255)?255:(int)(c.red/0.7);
	c2.green = (c.green/0.7>255)?255:(int)(c.green/0.7);
	c2.blue = (c.blue/0.7>255)?255:(int)(c.blue/0.7);

	return c2;

}
