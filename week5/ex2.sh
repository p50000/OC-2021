if !(test -f ex2.txt); then
    echo 0 >> ex2.txt
fi

while true
do 
    a=$(tail -n1 ex2.txt)
    a=$((a+=1))
    echo $a >> ex2.txt
done