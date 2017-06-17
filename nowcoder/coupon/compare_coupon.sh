#!/bin/bash


g++ coupon.cpp -std=c++11 -o coupon
g++ baseline_coupon.cpp -std=c++11 -o baseline
while true; do
    python data_generator_coupon.py > data.txt
    ./coupon < data.txt > coupon.out
    ./baseline < data.txt > baseline.out
    diff coupon.out baseline.out
    if [ $? -ne 0 ] ; then break; fi
done
