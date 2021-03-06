
#(V)_
#( ..)
#c(")(")
#Bunny


LOCAL_ALLOW_UNDEFINED_SYMBOLS := true

# Test which OS we are compiling from to get the appropriate executable file.
$(info $(SHELL))
ifeq ($(shell uname -s), Linux)
TARGET_EXEC ?= a.out
endif
ifeq ($(OS),Windows_NT)
TARGET_EXEC ?= a.exe
endif
ifeq ($(shell uname -s), Darwin) # OS X
TARGET_EXEC ?= a.out
endif

# Define the build and compiled source path.
BUILD_DIR ?= "build"
SRC_DIR ?= "src"

# Define where to get the file to compile and how to output as object and dependencies ?
SRCS := $(shell find $(SRC_DIR) -name *.cpp -or -name *.c -or -name *.s)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

# Define the includes' directory and their flags
INC_DIRS := $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Depending on the OS we set a bunch of parameters for the compiler


ifeq ($(shell uname -s), Linux)
CPPFLAGS ?= $(INC_FLAGS)  -std=c++14 -MMD -MP -g -Wall -Wextra -O3 -fpermissive #-Werror
endif
ifeq ($(OS),Windows_NT)
CPPFLAGS ?= $(INC_FLAGS) -g -std=c++14 -std=gnu++14 -MMD -MP -g -Wall -Wextra -O3 -fpermissive -static  -Wunused-parameter -Wstrict-aliasing #-Wl,-subsystem,windows #-Werror
endif
ifeq ($(shell uname -s), Darwin)
CPPFLAGS ?= $(INC_FLAGS) -std=c++14 -MMD -MP -g -Wall -Wextra -fpermissive
endif

# Define the linkers' flag. So which libraries we are linking to.
ifeq ($(shell uname -s), Linux)
LINKER_FLAGS = -I./inc/ -L./lib/Linux/ -lGLEW -lGL -lglfw -lSOIL
endif
ifeq ($(OS),Windows_NT)
LINKER_FLAGS = -I"./inc/" -L"lib/Windows" -static -std=c++14 -std=gnu++14 -Wunused-parameter -Wstrict-aliasing -lmingw32 -lglew32 -lglfw3 -llibSOIL -lopengl32 -lglu32 -lgdi32 -dl #-I"./inc/steam/" -lsteam_api #-llua53 -dl
endif
ifeq ($(shell uname -s), Darwin)
LINKER_FLAGS = -I./inc/ -L./lib/macOS -framework OpenGL -lGLEW -lglfw -lSOIL
endif

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	g++ $(OBJS) -o $@ $(LDFLAGS) $(LINKER_FLAGS)

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) $(LINKER_FLAGS) -c $< -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	g++ -std=c++0x $(CPPFLAGS) $(CFLAGS) $(LINKER_FLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	g++ $(CPPFLAGS) $(CXXFLAGS) $(LINKER_FLAGS) -c $< -o $@


.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)/$(SRC_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
