#include <iostream>
#include "include/my_vector.h"          //8 -> 25
#include "include/my_queue.h"           //27 -> 42
#include "include/my_stack.h"           //44 -> 57
#include "include/my_list.h"            //62 -> 81

using namespace std;

int main(){
    //Vector -------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------
    
    // Vector<int> v = {1, 2, 3};

    // v.push_back(1);
    // v.push_back(2);
    // v.pop_back();
    // v.push_back(3);

    // for(int i = 0; i < v.get_size(); i++){
    //     cout<<v[i]<<" ";                                    // prints 1 2 3 1 3
    // }

    // v.pop_back();

    // cout<<"\nCapacity -- "<<v.get_capacity()<<"\n";         // -> 6 [1, 2, 3, 1, 3, []] * 2 (12 after adding two more)  
    // cout<<"Size -- "<<v.get_size()<<"\n";                   // -> 4

    //Queue  -------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------

    // Queue<int> q;
    
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);

    // cout<<"Front " <<q.front()<<"\n";                        // -> 1
    
    // q.dequeue();
    // cout<<"Front after dequeue "<<q.front()<<"\n";           // -> 2
    // cout<<"size "<<q.get_size()<<"\n";                       // -> 2

    //Stack  -------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------

    // Stack<int> s;

    // s.push(15);
    // s.push(22);
    // s.push(34);

    // cout<<"Top "<<s.top()<<"\n";                                // -> 34

    // s.pop();
    // cout<<"Top after pop "<<s.top()<<"\n";                      // -> 22
    // cout<<"Size "<<s.get_size()<<"\n";                          // -> 2

    //--------------------------------------------------------------------------------------
    //--------------------------------------------------------------------------------------

    List<int> myList = {1, 2, 3, 4, 5};

    myList.push_front(9);
    myList.push_back(11);

    cout<<"List contains ";
    for(auto it = myList.begin(); it != myList.end(); ++it) {
        cout<<*it<<" ";
    }
    cout<<"\n";

    cout<<"List contains 3 ? " << (myList.contains(3) ? "Yes\n" : "No\n");
    cout<<"List contains 10 ? " << (myList.contains(10) ? "Yes\n" : "No\n");

    int* found = myList.find(4);
    if(found){
        cout<<"Found value "<<*found<<"\n";
    }else{
        cout<<"Value not found\n";
    }
}