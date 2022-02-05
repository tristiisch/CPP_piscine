#!/bin/bash
#################################### SETTINGS ####################################
CORRECT=true

for TEST in $(ls -d cpp*/)
do
	FILE=test_${TEST%%/}.sh
	if test -f "${TEST%%/}/$FILE"; then
		cd $TEST
		echo "###################################################"
		echo "Tests ${TEST%%/}"
		./$FILE
		if [ $? != 0 ]; then
			CORRECT=false
		fi
		cd - >> /dev/null
	else
		echo "###################################################"
		echo "Tests ${TEST%%/}"
		cd $TEST
		for TEST_EX in $(ls -d ex*/)
		do
			cd $TEST_EX
			echo "---------------------------------------------------"
			echo "Test ${TEST%%/}/${TEST_EX%%/}"
			make >> /dev/null
			# ./${TEST_EX%%/}
			if valgrind ./${TEST_EX%%/} 1>/dev/null 2>/dev/null | grep -q "definitely lost"  >> /dev/null ; then
				echo -e "\e[0;31mKO : leaks\e[0m"
			else
				echo -e "\e[0;32mOK\e[0m"
			fi
			make fclean >> /dev/null
			cd - >> /dev/null
		done
		cd ..
	fi
done
################################## RETURN CODE ##################################
if [ $CORRECT != "true" ]; then
	exit 1
else
	exit 0
fi
