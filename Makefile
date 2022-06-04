
SOURCES = ${wildcard src/*.cpp src/*/*.cpp}
OBJS = ${SOURCES:.cpp=.o}

CXX = g++

CFLAGS = -I./include -O2 -Wall -std=c++20 -g --static

assembler: $(OBJS)
	$(CXX) $(CFLAGS) obj/*.o -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o obj/$(notdir $@)