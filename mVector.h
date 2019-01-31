
template<class T>
class mVector {
        T* ptr = nullptr;
        int vSize;
        int arrSize;
    public:
        class iterator{
                T* p;
            public:
                iterator(T* add): p(add){}
                iterator(): p(nullptr) {}
                void operator= (T* add) {p = add;}
                bool operator!= ( T* add) {return p != add;}
                T operator* () {return *p;}
                T& operator[] (const int& address) {return ptr[address];}
                const T& operator[] (const int& address) const {return ptr[address];}
                void operator+ (const int* val) {p = p + val;}
                void operator++ () {p = p + 1;}
        };
        void insert(iterator it, const T& value);
        void erase(iterator it);
        void clear();
        int capacity() {return arrSize;}
        int size() {return vSize;}
        void push_back(const T& val);
        void pop_back();
        T* begin();
        T* end();
        bool Empty();
        T at(int position);
        mVector() : arrSize(0), ptr(nullptr), vSize(0) {}
        mVector(int val);
        mVector(int val1, int val2);
        mVector(const mVector& mv);
        mVector(mVector&& mv);
        ~mVector() {delete[] ptr;}
        T& operator[] (const int& address);
        const T& operator[] (const int& address) const;
        mVector<T>& operator= (const mVector<T>& mv1);
        mVector<T>& operator= (mVector<T>&& mv1);                
};
