// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of UniqueConstraint *
****************************************/
#ifndef UNIQUECONSTRAINT_H
#define UNIQUECONSTRAINT_H

#include "Constraint.h"
#include "UniqueException.h"

#include <vector>

class UniqueConstraint : public Constraint
{
private:
	string columnName;
	vector<string> values;
public:
	/****************************************************************
	* function name: UniqueConstraint                                            *
	* The Input: newColumnName                                          *
	* The output: none                                                *
	* The Function operation:ctor*
	****************************************************************/
	UniqueConstraint( const string &newColumnName ): 
	  columnName( newColumnName ){ }
	 /****************************************************************
	* function name: check                                            *
	* The Input:record                                           *
	* The output: none                                                *
	* The Function operation:check*
	****************************************************************/
	void check( Record &record )
	{
		for( unsigned i = 0 ; i < values.size() ; i++ )
			if( values[i] == record.getValue( columnName ) )
				throw UniqueException( record.getValue( columnName ), columnName ); 
		values.push_back( record.getValue( columnName ) );
	}
};

#endif
