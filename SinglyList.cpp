#include<iostream>
using namespace std;

struct node{
	int data;
	node*next;
};

class singly{
	private:
		node*head;
		node*curr;
	public:
		singly(){
			head = new node;
			head = NULL;
			curr = new node;
			curr = NULL;
		}
		
		void insert_at_tail(int d){
			node*newnode = new node;
			newnode->next = NULL;
			newnode->data = d;
			if(head == NULL){
				curr = head;
				head = newnode;
			}
			else{
				curr = head;
				while(curr->next != NULL){
					curr = curr->next;
				}
				curr->next = newnode;
			}
		}
		
		void insert_at_head(int d){
			node*newnode = new node;
			newnode->next = NULL;
			newnode->data = d;
			
			newnode->next = head;
			head = newnode;
		}
		
		void insert_at_middle(int d, int t){
			node*newnode = new node;
			newnode->next = NULL;
			newnode->data = d;
			curr = head;
			int i = 1;
			while(curr->next != NULL && i!=t){
				curr = curr->next;
				i+=1;
			}
			newnode->next = curr->next;
			curr->next = newnode;
		}
		
		void traversal(){
			curr = head;
			while(curr != NULL){
				cout<<curr->data<<"->";
				curr = curr->next;
			}
			cout<<"NULL"<<endl;
		}	
		
		void delete_tail(){
			curr = head;
			while(curr->next->next != NULL){
				//cout<<curr->data<<"->";
				curr = curr->next;
			}
			node*temp = new node;
			temp = curr->next;
			curr->next = NULL;
			delete temp;	
		}
		
		void delete_head(){
			node*temp = new node;
			temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
		}
		
		void delete_from_middle(int t){
			node*temp = new node;
			curr = head;
			int i = 1;
			while(curr->next->next != NULL && i!=t){
				curr = curr->next;
				i+=1;
			}
			temp = curr->next;
			curr->next = curr->next->next;
			delete temp;
		}
		
		bool search(int d){
			curr = head;
			while(curr!=NULL){
				if(curr->data == d){
					return true;
				}
				curr=curr->next;
			}
			return false;
		}
};


int main(){
	singly list;
	list.insert_at_tail(30);
	list.insert_at_tail(20);
	list.insert_at_tail(10);
	list.insert_at_tail(40);
	list.insert_at_head(70);
	list.insert_at_head(10);
	list.insert_at_middle(90,2);
	list.insert_at_middle(90,5);
	list.delete_tail();
	list.delete_head();
	list.delete_from_middle(2);
	list.traversal();
	
	return 0;
}