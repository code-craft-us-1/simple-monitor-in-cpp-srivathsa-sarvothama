#pragma once
#include <vector>

enum Vital {
    Temperature,
    PulseRate,
    SPO2
};

struct VitalRange {
    Vital vital;
    float min;
    float max;
    const char* message;
};

struct VitalValue {
    Vital vital;
    float value;
};

int vitalsOk(std::vector<VitalValue> inputVitals);
