
#define CELL_UNDER_VOLTAGE_WARNING_THRESHOLD = 3.7
#define CELL_UNDER_VOLTAGE_FAULT_THRESHOLD = 3.6
#define CELL_OVER_VOLTAGE_WARNING_THRESHOLD = 4.0
#define CELL_OVER_VOLTAGE_FAULT_THRESHOLD = 4.1


struct BatteryModule {
	float cellVoltage[16];        // Voltages of each cell
	int cellOverVoltageWarnings;  // count of cells with voltage higher than the warning threshold
	int cellOverVoltageFaults;    // count of cells with voltage higher then the fault threshold	
	int cellUnderVoltageWarnings; // count of cells with voltage lower than the warning threshold
	int cellUnderVoltageFaults;   // count of cells with voltage lower than the fault threshold
};