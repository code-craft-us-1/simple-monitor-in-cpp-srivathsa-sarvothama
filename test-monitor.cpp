#include "./monitor.h"

#include "gtest/gtest.h"

std::vector<VitalValue> vitalsAllOKData = {
    {Temperature, 96},
    {PulseRate, 70},
    {SPO2, 95}
};

TEST(Monitor, AllVitalsOK) {
    ASSERT_TRUE(vitalsOk(vitalsAllOKData));
}

TEST(Monitor, HighTemperature) {
    std::vector<VitalValue> highTempData = vitalsAllOKData;
    highTempData[Temperature].value = 103;
    ASSERT_FALSE(vitalsOk(highTempData));
}

TEST(Monitor, LowTemperature) {
    std::vector<VitalValue> lowTempData = vitalsAllOKData;
    lowTempData[Temperature].value = 90;
    ASSERT_FALSE(vitalsOk(lowTempData));
}

TEST(Monitor, HighPulseRate) {
    std::vector<VitalValue> highPulseRateData = vitalsAllOKData;
    highPulseRateData[PulseRate].value = 120;
    ASSERT_FALSE(vitalsOk(highPulseRateData));
}

TEST(Monitor, LowPulseRate) {
    std::vector<VitalValue> lowPulseRateData = vitalsAllOKData;
    lowPulseRateData[PulseRate].value = 40;
    ASSERT_FALSE(vitalsOk(lowPulseRateData));
}

TEST(Monitor, LowSPO2) {
    std::vector<VitalValue> lowSPO2Data = vitalsAllOKData;
    lowSPO2Data[SPO2].value = 70;
    ASSERT_FALSE(vitalsOk(lowSPO2Data));
}

