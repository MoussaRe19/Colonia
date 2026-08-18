CC        = gcc
CFLAGS    = -std=c11 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined
LDLIBS    = -lm

# Engine paths
ENGINE_DIR = ../../engine
ENGINE_INC = $(ENGINE_DIR)
ENGINE_LIB = $(ENGINE_DIR)/build/libqsim.a

# Model source files
SRCS      = entity.c entity_queue.c mm1_handlers.c mm1_init.c mm1_report.c test_mm1.c
OBJS      = $(SRCS:%.c=$(BUILD_DIR)/%.o)

BUILD_DIR = build
TARGET    = $(BUILD_DIR)/test_mm1

# WSL ASLR workaround
NOASLR    = setarch $(shell uname -m) -R

all: $(TARGET)

# Ensure engine static library is built before linking
$(ENGINE_LIB):
	$(MAKE) -C $(ENGINE_DIR)

# Compile model object files with engine headers included
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(ENGINE_INC) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link model executable against engine library
$(TARGET): $(OBJS) $(ENGINE_LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(ENGINE_LIB) $(LDLIBS)

test: $(TARGET)
	$(NOASLR) ./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean
