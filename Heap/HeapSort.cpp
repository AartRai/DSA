// 1. Convert the array into a Max Heap.
//    In a Max Heap, the parent node is always greater than its children.
// 2. The root of the Max Heap contains the largest element.
// 3. Swap the root with the last element of the heap.
// 4. Reduce the heap size by 1 because the last element is now sorted.
// 5. Restore the Max Heap property using heapify().
// 6. Repeat steps 3–5 until only one element remains.
// 7. The array becomes sorted in ascending order.


void heapifyDown(int pos)
{
    while (true)
    {
        int left = 2 * pos;
        int right = 2 * pos + 1;
        int largest = pos;

        if (left <= size && heap[left] > heap[largest])
            largest = left;

        if (right <= size && heap[right] > heap[largest])
            largest = right;

        if (largest == pos)
            break;

        swap(heap[pos], heap[largest]);
        pos = largest;
    }
}

void heapSort()
{
    for (int i = size / 2; i >= 1; i--)
        heapifyDown(i);

    int originalSize = size;
    while (size > 1)
    {
        swap(heap[1], heap[size]);
        size--;
        heapifyDown(1);
    }

    size = originalSize;
}

//TC : O(n log n)
//SC : O(1)
