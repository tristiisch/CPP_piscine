#!/bin/bash
#################################### SETTINGS ####################################
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
MODULE=`echo $SCRIPT_DIR | xargs basename`
CORRECT=true
CORRECT_RETURN=true

for TEST in $(ls -d ex*/)
do
	FILE=test.sh
	if test -f "${TEST%%/}/$FILE"; then
		cd $TEST
		./$FILE
		if [ $? != 0 ]; then
			CORRECT=false
		fi
		cd - >> /dev/null
	elif ! test -z "${TEST%%/}"; then
		echo "---------------------------------------------------"
		echo "Test $MODULE/${TEST%%/}"
		if test -f "${TEST%%/}/Makefile"; then
			cd $TEST
			make all > ../compile_${TEST%%/} 2> ../compile_${TEST%%/}
			if [ $? != 0 ]; then
				CORRECT=false
				echo -e "\033[0;31mKO : Does not compile\033[0m"
				echo -e "\033[0;31m'cat compile_${TEST%%/}' to read logs\033[0m"
				echo
			else
				rm -f ../compile_${TEST%%/}
				./${TEST%%/} > ../main_${TEST%%/} 2> ../main_${TEST%%/} 
				if [ $? != 0 ]; then
					CORRECT=false
					echo -e "\033[0;31mKO : Return code != 0\033[0m"
					echo -e "\033[0;31m'cat main_${TEST%%/}' to read logs\033[0m"
				else
					rm -f ../main_${TEST%%/}
					echo -e "\033[33mWARN Need units tests...\033[0m"
					echo -e "\033[0;32mOK : launching main return 1\033[0m"
				fi
			fi
			make fclean > ../compile_${TEST%%/}_fclean 2> ../compile_${TEST%%/}_fclean
			if [ $? != 0 ]; then
				CORRECT=false
				echo -e "\033[0;31mKO : fclean on Makefile return 1\033[0m"
				echo -e "\033[0;31m'cat compile_${TEST%%/}' to read logs\033[0m"
				echo
			else
				rm -f ../compile_${TEST%%/}_fclean
			fi
			cd - >> /dev/null
		else
			echo -e "\033[0;31mKO : No MakeFile\033[0m"
			echo
		fi
	else
		echo "---------------------------------------------------"
		echo "Test $MODULE/${TEST%%/}"
		echo -e "\033[0;31mNTI : Nothing turned in\033[0m"
	fi
done
################################## RETURN CODE ##################################
if [ $CORRECT != "true" ]; then
	exit 1
else
	exit 0
fi
