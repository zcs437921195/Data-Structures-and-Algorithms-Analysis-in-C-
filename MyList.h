//
//  MyList.h
//  Data_Structures_Algorithms
//
//  Created by 周传赛 on 2023/2/28.
//

#ifndef MyList_h
#define MyList_h


template <typename Object> class List{
private:
    struct Node{
        Object data;
        Node * next;
        Node * prev;
        Node(const Object & initdata = Object{}, Node * p = nullptr, Node * n = nullptr): data{initdata}, prev{p}, next{n} {}
        Node(Object && initdata, Node * p = nullptr, Node* n = nullptr): data{std::move(initdata)}, prev{p}, next{n} {}
    };
public:
    // 常量迭代器
    class const_iterator{
    public:
        const_iterator(): current{ nullptr } {}
        
        const Object & operator* () const { return retrieve(); }
        const_iterator & operator++ () {
            current = current->next;
            return *this;
        }
        
        const_iterator operator++ ( int ) {
            const_iterator old = *this;
            ++( *this );
            return old;
        }
        
        const_iterator & operator-- () {
            current = current->prev;
            return *this;
        }
        
        bool operator== (const const_iterator & rhs) const {
            return (current == rhs.current);
        }
        bool operator!= (const const_iterator & rhs) const {
            return !(*this == rhs);
        }
    protected:
        Node *current;
        Object & retrieve() const { return current->data; }
        const_iterator( Node *p ): current{ p } { }
        friend class List<Object>;
    };
    // 一般迭代器
    class iterator: public const_iterator{
    public:
        iterator() {}
        Object & operator* () { return const_iterator::retrieve(); }
        const Object & operator* () const { return const_iterator::operator*(); }
        
        iterator & operator++ () {
            this->current = this->current->next;
            return *this;
        }
        
        iterator operator++ ( int ) {
            iterator old = *this;
            ++( *this );
            return old;
        }
        
        iterator & operator-- () {
            this->current = this->current->prev;
            return *this;
        }
        
    protected:
        iterator( Node *p ): const_iterator{ p } {}
        friend class List<Object>;
        
    };

public:
    List() { init(); }
    List(const List & rhs){
        init();
        for (auto & x: rhs)
            push_back(x);
    }
    List & operator= (const List & rhs){
        List copy = rhs;
        std::swap(*this, copy);
        return *this;
    }
    List(List && rhs): Size{rhs.Size}, head{rhs.head}, tail{rhs.tail} {
        rhs.Size = 0;
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }
    List & operator= (List && rhs){
        std::swap(Size, rhs.Size);
        std::swap(head, rhs.head);
        std::swap(tail, rhs.tail);
        return *this;
    }
    ~List() {
        clear();
        delete head;
        delete tail;
    }
    
    
    iterator begin(){ return head->next; }
    const_iterator begin() const { return head->next; }
    iterator end(){ return tail; }
    const_iterator end() const { return tail; }
    
    int size(){ return Size; }
    bool empty(){ return (size() == 0); }
    
    void clear(){
        while (!empty())
            pop_front();
    }
    
    Object & front(){ return *begin(); }
    const Object & front() const { return *begin(); }
    Object & back() { return *--end(); }
    const Object & back() const { return *--end(); }
    void push_front(const Object & x){ insert(begin(), x); }
    void push_front(Object && x) { insert(begin(), std::move(x)); }
    void push_back(const Object & x){ insert(end(), x); }
    void push_back(Object && x) { insert(end(), std::move(x)); }
    void pop_front() { erase(begin()); }
    void pop_back() { erase(--end()); }
    
    iterator insert(iterator itr, const Object & x){
        Node *p = itr.current;
        p->prev->next = new Node{x, p->prev, p};
        p->prev = p->prev->next;
        Size++;
        return --itr;
    }
    
    iterator insert(iterator itr, Object && x){
        Node *p = itr.current;
        p->prev->next = new Node{std::move(x), p->prev, p};
        p->prev = p->prev->next;
        Size++;
        return --itr;
    }
    
    iterator erase(iterator itr){
        Node *p = itr.current;
        iterator cur{p->next};
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
        Size--;
        return cur;
    }
    
    iterator erase(iterator from, iterator to){
        // for跑完itr马上过时
        for(iterator itr = from; itr != to;)
            itr = erase(itr);
        return to;
    }
    
private:
    int Size;
    Node * head;
    Node * tail;
    
    void init(){
        Size = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }
};

#endif /* MyList_h */
