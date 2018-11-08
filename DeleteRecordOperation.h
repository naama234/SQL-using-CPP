// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of DeleteRecordOperation *
****************************************/
#ifndef DELETERECORDOPERATION_H
#define DELETERECORDOPERATION_H

#include "DataBaseOperation.h"
class DeleteRecordOperation : public DataBaseOperation
{
private:
	const string _tableName;
	const string _columnName;
	const string _columnValue;
public:

	/****************************************************************
	* function name: DeleteRecordOperation                                            *
	* The Input:tableName,columnValue,columnName                                              *
	* The output: DeleteRecordOperation                                                *
	* The Function operation:delete *
	****************************************************************/
	DeleteRecordOperation( const string& tableName, const string& columnName,
		const string& columnValue ):
	_tableName( tableName ), _columnName( columnName ), 
	_columnValue( columnValue ) {}
	
	/****************************************************************
	* function name: apply                                            *
	* The Input:DataBase                                              *
	* The output: none                                                *
	* The Function operation:apply *
	****************************************************************/
	void apply(DataBase& db)
	{
		db.deleteRecord( _tableName, _columnName, _columnValue );
	}
};

#endif
