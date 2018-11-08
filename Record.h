// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of Record *
****************************************/
#ifndef RECORD_H
#define RECORD_H
#include <string>
#include <map>
using namespace std;

class Record
{
private:
	map<string, string> _values;
public:
	Record( map<string, string> values ) { _values = values; };
	
	bool applyTerm(string column_name,string column_value)
	{ return _values.find( column_name ) != _values.end() && _values[column_name] == column_value; };
	
	const string getValue( const string &column_name )
	{ return _values.find(column_name)!=_values.end()?
				_values[column_name] : "NULL"; }
};
#endif