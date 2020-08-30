/* Chris Cheng
 * 08/27/2020
 * Circular-Array-based implementation of a Queue
 */

/* This is an implementation of a queue using a circular array.
 * The circular array has a size of 10 and is heap-allocated.
 * 
 * The big disadvantage of using an array-based implementation of a queue is that you create
 * the queue with a fixed size and so the queue can only store up a max num of elements 
 * equal to the fixed size. 
 * 
 * Otherwise, all of the operations work in O(1) time like with linked-list implementation.
 * 
 * 
 * EDIT (08/29/2020):
 * I am adding array resize() functionality to double the size of the array and copy the contents of the 
 * full array (starting at front element and going to back element even in circular situation) plus the 
 * new element into the new array, under the condition that you are pushing an element into a fully-occupied queue.
 * 
 * The queue therefore dynamically changes size to store an increased or decreased number of elements. 
 * 
 * Analogous functionality to halve the size of the array and copy the elements over, under the condition that 
 * the number of elements in the array after the pop() is half the array's capacity.
 * 
 */

#include <iostream>
using namespace std;

const int QUEUE_FIXED_SIZE = 10;

class Queue {
    private:
        int num_elements;   // fixed size for array
        int size;           // num elements currently held in queue
        int* my_array;      // heap-allocate the array to store queue
        int front, back;    // front and back store the indices of the front and back elements
    public:
        // since array is heap-allocated, I need to provide Ctor, Copy-Ctor, and Dtor
        Queue(int arg_num_elements = QUEUE_FIXED_SIZE) : num_elements(arg_num_elements) {
            size = 0;
            my_array = new int[num_elements];
            front = back = -1;
        }
        // copy constructor
        Queue (const Queue& template_queue) {
            // allocate array of same size as one in template queue
            my_array = new int[template_queue.Get_Num_Elements()];
            // copy over all elements currently held in template queue
            for (int i = 0; i < template_queue.Get_Size(); ++i) {
                *(my_array + i) = *(template_queue.my_array + i);
            }
            front = template_queue.Get_Front();
            back = template_queue.Get_Back();
            num_elements = template_queue.Get_Num_Elements();
            size = template_queue.Get_Size(); 
        }
        ~Queue() {
            size = 0;
            delete [] my_array;
            front = back = -1;
        }
        int Get_Num_Elements() const { return num_elements; }
        int Get_Size() const { return size; }
        int Get_Front() const { return *(my_array + front); }
        int Get_Back() const { return *(my_array + back); }
        bool isEmpty() const { return front == -1; }
        bool isFull() const { return size == num_elements; }
        void Push(int data) {
            if (isFull()) {
                //cout << "Queue is full.\n";
                // create a new temp array that has double the fixed size as current array
                num_elements *= 2;
                int* temp_array = new int[num_elements];
                // copy the contents of current array into new array
                if (front <= back) {
                    for (int i = 0; i < num_elements; ++i) {
                        *(temp_array + i) = *(my_array + i); 
                    }
                }
                else {
                    int j = 0;
                    for (int i = front; i < size; ++i,++j) {
                        *(temp_array + j) = *(my_array + i); 
                    }
                    for (int i = 0; i <= back; ++i,++j) {
                        *(temp_array + j) = *(my_array + i); 
                    }
                }
                delete [] my_array;
                // point the my_array pointer to the new temp array 
                my_array = temp_array;
                front = 0, back = size-1;
            }
            if (isEmpty()) {
                front = 0;
            }
            back = (back + 1) % num_elements;
            *(my_array + back) = data;
            ++size;
        }
        void Pop() {
            if (isEmpty()) {
                cout << "Queue is empty.\n";
                front = back = -1;
            }
            else {
                front = (front + 1) % num_elements;
                --size;

                if (size == num_elements / 2) {
                    // create new temp array that is half the fixed size as current array
                    num_elements /= 2;
                    int* temp_array = new int[num_elements];

                    // copy elements of current array over to smaller array 
                    int j = 0;
                    if (front <= back) {
                        for (int i = front; i <= back; ++i,++j) {
                            *(temp_array + j) = *(my_array + i); 
                        }
                     }
                    else {
                        j = 0;
                        for (int i = front; i < num_elements; ++i,++j) {
                            *(temp_array + j) = *(my_array + i); 
                        }
                        for (int i = 0; i <= back; ++i,++j) {
                            *(temp_array + j) = *(my_array + i); 
                        }
                    }
                    delete [] my_array;
                    my_array = temp_array;
                    // reset front index to zero, and back index to (smaller array's size - 1)
                    front = 0, back = num_elements - 1;
                }
            }
        }
        // tried using the modulus technique to loop back and print circular array contents
        // but ended up with a infinite loop. 
        // this (from GeekforGeeks) works and makes sense. 
        void Print_Data() {
            // if front <= back then just print from front index to back index inclusive.
            if (front <= back) {
                for (int i = front; i <= back; ++i) {
                    cout << *(my_array + i) << " ";
                }
            }
            // otherwise we have a circular array situation with front > back and we 
            // first print front elements located at the back of array, then loop back
            // to front of array and print back elemenets.
            else {
                for (int i = front; i < num_elements; ++i) {
                    cout << *(my_array + i) << " ";
                }
                for (int i = 0; i <= back; ++i) {
                    cout << *(my_array + i) << " ";
                }
            }
            cout << endl;
        }
};

void Print_Details(Queue& my_queue) {
    my_queue.Print_Data();
    cout << "Front value is: " << my_queue.Get_Front() << endl;
    cout << "Back value is: " << my_queue.Get_Back() << endl;
    cout << "Queue contains: " << my_queue.Get_Size() << " elements.\n";
}

int main() {
    Queue my_queue;

    for (int i = 1; i <= 10; ++i) {
        my_queue.Push(i);
    }
    Print_Details(my_queue);
    for (int i = 0; i < 6; ++i) {
        my_queue.Pop();
    }
    Print_Details(my_queue);
    for (int i = 1; i <= 2; ++i) {
        my_queue.Push(i);
    }
    Print_Details(my_queue);

    for (int i = 0; i < 7; ++i) {
        my_queue.Pop();
    }
    Print_Details(my_queue);

    // for (int i = 0; i < 5; ++i) {
    //     my_queue.Push((i+1) * 2000);
    // }
    // my_queue.Print_Data();
    // cout << "Queue contains: " << my_queue.Get_Size() << " elements.\n";
    // for (int i = 0; i < 3; ++i) {
    //     my_queue.Push((i+1) * 43);
    // }
    // my_queue.Print_Data();
    // cout << "Queue contains: " << my_queue.Get_Size() << " elements.\n";
    // // my_queue.Print_Data();
    // // my_queue.Push(4);
    // for (int i = 0; i < 10; ++i) {
    //     my_queue.Pop();
    // }
    // my_queue.Print_Data();
    // //cout << "Queue contains: " << my_queue.Get_Size() << " elements.\n";
    return 0;
}