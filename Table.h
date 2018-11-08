// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of Table *
****************************************/
#ifndef TABLE_H
#define TABLE_H

#include "Record.h"
#include <vector>
#include "MaxLengthConstraint.h"
#include "UniqueConstraint.h"
#include "NotNullConstraint.h"
#include <iostream>
#include <sstream>
using namespace std;
typedef map< string ,vector<string> > Columns;

class Table
{
private:

	vector<Record> _records;
	vector<string> _columnNames;
	vector<NotNullConstraint> _notNullConstraints;
	vector<UniqueConstraint> _uniqueConstraints;
	vector<MaxLengthConstraint> _maxLengthlConstraints;

public:
	
	/****************************************************************
	* function name: Table                                            *
	* The Input:none                                         *
	* The output: none                                                *
	* The Function operation:ctor *
	****************************************************************/
	Table() {}

	/****************************************************************
	* function name: Table                                            *
	* The Input:none                                          *
	* The output: none                                                *
	* The Function operation:dtor *
	****************************************************************/
	~Table()
	{}

	/****************************************************************
	* function name: Table                                            *
	* The Input:vector,map                                          *
	* The output: none                                                *
	* The Function operation:ctor *
	****************************************************************/
	Table( Columns columns ) 
	{ 
		for(Columns::const_iterator it = columns.begin();
			it != columns.end(); ++it )
		{
			string column_name = it->first;
			_columnNames.push_back(column_name);

			vector<string> constraints = it->second;
			for( unsigned i = 0 ; i < constraints.size() ; ++i )
			{
				if( constraints[i]=="UNIQUE" )
					_uniqueConstraints.push_back( UniqueConstraint( column_name ) );
				else if( constraints[i]=="NOT_NULL" )
					_notNullConstraints.push_back( NotNullConstraint( column_name ) );
				else if( constraints[i].find("MAX_LENGTH ")==0 )
				{
					std::istringstream in(constraints[i].substr(string("MAX_LENGTH ").size()).c_str());

					int length;
					in >> length;
					_maxLengthlConstraints.push_back( MaxLengthConstraint( column_name, length ) );
				}
			}
		}
	}

	/**********************************************************
	* function name: insertRecord                                            *
	* The Input:values,  columns         ******                                   *
	* The output: none                                                *
	* The Function operation:insert *
	****************************************************************/
	void insertRecord( vector<string> columns, vector<string> values );

	/****************************************************************
	* function name: selectRecords                                            *
	* The Input:column_name,  columns,column_value                                          *
	* The output: none                                                *
	* The Function operation:select *
	****************************************************************/
	void selectRecords(vector<string> columns, string column_name,string column_value);

	/****************************************************************
	* function name: deleteRecord                                            *
	* The Input:column_name,  column_value\                                            *
	* The output: none                                                *
	* The Function operation:delete *
	****************************************************************/
	void deleteRecord(string column_name,string column_value);

	/****************************************************************
	* function name: columnExist                                            *
	* The Input:column_name                                           *
	* The output: bool                                                *
	* The Function operation:check if exict *
	****************************************************************/
	bool columnExist( string column_name );
};

#endif
