// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of UnknownTableException *
****************************************/
#ifndef UNKNOWNTABLEEXCEPTION_H
#define UNKNOWNTABLEEXCEPTION_H

#include "Exception.h"

class UnknownTableException : public Exception
{
private:
	const string _tableName;
public:

	/****************************************************************
	* function name: UnknownTableException                                            *
	* The Input:tableName                                              *
	* The output: none                                                *
	* The Function operation:ctor *
	****************************************************************/
	UnknownTableException( const string &tableName ): 
		_tableName( tableName) {}

	/****************************************************************
	* function name: toString                                            *
	* The Input:none                                              *
	* The output: string                                                *
	* The Function operation:make string *
	****************************************************************/
	const string toString()
	{
		return "Unknown table " + _tableName + "\n";
	}
};
#endif