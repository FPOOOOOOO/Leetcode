//题目：设有两个带头结点的单向链表A和B，其结点数据域均为整数，并且递增有序。设计一个算法，将A和B合并成一个递增有序的链表C。
#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL){}  
};


ListNode* mergeList(ListNode* A, ListNode* B){
  ListNode* Chead = new ListNode(-1);
  ListNode* cur = Chead; //新链表的当前指针

  while(A && B){
    if(A -> val < B -> val){ //因为AB有序，所以依次比较插入
      cur -> next = A;
      A = A -> next;
    }else {
      cur -> next = B;
      B = B -> next;
    }
    cur = cur -> next;
  }
  
  if(A){
    cur -> next = A;  //保证尾部的next为NULL
  }else{
    cur -> next = B;
  }

  ListNode* result = Chead -> next;
  delete Chead;
  return result;
}

int main(){
  //先创建两个链表A和B，然后用新的空间链表C,模拟生成两个链表
  ListNode* A = new ListNode(-1); //
  ListNode* A1 = new ListNode(1);
  ListNode* A2 = new ListNode(2);
  ListNode* A3 = new ListNode(7);
  A -> next = A1;
  A1 -> next = A2;
  A2 -> next = A3;

  ListNode* B = new ListNode(-1); //
  ListNode* B1 = new ListNode(3);
  ListNode* B2 = new ListNode(4);
  ListNode* B3 = new ListNode(5);
  ListNode* B4 = new ListNode(6);
  B -> next = B1;
  B1 -> next = B2;
  B2 -> next = B3;
  B3 -> next = B4;

  ListNode* C  = mergeList(A -> next, B -> next);

  while(C){ //新的链表print
    cout << C -> val << endl;
    C = C -> next;
  }
  return 0;

}

