CC        = gcc
CFLAGS    = -std=c11 -Wall -Wextra -Wpedantic -g -fsanitize=address,undefined
LDLIBS    = -lm

# Domain-agnostic engine core
CORE_OBJS = fel.o clock.o context.o kernel.o dispatch.o prng.o dist.o time_acc.o sample_acc.o timed_clock.o timed_loop.o

TESTS     = test_fel test_clock test_dispatch test_prng_dist

BUILD_DIR = build
LIB       = $(BUILD_DIR)/libqsim.a

ENGINE_OBJS = $(CORE_OBJS:%=$(BUILD_DIR)/%)
TEST_BINS   = $(TESTS:%=$(BUILD_DIR)/%)

# Disable ASLR for WSL compatibility
NOASLR = setarch $(shell uname -m) -R

all: $(LIB) $(TEST_BINS)

# Static library
$(LIB): $(ENGINE_OBJS)
	ar rcs $@ $^


$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Test executables

$(BUILD_DIR)/test_fel: $(BUILD_DIR)/test_fel.o $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

$(BUILD_DIR)/test_clock: $(BUILD_DIR)/test_clock.o $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

$(BUILD_DIR)/test_dispatch: $(BUILD_DIR)/test_dispatch.o $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

$(BUILD_DIR)/test_prng_dist: $(BUILD_DIR)/test_prng_dist.o $(LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

# Tests
test: $(TEST_BINS)
	$(NOASLR) ./$(BUILD_DIR)/test_fel
	$(NOASLR) ./$(BUILD_DIR)/test_clock
	$(NOASLR) ./$(BUILD_DIR)/test_dispatch
	$(NOASLR) ./$(BUILD_DIR)/test_prng_dist

# Clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all test clean
