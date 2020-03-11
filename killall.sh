read ceProc
test=$(pidof $ceProc)

for i in $test
do
	kill -9 $i
done
