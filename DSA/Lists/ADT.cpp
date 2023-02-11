#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class List {
    private:
        int data[MAX_SIZE];
        int size;
    public:
        List() : size(0) {}

        bool  add(int value) {

            if(size < MAX_SIZE){
                data[size++] = value;
                return true;
            }        
            return false;
        }
        void remove(int index){
            if(index >= 0 && index < size) {
                for(int i = index; i < size - 1; i++){
                    data[i] = data[i+1];
                }
                size--;
            }
        }
        int get(int index) const {
            if(index >= 0 && index < size){
                return data[index];
            }
            return -1;
        }
       int getSize() const {
           return size;
       } 

};

int main(){
    List list;
    if (list.add(42) && list.add(13)){
        cout << list.get(0) << endl;
        cout << list.get(1) << endl;
        cout << list.getSize() << endl;
    }
     
}
