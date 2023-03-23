echo "Enter a number: "
read num

if [ $num -lt 0 ]
then
	echo "Negative number"
elif [ $num -gt 0 ]
then
	echo "Positive number"
else
	echo "Number is zero"
fi
