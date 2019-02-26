#include <Arduino.h>

template<typename T, typename P>
class Task {
public:
    Task();
    void attach(T (*fun)(P)){
        this->target = fun;
    };
    T run(P var){
        return this->target(var);
    }
private:
    T (*target)(P);
};

template<typename T, typename P>
Task<T, P>::Task(){}