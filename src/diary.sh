cd entry
echo "Enter the date for diary entry in yyyy-mm-dd format."
read date
if [[ '$date' ]]; then
	name="$date.txt"
else
	name="$(date +'%Y-%m-%d').txt"
fi
if [[ -e "$name" ]]; then
	cd ..
	touch today.txt
	./code entry/$name today.txt
	rm entry/$name
else
	cd ..
fi
nano today.txt
./code today.txt entry/$name
rm today.txt
unset date
