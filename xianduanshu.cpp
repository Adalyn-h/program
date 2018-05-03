ACM训练总结--线段树
一、概念
  1.使用树结构的一段区间。
  2.若父节点维护区间[l,r],则其左右孩子维护区间[l，l+mid],[mid+1,r](mid = (l+r)/2)。
二、思路
  1.建树
    使用结构体或者用数组存储信息都行。
    （1）用分治的思想，将问题分解为更小的子问题，即将一段比较大的区间分解为更小的区间，在小区间内求解。
          
    （2）实现：
         void build(int x, int l, int r){
              if(l == r){
               tree[x] = 1;
                return;
         }
         int mid = (l + r) / 2;
         build(x, l,mid);
         build(x,mid+1,r);
          tree[x] = 
          }


