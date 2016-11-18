class heap {
   public :
   heap(int);
   virtual void topDownHeapify() = 0;
   virtual void bottomUpHeapify() = 0;
   int getTop();
   int extractTop();
   void addToHeap(int);
   void printElements();

   protected :
   int * arr;
   int max_size;
   int heap_size;
   void allocateSpace();
   void swap(int , int);
};

class maxHeap : public heap {
    public:
    maxHeap(int) ;
    virtual void topDownHeapify();
    virtual void bottomUpHeapify();
};

class minHeap : public heap {
    public:
    minHeap(int) ;
    virtual void topDownHeapify();
    virtual void bottomUpHeapify();
};
