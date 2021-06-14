#!/bin/bash
for (( y=1; y<=10; y++))
do
touch $y	
b=$(( y + 10 ))	
mv $y $b
done

#	read -s -p "Enter your password:" pass
#if	read -t 4 -p "Enter your name:" name
#then	
#	echo "Hello $name, welcome to my script!"
#else
#	echo "Sorry, too slow!"
#fi
#../lab_t11c/hello_world/main.out
#../lab_t11c/hello_world/main.out .> hello
