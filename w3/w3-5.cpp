#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* pre;
    Node* next;

    Node(int v) {
        val = v;
        pre = next = nullptr;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        Node* arr[n+5];
        Node* head = new Node(1);
        arr[1] = head;
        Node* tail = head;
        for (int i = 2 ; i <= n ; i++) {
            Node* node = new Node(i);
            arr[i] = node;
            tail->next = node;
            node->pre = tail;
            tail = node;
        }
        while (q--) {
            char c;
            int i;
            cin >> c >> i;
            if (c == 'H') {
                if (i == head->val) continue;
                if (arr[i]->next) arr[i]->next->pre = arr[i]->pre;
                if (arr[i]->pre) arr[i]->pre->next = arr[i]->next;
                if (i == tail->val) tail = tail->pre;
                arr[i]->next = head;
                head->pre = arr[i];
                head = arr[i];
                head->pre = nullptr;
            }
            else {
                if (i == tail->val) continue;
                if (arr[i]->next) arr[i]->next->pre = arr[i]->pre;
                if (arr[i]->pre) arr[i]->pre->next = arr[i]->next;
                if (i == head->val) head = head->next;
                arr[i]->pre = tail;
                tail->next = arr[i];
                tail = arr[i];
                tail->next = nullptr;
            }
        }
        cout << head->val;
        head = head->next;
        while (head != nullptr) {
            cout << " " << head->val;
            head = head->next; 
        }
        cout << "\n";
    }
}