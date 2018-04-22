#include "CircularInt.hpp"
using namespace std;

CircularInt::CircularInt(const int& min,const int& max){
    this->min=min;
    this->max=max;
    this->hour=1;
}
CircularInt::CircularInt(int hour){
    this->hour=hour;
}
// CircularInt::~CircularInt(){
//     delete &min;
//     delete &max;
//     delete &hour;
// }
int CircularInt::GetHour() const{
    return hour;
}
int CircularInt::GetMax() const{
    return max;
}
int CircularInt::GetMin() const{
    return min;
}
void CircularInt:: setHour(int hour){
     this->hour=hour;
}
CircularInt& CircularInt:: operator+= (const CircularInt& other){
    this->hour=hour+other.hour;
    while(hour>max){
        hour=hour-(max-min+1);
    }
    return *this;
}
CircularInt& CircularInt:: operator-= (const CircularInt& other){
    this->hour=hour-other.hour;
    while(hour<min){
        hour=hour+(max-min+1);
    }
    return *this;
}
const CircularInt& CircularInt:: operator=(const CircularInt& a){
    this->hour=a.hour;
    return(*this);
}

CircularInt& CircularInt:: operator++ (){
    hour=hour+1;
    if(hour>max){
        hour=min;
    }
    return *this;
}
CircularInt CircularInt:: operator++(int){
    CircularInt temp(*this);
    operator++();
    return temp;
}
const CircularInt CircularInt:: operator-(){
    CircularInt temp(*this);
    temp.hour=-hour;
    while(temp.hour<min){
        temp.hour=temp.hour+(max-min+1);
    }
    return temp;
}
const CircularInt& CircularInt:: operator*= (const CircularInt& a){
    hour=hour*a.hour;
    while(hour>max){
        hour=hour-(max-min+1);
    }
    while(hour<min){
        hour=hour+(max-min+1);
    }
    return *this;
}
const CircularInt& CircularInt:: operator/= (const CircularInt& a){
    if(this->hour%a.hour!=0)
            throw string("There is no number x in {"+to_string(this->min)+","+to_string(this->max)+"} such that x*"+to_string(a.hour)+"="+to_string(this->hour));
    hour=hour/a.hour;
    while(hour>max){
        hour=hour-(max-min+1);
    }
    while(hour<min){
        hour=hour+(max-min+1);
    }
    return *this;
}

