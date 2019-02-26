class Trigger
{
private:
    int Trig;
public:
    Trigger(){};
    Trigger(int Trig){
        this-> Trig = Trig;
    }
    int getTrigger();
    int setTrigger(int Trig);   
    
};

Trigger::getTrigger()
{
    return Trig;
};
Trigger::setTrigger(int Trig){
    return this ->Trig = Trig;
}
