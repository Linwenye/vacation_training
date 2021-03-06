// #include <iostream>
// #include <string>
// using namespace std;
// 
// class Solution {
// 
// public:
// 	struct Node {
// 		Node *loop;
// 		Node *next;
// 		bool end;
// 		char value;
// 		Node(char val) {
// 			value = val;
// 			loop = next = NULL;
// 		}
// 	};
// 
// 	Node* first;
// 	Node* tail;
// 	string s;
// 	bool result;
// 
// 	bool isMatch(string s, string p) {
// 		this->s = s;
// 		result = false;
// 		first = new Node('.'); //pivot
// 		tail = first;
// 
// 		//construct pattern state diagram
// 		for (int i = 0; i < p.size(); i++)
// 		{
// 			if ((p[i] >= 'a'&&p[i] <= 'z') || p[i] == '.')
// 			{
// 				tail->next = new Node(p[i]);
// 				tail = tail->next;
// 			}
// 			else
// 			{
// 				tail->loop = tail;
// 			}
// 		}
// 		if (p.size())
// 		{
// 			_judge_end(first->next);
// 		}
// 		match();
// 		cout << result << endl;
// 		return result;
// 	}
// 
// 	void _judge_end(Node *judging_node) {
// 		if (judging_node == tail)
// 		{
// 			if (tail->loop)
// 			{
// 				tail->end = true;
// 			}
// 			else
// 			{
// 				tail->end = false;
// 			}
// 		}
// 		else
// 		{
// 			_judge_end(judging_node->next);
// 			if (!judging_node->loop)
// 			{
// 				judging_node->end = false;
// 			}
// 			else {
// 				judging_node->end = judging_node->next->end;
// 			}
// 		}
// 	}
// 
// 	void match() {
// 		_match(first->next, 0);
// 	}
// 
// 	void _match(Node* matching, int i) {
// 		if (i == s.size() || matching == NULL || result)
// 		{
// 			if (i == s.size() && (matching == NULL || matching->end))  //!
// 			{
// 				result = true;
// 			}
// 			return;
// 		}
// 
// 		if (matching->loop)
// 		{
// 			_match(matching->next, i);  //0 time match this char
// 			if (matching->value == s[i] || matching->value == '.')
// 			{
// 				_match(matching->next, i + 1);
// 				_match(matching->loop, i + 1);
// 			}
// 
// 		}
// 
// 		else if (matching->value == s[i] || matching->value == '.')
// 		{
// 			_match(matching->next, i + 1);
// 		}
// 	}
// };
// 
// int main() {
// 	Solution so;
// 	so.isMatch("aab", "c*a*b");
// 	so.isMatch("aab", "a*");
// 	so.isMatch("aa", "a*");
// 	so.isMatch("aa", "a");
// 	so.isMatch("mississippi", "mis*is*ip*.");
// }