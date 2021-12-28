#!/bin/bash
#################################### SETTINGS ####################################
MODULE="cpp00"
PROG="ex00"
CORRECT=true
CORRECT_RETURN=true

#################################### COMPILE ####################################
make > /dev/null

echo "---------------------------------------------------"
echo "Test $MODULE/$PROG"
echo

##################################### TESTS #####################################
./$PROG "shhhhh... I think the students are asleep..." > test1_user
if [ $? != 0 ]; then
	CORRECT_RETURN=false
fi
echo "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." > test1_correct
diff test1_user test1_correct --color
if [ $? != 0 ]; then
	CORRECT=false
fi

./$PROG Damnit " ! " "Sorry students, I thought this thing was off." > test1_user
if [ $? != 0 ]; then
	CORRECT_RETURN=false
fi
echo "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF." > test1_correct
diff test1_user test1_correct --color
if [ $? != 0 ]; then
	CORRECT=false
fi

./$PROG > test1_user
if [ $? != 0 ]; then
	CORRECT_RETURN=false
fi
echo "* LOUD AND UNBEARABLE FEEDBACK NOISE *" > test1_correct
diff test1_user test1_correct --color
if [ $? != 0 ]; then
	CORRECT=false
fi

#################################### RESULTS ####################################
rm -f test1_correct test1_user
echo
if [ $CORRECT_RETURN != "true" ]; then
	echo -e "\e[0;31mreturn code KO\e[0m"
fi
if [ $CORRECT != "true" ]; then
	echo -e "\e[0;31mKO\e[0m"
else
	echo -e "\e[0;32mOK\e[0m"
fi
echo "---------------------------------------------------"

################################## RETURN CODE ##################################

if [ $CORRECT_RETURN != "true" ] || [ $CORRECT != "true" ]; then
	exit 1
else
	exit 0
fi
