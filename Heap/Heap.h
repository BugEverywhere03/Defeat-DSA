#include <vector>
#include <iostream>
class Heap
{

private:
    std::vector<int> heap;
    int getParent(int index)
    {
        return (index - 1) / 2;
    }
    int getLeftChild(int index)
    {
        return 2 * index + 1;
    }
    int getRightChild(int index)
    {
        return 2 * index + 2;
    }
    void heapifiUp()
    {
        int index = heap.size() - 1;
        while (index >= 0 && heap[getParent(index)] < heap[index])
        {
            std::swap(heap[getParent(index)], heap[index]);
            index = getParent(index);
        };
    }
    void heapifiDown(int index)
    {
        int largestIndex = index;
        int leftChild = getLeftChild(largestIndex);
        int rightChild = getRightChild(largestIndex);
        if (leftChild < heap.size() && heap[largestIndex] < heap[leftChild])
            largestIndex = leftChild;
        if (rightChild < heap.size() && heap[largestIndex] < heap[rightChild])
            largestIndex = rightChild;
        if (largestIndex != index)
        {
            std::swap(heap[largestIndex], heap[index]);
            heapifiDown(largestIndex);
        }
    }

public:
    Heap() {}
    Heap(std::vector<int> vector)
    {
        heap = vector;
    }
    void push(int value)
    {
        heap.push_back(value);
        int index = heap.size() - 1;
        heapifiUp();
    }
    void pop()
    {
        if (heap.empty())
        {
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifiDown(0);
    }
    int top()
    {
        if (heap.empty())
            throw std::out_of_range("Heap is empty");
        return heap[0];
    }
    bool empty()
    {
        return heap.empty();
    }
};

