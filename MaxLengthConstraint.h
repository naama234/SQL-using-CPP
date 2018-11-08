// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of MaxLengthConstraint *
****************************************/
#ifndef MAXLENGTHCONSTRAINT_H
#define MAXLENGTHCONSTRAINT_H

#include "Constraint.h"
#include "MaxLengthException.h"

class MaxLengthConstraint : public Constraint
{
private:
	string columnName;
	unsigned maxLength;
public:
	/****************************************************************
	* function name: MaxLengthConstraint                                            *
	* The Input:newColumnName, newMaxLength                                              *
	* The output: none                                                *
	* The Function operation:ctor *
	****************************************************************/
	MaxLengthConstraint( const string &newColumnName, unsigned newMaxLength ): 
	  columnName( newColumnName ),
	  maxLength( newMaxLength ){ }

	/****************************************************************
	* function name: check                                            *
	* The Input:record                                              *
	* The output: none                                                *
	* The Function operation:check *
	****************************************************************/
	void check( Record &record )
	{
		if( record.getValue( columnName ).length() > maxLength )
			throw MaxLengthException( record.getValue( columnName ), columnName );
	}
};

#endif