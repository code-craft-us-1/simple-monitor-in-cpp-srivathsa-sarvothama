#include "./monitor.h"

#include "gtest/gtest.h"

TEST(Monitor, HighTemperature)
{
    std::vector<VitalValue> measuredValues = {
        {Temperature, 103},
        {PulseRate, 70},
        {SPO2, 95}
    };

  ASSERT_FALSE(vitalsOk(measuredValues));
}

TEST(Monitor, LowTemperature)
{
    std::vector<VitalValue> measuredValues = {
        {Temperature, 90},
        {PulseRate, 70},
        {SPO2, 95}
    };

    ASSERT_FALSE(vitalsOk(measuredValues));
}

TEST(Monitor, HighPulseRate)
{
    std::vector<VitalValue> measuredValues = {
        {Temperature, 96},
        {PulseRate, 120},
        {SPO2, 95}
    };

    ASSERT_FALSE(vitalsOk(measuredValues));
}

TEST(Monitor, LowPulseRate)
{
    std::vector<VitalValue> measuredValues = {
        {Temperature, 96},
        {PulseRate, 40},
        {SPO2, 95}
    };

    ASSERT_FALSE(vitalsOk(measuredValues));
}

TEST(Monitor, LowSPO2)
{
    std::vector<VitalValue> measuredValues = {
        {Temperature, 96},
        {PulseRate, 70},
        {SPO2, 70}
    };

    ASSERT_FALSE(vitalsOk(measuredValues));
}

TEST(Monitor, AllVitalsOK)
{
    std::vector<VitalValue> measuredValues = {
        {Temperature, 96},
        {PulseRate, 70},
        {SPO2, 95}
    };

    ASSERT_TRUE(vitalsOk(measuredValues));
}