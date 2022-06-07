
#include "structs.h"

void requestModuleData(BatteryModule *module);
bool pollAllModulesForData(struct repeating_timer *t);
void enableModulePolling();
bool sendStatusMessage();
void enableStatusMessages();
bool sendChargeLimitsMessage();
void enableChargeLimitsMessages();
void disableChargeLimitsMessages();