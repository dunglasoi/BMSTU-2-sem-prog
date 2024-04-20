#!/bin/bash
#
# Хуинь Вьет Хынг ИУ7-22Б, ИУ7И-27Б
#
# Functional test program
#

echo "Test arg p"
../common/src/func_tests_opt.sh p

echo ""
echo "Test arg s"
../common/src/func_tests_opt.sh s

# other test
echo ""
./func_tests/scripts/func_tests_m.sh

exit $?
