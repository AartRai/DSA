#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    vector<int> heap;
    int size;

    MinHeap() {
        heap.push_back(-1);  
        // Dummy element so that heap starts from index 1
        size = 0;
    }

    // 1-based indexing formulas
    int parent(int i) { return i / 2; }
    int leftChild(int i) { return 2 * i; }
    int rightChild(int i) { return 2 * i + 1; }

    // Peek returns minimum element (root of Min Heap)
    int peek() {
        if (size > 0) return heap[1];
        return INT_MAX;
    }

    // Heapify Up is used after insertion
    // New element is moved upward until Min Heap property is satisfied
    void heapifyUp(int pos) {
        while (pos > 1 && heap[parent(pos)] > heap[pos]) {
            swap(heap[parent(pos)], heap[pos]);
            pos = parent(pos);
        }
    }

    // Heapify Down is used after deletion of root
    // Root element is pushed down until Min Heap property is restored
    void heapifyDown(int pos) {
        while (true) {
            int left = leftChild(pos);
            int right = rightChild(pos);
            int smallest = pos;

            // Compare with left child
            if (left <= size && heap[left] < heap[smallest])
                smallest = left;

            // Compare with right child
            if (right <= size && heap[right] < heap[smallest])
                smallest = right;

            // If node is already smallest, stop
            if (smallest == pos) break;

            swap(heap[pos], heap[smallest]);
            pos = smallest;
        }
    }

    // Insert operation:
    // Step 1: Insert element at end
    // Step 2: Fix heap using heapifyUp
    void insert(int num) {
        heap.push_back(num);
        size++;
        heapifyUp(size);
    }

    // Delete root operation:
    // Step 1: Replace root with last element
    // Step 2: Remove last element
    // Step 3: Fix heap using heapifyDown
    void deleteRoot() {
        if (size == 0) return;

        heap[1] = heap[size];
        heap.pop_back();
        size--;

        if (size > 0)
            heapifyDown(1);
    }

    // Display heap elements in array form
    void display() {
        for (int i = 1; i <= size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;

    // Inserting elements into Min Heap
    h.insert(10);
    h.insert(5);
    h.insert(20);
    h.insert(2);

    cout << "Heap Elements: ";
    h.display();

    // Minimum element is always at root
    cout << "Min Element (Peek): " << h.peek() << endl;

    // Delete root element
    h.deleteRoot();

    cout << "After Deleting Root: ";
    h.display();

    return 0;
}
