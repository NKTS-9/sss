#! /bin/bash
echo $USER 
echo "======="
echo $HOME
echo "======="
who > users
echo "======="
ls ~
echo "======="
cat new3 | head -n 3 | tail -n 1 > text3
echo "======="
cat ./hello_world/main.cpp
echo "======="
./hello_world/main.out
echo "======="
./hello_world/main.out > hello
echo "======="
ls ../..
echo "======="
cal 02 2002 > birth
