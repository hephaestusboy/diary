echo "Enter the date in yyyy-mm-dd Format"
read date
touch text.txt
./code entry/$date.txt text.txt
cat text.txt
rm text.txt
unset date
