#! /usr/bin/env python
#coding=utf-8

# 插入排序说起来是一个简单的排序算法，在排序开始后，程序将数组分成了两个区域，
# 一个是有序区一个是乱序区，然后程序遍历数组，从乱序区中取元素，将取得的元素
# 放入有序区的相应位置中，遍历完毕后则完成排序。

def insertSort(raw):
    for i in xrange(len(raw)):
        for j in xrange(i, 0, -1):
            if (raw[j] < raw[j-1]):
                raw[j], raw[j-1] = raw[j-1], raw[j]
            else: break
    return raw

def insertSort_dx(raw):
    for i in xrange(1, len(raw)):
        j = i - 1
        key = raw[i]
        while (raw[j] > key) and (j >= 0):
            raw[j+1] = raw[j]
            j -= 1
        raw[j+1] = key
    return raw

def main():
    import time
    import creat_random_array
    data1 = data2 = creat_random_array.getRandomData(10)

    start = time.time()
    result = insertSort_dx(data1)
    elapsed = (time.time() - start)
    print "found %s in %s seconds" % ('B', elapsed)  

    for i in range(len(result)):
        print i, result[i]

    start = time.time()
    result = insertSort(data2)
    elapsed = (time.time() - start)
    print "found %s in %s seconds" % ('A', elapsed)  

    for i in range(len(result)):
        print i, result[i]
    
if __name__ == '__main__':
    main()

