// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of QueryParser *
****************************************/
#ifndef QUERYPARSER_H
#define QUERYPARSER_H

#include "DataBase.h"
#include "DataBaseOperation.h"
#include "ParseException.h"

#include "CreateTableOperation.h"
#include "DeleteRecordOperation.h"
#include "DeleteTableOperation.h"
#include "InsertRecordOperation.h"
#include "SelectRecordOperation.h"
using namespace std;
#include <list>
#include <istream>

class QueryParser {
private:
	int _lineNum;

	/****************************************************************
	* function name: extractString                                            *
	* The Input:restOfLine                                              *
	* The output: string                                                *
	* The Function operation:extract *
	****************************************************************/
	string extractString( string& restOfLine );

	/****************************************************************
	* function name: extractStrings                                            *
	* The Input:restOfLine                                              *
	* The output: vector                                                *
	* The Function operation:extract *
	****************************************************************/
	vector<string> extractStrings( string& restOfLine );

	/****************************************************************
	* function name: advanceString                                            *
	* The Input:restOfLine,advanceString                                              *
	* The output: none                                                *
	* The Function operation:advance String *
	****************************************************************/
	void advanceString( string& restOfLine, const string advanceString );
public:
	/****************************************************************
	* function name: parse                                            *
	* The Input:input_stream                                              *
	* The output: list                                                *
	* The Function operation:parse *
	****************************************************************/
	list< DataBaseOperation* > parse(istream& input_stream);

	/****************************************************************
	* function name: QueryParser                                            *
	* The Input:none                                              *
	* The output: none                                                *
	* The Function operation:ctor *
	****************************************************************/
	QueryParser() { _lineNum = 0; }

};

#endif