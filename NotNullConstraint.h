// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of NotNullConstraint *
****************************************/
#ifndef NOTNULLCONSTRAINT_H
#define NOTNULLCONSTRAINT_H

#include "Constraint.h"
#include "NotNullException.h"

class NotNullConstraint : public Constraint
{
private:
	string columnName;
public:

	/****************************************************************
	* function name: NotNullConstraint                                            *
	* The Input:newColumnName                                              *
	* The output: none                                                *
	* The Function operation:ctor *
	****************************************************************/
	NotNullConstraint( const string &newColumnName ): 
	  columnName( newColumnName ) { }

	/****************************************************************
	* function name: check                                            *
	* The Input:record                                              *
	* The output: none                                                *
	* The Function operation:check *
	****************************************************************/
	void check( Record &record )
	{
		if( record.getValue( columnName ) =="NULL" )
			throw NotNullException( columnName );
	}
};

#endif
