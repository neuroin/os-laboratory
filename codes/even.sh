echo "Enter a number: "
read n

echo "Result: "
if [ $(( $n % 2 )) == 0 ]
then
	echo "$n is even"
else
	echo "$n is odd"
fi
