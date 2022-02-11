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
			make re >> /dev/null
			if [ $? != 0 ]; then
				echo -e "\033[0;31mKO : make re error\033[0m"
				CORRECT=false
			fi
			# ./${TEST_EX%%/}
			EXEC=$(ls -t * | head -1)
			if [[ $OSTYPE == 'darwin'* ]]; then
				if leaks -atExit --q -- ./$EXEC 1>/dev/null 2>/dev/null ; then
					echo -e "\033[0;32mOK\033[0m"
				else
					echo -e "\033[0;31mKO : leaks\033[0m"
					CORRECT=false
				fi
			else
				if valgrind ./$EXEC 1>/dev/null 2>/dev/null | grep -q "definitely lost"  >> /dev/null ; then
					echo -e "\033[0;31mKO : leaks\033[0m"
					CORRECT=false
				else
					echo -e "\033[0;32mOK\033[0m"
				fi
			fi
			make fclean >> /dev/null
			if [ $? != 0 ]; then
				echo -e "\033[0;31mKO : make fclean error\033[0m"
				CORRECT=false
			fi
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
