#!/usr/bin/env python
#coding=utf-8

def BinarySearch(a, target):
    low = 0
    high = len(a) - 1
    # 在其它语言中,如果low + high的和大于Integer的最大值,比如2 ** 31 - 1,
    # 计算便会发生溢出,使它成为一个负数,然后被2除时结果仍为负数。
    # 方法之一是用减法而不是加法——来实现：mid = low + ((high - low) / 2)。
    while low <= high:
        mid = low + ((high - low) / 2)
        midVal = a[mid]

        if midVal < target:     # <
             low = mid + 1
        elif midVal > target:   # >
            high = mid - 1
        else:                   # ==
            return mid
    return -1

if __name__ == '__main__':
    array = [2, 12, 34, 56, 71, 77, 84, 86, 87, 94, 98, 102, 112, 142, 156, 174, 183, 196, 199, 201, 226]
    print "The target position is: ", BinarySearch(array, 87)
