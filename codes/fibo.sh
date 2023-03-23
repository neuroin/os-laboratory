echo "Enter the limit: "
read N
a=0
b=1

echo "The fibonacci series is: "
for (( i=0; i<N; i++ ))
do
	echo -n "$a "
	fn=$(( a + b ))
	a=$b
	b=$fn
done
echo
