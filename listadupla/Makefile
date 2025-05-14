# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -g

# Arquivos fonte
SRCS = main.cpp listaduplamente.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = listadupla

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp listaduplamente.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET) 