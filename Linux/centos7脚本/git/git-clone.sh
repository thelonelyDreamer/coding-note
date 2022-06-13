
git_clone(){
    echo $1
    if [ $2 -eq 15 ];then
        return
    fi
    git clone $1
    if [ $? -ne 0 ];then 
        git_clone $1 $[$2+1]
    fi
}

git_clone $1 0