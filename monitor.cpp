#include "./monitor.h"
#include <cassert>
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

VitalRange vitalRanges[] = {
    {Temperature, 95.0f, 102.0f, "Temperature is critical!\n"},
    {PulseRate, 60.0f, 100.0f, "Pulse Rate is out of range!\n"},
    {SPO2, 90.0f, std::numeric_limits<float>::max(), "Oxygen Saturation out of range!\n"}
};

void showMessage(std::string message) {
    cout << message;
    for (int i = 0; i < 6; i++) {
    cout << "\r* " << flush;
    sleep_for(seconds(1));
    cout << "\r *" << flush;
    sleep_for(seconds(1));
  }
}

bool isVitalInRange(const VitalValue& vitalValue, const VitalRange& vitalRange) {
    return vitalValue.value >= vitalRange.min && vitalValue.value <= vitalRange.max;
}

int vitalsOk(std::vector<VitalValue> inputVitals) {
    for (size_t i = 0; i < inputVitals.size(); i++) {
        assert(inputVitals[i].vital == vitalRanges[i].vital);
        if (!isVitalInRange(inputVitals[i], vitalRanges[i])) {
            showMessage(vitalRanges[i].message);
            return 0;
        }
    }
    return 1;
}
