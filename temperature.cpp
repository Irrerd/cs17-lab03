//
// Created by u211-04 on 27.04.2017.
//
#include <iostream>
#include "temperature.h"
using namespace std;

istream & operator >>(istream & in, temperature& t){
    in>>t.value;
    if(!in){
        in.setstate(ios_base::failbit);
        return in;
    }
    char symbol;
    in>>symbol;
    switch (symbol){
    case 'K':
        t.scale = Kelvin;
        break;
    case 'C':
        t.scale = Celsius;
        break;
    case 'F':
        t.scale = Farengheit;
        break;
    default:
        in.setstate(ios_base::failbit);
        return in;
    }
    temperature T;
    T = convert(t,Kelvin);
    if(T.value<0){
        in.setstate(ios_base::failbit);
        return in;
    }
    return in;
}

temperature convert (const temperature& from, Scale scale) {
    double kelvin;
    switch (from.scale){
    case Kelvin:
        kelvin = from.value;
        break;
    case Farengheit:
        kelvin = (from.value - 32)/1,8 + 273,15;
        break;
    case Celsius:
        kelvin = from.value + 273,15;
        break;
    }
    temperature result;
    result.scale = scale;
    switch (scale){
    case Kelvin:
        result.value = kelvin;
        break;
    case Farengheit:
        result.value = kelvin + 273,15;
        break;
    case Celsius:
        result.value = 1,8*kelvin + 32 ;
        break;
    }
    return result;
}


bool  operator<(temperature& lhs, temperature& rhs){
    lhs = convert(lhs, rhs.scale);
    return lhs.value < rhs.value;
}

bool  operator>(temperature& lhs, temperature& rhs){
    lhs = convert(lhs, rhs.scale);
    return lhs.value > rhs.value;
}

