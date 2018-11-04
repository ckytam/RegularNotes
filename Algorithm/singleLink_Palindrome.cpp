#include <iostream>
#include <string>

#define data_type char

using namespace std;

// 首先定义单链表结构
class singleLink{
  public:
    singleLink() = default;
    data_type ctr;
    singleLink *next;
    ~singleLink();
};

// 链表初始化 头结点
singleLink* initSingLinkList(){
   singleLink *head = new singleLink();
   head->next = NULL;
   return head;
}

// 链表插入一个元素，指定位置
bool insertSingLinkNode(data_type ctr,singleLink* singlist,int n){
   int i = 0;
   int j = n-1;
   while(i<j && singlist){
      singlist = singlist->next;
      ++i;
   }
   if(singlist != NULL){
      singleLink *insertNode = new singleLink(); // 动态申请内存空间
      auto tmp = singlist->next;
      singlist->next = insertNode;
      insertNode->ctr = ctr;
      insertNode->next = tmp;
      return true;
   }else{
      return false;
   }
}

// 头插法插入数据
singleLink* insertHead(const string &s,singleLink *head){
  if(s.size()){
    for(int i = 0;i<s.size();i++){
      singleLink* singNode = new singleLink();
      singNode->ctr = s[i];
      singNode->next = head;
      head = singNode;
    }
    return head;
  }else{
    return head;
  }
}
// 删除第n个元素
bool delsingNode(singleLink *linkList,int n){
  int i = 0;
  int j = n-1;
  while(i<j && linkList){
    linkList = linkList->next;
    ++i;
  }
  if(linkList!= NULL){
    linkList->next = linkList->next->next;
    return true;
  }else{
    return false;
  }
}
// 查找第n个元素
singleLink* searchNode(singleLink *linkList,int n){
  int i = 0;
  while(i<n&&linkList){
    linkList = linkList->next;
    ++i;
  }
  if(linkList != NULL){
    return linkList->next;
  }else{
    return NULL;
  }
}
// 链表翻转
singleLink* reveseLink(singleLink *linkList){
  // 不要断链
    auto tmp = linkList->next;
    linkList->next = linkList;
    if(tmp){
      reveseLink(tmp);
    }

}

int main(){
  singleLink *head = new singleLink();
  head = initSingLinkList();
  head = insertHead("ssobbb",head);
  if(insertSingLinkNode('c',head,3)){
    cout << "insert Success" << endl;
  }else{
    cout << "insert wrong" << endl;
  }
  if(delsingNode(head,2)){
    cout << "delete Success" << endl;
  }else{
    cout << "delete wrong" << endl;
  }
  while(head){
    cout << head->ctr << endl;
    head = head->next;
  }
  cout << "hello, world?" << endl;
  return 0;
}
