using namespace std;

struct EncodedList {
	std::string storage;
};
struct Node {
	int val;
	struct Node* next;
	Node(int v) : val(v), next(nullptr) {}
};

EncodedList encode(Node* head) {
	EncodedList e;
	for(auto it = head; it != nullptr; it = it->next) {
		e.storage += to_string(it->val);
		if(it->next) e.storage += ",";
	}
	return e;
}

Node* decode(const EncodedList& e) {
	Node* head = nullptr;
	Node* last = nullptr;
	const auto& str = e.storage;
	auto pos = str.find(",", 0);
	auto prevPos = 0;
	while(pos != string::npos) {
		auto val = str.substr(prevPos, pos - prevPos);
		auto p = new Node(stoi(val));
		if(!head) head = last = p;
		else {
			last->next = p;
			last = p;
		}
		prevPos = pos + 1;
		pos = str.find(",", prevPos);
	}
	// add the last Node
	last->next = new Node(stoi(str.substr(prevPos, str.length() - prevPos)));
	return head;
}

Node* insertLast(Node* head, int v) {
    auto p = new Node(v);
    if(!head) return p;
    
    auto* last = head;
    while(last->next) {
        last = last->next;
    }
    last->next = p;
    return head;
}

void printList(Node* head) {
    for(auto curr = head; curr; curr = curr->next) {
        cout << curr->val;
        if(curr->next) cout <<", ";
    }
    cout << "\n";
}

void tester(void) {
    vector<int> vec = {10,20,30,40,50};
    Node* head = nullptr;
    for(auto a : vec) head = insertLast(head, a);
    printList(head);
    
    EncodedList e;
    e = encode(head);
    cout << " Encoded string: " << e.storage <<"\n";
    auto decodedList = decode(e);
    printList(decodedList);
}
int main()
{
    tester();
    return 0;
}
