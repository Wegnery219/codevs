# 最小的N个和
### 题目描述 Description
有两个长度为 N 的序列 A 和 B，在 A 和 B 中各任取一个数可以得到 N^2 个和，求这N^2 个和中最小的 N个。
### 输入描述 Input Description
第一行输入一个正整数N；第二行N个整数Ai 且Ai≤10^9；第三行N个整数Bi，
且Bi≤10^9
### 输出描述 Output Description
输出仅一行，包含 n 个整数，从小到大输出这 N个最小的和，相邻数字之间用
空格隔开。
### 样例输入 Sample Input
5

1 3 2 4 5 </br>
6 3 4 1 7
### 样例输出 Sample Output
2 3 4 4 5
### 数据范围及提示 Data Size & Hint
【数据规模】 对于 100%的数据，满足 1≤N≤100000。
### 解题思路
一开始想的是建两个堆，一个是a的，一个是b的，用a堆和b堆提取出来两个最小元素相加，作为第一个元素，然后pop出去两个最小元素中较大的那一个，用小的那个和下一个堆顶元素相加，但是存在一种两个元素相等不知道该pop出去谁的情况，而且这样得到的元素就是其中一个堆的元素和另一个元素全部值相加的结果。因为小的那个永远pop不出去，举一个反例，1，3|2，8，最小元素是1+2=3，但是第二小的元素是2+3=5，如果把2pop出去就会有问题。所以以b为基准，先用b中第一个元素加上a中全部元素（排好序）,找到最小的数，然后用最小的数对应的a的值加上b中下一个元素的值,push进栈，不用加全部元素的原因是如果a+b[1]是最小元素，b[1]会继续迭代成b[2]，以此类推，相当于从剩下的元素中找到最有可能是最小的元素加入堆中。
### 核心代码
```
sort(a,a+n,cmp);
	sort(b,b+n,cmp);
	node k;
	for(int i=0;i<n;i++){
		node k;
		k.index=0;
		k.value=a[i]+b[0];
		q.push(k);
	}
	int s=0;
	while(s<n){
		node now=q.top();
		q.pop();
		node k;
		if(now.index+1<n){
			k.index=now.index+1;
			k.value=now.value-b[now.index]+b[now.index+1];
			q.push(k);
		}
		s++;
		cout<<now.value<<' ';
	
```