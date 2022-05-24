
#define NUM_PACKS         2  // The total number of paralleled packs in this battery
#define CELLS_PER_MODULE 16  // The number of cells in each module
#define MODULES_PER_PACK  6  // The number of modules in each pack

#define PACK_ALIVE_TIMEOUT 5   // If we have not seen an update from the BMS in
                               // PACK_ALIVE_TIMEOUT seconds, then mark the pack
                               // as dead.

#define CELL_UNDER_VOLTAGE_WARNING_THRESHOLD 3.7
#define CELL_UNDER_VOLTAGE_FAULT_THRESHOLD 3.6
#define CELL_OVER_VOLTAGE_WARNING_THRESHOLD 4.0
#define CELL_OVER_VOLTAGE_FAULT_THRESHOLD 4.1
#define CELL_UNDER_TEMPERATURE_FAULT_THRESHOLD 0
#define CELL_OVER_TEMPERATURE_WARNING_THRESHOLD 55  // degrees
#define CELL_OVER_TEMPERATURE_FAULT_THRESHOLD 65    // degrees