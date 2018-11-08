// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of ParseException *
****************************************/
#ifndef PARSEEXCEPTION_H
#define PARSEEXCEPTION_H
using namespace std;

#include "Exception.h"
#include <sstream>
class ParseException : public Exception
{
private:
	const int _lineNum;
public:

	/****************************************************************
	* function name: ParseException                                            *
	* The Input:lineNum                                              *
	* The output: none                                                *
	* The Function operation:ctor *
	****************************************************************/
	ParseException( int lineNum ):
	  _lineNum( lineNum) {}

	/****************************************************************
	* function name: toString                                            *
	* The Input:none                                              *
	* The output: string                                                *
	* The Function operation:make string *
	****************************************************************/
	const string toString()
	{
		std::stringstream sin;
		int n = _lineNum;
		sin<<n;
		return string( "Syntax error, at line ") +
			sin.str() + " \n";
	}
};
#endif