/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	LAB # 5   : Inheritance - Cylinders
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/4/2014
*******************************************************************************/

#ifndef CYLINDERTYPE_H_
#define CYLINDERTYPE_H_

#include "CircleType.h"

class CylinderType : public circleType
{
	public:
		CylinderType();
		CylinderType(double h, double r);
		~CylinderType();

		// M U T A T O R S
		void setHeight(double h);

		// A C C E S S O R S
		double getHeight() const;
		double volume() const;
		double surfaceArea() const;

	private:
		double height;
};



#endif /* CYLINDERTYPE_H_ */
