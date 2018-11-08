// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of UnknownColumnInTableException *
****************************************/
#ifndef UNKNOWNCOLUMNINTABLEEXCEPTION_H
#define UNKNOWNCOLUMNINTABLEEXCEPTION_H

#include "Exception.h"

class UnknownColumnInTableException : public Exception
{
private:
	const string _tableName;
	const string _columnName;
public:

	/****************************************************************
	* function name: UnknownColumnInTableException                                            *
	* The Input:tableName,columnName                                              *
	* The output: none                                                *
	* The Function operation:ctor *
	****************************************************************/
	UnknownColumnInTableException( const string& tableName, 
		 const string& columnName ) : 
			_tableName( tableName) , _columnName( columnName ) {} 
	
	/****************************************************************
	* function name: toString                                            *
	* The Input:none                                              *
	* The output: string                                                *
	* The Function operation:make string *
	****************************************************************/
	const string toString()
	{
		return "Unknown column "+_columnName+" in table " + _tableName + "\n";
	}
};
#endif