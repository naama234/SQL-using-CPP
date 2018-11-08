// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: QueryParser *
****************************************/
#include "QueryParser.h"

#include <iostream>

/****************************************************************
* function name: parse                                            *
* The Input:input_stream                                              *
* The output: list                                                *
* The Function operation:parse *
****************************************************************/
list<DataBaseOperation*> QueryParser::parse(istream& input_stream)
{
	string line;
	list<DataBaseOperation*> operations;

	try { 
	//loop for all the input
	while ( getline(input_stream, line) )
	{
		_lineNum ++;
		string restOfLine;
		
		if( line.find("CREATE TABLE ")==0 )
		{
			//create new table
			Columns columns;
			restOfLine = line.substr(string("CREATE TABLE ").size());
			string table_name = extractString( restOfLine );
			advanceString( restOfLine, "( ");
			//update constriants
			vector<string> constriants;
			while( restOfLine.find(") ")!=0 )
			{
				string column_name;
				
				column_name = extractString( restOfLine );
				constriants.clear();
				while( restOfLine.find(", ")!=0 && restOfLine.find(") ")!=0 )
				{
					if( restOfLine.find("UNIQUE " )==0 || restOfLine.find("NOT_NULL " )==0 )
					{
						constriants.push_back( extractString( restOfLine ) );
					}
					else if( restOfLine.find("MAX_LENGTH ")==0 )
					{
						string constriant = extractString( restOfLine );
						constriant+=" ";
						constriant+=extractString( restOfLine );
						constriants.push_back( constriant );
					}
					else
						throw( ParseException( _lineNum ) );
				}

				pair< string, vector<string> > entry(column_name, constriants );
				columns.insert(entry);
			
				if( restOfLine.find(") ")!=0 )
					advanceString( restOfLine, ", ");
			}
			restOfLine = restOfLine.substr(string(") ").size());

			if(restOfLine[0] != ';' )
				throw( ParseException( _lineNum ) );

			operations.push_back( new CreateTableOperation( table_name, columns ) );
			continue;
		}


		if( line.find("DROP TABLE ")==0 )
		{
			restOfLine = line.substr(string("DROP TABLE ").size());
			string table_name = extractString( restOfLine );

			if(restOfLine[0] != ';' )
				throw( ParseException( _lineNum ) );

			operations.push_back( new DeleteTableOperation( table_name ) );
			continue;
		}
		
		if( line.find("SELECT ")==0 )
		{
			vector<string> columns;
			string table_name;
			string column_name;
			string column_value;
			restOfLine = line.substr(string("SELECT ").size());
			while( restOfLine.find("FROM ")!=0 )
			{
				columns.push_back( extractString( restOfLine ) );
				if( restOfLine.find("FROM ")!=0 )
					advanceString( restOfLine, ", ");
			}
			advanceString( restOfLine, "FROM ");
			table_name = extractString( restOfLine );
			advanceString( restOfLine, "WHERE ");
			column_name = extractString( restOfLine );
			advanceString( restOfLine, "= ");
			column_value = extractString( restOfLine );

			if(restOfLine[0] != ';' )
				throw( ParseException( _lineNum ) );

			operations.push_back( new SelectRecordOperation( table_name, columns, 
										column_name, column_value ) );
			continue;
		}

		if( line.find("DELETE FROM ")==0 )
		{
			string table_name;
			string column_name;
			string column_value;
			restOfLine = line.substr(string("DELETE FROM ").size());
			
			table_name = extractString( restOfLine );
			advanceString( restOfLine, "WHERE ");
			column_name = extractString( restOfLine );
			advanceString( restOfLine, "= ");
			column_value = extractString( restOfLine );

			if(restOfLine[0] != ';' )
				throw( ParseException( _lineNum ) );

			operations.push_back( new DeleteRecordOperation( table_name, column_name, column_value ) );
			continue;
		}

		if( line.find("INSERT INTO ")==0 )
		{
			restOfLine = line.substr(string("INSERT INTO ").size());
			string table_name = extractString( restOfLine );
			vector<string> columns = extractStrings( restOfLine );
			
			advanceString( restOfLine, "VALUES ");
			vector<string> values = extractStrings( restOfLine );

			if(restOfLine[0] != ';' )
				throw( ParseException( _lineNum ) );
			operations.push_back( new InsertRecordOperation( table_name, columns, values ) );
			continue;
		}
		if(line=="--")
			break;
		if( !(line=="" || line[0]=='#') )
			throw( ParseException( _lineNum ) );
	}
	}
	catch( Exception &exp )
	{
		for(list<DataBaseOperation*>::iterator op = operations.begin(); 
		op != operations.end(); op++)
		{
			delete (*op);
		}
		throw( ParseException( _lineNum ) );
	}

	return operations;
}

/****************************************************************
* function name: advanceString                                            *
* The Input:restOfLine,advanceString                                              *
* The output: none                                                *
* The Function operation:advance String *
****************************************************************/
void QueryParser::advanceString( string& restOfLine, const string advanceString )
{
	if( restOfLine.find(advanceString)==0 )
		restOfLine = restOfLine.substr(advanceString.length());
	else
		throw( ParseException( _lineNum ) );
}

/****************************************************************
* function name: extractString                                            *
* The Input:restOfLine                                              *
* The output: string                                                *
* The Function operation:extract *
****************************************************************/
string QueryParser::extractString( string& restOfLine )
{
	size_t indexOfClosure = restOfLine.find(" ");
			
	if( indexOfClosure == string::npos )
		throw( ParseException( _lineNum ) );
			
	string insideString = restOfLine.substr(0,indexOfClosure);
	restOfLine = restOfLine.substr( indexOfClosure + 1 );
	return insideString;
}

/****************************************************************
* function name: extractStrings                                            *
* The Input:restOfLine                                              *
* The output: vector                                                *
* The Function operation:extract *
****************************************************************/
vector<string> QueryParser::extractStrings( string& restOfLine )
{
	vector<string> strings;
	if( restOfLine.find("( " ) != 0 || restOfLine.find(") " ) == string::npos )
		throw( ParseException( _lineNum ) );
	restOfLine = restOfLine.substr(string("( ").size());

	while( restOfLine.find(") " ) != 0 )
	{
		strings.push_back( extractString( restOfLine ) );
		if( restOfLine.find(", " ) != 0 && restOfLine.find(") " ) != 0 )
			throw( ParseException( _lineNum ) );

		if( restOfLine.find(") " ) != 0 )
			restOfLine = restOfLine.substr(string(", ").size());
	}
	
	restOfLine = restOfLine.substr(string(") ").size());

	return strings;
}