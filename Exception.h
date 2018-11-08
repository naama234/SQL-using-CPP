// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of Exception *
****************************************/
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
using namespace std;

class Exception
{
public:
	/****************************************************************
	* function name: toString                                            *
	* The Input:none                                              *
	* The output: string                                                *
	* The Function operation:make string *
	****************************************************************/
	virtual const string toString() = 0; 
};
#endif
