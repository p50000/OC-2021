if !(test -f ex2.txt); then
    echo 0 >> ex2.txt
fi

if ln ex2_2.txt ex2_2.txt.lock; then
    while true
    do 
        a=$(tail -n1 ex2_2.txt)
        a=$((a+=1))
        echo $a >> ex2_2.txt
    done
    rm ex2_2.txt.lock
fi