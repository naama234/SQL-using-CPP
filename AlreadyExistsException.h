// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of AlreadyExistsException *
****************************************/
#ifndef ALREADYEXISTSEXCEPTION_H
#define ALREADYEXISTSEXCEPTION_H

#include "Exception.h"

class AlreadyExistsException : public Exception
{
private:

	const string _tableName;

public:

	/****************************************************************
	* function name: AlreadyExistsException                                            *
	* The Input: string                                                *
	* The output: none                                                *
	* The Function operation: ctor AlreadyExistsException              *
	****************************************************************/
	AlreadyExistsException( const string &tableName):
	  _tableName( tableName) {}

	/****************************************************************
	* function name: toString                                            *
	* The Input: none                                                *
	* The output: string                                                *
	* The Function operation: make string             *
	****************************************************************/
	const string toString()
	{
		return "Table "+_tableName+" already exists\n";
	}
};
#endif