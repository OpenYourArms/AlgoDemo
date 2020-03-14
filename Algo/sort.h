//
// Created by Administrator on 2020/3/14.
//

#ifndef ALGODEMO_SORT_H
#define ALGODEMO_SORT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

/* 排序算法实践
 * ref:https://www.cnblogs.com/onepixel/articles/7674659.html
 * 1. 冒泡
 * 2. 选择
 * 3. 插入
 * 4. 归并排序
 * 5. 快速排序
 * 6. 堆排序
 * 7. 希尔排序
 * 8. 多路归并排序
 * 9. 计数排序
 * 10. 桶排序
 * 11. 基数排序
 * */

namespace oyas{
    namespace sort{

        //冒泡排序
        template<typename T>
        void BubbleSort(vector<T>& vc,int be=0,int en=1e9){
            en=min(en, static_cast<int>(vc.size()));
            int lo=be,hi=en;
            for(int i=hi-1;i>lo;i--){
                for(int j=lo+1;j<=i;j++){
                    if(vc[j-1]>vc[j]){
                        swap(vc[j-1],vc[j]);
                    }
                }
            }
        }
        //选择排序
        template<typename T>
        void SelectionSort(vector<T>& vc,int be=0,int en=1e9){
            en=min(en, static_cast<int>(vc.size()));
            int lo=be,hi=en;
            int pos=be;
            for(int i=hi-1;i>lo;i--){
                pos=lo;
                for(int j=lo;j<=i;j++){
                    if(vc[j]>vc[pos]){
                        pos=j;
                    }
                }
                swap(vc[pos],vc[i]);
            }
        }
        //插入排序
        template<typename T>
        void InsertionSort(vector<T>& vc,int be=0,int en=1e9){
            en=min(en, static_cast<int>(vc.size()));
            int lo=be,hi=en;
            T val={};
            int pos=0;
            for(int i=be+1;i<hi;i++){
                val=vc[i];
                pos=i-1;
                while(pos>=lo&&vc[pos]>val){
                    vc[pos+1]=vc[pos];
                    pos--;
                }
                vc[pos+1]=val;
            }
        }
        //归并排序
        template<typename T>
        void MergeSort(vector<T>&vc,int be=0,int en=1e9){
            en=min(en,static_cast<int>(vc.size()));
            int lo=be,hi=en;
            if(lo+1>=hi){
                return;
            }
            int mi=lo+(hi-lo)/2;
            MergeSort(vc,lo,mi);
            MergeSort(vc,mi,hi);
            vector<T>::iterator it1=vc.begin();
            vector<T>::iterator it2=it1;
            advance(it1,lo);
            advance(it2,mi);
            vector<T> tmp=vector<T>(it1,it2);
            vector<T>::iterator it3=tmp.begin();
            vector<T>::iterator it4=vc.begin();
            advance(it4,hi);
            for(int i=lo;i<hi;i++){
                if(it3!=tmp.end()&&it2!=it4){
                    if(*it3<*it2){
                        vc[i]=*it3;
                        it3++;
                    }else{
                        vc[i]=*it2;
                        it2++;
                    }
                }else if(it3!=tmp.end()){
                    vc[i]=*it3;
                    it3++;
                }else{
                    ;
                }
            }
        }
        //快速排序
        template<typename T>
        void QuickSort(vector<T>& vc,int first=0,int last=1e9){
            last=min(last, static_cast<int>(vc.size())-1);
            int lo=first,hi=last;
            if(lo>=hi){
                return;
            }
            int pos=qsPartition_1(vc,lo,hi);
            QuickSort(vc,lo,pos);
            QuickSort(vc,pos+1,hi);
        }
        template<typename T>
        int qsPartition_1(vector<T>& vc,int first,int last){
            //1 pos
            int lo=first,hi=last;
            T val=vc[lo];
            while(lo<hi){
                while(lo<hi&&val<=vc[hi]) hi--;
                vc[lo]=vc[hi];
                while(lo<hi&&vc[lo]<=val) lo++;
                vc[hi]=vc[lo];
            }
            vc[lo]=val;
//            cout<<lo<<" "<<hi<<endl;
            return lo;
        }
        template<typename T>
        int qsPartition_mi(vector<T>& vc,int first,int last){
            //mi pos
            int lo=first-1,hi=last+1;
            int mi=(first+last)/2;
            T val=vc[mi];
            while(lo<hi){
                do{lo++;}while(vc[lo]<val);
                do{hi--;}while(vc[hi]>val);
                if(lo<hi){
                    swap(vc[lo],vc[hi]);
                }
            }
//            cout<<lo<<" "<<hi<<endl;
            return hi;
        }
        template<typename T>
        int qsPartition_rand(vector<T>& vc,int first,int last){
            //rand pos
        }

        //输出到一行
        template<typename T>
        void print(vector<T>& vc,int lo=0,int hi=1e9){
            hi=min(hi, static_cast<int>(vc.size()));
            cout<<"["<<lo<<", "<<hi<<"): ";
            for(int i=lo;i<hi;i++){
                cout<<vc[i]<<" ";
            }
            cout<<endl;
        }

        //产生随机数
        template<typename T>
        void randData(vector<T>& vc,int n,T lb=0,T hb=1e9){
            unsigned int seed= static_cast<unsigned int>(time(nullptr));
            srand(seed);//设置种子
            for(int i=0;i<n;i++){
                T tmp=rand() % static_cast<int>(hb-lb);
                tmp+=lb;
                vc.push_back(tmp);
//                vc.back()/=1.2;
            }
        }
    }
}

#endif //ALGODEMO_SORT_H
