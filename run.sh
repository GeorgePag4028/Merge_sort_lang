#!/bin/bash


case $1 in 
  c)
    ## C
    echo "Runing C code"
    gcc merge_sort.c -o merge_sort && ./merge_sort
    echo ""
    ;;

  cpp)
    ## C++
    echo "Runing C++ code"
    g++ merge_sort.cpp -o merge_sort && ./merge_sort
    echo ""
    ;;

  python)
    ## Python
    echo "Runing python code"
    python3 merge_sort.py
    echo ""
    ;;
  java)
    ## Java
    echo "Runing java code"
    javac merge_sort.java && java merge_sort
    echo ""
    ;;
  *)
    echo "unknown"
    ;;
esac
