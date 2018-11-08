ANSI_FLAGS=-ansi -pedantic


a.out: main.o DataBase.o QueryParser.o Table.o Record.o
	g++ main.o DataBase.o QueryParser.o Table.o Record.o

main.o: main.cpp
	g++ -c main.cpp $(ANSI_FLAGS)

DataBase.o: DataBase.h Table.h AlreadyExistsException.h UnknownTableException.h UnknownColumnInTableException.h Exception.h
	g++ -c DataBase.cpp $(ANSI_FLAGS)

QueryParser.o: QueryParser.h DataBaseOperation.h ParseException.h CreateTableOperation.h DeleteRecordOperation.h DeleteTableOperation.h InsertRecordOperation.h SelectRecordOperation.h Exception.h
	g++ -c QueryParser.cpp $(ANSI_FLAGS)

Table.o: Table.h Record.h MaxLengthConstraint.h UniqueConstraint.h NotNullConstraint.h Constraint.h 
	g++ -c Table.cpp $(ANSI_FLAGS)

Record.o: Record.h
	g++ -c Record.cpp $(ANSI_FLAGS)
