#!/usr/bin/env python
# encoding: utf-8
import random

data = ['I 1', 'O 1', '?']
maxn = 100
print(maxn)
for i in range(maxn):
    print(data[random.randint(0, 2)])

