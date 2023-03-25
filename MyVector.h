//
//  MyVector.h
//  Data_Structures_Algorithms
//
//  Created by 周传赛 on 2023/2/28.
//

#ifndef MyVector_h
#define MyVector_h

template <typename Object>
class Vector{
public:
    explicit Vector( int initSize = 0 ): Size{initSize}, Capacity{initSize + SPARE_CAPACITY} { objects = new Object[Capacity]; }
    Vector(const Vector & rhs): Size{rhs.Size}, Capacity{rhs.Capacity} {
        objects = new Object[Capacity];
        for (int i = 0; i < Size; i++)
            objects[i] = rhs.objects[i];
    }
    Vector & operator= (const Vector & rhs){
        Vector copy = rhs;
        std::swap(*this, copy);
        return *this;
    }
    ~Vector() { delete [] objects; }
    
    Vector( Vector && rhs ): Size{ rhs.Size }, Capacity{ rhs.Capacity }, objects{ rhs.objects }
    {
        rhs.objects = nullptr;
        rhs.Size = 0;
        rhs.Capacity = 0;
    }
    
    Vector & operator= ( Vector && rhs ){
        std::swap(Size, rhs.Size);
        std::swap(Capacity, rhs.Capacity);
        std::swap(objects, rhs.objects);
        return *this;
    }
    
    
    void reserve( int newCapacity ){
        if (newCapacity < Size)
            return;
        
        Object * newobjects = new Object[newCapacity];
        for (int i = 0; i < Size; i++)
            newobjects[i] = std::move(objects[i]);
        Capacity = newCapacity;
        std::swap(objects, newobjects);
        delete [] newobjects;
    }
    
    void resize( int newSize ){
        if (newSize > Capacity)
            reserve(newSize * 2);
        Size = newSize * 2;
    }
    
    Object & operator[] (int k){
        return objects[k];
    }
    const Object & operator[] (int k) const {
        return objects[k];
    }
    
    int size() const { return Size; }
    bool empty() { return (size() == 0); }
    int capacity() const { return Capacity; }
    
    void push_back( const Object & x ){
        if (Size == Capacity)
            reserve( 2 * Capacity + 1 );
        objects[Size++] = x;
    }
    
    void push_back( Object && x ){
        if (Size == Capacity) {
            reserve( 2 * Capacity + 1);
        }
        objects[Size++] = std::move(x);
    }
    
    void pop_back(){
        if (empty())
            return;
        Size--;
    }
    
    const Object & back() const {
        return objects[Size - 1];
    }
    
    typedef Object * iterator;
    typedef const Object * const_iterator;
    
    iterator begin(){ return &objects[0]; }
    const_iterator begin() const { return &objects[0]; }
    iterator end() { return &objects[Size]; }
    const_iterator end() const { return &objects[Size]; }
    
    static const int SPARE_CAPACITY = 16;
    
private:
    int Size;
    int Capacity;
    Object * objects;
    
};


#endif /* MyVector_h */
