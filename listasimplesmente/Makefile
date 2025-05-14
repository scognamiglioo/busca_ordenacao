# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -g

# Arquivos fonte
SRCS = main.cpp listasimplesmente.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = listasimple

# Diretório dos fontes
SRC_DIR = .

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp listasimplesmente.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET) 