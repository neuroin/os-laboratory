echo "Enter num1: "
read a
echo "Enter num2: "
read b
echo "Enter num3: "
read c

if [ $a -gt $b ] && [ $a -gt $c ]
then
	echo "$a is big"
elif [ $b -gt $c ]
then
	echo "$b is big"
else
	echo "$c is big" 
fi
