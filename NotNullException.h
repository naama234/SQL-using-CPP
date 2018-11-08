// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of NotNullException *
****************************************/
#ifndef NOTNULLEXCEPTION_H
#define NOTNULLEXCEPTION_H

#include "Exception.h"

class NotNullException : public Exception
{
private:
	const string columnName;
public:

	/****************************************************************
	* function name: NotNullException                                            *
	* The Input:column_name                                              *
	* The output: none                                                *
	* The Function operation:ctor *
	****************************************************************/
	NotNullException( const string &column_name ):
		columnName( column_name) {}

	/****************************************************************
	* function name: toString                                            *
	* The Input:none                                              *
	* The output: string                                                *
	* The Function operation:make string *
	****************************************************************/
	const string toString()
	{
		return "Constraint violation: column "+ 
			columnName + " must contain a value\n";
	}
};
#endif
