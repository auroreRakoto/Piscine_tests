#!/bin/bash

# Define the DIR_PATH (you can pass it as an argument or use a default)
DIR_PATH=${1:-"../../C07/ex*"}

# Find all .c files in DIR_PATH (both exercises and tests)
EX_FILES=$(find $DIR_PATH -name "*.c")
TEST_FILES=$(find . -name "test_*.c")

# Run norminette (coding standard check)
echo "Running norminette ..."
norminette $EX_FILES

# Compile the code and tests
echo "Compiling code..."
cc -Wall -Wextra -Werror main.c assert.c $EX_FILES $TEST_FILES -o test

# If compilation is successful, run the tests with Valgrind
if [ $? -eq 0 ]; then
    echo "Compilation successful! Running tests under Valgrind..."
    valgrind --leak-check=full --error-exitcode=42 ./test
    
    # Check Valgrind's exit code to determine if there were memory leaks
    if [ $? -eq 42 ]; then
        echo "💥 Memory leak detected!"
    else
        echo "✅ No leaks detected."
    fi
else
    echo "❌ Compilation failed!"
fi