#! /usr/bin/env python
#coding=utf-8

# 快速排序的原理说起来其实也不是太难，简单地说就是随便选一个中间值，然后把数组分成三块，
# 一块是比这个中间值小的值，一块是比这个中间值大的值，最后一块就是这个中间值。然后把得到
# 的元素数大于二个的数组再重复以上操作直到排序完毕。
# 快速排序在最差情况下的代价是n^2， 平均情况下是nlogn

def quickSort(l):
    return l if len(l)<=1 else quickSort([x for x in l[1:] if x<l[0]])+[l[0]]+quickSort([x for x in l[1:] if x>=l[0]])

def main():
    import creat_random_array
    data = creat_random_array.getRandomData(10)
    for i in range(10):
        print i,data[i]
    print '========================'
    result = quickSort(data)
    for i in range(len(result)):
        print i, result[i]
 
if __name__ == '__main__':
    main()

