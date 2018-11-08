// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of DataBase *
****************************************/
#ifndef DATABASE_H
#define DATABASE_H

#include "Table.h"
#include "AlreadyExistsException.h"
#include "UnknownTableException.h"
#include "UnknownColumnInTableException.h"
class DataBase
{
private:

	map<string, Table> _tables;
	bool isTableAlreadyExist( string tableName );

public :

	/****************************************************************
	* function name: createTable                                            *
	* The Input:tableName,columns                                                *
	* The output: none                                                *
	* The Function operation: create *
	****************************************************************/
	void createTable( string tableName, Columns columns );

	/****************************************************************
	* function name: deleteRecord                                            *
	* The Input:tableName,column_name,column_value                                              *
	* The output: none                                                *
	* The Function operation: delete *
	****************************************************************/
	void deleteTable( string tableName );

	/****************************************************************
	* function name: deleteRecord                                            *
	* The Input:tableName,column_name,column_value                                              *
	* The output: none                                                *
	* The Function operation: delete *
	****************************************************************/
	void deleteRecord(string tableName,string column_name,string column_value);

	/****************************************************************
	* function name: insertRecord                                            *	
	* The Input:tableName,columns,values                                                *
	* The output: none                                                *
	* The Function operation: insert Record *
	****************************************************************/
	void insertRecord( string tableName, vector<string> columns, vector<string> values );

	/****************************************************************
	* function name: selectRecords                                            *
	* The Input:tableName,columns,column_name,column_value                                              *
	* The output: none                                                *
	* The Function operation: select *
	****************************************************************/
	void selectRecords(string tableName, vector<string> columns, 
		string column_name,string column_value);

};
#endif
