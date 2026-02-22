# Compilers
CXX      = g++
SWIPL_LD = swipl-ld

# Flags
# swipl-ld automatically finds SWI-Prolog headers. 
# We pass C++20 and optimization flags via -cc-arg.
CXXFLAGS = -std=c++20 -O0

# Files
PROLOG_SRCS = nanisearch.pl
CPP_SRCS    = main.cpp
# Note: SWI-Prolog typically links the .pl directly or via a saved state
TARGET      = nani

# 1. Final Link (Using swipl-ld)
# -ld specifies the C++ compiler to use for linking
$(TARGET): $(CPP_SRCS) $(PROLOG_SRCS)
	$(SWIPL_LD) -ld $(CXX) $(CXXFLAGS) -o $(TARGET) $(CPP_SRCS) $(PROLOG_SRCS)

# 2. Rule for C++ files (if you prefer separate object compilation)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(shell swipl --dump-runtime-variables | grep PLBASE | cut -d'"' -f2)/include -c $< -o $@

# Clean up
clean:
	rm -f *.o $(TARGET)

