CXXFLAGS = -Wall

all : create.o query.o update.o utils.o main.o
	g++ $(CXXFLAGS) -o a.out create.o query.o update.o utils.o main.o

create.o : management.h
query.o : management.h
update.o : management.h
utils.o : management.h
main.o : management.h
