#!/bin/bash
#
# Хуинь Вьет Хынг ИУ7-22Б, ИУ7И-27Б
#
# Run program with sanitizers
#

echo "sanitize build debug"
./clean.sh
./build_debug.sh
./func_tests/scripts/func_tests.sh

echo "sanitize build debug asan"
./clean.sh
./build_debug_asan.sh
./func_tests/scripts/func_tests.sh

echo "sanitize build debug msan"
./clean.sh
./build_debug_msan.sh
./func_tests/scripts/func_tests.sh

echo "sanitize build debug ubsan"
./clean.sh
./build_debug_ubsan.sh
./func_tests/scripts/func_tests.sh

echo "sanitize build debug clang"
./clean.sh
../common/src/build_debug_clang.sh
./func_tests/scripts/func_tests.sh
