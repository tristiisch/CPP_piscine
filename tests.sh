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
		echo "###################################################"
		cd - >> /dev/null
	else
		echo "###################################################"
		echo "Tests ${TEST%%/}"
		echo -e "\e[0;31mNTI : Nothing turned in\e[0m"
		echo "###################################################"
	fi
done
################################## RETURN CODE ##################################
if [ $CORRECT != "true" ]; then
	exit 1
else
	exit 0
fi
