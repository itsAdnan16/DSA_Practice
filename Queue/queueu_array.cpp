#include<iostream>
#include<vector>
using namespace std;

class Queue {
private:
    int front;
    int rear;
    int n;
    vector<int> arr;

public:
    Queue(int n) {
        this->n = n;
        arr.resize(n);
        front = 0;
        rear = 0;
    }

    void push(int data) {
        if(rear >= n) {
            cout << "Overflow" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    void pop() {
        if(rear == front) {
            cout << "Queue is empty and cannot pop" << endl;
            front = 0;
            rear = 0;
        } else {
            arr[front] = -1; 
            front++;
        }
    }

    int size() {
        return rear - front;
    }

    int get_front() {
        if(front == rear) {
            return -1;  
        }
        return arr[front];
    }
};

int main() {
    int n = 5;
    Queue* queue = new Queue(n);

    // Pushing values into the queue
    queue->push(10);
    queue->push(20);
    queue->push(30);

    /*cout << "Front value: " << queue->get_front() << endl; // Should output 10

    queue->pop();

    cout << "Front value after pop: " << queue->get_front() << endl; 

    cout << "Queue size: " << queue->size() << endl; */

    queue->push(40);
    queue->push(50);
    cout<<"Now the size after queue is full "<<queue->size();
    //queue->push(60); 

    delete queue; 

    return 0;
}



