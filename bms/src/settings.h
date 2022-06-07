
#define NUM_PACKS         2                        // The total number of paralleled packs in this battery
#define CELLS_PER_MODULE 16                        // The number of cells in each module
#define TEMPS_PER_MODULE  4                        // The number of temperature sensors in each module
#define MODULES_PER_PACK  6                        // The number of modules in each pack


#define PACK_ALIVE_TIMEOUT 5                       // If we have not seen an update from the BMS in
                                                   // PACK_ALIVE_TIMEOUT seconds, then mark the pack
                                                   // as dead.

// Official min pack voltage = 269V. 269 / 6 / 16 = 2.8020833333V
#define CELL_UNDER_VOLTAGE_WARNING_THRESHOLD 2.9
#define CELL_UNDER_VOLTAGE_FAULT_THRESHOLD 2.81

// Official max pack voltage = 398V. 398 / 6 / 16 = 4.1458333333V
#define CELL_OVER_VOLTAGE_WARNING_THRESHOLD 4.1
#define CELL_OVER_VOLTAGE_FAULT_THRESHOLD 4.1458

#define CELL_UNDER_TEMPERATURE_FAULT_THRESHOLD 0
#define CELL_OVER_TEMPERATURE_WARNING_THRESHOLD 55  // degrees
#define CELL_OVER_TEMPERATURE_FAULT_THRESHOLD 65    // degrees

#define CHARGE_THROTTLE_TEMP_LOW  45                // Start throttling charge current above this temperature
#define CHARGE_THROTTLE_TEMP_HIGH 65                // Top of the throttling scale. Limit current to CHARGE_CURRENT_MIN at and above this temperature
#define CHARGE_CURRENT_MAX 125                      // ~50kw
#define CHARGE_CURRENT_MIN 8                        // ~3.3kw



//// ---- CAN message IDs

#define STATUS_MSG_ID 0x300                         // Status message emitted by the BMS
#define CAN_ID_ISA_SHUNT_AH 0x527                   // Message ISA shunt sends which contains Ah data.
#define CAN_ID_ISA_SHUNT_WH 0x528                   // Message ISA shunt sends which contains Wh data.