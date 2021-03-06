Second Try:
//a better solution
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        int left, right;
        for(right=size-1, left=right-1; left >=0; left--, right--) {
            if(num[left] < num[right]) {
                break;
            }
        }
        if(left < 0) {
            sort(num.begin(), num.end());
            return;
        }
        for(int i=size-1; i>=right; i--) {
            if(num[i] > num[left]) {
                swap(num[i], num[left]);
                break;
            }
        }
        sort(num.begin()+right, num.end());
    }
};

/*
函数实现原理：
在当前序列中，从尾端往前寻找两个相邻元素，前一个记为*i，后一个记为*ii，并且满足*i < *ii。
然后再从尾端寻找另一个元素*j，如果满足*i < *j，即将第i个元素与第j个元素对调，
并将第ii个元素之后（包括ii）的所有元素颠倒排序，即求出下一个序列了。
*/
class Solution {
public:
    void swap(vector<int> &num, int i, int j)  
    {  
        int temp = num[i];  
        num[i] = num[j];  
        num[j] = temp;  
    } 
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = num.size(), index = -1;
        //从后往前找出现的第一个升序排列的数对
        for(int i=len-2; i>=0; i--){
            if(num[i] < num[i+1]){
                index = i;//记录下较小数的位置
                break;
            }
        }
        if(index == -1){ //找不到升序排列的数对,i < ii
            sort(num.begin(),num.end());
            return;
        }
        //在顺序数对后，从最右边找一个大于i的数，跟i交换
        for(int i=len-1; i>index; i--){
            if(num[i] > num[index]){
                swap(num, index, i);
                break;      //记得要break，这里WA了一次
            }
        }
		//然后，从ii开始往右排序，就得到next_permutation了
        sort(num.begin()+index+1, num.end());
    }
};