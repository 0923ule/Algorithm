#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class LinkedList{
	private:
		Node* head = new Node;
		Node* tail = new Node;
		int count = 0;

	public:
		LinkedList(){
			head->next = tail;
			tail->next = NULL;
		}
		
		Node* findCursor(int idx){
			Node* cursor = head;
			for (int i = 0; i < idx; i++) cursor = cursor->next;
			return cursor;
		}

		void insert(const vector<int>& v, int idx){
			Node* cursor = findCursor(idx);

			Node* next = cursor->next;
			for (int i = v.size()-1; i >= 0; i--){
				Node* newNode = new Node;
				newNode->data = v[i];
				newNode->next = next;
				next = newNode;
			}
			cursor->next = next;
			count += v.size();
		}

		void del(int idx, int cnt) {
			Node* cursor = findCursor(idx);
			for (int i = 0; i < cnt; i++) {
				cursor->next = cursor->next->next;
			}
			count -= cnt;
		}

		void insert_back(const vector<int>& v) {
			insert(v, count);
		}

		void print() {
			Node* cursor = head->next;
			for (int i = 1; i <= 10; i++) {
				cout << cursor->data << " ";
				cursor = cursor->next;
			}
		}

};


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int testcase = 10;
	for (int t = 1; t <= testcase; t++) {
		LinkedList list;

		int n, m;
		cin >> n;

		vector<int> v;
		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			v.push_back(data);
		}
		list.insert(v, 0);
		v.clear();

		
		cin >> m;
		for (int i = 0; i < m; i++) {
			char cmd;
			cin >> cmd;

			
			if (cmd == 'I') {
				int x, y;
				cin >> x >> y;
				for (int j = 0; j < y; j++){
					int data;
					cin >> data;
					v.push_back(data);
				}
				list.insert(v,x);
				v.clear();
			}
			else if (cmd == 'D') {
				int x, y;
				cin >> x >> y;
				list.del(x, y);
			}
			else if (cmd == 'A') {
				int y;
				cin >> y;
				for (int j = 0; j < y; j++){
					int data;
					cin >> data;
					v.push_back(data);
				}
				list.insert_back(v);
				v.clear();
			}
		}
		
		cout << "#" << t << " ";
		list.print();
		cout << "\n";
	}
	return 0;
}
