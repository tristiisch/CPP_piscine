#!/bin/bash
#################################### SETTINGS ####################################
SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd)
PROG=`echo $SCRIPT_DIR | xargs basename`
MODULE=`cd $SCRIPT_DIR && echo $(cd -- "$(dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd) | xargs basename`
CORRECT=true
CORRECT_RETURN=true

#################################### COMPILE ####################################
tail -f compile &make > compile
if [ $? != 0 ]; then
	cat compile
	echo -e "\e[0;31mKO : Does not compile\e[0m"
	exit 1
fi

echo "---------------------------------------------------"
echo "Test $MODULE/$PROG"

##################################### TESTS #####################################
./$PROG "shhhhh... I think the students are asleep..." | cat -e > test1_user
if [ $? != 0 ]; then
	CORRECT_RETURN=false
fi
echo "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." | cat -e > test1_correct
diff test1_user test1_correct --color
if [ $? != 0 ]; then
	CORRECT=false
fi

./$PROG Damnit " ! " "Sorry students, I thought this thing was off." | cat -e  > test1_user
if [ $? != 0 ]; then
	CORRECT_RETURN=false
fi
echo "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." | cat -e  > test1_correct
diff test1_user test1_correct --color
if [ $? != 0 ]; then
	CORRECT=false
fi

./$PROG |cat -e > test1_user | cat
if [ $? != 0 ]; then
	CORRECT_RETURN=false
fi
echo "* LOUD AND UNBEARABLE FEEDBACK NOISE *" | cat -e  > test1_correct | cat
diff test1_user test1_correct --color
if [ $? != 0 ]; then
	CORRECT=false
fi

#################################### RESULTS ####################################
rm -f test1_correct test1_user
if [ $CORRECT_RETURN != "true" ]; then
	echo -e "\e[0;31mKO : return code\e[0m"
fi
if [ $CORRECT != "true" ]; then
	echo -e "\e[0;31mKO : error on tests\e[0m"
else
	echo -e "\e[0;32mOK\e[0m"
fi

################################## RETURN CODE ##################################
rm -f compile
if [ $CORRECT_RETURN != "true" ] || [ $CORRECT != "true" ]; then
	exit 1
else
	exit 0
fi
