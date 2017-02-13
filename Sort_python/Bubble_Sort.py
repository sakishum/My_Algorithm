#! /usr/bin/env python
#coding=utf-8
# Desc: 冒泡排序算法(BubbleSort)的概念是:
#       依次相邻的两个数，将小的放在前面，大的放在后面。
#       可以修改升序，降序。
#  
# 1.比较相邻的元素。如果第一个比第二个大，就交换他们两个。
# 2.对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
# 3.针对所有的元素重复以上的步骤，除了最后一个。
# 4.持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

def bubbleSort(raw):
    for i in xrange(len(raw)-1):
        # range(start, end, step)
        for j in xrange(len(raw)-1, 0, -1):
            if (raw[j] < raw[j-1]):
                raw[j], raw[j-1] = raw[j-1], raw[j]
    return raw

def main():
    import creat_random_array
    data = creat_random_array.getRandomData(10)
    for i in range(10):
        print i,data[i]
    print '========================'
    result = bubbleSort(data)
    for i in range(len(result)):
        print i, result[i]

if __name__ == '__main__':
    main()
