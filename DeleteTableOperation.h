// 318421070 Naama Nisim 
/****************************************
* Student Name: Naama Nisim *
* Exercise Name: Ex4 *
* File description: header of DeleteTableOperation *
****************************************/
#ifndef DELETETABLEOPERATION_H
#define DELETETABLEOPERATION_H

#include "DataBaseOperation.h"
class DeleteTableOperation : public DataBaseOperation
{
private:
	const string _tableName;
public:
	/****************************************************************
	* function name: DeleteTableOperation                                            *
	* The Input:tableName                                              *
	* The output: DeleteTableOperation                                                *
	* The Function operation:delete *
	****************************************************************/
	DeleteTableOperation( const string& tableName ):
	_tableName( tableName ) {}
	
	/****************************************************************
	* function name: apply                                            *
	* The Input:DataBase                                              *
	* The output: none                                                *
	* The Function operation:apply *
	****************************************************************/
	void apply(DataBase& db)
	{
		db.deleteTable( _tableName );
	}
};

#endif
