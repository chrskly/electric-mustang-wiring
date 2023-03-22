
typedef struct {
    uint16_t batteryCapacity;
    uint16_t targetBatteryVoltage;
    uint16_t maximumBatteryVoltage;
    bool vehicleShiftLeverPosition;
    bool contactorStatus;
} CAR;



typedef struct {
    bool evseSupportsCarContactorWeldDetection;
} EVSE;