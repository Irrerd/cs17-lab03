//
// Created by u211-04 on 27.04.2017.
//
#include <sstream>
#include "temperature.h"
#include <cassert>
using namespace std;

int main(){
    stringstream in ("30C");
    temperature t;
    in>>t;
    assert(t.value == 30);
    assert(t.scale == Celsius);

    stringstream on ("-5F");
    on>>t;
    assert(t.value == -5);
    assert(t.scale == Farengheit);

    stringstream en ("0K");
    en>>t;
    assert(t.value == 0);
    assert(t.scale == Kelvin);

    stringstream un ("I'm Ironman");
    un>>t;
    assert(!un);

    stringstream an ("21-etagggg");
    an>>t;
    assert(!an);

    stringstream yn ("07Zvezdniylord");
    yn>>t;
    assert(!yn);
}

