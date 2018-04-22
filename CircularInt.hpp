#include <iostream>
using namespace std;

#include <string>
class CircularInt{
    int max;
    int min;
    int hour;
    public:
    CircularInt(const int& ,const int&);
    CircularInt(int);
    //~CircularInt();
    int GetHour() const;
    void setHour(int);
    int GetMin() const;
    int GetMax() const;
    const CircularInt& operator=(const CircularInt&);
    CircularInt& operator+= (const CircularInt&);
    CircularInt& operator-= (const CircularInt&);
    CircularInt& operator++ ();
    CircularInt operator++ (int);
    friend const CircularInt operator+ (const CircularInt& ,const CircularInt&);
    const CircularInt operator-();
    const CircularInt& operator*=(const CircularInt&);
    const CircularInt& operator/=(const CircularInt&);
    friend const CircularInt operator/(const CircularInt&, const CircularInt&);
    friend const CircularInt operator- (const CircularInt&,const CircularInt&);
    friend const CircularInt operator*(const CircularInt&, const CircularInt&);
    friend ostream& operator<< (ostream& out, CircularInt);
};

inline ostream&  operator<< (ostream& out, CircularInt c){
    out << c.hour;
    return out;

}
inline const CircularInt operator-(const CircularInt& c1,const CircularInt& c2){
    CircularInt temp(c1.hour-c2.hour);
    if(c1.min>INT16_MIN&&c1.max>INT16_MIN&&c1.min!=c1.max){
        while(temp.hour<c1.min){
            temp.hour=temp.hour+(c1.max-c1.min+1);
        }
        while(temp.hour>c1.max){
            temp.hour=temp.hour-(c1.max-c1.min+1);
        }
    }
    else{
        while(temp.hour<c2.min){
            temp.hour=temp.hour+(c2.max-c2.min+1);
        }
        while(temp.hour>c2.max){
            temp.hour=temp.hour-(c2.max-c2.min+1);
        }
    }
    return temp;
}
inline const CircularInt operator+ (const CircularInt& c1, const CircularInt& c2){
    CircularInt temp(c1.hour+c2.hour);
    if(c1.min>INT16_MIN&&c1.max>INT16_MIN&&c1.min!=c1.max){
        while(temp.hour>c1.max){
            temp.hour=temp.hour-(c1.max-c1.min+1);
        }
        while(temp.hour<c1.min){
            temp.hour=temp.hour+(c1.max-c1.min+1);
        }
    }
    else{
        while(temp.hour>c2.max){
            temp.hour=temp.hour-(c2.max-c2.min+1);
        }
        while(temp.hour<c2.min){
            temp.hour=temp.hour+(c2.max-c2.min+1);
        }
    }
    return temp;
}
inline const CircularInt operator/(const CircularInt& c1, const CircularInt& c2){
    if(c1.min>INT16_MIN&&c1.max>INT16_MIN&&c1.min!=c1.max){
        if(c1.hour%c2.hour!=0)
            throw string("There is no number x in {"+to_string(c1.min)+","+to_string(c1.max)+"} such that x*"+to_string(c2.hour)+"="+to_string(c1.hour));
    }
    else{
        if(c1.hour%c2.hour!=0)
            throw string("There is no number x in {"+to_string(c2.min)+","+to_string(c2.max)+"} such that x*"+to_string(c2.hour)+"="+to_string(c1.hour));
    }
    CircularInt temp(c1.hour/c2.hour);
    if(c1.min>INT16_MIN&&c1.max>INT16_MIN&&c1.min!=c1.max){
        while(temp.hour<c1.min){
            temp.hour=temp.hour+(c1.max-c1.min+1);
        }
        while(temp.hour>c1.max){
            temp.hour=temp.hour-(c1.max-c1.min+1);
        }
    }
    else{
        while(temp.hour<c2.min){
            temp.hour=temp.hour+(c2.max-c2.min+1);
        }
        while(temp.hour>c2.max){
            temp.hour=temp.hour-(c2.max-c2.min+1);
        }
    }
    return temp;
}
inline const CircularInt operator*(const CircularInt& c1, const CircularInt& c2){
    CircularInt temp(c1.hour*c2.hour);
    if(c1.min>INT16_MIN&&c1.max>INT16_MIN&&c1.min!=c1.max){
        while(temp.hour>c1.max){
            temp.hour=temp.hour-(c1.max-c1.min+1);
        }
        while(temp.hour<c1.min){
            temp.hour=temp.hour+(c1.max-c1.min+1);
        }
    }
    else{
        while(temp.hour>c2.max){
            temp.hour=temp.hour-(c2.max-c2.min+1);
        }
        while(temp.hour<c2.min){
            temp.hour=temp.hour+(c2.max-c2.min+1);
        }
    }
    return temp;
}