#include <iostream>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
#include <set>
#include <fstream>
using namespace std;
struct Node{// to make list of number if there are multi numbers to one person
    string P_number;
    Node* next; // we use it because if there are another number
};
struct contact// struct that include info about person that we want to contact with him
{
    Node* head;
    string name;
};
vector<contact>vec;
set<string>c_name;

void get_name(){
    fstream f;
    string x,t,y;
    int m=0;
    f.open("contacts.txt",ios::in);
    f.seekg(0,ios::beg);
    while(f>>y>>x>>t){
        m++;
        c_name.insert(x+" "+t);
    }
    f.close();
}
bool comparevector(string i1, string i2)
{
    return (i1 < i2);
}
void get_number(){
    string x,t,y;
    int m=0;
    set<string>::iterator it;
    for(it=c_name.begin();it!=c_name.end();++it){
        string n=*it;
        fstream f;
        vector<string>c_num;
        f.open("contacts.txt",ios::in);
        while(f>>y>>x>>t){
            if(n==x+" "+t){
                c_num.push_back(y);
            }
        }
        sort(c_num.begin(), c_num.end(), comparevector);
        contact c;
        c.name=n;
        for(int vec = 0 ; vec < c_num.size() ; vec++){
                string h=c_num[vec];
                Node* new_node=new Node();
                new_node->next=NULL;
                new_node->P_number=h;
                if(vec==0){
                    c.head=new_node;
                }
                else{
                    Node* node = c.head;
                    while(node->next!=NULL){
                        node=node->next;
                    }
                    node->next=new_node;
                }
        }
        vec.push_back(c);
        f.close();

    }

}
void print(){
    contact c;
    vector<contact>::iterator it;
    for(it=vec.begin();it!=vec.end();it++){
        c=*it;
        cout<<c.name<<" ";
        Node* new_node=c.head;
        while(new_node!=NULL){
            cout<<new_node->P_number<<"--";
            new_node=new_node->next;
        }
        cout<<endl;
    }
}
int main()
{
    get_name();
    get_number();
    print();

    return 0;
}
