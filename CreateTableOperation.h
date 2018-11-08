// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of CreateTableOperation *
****************************************/
#ifndef CREATETABLEOPERATION_H
#define CREATETABLEOPERATION_H

#include "DataBaseOperation.h"
class CreateTableOperation : public DataBaseOperation
{
private:

	const string _tableName;
	Columns _columns;

public:
	/****************************************************************
	* function name: CreateTableOperation                                            *
	* The Input: string ,vector,map                                                *
	* The output: Table                                                *
	* The Function operation: Create Table Operation*
	****************************************************************/
	CreateTableOperation( const string& tableName, 
		Columns &columns ):
	_tableName( tableName ), _columns( columns ) {}
	
	/****************************************************************
	* function name: apply                                            *
	* The Input:DataBase                                                *
	* The output: none                                                *
	* The Function operation: apply Table *
	****************************************************************/
	void apply(DataBase& db)
	{
		db.createTable( _tableName, _columns );
	}

};

#endif
