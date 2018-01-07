package main

import (
    "fmt"
)

// 选出最大的值(选最小值也行)，放在另一个数组里面，如果从前向后放，则就是降序了，从后向前放，就是升序了
// 另一个数组也可以服用原数组，比如下面的实现

//堆排序
//s[0]不用，实际元素从角标1开始
//父节点元素大于子节点元素
//左子节点角标为2*k
//右子节点角标为2*k+1
//父节点角标为k/2

// 以大顶堆为例
func HeapSort(s []int) {
    N := len(s) - 1 //s[0]不用，实际元素数量和最后一个元素的角标都为N
    //构造堆
    //如果给两个已构造好的堆添加一个共同父节点，
    //将新添加的节点作一次下沉将构造一个新堆，
    //由于叶子节点都可看作一个构造好的堆，所以
    //可以从最后一个非叶子节点开始下沉，直至
    //根节点，最后一个非叶子节点是最后一个叶子
    //节点的父节点，角标为N/2
    for k := N / 2; k >= 1; k-- { // 构造堆
        sink(s, k, N)
    }

    // 大顶堆只满足大顶堆的性质，顶点是最大的，但整体不是有序的。我们利用顶点是最大值这个特性，来排序，经过下面的处理就排序了
    //下沉排序
    for N > 1 {
        swap(s, 1, N) //将大的放在数组后面，升序排序
        N--
        sink(s, 1, N)
    }
}

//下沉（由上至下的堆有序化）
func sink(s []int, k, N int) {
    for {
        i := 2 * k // 左孩子
        if i > N { //保证该节点是非叶子节点
            break
        }
        if i < N && s[i+1] > s[i] { //选择较大的子节点
            i++
        }
        // i是较大的子节点
        if s[k] >= s[i] { //没下沉到底就构造好堆了
            break
        }
        swap(s, k, i) // 交换
        k = i // 下次循环，继续判断是否满足大顶堆
    }
}

func swap(s []int, i int, j int) {
    s[i], s[j] = s[j], s[i]
}

func main() {
    s := []int{-1,9, 0, 6, 5, 8, 2, 1, 7, 4, 3}
    fmt.Println(s[1:])
    HeapSort(s)
    fmt.Println(s[1:])
}