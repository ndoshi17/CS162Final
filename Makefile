CC=g++
EXE_FILE = escape

all: $(EXE_FILE)

$(EXE_FILE): MazeLocation.o wall.o openspace.o mazelevel.o maze.o mazeperson.o intrepidStudent.o ta.o instructor.o main.cpp
	$(CC) MazeLocation.o wall.o openspace.o mazelevel.o maze.o mazeperson.o intrepidStudent.o ta.o instructor.o main.cpp -o $(EXE_FILE)

MazeLocation.o: MazeLocation.cpp MazeLocation.hpp
	$(CC) -c MazeLocation.cpp

wall.o: wall.cpp wall.hpp
	$(CC) -c wall.cpp

openspace.o: openspace.cpp openspace.hpp
	$(CC) -c openspace.cpp

mazelevel.o: mazelevel.cpp mazelevel.hpp
	$(CC) -c mazelevel.cpp

maze.o: maze.cpp maze.hpp
	$(CC) -c maze.cpp

mazeperson.o: mazeperson.cpp mazeperson.hpp
	$(CC) -c mazeperson.cpp

intrepidStudent.o: intrepidStudent.cpp intrepidStudent.hpp
	$(CC) -c intrepidStudent.cpp

ta.o: ta.cpp ta.hpp
	$(CC) -c ta.cpp

instructor.o: instructor.cpp instructor.hpp
	$(CC) -c instructor.cpp

clean:
	rm -f *.o $(EXE_FILE)