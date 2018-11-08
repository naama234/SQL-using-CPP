// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of SelectRecordOperation *
****************************************/
#ifndef SELECTRECORDOPERATION_H
#define SELECTRECORDOPERATION_H

#include "DataBaseOperation.h"
class SelectRecordOperation : public DataBaseOperation
{
private:

	const string _tableName;
	vector<string> _columns;
	const string _columnName;
	const string _columnValue;

public:

	/****************************************************************
	* function name: SelectRecordOperation                                            *
	* The Input:tableName,  columns,columnName,columnValue                                            *
	* The output: none                                                *
	* The Function operation:ctor *
	****************************************************************/
	SelectRecordOperation( const string& tableName, vector<string> columns,
		const string& columnName, const string& columnValue ):
	_tableName( tableName ), _columns(columns), _columnName( columnName ), 
	_columnValue( columnValue ) {}
	
	/****************************************************************
	* function name: apply                                            *
	* The Input:DataBase                                              *
	* The output: none                                                *
	* The Function operation:apply *
	****************************************************************/
	void apply(DataBase& db)
	{
		db.selectRecords(  _tableName, _columns, _columnName, _columnValue );
	}
};

#endif
