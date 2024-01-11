/* Dylan Skroskznik	cop3514		FEB. 28  2021
 *	This program asks the user to input the radius and height of a solid cylinder using
 *	two variables of type double, and then calculates the surface area and volume of the cylinder
 */

#include <stdio.h>
#define PI 3.14159//predefined number pi

//establish function parameters for area_volume 
void area_volume(double radius, double height, double *pointer_area, double  *pointer_volume);

int main()
{
	double r, h;//radius, height variables
	double a, v;//area, volume variables
	
	printf("Enter the radius of the cylinder: ");
	scanf("%lf", &r);//scans for users radius input
	if(r<0) { //radius cannot be negative
		printf("Invalid Input. Enter the radius of the cylinder: ");	
		scanf("%lf", &r);//rescan radius
	}
	printf("Enter the height of the cylinder: "); 
	scanf("%lf", &h);//scans for users height input
	if(h<0) { //height cannot be negative
		printf("Invalid Input. Enter the height of the cylinder: ");
		scanf("%lf", &h);//rescan radius
	}
	area_volume(r, h, &a, &v);//calls area_volume function calculation

	//output message for cylinders volume and surface area
	printf("Output:\nThe volume of the cylinder is %.2lf and the area is %.2lf.", v, a); 

	return 0;

}//end main

void area_volume(double radius, double height, double *pointer_area, double  *pointer_volume)
{
	double a, v;//local varaibles for function 
	
	// a = surface area eq. - v = volume eq.
	a = (2 * PI * radius * height)+(2 * PI * (radius*radius));
	v = (PI * (radius*radius) * height);

	*pointer_area = a;//directs 'a' to area pointer
	*pointer_volume = v;//directs 'v' to volume pointer

}//end area_volume
