/*******************************************************************************
*	AUTHOR	  : Jeffrey Lo
*	STU ID#	  : 374780
*	LAB # 5   : Inheritance - Cylinders
*	CLASS     : CS1C
*	SECTION   : 6-10p T-Th
*	DUE DATE  : 9/4/2014
*******************************************************************************/

#include "LabFive.h"
#include "CircleType.h"
#include "CylinderType.h"
using namespace JeffreyLo;

int main()
{
	const int	 UP  = 4;
	const int	 LOW = 0;
	CylinderType myCylinder;
	int			 inCommand;
	double		 radius;
	double		 height;

	// OutputHeader- prints out author information
	OutputHeader(NAME, CLASS, SECTION, AS_NUM, AS_NAME, AS_TYPE, cout);

	cout << "Please input cylinder radius: ";
	cin  >> radius;
	myCylinder.setRadius(radius);
	cout << "Please input cylinder height: ";
	cin  >> height;
	myCylinder.setHeight(height);
	cout << endl;

	inCommand = GetInput(UP, LOW);

	while(inCommand != EXIT)
	{
		switch(inCommand)
		{
		case SET_DIMENSIONS: cout << "Please input cylinder radius: ";
							 cin  >> radius;
							 myCylinder.setRadius(radius);
							 cout << "Please input cylinder height: ";
							 cin  >> height;
							 myCylinder.setHeight(height);
							 cout << endl;
							 break;
		case VOLUME:		 cout << "The Volume is: " << myCylinder.volume();
							 cout << endl;
							 break;
		case SURF_AREA:		 cout << "The Surface Area is: "
								  << myCylinder.surfaceArea()
								  << endl;
							 break;
		case GET_DIMENSIONS: cout << "The radius is: "
								  << myCylinder.getRadius() << endl;
							 cout << "The height is: "
								  << myCylinder.getHeight()	<< endl;
							 break;
		default:			 cout << "\n**Error - Undefined Command**\n";
		}

		cout << endl << endl;
		inCommand = GetInput(UP, LOW);
	}
	return 0;
}
