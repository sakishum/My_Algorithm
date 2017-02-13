#! /usr/bin/env python
#coding=utf-8

# 选择排序的原理，假设我们要得到的结果是升序的，那么首先从数组中选一个最小的元素，
# 将它与第一个元素调换位置，然后选第二小的元素，让它与数组的第二个元素交换。当全部
# 元素交换完毕时，排序工作就完成了。


def selectSort(raw):
    for i in range(len(raw)-1):
        indexMark = i
        for j in range(i, len(raw)):
            if (raw[j] < raw[indexMark]):
                indexMark = j
        raw[i], raw[indexMark] = raw[indexMark],  raw[i]
    return raw

def main():
    import creat_random_array
    data = creat_random_array.getRandomData(10)
    result = selectSort(data)
    for i in range(len(result)):
        print i, result[i]

if __name__ == '__main__':
    main()
