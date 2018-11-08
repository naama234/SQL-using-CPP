// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of MaxLengthException *
****************************************/
#ifndef MAXLENGTHEXCEPTION_H
#define MAXLENGTHEXCEPTION_H

#include "Exception.h"

class MaxLengthException : public Exception
{
private:
	const string value;
	const string columnName;
public:

	/****************************************************************
	* function name: MaxLengthException                                            *
	* The Input:newValue,  column_name                                            *
	* The output: none                                                *
	* The Function operation:ctor *
	****************************************************************/
	MaxLengthException( const string &newValue, const string &column_name ):
	  columnName( column_name), value( newValue ) {}

	/****************************************************************
	* function name: toString                                            *
	* The Input:none                                              *
	* The output: string                                                *
	* The Function operation:make string *
	****************************************************************/
	const string toString()
	{
		return "Constraint violation: value " +
			value + " is too long for column " + columnName + "\n";
	}
};
#endif