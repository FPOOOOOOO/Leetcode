//��Ŀ������������ͷ���ĵ�������A��B�������������Ϊ���������ҵ����������һ���㷨����A��B�ϲ���һ���������������C��
#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL){}  
};


ListNode* mergeList(ListNode* A, ListNode* B){
  ListNode* Chead = new ListNode(-1);
  ListNode* cur = Chead; //������ĵ�ǰָ��

  while(A && B){
    if(A -> val < B -> val){ //��ΪAB�����������αȽϲ���
      cur -> next = A;
      A = A -> next;
    }else {
      cur -> next = B;
      B = B -> next;
    }
    cur = cur -> next;
  }
  
  if(A){
    cur -> next = A;  //��֤β����nextΪNULL
  }else{
    cur -> next = B;
  }

  ListNode* result = Chead -> next;
  delete Chead;
  return result;
}

int main(){
  //�ȴ�����������A��B��Ȼ�����µĿռ�����C,ģ��������������
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

  while(C){ //�µ�����print
    cout << C -> val << endl;
    C = C -> next;
  }
  return 0;

}

