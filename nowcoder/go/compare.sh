#!/bin/bash

g++ go_incre.cpp -std=c++11 -o go_incre
g++ go_force.cpp -std=c++11 -o go_force
g++ data_generator.cpp -std=c++11 -o data_generator
while true; do
    ./data_generator > data.txt
    ./go_incre < data.txt > go_incre.out
    ./go_force < data.txt > go_force.out
    diff go_incre.out go_force.out
    if [ $? -ne 0 ] ; then break; fi
done
