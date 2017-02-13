#! /usr/bin/env python
#coding=utf-8
# Filename: creat_random_array.py

import random
version = '0.1'

def getRandomData(num):
    a = []
    i = 0
    while i < num:
        a.append(random.randint(0, 10000000))
        i += 1
    return a

def main():
    a = getRandomData(20)
    for i in range(15):
        print a[i]

if __name__ == '__main__':
    main()
