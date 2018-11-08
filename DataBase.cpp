// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: DataBase *
****************************************/
#include "DataBase.h"

/****************************************************************
* function name: insertRecord                                            *
* The Input:tableName,columns,values                                                *
* The output: none                                                *
* The Function operation: insert Record *
****************************************************************/
void DataBase::insertRecord( string tableName, vector<string> columns, vector<string> values )
{
	//not insert
	if( !isTableAlreadyExist( tableName ) )
		throw UnknownTableException( tableName );
	for( unsigned i = 0 ; i < columns.size() ; i++ )
	{
		if( !_tables[tableName].columnExist( columns[i] ) )
			//check valid
			throw UnknownColumnInTableException( tableName, columns[i] );
	}

	_tables[tableName].insertRecord( columns, values );
}

/****************************************************************
* function name: createTable                                            *
* The Input:tableName,columns                                                *
* The output: none                                                *
* The Function operation: create *
****************************************************************/
void DataBase::createTable( string tableName, Columns columns )
{
	//not create- throw error
	if( isTableAlreadyExist( tableName ) )
		throw AlreadyExistsException( tableName );
	//make new table
	pair<string, Table> entry(tableName, Table(columns) );
	_tables.insert(entry);
}

/****************************************************************
* function name: selectRecords                                            *
* The Input:tableName,columns,column_name,column_value                                              *
* The output: none                                                *
* The Function operation: select *
****************************************************************/
void DataBase::selectRecords(string tableName, vector<string> columns, 
		string column_name,string column_value)
{
	//the table alreday exict
	if( !isTableAlreadyExist( tableName ) )
		throw UnknownTableException( tableName );
	//check all the elemnets
	for( unsigned i=0;i<columns.size();i++)
	{
		if( !_tables[tableName].columnExist( columns[i] ) )
		throw UnknownColumnInTableException( tableName, columns[i] );
	}
	//check valid
	if( !_tables[tableName].columnExist( column_name ) )
		throw UnknownColumnInTableException( tableName, column_name );

	//put the recond
	_tables[tableName].selectRecords( columns, column_name, column_value );
}

/****************************************************************
* function name: deleteRecord                                            *
* The Input:tableName,column_name,column_value                                              *
* The output: none                                                *
* The Function operation: delete *
****************************************************************/
void DataBase::deleteRecord(string tableName,string column_name,string column_value)
{
	//not column exist
	if( !_tables[tableName].columnExist( column_name ) )
		throw UnknownColumnInTableException( tableName, column_name );
	//not table exist
	if( !isTableAlreadyExist( tableName ) )
		throw UnknownTableException( tableName );
	return _tables[tableName].deleteRecord( column_name, column_value );
}

/****************************************************************
* function name: deleteRecord                                            *
* The Input:tableName,column_name,column_value                                              *
* The output: none                                                *
* The Function operation: delete *
****************************************************************/
void DataBase::deleteTable( string tableName )
{
	//not table exist
	if( !isTableAlreadyExist( tableName ) )
		throw UnknownTableException( tableName );
	//delete table
	_tables.erase(tableName);
}

/****************************************************************
* function name: isTableAlreadyExist                                            *
* The Input:tableName                                              *
* The output: bool                                                *
* The Function operation: check if exist *
****************************************************************/
bool DataBase::isTableAlreadyExist( string tableName )
{
	//check all the tables
	for(map<string,Table>::const_iterator it = _tables.begin();
			it != _tables.end(); ++it )
		{
			if( it->first == tableName )
				return true;
		}
	return false;
}