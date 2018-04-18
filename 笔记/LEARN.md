# 踩过的坑
1. 最大数的表示`long long max=0xffffffff`
2. 题目：我们一般认为两个浮点数相等，当且当他们之间的误差不超过1e-8。可以直接定义成float，不需要double然后去判断和1e-8的差。
3. C++11支持printf，格式化输出两位可以`printf("%.2lf",a)`,cout格式化输出`cout.setf(ios::fixed);  
    cout <<fixed<< setprecision(2) << d <<endl;  `头文件还要包含`iomanip`具体的格式化见[参考](http://blog.csdn.net/u012707739/article/details/77824635)
4. **字符串翻转**</br>
- 翻转没有考虑最后一个单词
```
for(int i=0;i<l;i++){
		if(x[i]==' '){
			fanzhuan(x,mark,i-1);
			mark=i+1;
		}
	}
    //写到这里还差最后一个单词没有翻转
fanzhuan(x,mark,l-1);
```
- <font size=5>很重要:  函数直接传string类型不会改变string的值，见下
```
void fanzhuan(string s,int begin,int end){
	while(begin<end){
		char m=s[begin];
		s[begin++]=s[end];
		s[end--]=m;
	}
}
```
   像上面的代码这么写，函数运行之后，s的值不会有任何改变，见`测试.cpp`应该改为C风格字符串形式
```
void fanzhuan(char *s,int begin,int end){
	while(begin<end){
		char m=s[begin];
		s[begin++]=s[end];
		s[end--]=m;
	}
}
//或者直接传引用
void fanzhuan(string &s,int begin,int end)
```
这样才会改变s</font>
- C风格字符串用strlen需要包含`<cstring>头文件`
- 忘记begin,默认begin都是0，是不对的，因为中间还要翻转其他的。
- 读取一行包括空格的C风格字符串`cin.getline(x,100)`,读取一行包括空格的string`getline(cin,s)`
- sort函数包含在algorithm头文件中，对于数组e，sort(e,e+m,函数)，对于vector v,sort(v.begin(),v.begin()+m,函数)
- 最优布线问题：kruscal能过,prim不能。