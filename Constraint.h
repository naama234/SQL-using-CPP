// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of Record *
****************************************/
#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "Record.h"

class Constraint
{
public:
	/****************************************************************
	* function name: check                                            *
	* The Input: record                                                *
	* The output: none                                                *
	* The Function operation: check recond*
	****************************************************************/
	virtual void check( Record &record ) = 0; 
};
#endif