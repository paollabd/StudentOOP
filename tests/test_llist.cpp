    
#include <cassert>
#include "../my_code/llist.h"

using namespace std;

int main() {
    Node* head = nullptr;
    head = new Node(8, nullptr);
    add_at_end(head, 16);
    add_at_end(head, 32);
    add_at_end(head, 64);
    add_at_end(head, 128);
    add_at_end(head, 256);
    cout << "head->data: " << head->data << endl;
    assert(head->data == 8);
    cout << endl;

// let's see if our last() function works:
    Node* lastp = last(head);
    cout << "Last: " << lastp << endl;
    assert(lastp->data == 256);
    cout << endl;

    add_at_front(head, 4);
    assert(head->data == 4);
    cout << endl;

// delete the head:
    del_head(head);
    assert(head->data == 8);
    cout << endl;

// delete the tail:
    del_tail(head);
    lastp = last(head);
    cout << "Last: " << lastp << endl;
    assert(lastp->data == 128);
    Node* list_of_one = new Node(1, nullptr);
    del_tail(list_of_one);
    print_list(cout, list_of_one);
    cout << endl;

// check our whole list:
    cout << "Head list: \n";
    print_list(cout, head);
    cout << endl;

// now reverse it:
    Node* reversed = reverse(head);
    cout << "Reversed: \n";
    print_list(cout, reversed);
    assert(reversed->data == 128);
    lastp = last(reversed);
    assert(lastp->data == 8);
    cout << endl;


// now duplicate it:
    Node* dupe = duplicate(head);
    cout << "Duplicate: \n";
    print_list(cout, dupe);
    assert(dupe->data == 8);
    lastp = last(dupe);
    assert(lastp->data == 128);
    cout << endl;

// now join the reversed list on to the end of the original list:
    head = join(head, reversed);
    cout << "Joined lists: \n";
    print_list(cout, head);
    lastp = last(head);
    assert(lastp->data == 8);
    cout << endl;

}