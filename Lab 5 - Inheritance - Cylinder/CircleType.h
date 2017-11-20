/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	LAB # 5   : Inheritance - Cylinders
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/4/2014
*******************************************************************************/

#ifndef CIRCLETYPE_H_
#define CIRCLETYPE_H_

#include <sstream>
#include <iomanip>
using namespace std;

class circleType
{
	public:
		/***********************************************************************
		 * Constructor
		 * --------------------------------------------------------------------
		 * Constructor with a default parameter. Radius is set according to the
		 * parameter. The default value of the radius is 0.0
		 * 	Postcondition: radius = r;
		 **********************************************************************/
		circleType(double r = 0);

		/***********************************************************************
		 * Method setRadius
		 * --------------------------------------------------------------------
		 * Function to set the radius.
		 * 	Postcondition: if (r>=0) radius = r;
		 * 				   otherwise radius = 0;
		 **********************************************************************/
		void setRadius(double r);

		/***********************************************************************
		 * Method getRadius
		 * --------------------------------------------------------------------
		 * Function to return the radius.
		 * 	Postcondition: The value of the radius is returned.
		 **********************************************************************/
		double getRadius() const;

		/***********************************************************************
		 * Method area
		 * --------------------------------------------------------------------
		 * Function to return the area of a circle.
		 * 	Postcondition: Area is calculated and returned.
		 **********************************************************************/
		double area() const;

		/***********************************************************************
		 * Method circumference
		 * --------------------------------------------------------------------
		 * Function to return the circumference of a circle.
		 * 	Postcondition: Circumference is calculated and returned.
		 **********************************************************************/
		double circumference() const;

		/***********************************************************************
		 * Method print
		 * --------------------------------------------------------------------
		 * Function to prints the radius, area, and circumference of the circle
		 * 	Postcondition: Radius, Area, and circumference printed to ostream
		 **********************************************************************/
		void print(ostream os) const;


	private:
		double radius;
};


#endif /* CIRCLETYPE_H_ */
