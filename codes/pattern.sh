for (( i=0; i<=10; i++ ))
do
	for (( j=0; j<=10; j++ ))
	do
		if [ $i -lt $j ]
		then
			echo -n "$j "
		fi
	done
	echo
done
