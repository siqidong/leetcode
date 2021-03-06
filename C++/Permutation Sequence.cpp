/*
n在[1,9]范围，最快的方法如下。
思路：
我们把a1 去掉，那么剩下的排列为a2; a3; :::; an, 共计n-1 个元素，n-1 个元素共有(n-1)!
个排列，于是就可以知道a1 = k/(n-1)!。以此类推。。。
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        int n_x[10];
        vector<char> v;
        string s = "";
        if(n == 1){
            return "1";
        }
        n_x[0] = 1; //0的阶乘
        for(int i=1; i<=n; i++){
            n_x[i] = n_x[i-1]*i; //计算i的阶乘
            v.push_back(i+48);   //把数字的字符放到v中
        }
        while(v.size()){
            int i = 0;
            while(k - n_x[v.size()-1] > 0){ //k-(n-1)!
                i++;
				k -= n_x[v.size()-1];
            }
            s += v[i];
            v.erase(v.begin()+i);
        }
        return s;
    }
};

//暴力枚举法，调用k-1 次next_permutation()。
//暴力枚举法把前k 个排列都求出来了，比较浪费，而我们只需要第k个排列。