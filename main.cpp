#include"mVector.cpp"
#include"iostream"
int main(){
    mVector<int> a(10,2);
    for(int i = 0; i < 10; ++i){
        a.push_back(i);
    }
    for(mVector<int>::iterator it = a.begin(); it != a.end(); ++it){
        std::cout<<*it;
    }
    std::cout<<std::endl<<a.capacity()<<" "<<a.size();
    return 0;
}