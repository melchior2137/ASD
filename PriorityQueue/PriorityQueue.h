#include <vector>

template <typename T>
struct Node
{
    T value;
    int priority;

    Node(T value, int priority)
    {
        this->value = value;
        this->priority = priority;
    }
};

template <typename T>
class priorityQueue
{
private:
    std::vector<Node<T>> tab;

public:
    void heapifyUp(int currIndex, int parentIndex)
    {
        while (currIndex > 0 && tab[currIndex].priority > tab[parentIndex].priority)
        {
            std::swap(tab[parentIndex], tab[currIndex]);
            currIndex = parentIndex;
            parentIndex = (currIndex - 1) / 2;
        }
    }

    void put(T value, int priority)
    {
        Node<T> node(value, priority);
        tab.push_back(node);

        int currIndex = tab.size() - 1;
        int parentIndex = (currIndex - 1) / 2;
        heapifyUp(currIndex, parentIndex);
    }

    Node<T> get()
    {
        Node<T> element = tab.front();
        tab[0] = tab.back();
        tab.pop_back();
        int size = tab.size();
        heapifyDown(0, size);
        return element;
    }

    void heapifyDown(int currIndex, int size)
    {
        int swapIndex = currIndex;
        if (2 * currIndex + 1 < size && tab[2 * currIndex + 1].priority > tab[swapIndex].priority)
        {
            swapIndex = 2 * currIndex + 1;
        }

        if (2 * currIndex + 2 < size && tab[2 * currIndex + 2].priority > tab[swapIndex].priority)
        {
            swapIndex = 2 * currIndex + 2;
        }

        if (swapIndex != currIndex)
        {
            std::swap(tab[swapIndex], tab[currIndex]);
            heapifyDown(swapIndex, size);
        }
    }

    Node<T> front()
    {
        return tab.front();
    }

    bool is_empty()
    {
        return tab.empty();
    }

    void make_null()
    {
        tab.clear();
    }

    void print()
    {
        for (Node<T> x : tab)
        {
            std::cout << "Value: " << x.value << " Priority: " << x.priority << ", "<<std::endl;
        }
        std::cout << std::endl;
    }
};
