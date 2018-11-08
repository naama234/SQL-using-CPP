#ifndef INSERTRECORDOPERATION_H
#define INSERTRECORDOPERATION_H

#include "DataBaseOperation.h"
class InsertRecordOperation : public DataBaseOperation
{
private:
	const string _tableName;
	vector<string> _columns;
	vector<string> _values;
public:
	/****************************************************************
	* function name: InsertRecordOperation                                            *
	* The Input:tableName,columns,values                                          *
	* The output: InsertRecordOperation                                                *
	* The Function operation:Insert *
	****************************************************************/
	InsertRecordOperation( const string& tableName, vector<string> columns, 
		vector<string> values ):
	_tableName( tableName ), _columns( columns ), 
	_values( values ) {}
	
	/****************************************************************
	* function name: apply                                            *
	* The Input:DataBase                                              *
	* The output: none                                                *
	* The Function operation:apply *
	****************************************************************/
	void apply(DataBase& db)
	{
		db.insertRecord( _tableName, _columns, _values );
	}
};

#endif
