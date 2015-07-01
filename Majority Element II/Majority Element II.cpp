/*
    ��res1��res2ά���������ܵĽ�
    cnt1��cnt2��ʾ���ǵľ�����������г���n/3��������ô���ľ�����һ���Ǵ���0��
    ʱ�临�Ӷ�O(n)
    �ռ临�Ӷ�O(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int res1,res2;                      //���ִ�������n/3�����ֻ������������res1,res2
        int cnt1 = 0,cnt2 = 0;              //������
        for(int i = 0;i < nums.size();i++){
            if(cnt1 && nums[i] == res1)     cnt1++;         //��ǰ����res1��ͬ
            else if(cnt2 && nums[i] == res2)    cnt2++;     //��ǰ����res2��ͬ
            else if(cnt1 == 0){                             //res1û����
                res1 = nums[i];cnt1++;
            }
            else if(cnt2 == 0){                             //res2û����
                res2 = nums[i];cnt2++;
            }
            else{                                           //��ǰ����res1,res2����ͬ
                cnt1--;cnt2--;
            }
        }
        //����õ����ǿ��ܵ�������res1,res2,������֤��������
        int sum1 = 0,sum2 = 0;                      //sum1,sum2�ֱ�Ϊres1��res2�������г��ֵĴ���
        for(int i = 0;i < nums.size();i++){
            if(cnt1 && nums[i] == res1)     sum1++;
            if(cnt2 && nums[i] == res2)     sum2++;
        }
        vector<int> res;
        if(sum1 > nums.size() / 3)  res.push_back(res1);
        if(sum2 > nums.size() / 3)  res.push_back(res2);
        return res;
    }
};

