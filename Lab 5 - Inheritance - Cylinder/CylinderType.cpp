/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	LAB # 5   : Inheritance - Cylinders
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/4/2014
*******************************************************************************/

#include "CylinderType.h"
CylinderType::CylinderType()
{
	setHeight(0.0);
	circleType::setRadius(0.0);
}


CylinderType::CylinderType(double h, double r)
{
	setHeight(h);
	circleType::setRadius(r);
}

CylinderType::~CylinderType()
{
}

void CylinderType::setHeight(double h)
{
	height = h;
}

double CylinderType::getHeight() const
{
	return height;
}

double CylinderType::volume() const
{
	return circleType::area() * height;
}

double CylinderType::surfaceArea() const
{
	return (circleType::area() * 2) + (circleType::circumference() * height);
}
