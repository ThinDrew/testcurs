APP_NAME = app
LIB_NAME = lib
FILE_NAME = input.txt
TEST_NAME = test
FILE_INT = _int.txt

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test
TEST_OBJ_DIR = $(OBJ_DIR)/$(TEST_DIR)

CFLAGS = -Wall -Werror
CPPFLAGS = -MMD -I thirdparty -I $(SRC_DIR) -I $(TEST_NAME) -I $(SRC_DIR)/$(LIB_NAME)
CC = g++

APP_PATH = $(BIN_DIR)/$(APP_NAME)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_DIR)/$(TEST_NAME)

SRC_EXT = cpp

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

TEST_SOURCES = $(shell find $(TEST_DIR) -name '*.$(SRC_EXT)')
TEST_OBJECTS = $(TEST_SOURCES:$(TEST_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TEST_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.d)
DEPS_TEST = $(TEST_OBJECTS:.o=.d)

##################################################
.PHONY: all
all: $(APP_PATH)
	./$< $(SRC_DIR)/$(APP_NAME)/$(FILE_NAME)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.$(SRC_EXT)
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

.PHONY: run
run: $(APP_PATH)
	./$< $(SRC_DIR)/$(APP_NAME)/$(FILE_NAME)
##################################################
.PHONY: test
test:$(TEST_PATH)

-include $(DEPS_TEST)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS_TEST) $^ -o $@


.PHONY: test_run
test_run: $(TEST_PATH)
	 ./$< 
##################################################
.PHONY: clean
clean:
	$(RM) $(APP_PATH) $(LIB_PATH) $(TEST_PATH)
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
