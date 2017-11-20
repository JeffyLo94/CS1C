/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	LAB # 5   : Inheritance - Cylinders
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/4/2014
*******************************************************************************/

#include "CircleType.h"

/***********************************************************************
 * Constructor
 * --------------------------------------------------------------------
 * Constructor with a default parameter. Radius is set according to the
 * parameter. The default value of the radius is 0.0
 * 	Postcondition: radius = r;
 **********************************************************************/
circleType::circleType(double r)
{
	setRadius(r);
}

// S E T T E R S
/***********************************************************************
 * Method setRadius
 * --------------------------------------------------------------------
 * Function to set the radius.
 * 	Postcondition: if (r>=0) radius = r;
 * 				   otherwise radius = 0;
 **********************************************************************/
void circleType::setRadius(double r)
{
	if (r >=0)
		radius = r;
	else
		radius = 0;
}

/***********************************************************************
 * Method getRadius
 * --------------------------------------------------------------------
 * Function to return the radius.
 * 	Postcondition: The value of the radius is returned.
 **********************************************************************/
double circleType::getRadius() const
{
	return radius;
}

/***********************************************************************
 * Method area
 * --------------------------------------------------------------------
 * Function to return the area of a circle.
 * 	Postcondition: Area is calculated and returned.
 **********************************************************************/
double circleType::area() const
{
	return 3.1416*radius*radius;
}

/***********************************************************************
 * Method circumference
 * --------------------------------------------------------------------
 * Function to return the circumference of a circle.
 * 	Postcondition: Circumference is calculated and returned.
 **********************************************************************/
double circleType::circumference() const
{
	return 2*3.1416*radius;
}


/***********************************************************************
 * Method print
 * --------------------------------------------------------------------
 * Function to prints the radius, area, and circumference of the circle
 * 	Postcondition: Radius, Area, and circumference printed to ostream
 **********************************************************************/
void circleType::print(ostream os) const
{
	os << left;
	os << setw(20) << "Radius: " << radius;
	os << setw(20) << "Area: " << area();
	os << setw(20) << "Circumference: " << circumference();
	os << right;
}
