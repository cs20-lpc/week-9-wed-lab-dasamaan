#include "ArrayQueue.hpp"
#include <iostream>
using namespace std;

int main() {
    cout << "=== TEST 1: Empty Queue Behavior ===\n";
    ArrayQueue<int> q1(5);

    try {
        cout << q1.front() << endl;
    } catch (string& e) {
        cout << e << endl;
    }

    try {
        cout << q1.back() << endl;
    } catch (string& e) {
        cout << e << endl;
    }

    cout << "Length: " << q1.getLength() << endl;
    cout << "Is Empty: " << q1.isEmpty() << endl;

    cout << "\n=== TEST 2: Enqueue Elements ===\n";
    for (int i = 1; i <= 5; i++) {
        q1.enqueue(i * 10);
        cout << "Enqueued: " << i * 10 << endl;
    }

    cout << "Front: " << q1.front() << endl;
    cout << "Back: " << q1.back() << endl;
    cout << "Length: " << q1.getLength() << endl;
    cout << "Is Full: " << q1.isFull() << endl;

    cout << "\n=== TEST 3: Enqueue on Full Queue ===\n";
    try {
        q1.enqueue(999);
    } catch (string& e) {
        cout << e << endl;
    }

    cout << "\n=== TEST 4: Dequeue Elements ===\n";
    while (!q1.isEmpty()) {
        cout << "Front: " << q1.front() << " -> Dequeue\n";
        q1.dequeue();
    }

    cout << "Length after dequeue: " << q1.getLength() << endl;

    cout << "\n=== TEST 5: Dequeue on Empty Queue ===\n";
    try {
        q1.dequeue();
    } catch (string& e) {
        cout << e << endl;
    }

    cout << "\n=== TEST 6: Circular Behavior ===\n";
    ArrayQueue<int> q2(5);

    for (int i = 0; i < 5; i++) {
        q2.enqueue(i);
    }

    // Remove 2 elements
    q2.dequeue();
    q2.dequeue();

    // Add 2 more (should wrap around)
    q2.enqueue(100);
    q2.enqueue(200);

    cout << "Queue contents: ";
    while (!q2.isEmpty()) {
        cout << q2.front() << " ";
        q2.dequeue();
    }
    cout << endl;

    cout << "\n=== TEST 7: Copy Constructor ===\n";
    ArrayQueue<int> q3(5);
    q3.enqueue(1);
    q3.enqueue(2);
    q3.enqueue(3);

    ArrayQueue<int> q4 = q3;

    cout << "Original queue: ";
    while (!q3.isEmpty()) {
        cout << q3.front() << " ";
        q3.dequeue();
    }
    cout << endl;

    cout << "Copied queue: ";
    while (!q4.isEmpty()) {
        cout << q4.front() << " ";
        q4.dequeue();
    }
    cout << endl;

    cout << "\n=== TEST 8: Assignment Operator ===\n";
    ArrayQueue<int> q5(5);
    q5.enqueue(7);
    q5.enqueue(8);

    ArrayQueue<int> q6(5);
    q6 = q5;

    cout << "Assigned queue: ";
    while (!q6.isEmpty()) {
        cout << q6.front() << " ";
        q6.dequeue();
    }
    cout << endl;

    cout << "\n=== TEST 9: Clear Function ===\n";
    ArrayQueue<int> q7(5);
    q7.enqueue(11);
    q7.enqueue(22);

    q7.clear();

    cout << "Length after clear: " << q7.getLength() << endl;
    cout << "Is Empty: " << q7.isEmpty() << endl;

    try {
        cout << q7.front() << endl;
    } catch (string& e) {
        cout << e << endl;
    }

    cout << "\n=== TEST 10: Different Data Type (string) ===\n";
    ArrayQueue<string> q8(3);

    q8.enqueue("hello");
    q8.enqueue("world");

    cout << q8.front() << " " << q8.back() << endl;

    q8.dequeue();
    cout << "After dequeue: " << q8.front() << endl;

    return 0;
}