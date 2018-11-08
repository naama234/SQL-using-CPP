// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: Table *
****************************************/
#include "Table.h"

/****************************************************************
* function name: insertRecord                                            *
* The Input:values,  columns                                            *
* The output: none                                                *
* The Function operation:insert *
****************************************************************/
void Table::insertRecord( vector<string> columns, vector<string> values )
{
	map<string, string> columnsToValues;

	for( unsigned i = 0 ; i < columns.size() ; i++ )
	{
		pair<string, string> entry(columns[i], values[i] );
		columnsToValues.insert(entry);
	}
	Record newRecord( columnsToValues );
	for( unsigned i = 0 ; i < _notNullConstraints.size() ; i ++ )
	{
		_notNullConstraints[i].check( newRecord );
	}
	for( unsigned i = 0 ; i < _uniqueConstraints.size() ; i ++ )
	{
		_uniqueConstraints[i].check( newRecord );
	}
	for( unsigned i = 0 ; i < _maxLengthlConstraints.size() ; i ++ )
	{
		_maxLengthlConstraints[i].check( newRecord );
	}
	_records.push_back( newRecord );
}

/****************************************************************
* function name: selectRecords                                            *
* The Input:column_name,  columns,column_value                                          *
* The output: none                                                *
* The Function operation:select *
****************************************************************/
void Table::selectRecords(vector<string> columns, string column_name,string column_value)
{
	for( unsigned i = 0 ; i < _records.size() ; i++ )
	{
		if ( _records[i].applyTerm( column_name, column_value) )
		{
			for( unsigned j=0;j<columns.size();j++)
			{
				cout<<_records[i].getValue( columns[j] );
				if( j != columns.size()-1)
					cout<<", ";
			}
			cout<<endl;
		}
	}
}

/****************************************************************
* function name: deleteRecord                                            *
* The Input:column_name,  column_value\                                            *
* The output: none                                                *
* The Function operation:delete *
****************************************************************/
void Table::deleteRecord(string column_name,string column_value)
{
	for( unsigned i = 0 ; i < _records.size() ; i++ )
	{
		if ( _records[i].applyTerm( column_name, column_value) )
			_records.erase(_records.begin()+i);
	}
}

/****************************************************************
* function name: columnExist                                            *
* The Input:column_name                                           *
* The output: bool                                                *
* The Function operation:check if exict *
****************************************************************/
bool Table::columnExist( string column_name )
{
	for( unsigned i = 0 ; i < _columnNames.size() ; i++ )
	{
		if( column_name == _columnNames[i] )
			return true;
	}
	return false;
}
