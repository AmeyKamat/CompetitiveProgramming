#!/bin/bash

handle_error() { 
    if [ $1 -ne '0' ]; then 
        exit 1;
    fi 
}

trap ctrl_c INT

function ctrl_c() {
    kill $(ps aux | grep -i "atom ./$FOLDER/$PROGRAM.cp[p] ./test.tx[t]" | awk {'print $2'} ORS=' ') 2>/dev/null
    exit 0;
}

clear
echo "starting cp script..."
echo
g++ --version


FOLDER=$1
PROGRAM=$2
PROGRAM_PATH=./$FOLDER/$PROGRAM.cpp
TEST=./test.txt

if [ ! -f "$PROGRAM_PATH" ]; then
    cp ./template.cpp $PROGRAM_PATH
    handle_error $?
fi

if [ ! -f "$TEST" ]; then
    touch $TEST
    handle_error $?
fi

atom $PROGRAM_PATH $TEST

LPTIME=`stat -c %Z $PROGRAM_PATH`
LTTIME=`stat -c %Z $TEST`

echo
echo "on watch mode..."
echo
echo "watching source file: " $PROGRAM_PATH
echo "watching test file: " $TEST
echo
echo "..................................................."
echo

while true
do
    APTIME=`stat -c %Z $PROGRAM_PATH`
    ATTIME=`stat -c %Z $TEST`

    
    if [[ "$APTIME" != "$LPTIME" ]]; then
        if test -f "a.out"; then
            rm a.out
            handle_error $?
        fi

        echo "compiling..."
        g++ $PROGRAM_PATH -o a.out -std=c++11
        chmod +x a.out
    fi

    if [[ "$APTIME" != "$LPTIME" || "$ATTIME" != "$LTTIME" ]]; then
        echo "running test..."
        echo
        if test -f "a.out"; then
            echo "test:"
            cat $TEST
            echo
            echo "output:"
            start=`date +%s.%N`
            ./a.out < $TEST 2>&1
            end=`date +%s.%N`
            #runtime=$(end-start)
            #echo "execution time: " $runtime
        else
            echo "cannot run code. binary not found."
        fi
        LTTIME=$ATTIME
        LPTIME=$APTIME
        echo
        echo "..................................................."
        echo
    fi
    sleep .01
done
