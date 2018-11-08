// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of DataBaseOperation *
****************************************/
#ifndef DATABASEOPERTAION_H
#define DATABASEOPERTAION_H

#include "DataBase.h"

class DataBaseOperation {
public:
	/****************************************************************
	* function name: apply                                            *
	* The Input:DataBase                                              *
	* The output: none                                                *
	* The Function operation:apply *
	****************************************************************/
	virtual void apply(DataBase& db) = 0;
};

#endif
