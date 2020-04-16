### [[4] Median of Two Sorted Arrays](cpp/4.median-of-two-sorted-arrays.cpp)

问题简述：
`O(log(m+n))`时间复杂度要求下，返回两个数组的中位数。

思路：
假设有数组A和B，长度分别是m，n。分别有下标i，j将两个数组分成left_A，right_A以及left_B，right_B。
- 有总长度为偶数时：i+j=m−i+n−j 或总长度为基数时：i+j=m−i+n−j+1
- B[j−1]<=A[i] && A[i-1]<=B[j]为终止条件。

因此在0< i < m范围二分查找特定的i的值，j=(m+n+1)/2-i。为保证j>=0，要求m<=n。


### [[10] Regular Expression Matching](cpp/10.regular-expression-matching.cpp)

问题简述：
正则表达式匹配(".", "*")。


### [[23] Merge k Sorted Lists](cpp/23.merge-k-sorted-lists.cpp)

问题简述：
合并k个有序链表到1个有序链表。

思路：
构造一个容量为k的最小堆，将每个有序链表的第一个节点按照元素大小作比较压入堆。每次取出堆中的最小元素，加入新的队列，并将该元素所在链表的下一个元素压入堆中，依次处理。


### [[25] Reverse Nodes in k-Group](cpp/25.reverse-nodes-in-k-group.cpp)

问题简述：
链表中每K个元素进行一次翻转。


### [[30] Substring with Concatenation of All Words](cpp/30.substring-with-concatenation-of-all-words.cpp)

问题简述：

### [[99]]