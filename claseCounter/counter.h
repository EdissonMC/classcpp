#ifndef counter_Included
#define counter_Included

class Counter {
    public:
        Counter(int maxValue);
        void increment();
        void decrement();
        int getValue() const;
    private:
        int value;
        const int maximum;
};
#endif
