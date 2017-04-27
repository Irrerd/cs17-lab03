#include <iostream>
#include <vector>
#include <sstream>
#include <cassert>
#include "temperature.h"
using namespace std;

void test_temperature_input(){
    stringstream in ("30C");
    temperature t;
    in>>t;
    assert(t.value == 30);
    assert(t.scale == Celsius);

    stringstream on ("-5F");
    on>>t;
    assert(t.value == -5);
    assert(t.scale == Farengheit);

    stringstream en ("-5F");
    en>>t;
    assert(t.value == 0);
    assert(t.scale == Kelvin);
}

int
main() {
    size_t number_count;
    cerr << "Enter number count: ";
    cin >> number_count;

    cerr << "Enter numbers: ";
    vector<temperature> numbers(number_count);
    for (size_t i = 0; i < number_count; i++) {
        cin >> numbers[i];
    }

    size_t column_count;
    cerr << "Enter column count: ";
    cin >> column_count;

    temperature min = numbers[0];
    temperature max = numbers[0];
    for (temperature number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }

    max = convert(max, min.scale);

    vector<size_t> counts(column_count);
    for (temperature number : numbers) {
        number = convert(number, min.scale);
        size_t column = (size_t)((number.value - min.value) / (max.value - min.value) *
                column_count);
        if (column == column_count) {
            column--;
        }
        counts[column]++;
    }

    const size_t screen_width = 80;
    const size_t axis_width = 4;
    const size_t chart_width = screen_width - axis_width;

    // Можно было бы считать в предыдущем цикле, но так более наглядно.
    size_t max_count = 0;
    for (size_t count : counts) {
        if (count > max_count) {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > chart_width;

    for (size_t count : counts) {
        if (count < 100) {
            cout << ' ';
        }
        if (count < 10) {
            cout << ' ';
        }
        cout << count << "|";

        size_t height = count;
        if (scaling_needed) {
            // Point: код должен быть в первую очередь понятным.
            const double scaling_factor = (double)chart_width / max_count;
            height = (size_t)(count * scaling_factor);
        }

        for (size_t i = 0; i < height; i++) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}