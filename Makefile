CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -fPIC

SRC := src
OUTPUT := output
TESTS := tests

ifeq ($(OS),Windows_NT)
    SHARED_LIB := $(OUTPUT)/mlib.dll
    SHARED_LIB_FLAGS := -shared
    SHARED_LIB_LINK := -Wl,--out-implib,$(OUTPUT)/mlib.lib
    TEST_EXE := $(OUTPUT)/test.exe
    RM := del /q /f
    MD := if not exist $(OUTPUT) mkdir $(OUTPUT)
    EXE_RUN := $(TEST_EXE)
else
    SHARED_LIB := $(OUTPUT)/mlib.so
    SHARED_LIB_FLAGS := -shared
    SHARED_LIB_LINK :=
    TEST_EXE := $(OUTPUT)/test.exe
    RM := rm -f
    MD := mkdir -p $(OUTPUT)
    EXE_RUN := ./test.exe
endif

LIB_SRC := $(wildcard $(SRC)/*.cpp)
LIB_HDR := $(wildcard $(SRC)/*.h)
TEST_SRC := $(TESTS)/test.cpp

.PHONY: all lib test clean

all: lib

lib: $(OUTPUT) $(SHARED_LIB)

$(OUTPUT):
	$(MD)

$(SHARED_LIB): $(LIB_SRC) $(LIB_HDR) | $(OUTPUT)
	$(CXX) $(CXXFLAGS) $(SHARED_LIB_FLAGS) $(SHARED_LIB_LINK) -I$(SRC) -o $(SHARED_LIB) $(LIB_SRC)

test: $(TEST_EXE)
	$(EXE_RUN)

$(TEST_EXE): $(TEST_SRC) $(SHARED_LIB)
	$(CXX) $(CXXFLAGS) -I$(SRC) $(TEST_SRC) $(SHARED_LIB) -o $(TEST_EXE)

clean:
ifeq ($(OS),Windows_NT)
	-$(RM) $(OUTPUT)\*.o $(OUTPUT)\*.so $(OUTPUT)\*.dll $(OUTPUT)\*.lib $(OUTPUT)\*.exe
else
	-$(RM) $(OUTPUT)/*.o $(OUTPUT)/*.so $(OUTPUT)/*.dll $(OUTPUT)/*.lib $(OUTPUT)/*.exe
endif
	@echo Cleanup complete!